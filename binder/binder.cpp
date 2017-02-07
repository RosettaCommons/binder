// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/binder.cpp
/// @brief  Main
/// @author Sergey Lyskov

#include <binder.hpp>

// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/AST/Comment.h>

// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include <context.hpp>
#include <enum.hpp>
#include <function.hpp>
#include <class.hpp>
#include <util.hpp>


using namespace clang::tooling;
using namespace llvm;


// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory BinderToolCategory("Binder options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
static cl::extrahelp MoreHelp("\nMore help text...\n");


using binder::Config;

using namespace clang;

using std::string;


cl::opt<std::string> O_root_module("root-module", cl::desc("Name of root module"), /*cl::init("example"),*/ cl::cat(BinderToolCategory));

cl::opt<int> O_max_file_size("max-file-size", cl::desc("Specify maximum length of generated source files"), cl::init(1024*16), cl::cat(BinderToolCategory));

cl::opt<std::string> O_prefix("prefix", cl::desc("Output prefix for all generated files. Might contain directories."), cl::init(""), cl::cat(BinderToolCategory));

cl::list<std::string> O_bind("bind", cl::desc("Namespace to bind, could be specified more then once. Specify \"\" to bind all namespaces."), cl::cat(BinderToolCategory)); // , cl::OneOrMore
cl::list<std::string> O_skip("skip", cl::desc("Namespace to skip, could be specified more then once"), cl::cat(BinderToolCategory)); // , cl::OneOrMore

cl::opt<std::string> O_config("config", cl::desc("Specify config file from which bindings setting will be read"), cl::init(""), cl::cat(BinderToolCategory));

cl::opt<bool> O_annotate_includes("annotate-includes", cl::desc("Annotate each includes in generated code with type name that trigger it inclusion"), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_single_file("single-file", cl::desc("Concatenate all binder output into single file with name: root-module-name + '.cpp'. Use this for a small projects and for testing."), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_trace("trace", cl::desc("Add tracer output for each binded object (i.e. for debugging)"), cl::init(false), cl::cat(BinderToolCategory));


class ClassVisitor : public RecursiveASTVisitor<ClassVisitor>
{
public:
    explicit ClassVisitor(DeclContext *dc) /*: decl_context(dc)*/ {}

	virtual ~ClassVisitor() {}

	virtual bool VisitEnumDecl(EnumDecl *record) {
		errs() << "ClassVisitor EnumDecl: " << record->getQualifiedNameAsString() << "\n";
		record->dump();
        return true;
	}

private:
    //DeclContext *decl_context;
};

string wrap_CXXRecordDecl(CXXRecordDecl *R)
{
	ClassVisitor v{R};
	v.TraverseDecl( R );
	//R->dump();
	return "";
}


class BinderVisitor : public RecursiveASTVisitor<BinderVisitor>
{
public:
    explicit BinderVisitor(CompilerInstance *ci) : ast_context( &( ci->getASTContext() ) )
	{
		Config & config = Config::get();

		config.root_module = O_root_module;
		config.prefix = O_prefix;
		config.maximum_file_length = O_max_file_size;

		config.namespaces_to_bind = O_bind;
		config.namespaces_to_skip = O_skip;

		if( O_config.size() ) config.read(O_config);
	}

	virtual ~BinderVisitor() {}

	bool shouldVisitTemplateInstantiations () const { return true; }

	virtual bool VisitFunctionDecl(FunctionDecl *F)
	{
		if( F->isCXXInstanceMember() || isa<CXXMethodDecl>(F) ) return true;

		if( binder::is_bindable(F) ) {
			binder::BinderOP b = std::make_shared<binder::FunctionBinder>(F);
			context.add(b);
		} else if( F->isOverloadedOperator()  &&  F->getNameAsString() == "operator<<" ) {
			//outs() << "Adding insertion operator: " << binder::function_pointer_type(F) << "\n";
			context.add_insertion_operator(F);
		}

        return true;
    }

	virtual bool VisitCXXRecordDecl(CXXRecordDecl *C) {
		if( C->isCXXInstanceMember()  ||  C->isCXXClassMember() ) return true;

		if( binder::is_bindable(C) ) {
			binder::BinderOP b = std::make_shared<binder::ClassBinder>(C);
			context.add(b);
		}

        return true;
    }

	// virtual bool VisitClassTemplateSpecializationDecl(ClassTemplateSpecializationDecl *C) {
	// 	if( FullSourceLoc(C->getLocation(), ast_context->getSourceManager() ).isInSystemHeader() ) return true;
	// 	errs() << "Visit ClassTemplateSpecializationDecl:" << C->getQualifiedNameAsString() << binder::template_specialization(C) << "\n";
	// 	C->dump();
    //     return true;
	// }

	// virtual bool VisitTemplateDecl(TemplateDecl *record) {
	// 	//if( FullSourceLoc(record->getLocation(), ast_context->getSourceManager() ).isInSystemHeader() ) return true;
	// 	errs() << "Visit TemplateDecl: " << record->getQualifiedNameAsString() << "\n";
	// 	//record->dump();
    //     return true;
	// }

	// virtual bool VisitClassTemplateDecl(ClassTemplateDecl *record) {
	// 	//if( FullSourceLoc(record->getLocation(), ast_context->getSourceManager() ).isInSystemHeader() ) return true;
	// 	errs() << "Visit ClassTemplateDecl: " << record->getQualifiedNameAsString() << binder::template_specialization( record->getTemplatedDecl() ) << "\n";
	// 	//record->dump();
    //     return true;
	// }

	// virtual bool VisitTypedefDecl(TypedefDecl *T) {
	// 	if( FullSourceLoc(T->getLocation(), ast_context->getSourceManager() ).isInSystemHeader() ) return true;
	// 	//errs() << "Visit TypedefDecl: " << T->getQualifiedNameAsString() << "  Type: " << T->getUnderlyingType()->getCanonicalTypeInternal()/*getCanonicalType()*/.getAsString() << "\n";
	// 	// record->dump();
    //     return true;
	// }

	// virtual bool VisitNamedDecl(NamedDecl *record) {
	// 	errs() << "Visit NamedRecord: " << record->getQualifiedNameAsString() << "\n";
    //     return true;
	// }

	// virtual bool VisitFieldDecl(FieldDecl *record) {
	// 	errs() << "Visit FieldDecl: " << record->getQualifiedNameAsString() << "\n";
	// 	record->dump();
    //     return true;
	// }

	virtual bool VisitEnumDecl(EnumDecl *E) {
		if( E->isCXXInstanceMember()  ||  E->isCXXClassMember() ) return true;

		binder::BinderOP b = std::make_shared<binder::EnumBinder>( E/*->getCanonicalDecl()*/ );
		context.add(b);

        return true;
	}

	void generate(void) {
		context.generate( Config::get() );
	}

private:
    ASTContext *ast_context;

	binder::Context context;
};


class BinderASTConsumer : public ASTConsumer
{
private:
    std::unique_ptr<BinderVisitor> visitor;

public:
    // override the constructor in order to pass CI
    explicit BinderASTConsumer(CompilerInstance *ci) : visitor(new BinderVisitor(ci)) {}

    // override this to call our ExampleVisitor on the entire source file
    virtual void HandleTranslationUnit(ASTContext &context)
	{
        visitor->TraverseDecl( context.getTranslationUnitDecl() );
		visitor->generate();
    }
};


class BinderFrontendAction : public ASTFrontendAction {
public:
    virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(CompilerInstance &ci, StringRef file) {
        return std::unique_ptr<ASTConsumer>( new BinderASTConsumer(&ci) );
    }
};


int main(int argc, const char **argv)
{
	CommonOptionsParser op(argc, argv, BinderToolCategory);

	ClangTool tool(op.getCompilations(), op.getSourcePathList());

	//outs() << "Root module: " << O_root_module << "\n";
	//for(auto &s : O_bind) outs() << "Binding: '" << s << "'\n";

	return tool.run(newFrontendActionFactory<BinderFrontendAction>().get());
}
