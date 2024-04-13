// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/binder.cpp
/// @brief  Classes IncludeSet and Binder
/// @author Sergey Lyskov

#include <binder.hpp>

#include <type.hpp> // is_python_builtin

#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/AST/Comment.h>
#include <clang/Basic/Diagnostic.h>

#include <llvm/Support/CommandLine.h> // Declares llvm::cl::extrahelp

#include <context.hpp>
#include <enum.hpp>
#include <const.hpp>
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
using std::vector;

namespace binder {

// const std::string _module_variable_name_{"M"};

// check if declaration is already in stack with level at least as 'level' or lower and add it if it is not - return true if declaration was added

bool IncludeSet::add_decl(clang::NamedDecl const *D, int level)
{
	auto it_inserted = stack_.insert( {D, level} );
	auto & it = it_inserted.first;
	auto & inserted = it_inserted.second;
	if(inserted) return true;
	else {
		if( it->second <= level ) return false;
		else {
			it->second = level;
			//it.value() = level;
			return true;
		}
	}

	// {
	// 	std::unordered_map<int, int> mp;
	// 	//tsl::robin_map<int, int> mp;
	// 	mp[0] = 0;
	// 	mp.find(0)->second = 1;
	// 	mp.insert({0, 1}).first->second = 2;
	// }


	// StackType::iterator it;
	// bool inserted;
	// std::tie(it, inserted) = stack_.insert( StackType::value_type(D, level) );


	// auto it = stack_.find(D);
	// if( it == stack_.end() ) {
	// 	 stack_[D] = level;
	// 	 return true;
	// }
	// else {
	// 	if( it->second <= level ) return false;
	// 	else {
	// 		it->second = level;
	// 		return true;
	// 	}
	// }

	// auto &l = stack_[D];
	// if( l.value and l.value <= level.value ) return false;
	// l = level;
	// return true;

	// if( stack_.count(D) and stack_[D] <= level ) return false;
	// stack_[D] = level;
	// return true;
}

// remove all includes and clear up the stack
void IncludeSet::clear()
{
<<<<<<< HEAD
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
		if( O_suppress_errors )	{
			clang::DiagnosticsEngine& di = ci->getDiagnostics();
#if  (LLVM_VERSION_MAJOR < 10)
			di.setSuppressAllDiagnostics();
#else
			di.setSuppressAllDiagnostics(true);
#endif
		}
	}

	virtual ~BinderVisitor() {}

	bool shouldVisitTemplateInstantiations () const { return true; }

	virtual bool VisitFunctionDecl(FunctionDecl *F)
	{
		if( F->isCXXInstanceMember() or isa<CXXMethodDecl>(F) ) return true;

		if( binder::is_bindable(F) ) {
			binder::BinderOP b = std::make_shared<binder::FunctionBinder>(F);
			context.add(b);
		} else if( F->isOverloadedOperator()  and  F->getNameAsString() == "operator<<" ) {
			//outs() << "Adding insertion operator: " << binder::function_pointer_type(F) << "\n";
			context.add_insertion_operator(F);
		}

        return true;
    }

	virtual bool VisitCXXRecordDecl(CXXRecordDecl *C) {
		if( C->isCXXInstanceMember()  or  C->isCXXClassMember() ) return true;

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
		if( E->isCXXInstanceMember()  or  E->isCXXClassMember() ) return true;

		binder::BinderOP b = std::make_shared<binder::EnumBinder>( E/*->getCanonicalDecl()*/ );
		context.add(b);

        return true;
	}
	 virtual bool VisitVarDecl(VarDecl *V) {
		if( !V->getType().isConstQualified() )  return true;
		if( !V->hasInit() ) return true;
		if( V->getType().getTypePtr()->isArrayType()) return true;
		if( V->isCXXInstanceMember()  or  V->isCXXClassMember() ) return true;
		binder::BinderOP b = std::make_shared<binder::ConstBinder>( V );
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
=======
	includes_.clear();
	stack_.clear();
>>>>>>> origin/master
}

/// return true if object declared in system header
bool Binder::is_in_system_header()
{
	using namespace clang;
	NamedDecl const *decl(named_decl());
	ASTContext &ast_context(decl->getASTContext());
	SourceManager &sm(ast_context.getSourceManager());

	return FullSourceLoc(decl->getLocation(), sm).isInSystemHeader();
}

// return true if code was already generate for this object
bool Binder::is_binded() const
{
	return code().size() or is_python_builtin(named_decl());
}

llvm::raw_ostream &operator<<(llvm::raw_ostream &os, Binder const &b)
{
	clang::NamedDecl const *decl = b.named_decl();

	string name = decl->getNameAsString();
	string qualified_name = decl->getQualifiedNameAsString();
	string path = decl->getQualifiedNameAsString().substr(0, qualified_name.size() - name.size());

	return os << "B{name=" << name << ", path=" << path << "\n"; //<< ", include= " code=\n" << b("module") << "\n}
}

} // namespace binder
