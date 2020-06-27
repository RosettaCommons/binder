// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/util.cpp
/// @brief  Various helper functions
/// @author Sergey Lyskov

#include <util.hpp>

#include <binder.hpp>
#include <enum.hpp>
#include <type.hpp>
#include <class.hpp>

#include <clang/AST/ASTContext.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/Comment.h>

//#include <experimental/filesystem>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace llvm;
using namespace clang;
using std::string;
using std::vector;

namespace binder {


/// Split string using given separator
vector<string> split(string const &buffer, string const & separator)
{
	string line;
	vector<string> lines;

	for(uint i=0; i<buffer.size(); ++i) {
		if( buffer.compare(i, separator.size(), separator) ) line.push_back( buffer[i] );
		else {
			lines.push_back(line);
			line.resize(0);
		}
	}

	if( line.size() ) lines.push_back(line);

	return lines;
}


/// Replace all occurrences of string
void replace(string &r, string const & from, string const &to)
{
	size_t i = r.size();
	while( ( i = r.rfind(from, i) ) != string::npos) {
		r.replace(i, from.size(), to);
		if(i) --i; else break;
	}
}


/// Replace all occurrences of string and return result as new string
string replace_(string const &s, string const & from, string const &to)
{
	string r{s};
	replace(r, from, to);
	return r;
}


/// check if string begins with given prefix
bool begins_with(std::string const &source, std::string const &prefix)
{
	return !source.compare(0, prefix.size(), prefix);
}


/// check if string ends with given prefix
bool ends_with(std::string const &source, std::string const &prefix)
{
	if( prefix.size() > source.size() ) return false;
	return !source.compare(source.size() - prefix.size(), prefix.size(), prefix);
}


string indent(string const &code, string const &indentation)
{
	auto lines = split(code);
	string r;

	for(auto & l : lines) r += l.size() ? indentation + l + '\n' : l + '\n';

	return r;
}


/// Try to read exisitng file and if content does not match to code - write a new version. Also create nested dirs starting from prefix if nessesary.
void update_source_file(std::string const &prefix, std::string const &file_name, std::string const &code)
{
	string path = prefix;

	vector<string> dirs = split(file_name, "/");  dirs.pop_back();
	for(auto &d : dirs) path += "/" + d;

	//std::experimental::filesystem::create_directories(path);
	string command_line = "mkdir -p "+path;
	system( command_line.c_str() );

	string full_file_name = prefix + file_name;
	std::ifstream f(full_file_name);
	std::string old_code((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

	if( old_code != code ) {
		if( O_verbose ) outs() << "Writing " << full_file_name << "\n";
		std::ofstream(full_file_name) << code;
	} else {
		if( O_verbose ) outs() << "File " << full_file_name << " is up-to-date, skipping...\n";
	}
}


string namespace_from_named_decl(NamedDecl const *decl)
{
	//return decl->getOuterLexicalRecordContext()->getNameAsString();
	//outs() << decl->getDeclKindName() << "\n";

	string qn = standard_name( decl->getQualifiedNameAsString() );
	string n  = decl->getNameAsString();

	int namespace_len = qn.size() - n.size();

	string path = qn.substr(0, namespace_len > 1 ? namespace_len-2 : namespace_len );  // removing trailing '::'

	return path;
}


/// generate unique string representation of type represented by given declaration
string typename_from_type_decl(TypeDecl *decl)
{
	return standard_name( decl->getTypeForDecl()->getCanonicalTypeInternal()/*getCanonicalType()*/.getAsString() );
}


/// Calculate base (upper) namespace for given one: core::pose::motif --> core::pose
string base_namespace(string const & ns)
{
	size_t f = ns.rfind("::");
	if( f == string::npos ) return "";
	else return ns.substr(0, f);
}


/// Calculate last namespace for given one: core::pose::motif --> motif
string last_namespace(string const & ns)
{
	size_t f = ns.rfind("::");
	if( f == string::npos ) return ns;
	else return ns.substr(f+2, ns.size()-f-2);
}


// replace all _Bool types with bool
void fix_boolean_types(string &type)
{
	string B("_Bool");
	size_t i = 0;
	while( ( i = type.find(B, i) ) != string::npos ) {
		if( ( i==0  or ( !std::isalpha(type[i-1]) and  !std::isdigit(type[i-1]) ) ) and
			( i+B.size() == type.size()  or ( !std::isalpha(type[i+B.size()]) and  !std::isdigit(type[i+B.size()]) ) ) ) type.replace(i, B.size(), "bool");
		++i;
	}
}


// Generate string representation of given expression
string expresion_to_string(clang::Expr *e)
{
	std::string _;
	llvm::raw_string_ostream s(_);

	if(e) {
		clang::LangOptions lang_opts;
		lang_opts.CPlusPlus = true;
		clang::PrintingPolicy Policy(lang_opts);

		e->printPretty(s, 0, Policy);
	}

	return s.str();
}


// Generate string representation of given TemplateArgument
string template_argument_to_string(clang::TemplateArgument const &t)
{
	clang::LangOptions lang_opts;
	lang_opts.CPlusPlus = true;
	clang::PrintingPolicy Policy(lang_opts);

	std::string _;
	llvm::raw_string_ostream s(_);
	t.print(Policy, s);
	return s.str();
}


// calcualte line in source file for NamedDecl
string line_number(NamedDecl const *decl)
{
	ASTContext & ast_context( decl->getASTContext() );
	SourceManager & sm( ast_context.getSourceManager() );

	return std::to_string( sm.getSpellingLineNumber(decl->getLocation() ) );
}


// generate string represetiong class name that could be used in python
string mangle_type_name(string const &name, bool mark_template)
{
	string r;
	bool mangle = true;
	bool template_ = false;

	for(auto & c : name) {
		if(c!=' '  and  c!='<'  and  c!='>'  and  c!=','  and  c!=':') { r.push_back(c); mangle=false; }
		else if(!mangle) { mangle = true; r.push_back('_'); }

		if( c=='<'  or  c=='>'  or  c==',') template_ = true;
	}

	if(template_ and mark_template) r.push_back('t');
	return r;
}


// generate C++ comment line for given declartion along with file path and line number: // core::scoring::vdwaals::VDWAtom file:core/scoring/vdwaals/VDWTrie.hh line:43
string generate_comment_for_declaration(clang::NamedDecl const *decl)
{
	string const include = relevant_include(decl);
	return "// " + standard_name( decl->getQualifiedNameAsString() ) + " file:" + (include.size() ? include.substr(1, include.size()-2) : "") + " line:" + line_number(decl) + "\n";
}




// extract text from hierarchy of comments
string get_text(comments::Comment const *C, SourceManager const & SM, SourceLocation previous)
{
	if( auto tc = dyn_cast<comments::TextComment>(C) ) return tc->getText();
	else {
		string r;

		if( isa<comments::ParagraphComment>(C) ) r += '\n';

		for(auto i = C->child_begin(); i!=C->child_end(); ++i) {
#if  (LLVM_VERSION_MAJOR < 8)
			if( SM.getSpellingLineNumber(previous) != SM.getSpellingLineNumber( (*i)->getLocStart() ) ) {  // getBeginLoc
				previous = (*i)->getLocStart(); // getBeginLoc();
				r += '\n';
			}
#endif
#if  (LLVM_VERSION_MAJOR >= 8)
			if( SM.getSpellingLineNumber(previous) != SM.getSpellingLineNumber( (*i)->getBeginLoc() ) ) {  // getBeginLoc
				previous = (*i)->getBeginLoc(); // getBeginLoc();
				r += '\n';
			}
#endif		
			r += get_text(*i, SM, previous);
		}

		return r;
	}
}


// extract doc string (Doxygen comments) for given declaration and convert it to C++ source code string
std::string generate_documentation_string_for_declaration(clang::Decl const* decl)
{
	string text;

	ASTContext & ast_context( decl->getASTContext() );
	if( auto comment = ast_context.getLocalCommentForDeclUncached(decl) ) {

		SourceManager & sm( ast_context.getSourceManager() );

		//comment->dumpColor();

		text = get_text(comment, sm, SourceLocation());

		uint i=0;
		for(; i<text.size()  and  (text[i]==' ' or text[i]=='\n'); ++i) {}
		if(i) text = text.substr(i);

		//replace(text, "\n\n\n", "\n");
		//replace(text, "\n\n",   "\n");

		//replace(text, "\n\n\n\n", "\n\n");
		//replace(text, "\n\n\n",   "\n\n");

		replace(text, "\\", "\\\\");
		replace(text, "\"", "\\\"");
		replace(text, "\n", "\\n");

		//outs() << text << "\n";
	}

	//if( auto comment = ast_context->getLocalCommentForDeclUncached(decl) ) comment->dumpColor();

	return text;
}


} // namespace binder
