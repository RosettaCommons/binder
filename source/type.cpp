
// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/type.cpp
/// @brief  Various functionality for handline clang::QualType's
/// @author Sergey Lyskov

#include <type.hpp>

#include <binder.hpp>
#include <class.hpp>
#include <enum.hpp>
#include <util.hpp>

#include <clang/AST/ASTContext.h>
#include <clang/AST/ExprCXX.h>
#include <llvm/Support/Regex.h>

//#include <experimental/filesystem>
#include <cstdlib>
#include <fstream>

//using namespace llvm;
using llvm::outs;

using namespace clang;

using std::string;
using std::vector;
using std::make_pair;


namespace binder {


/// check if user requested binding for the given QualType
bool is_binding_requested(clang::QualType const &qt, Config const &config)
{
	if( clang::PointerType const *pt = dyn_cast<clang::PointerType>( qt.getTypePtr() ) ) return is_binding_requested(pt->getPointeeType(), config);

	if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) return is_binding_requested(rt->getPointeeType(), config);

	if( CXXRecordDecl *r = qt->getAsCXXRecordDecl() ) return is_binding_requested(r, config);

	return false;
}


// check if user requested skipping for the given declaration
bool is_skipping_requested(QualType const &qt, Config const &config)
{
	if( clang::PointerType const *pt = dyn_cast<clang::PointerType>( qt.getTypePtr() ) ) return is_skipping_requested(pt->getPointeeType(), config);

	if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) return is_skipping_requested(rt->getPointeeType(), config);

	if( CXXRecordDecl *r = qt->getAsCXXRecordDecl() ) return is_skipping_requested(r, config);

	return false;
}


// extract include path needed for declaration itself (without template dependency if any), return empty string if no include could be found
string relevant_include(NamedDecl const *decl)
{
	ASTContext & ast_context( decl->getASTContext() );
	SourceManager & sm( ast_context.getSourceManager() );

	FileID fid = sm.getFileID( decl->getLocation() );
	SourceLocation include = sm.getIncludeLoc(fid);

	string include_string;
	if( include.isValid() ) {
		char const *data = sm.getCharacterData(include);

		if( strlen(data) > 2  and  (*data == '"' or  *data == '<') ) {  // should be at least 3 chars: open/close symbol + file name
			char terminator = *data == '"' ? '"' : '>';

			include_string.push_back(*data); ++data;
			for(; *data and  *data != terminator; ++data ) include_string.push_back(*data);
			if(*data == terminator) include_string.push_back(*data);
		}
		if( include_string.size()  and  include_string[0]=='"' ) include_string.resize(0); // avoid adding include in quotes because compiler will not be able to find them
	}

	return include_string;
}


// extract include path needed for declaration itself (without template dependency if any), do nothing if include could not be found (ie for build-in's)
void add_relevant_include_for_decl(NamedDecl const *decl, IncludeSet &includes/*, std::set<clang::NamedDecl const *> &stack*/)
{
	static std::unordered_map<string, string> type_map;

	if( type_map.empty() ) {
		std::vector< std::pair< string, std::vector<string> > > const include_types_map =
			{
			 { "<algorithm>", {"std::move_backward", "std::iter_swap", "std::min"} },

			 { "<iterator>",
			   {
				"std::advance", "std::distance", "std::iterator", "std::iterator_traits", "std::reverse_iterator", "std::bidirectional_iterator_tag",
				"std::forward_iterator_tag", "std::input_iterator_tag", "std::random_access_iterator_tag",
				"std::begin", "std::end",
			   }
			 },

			 { "<locale>", {"std::ctype", "std::ctype_byname", "std::ctype_base", "std::locale", "std::money_base", "std::messages_base", "std::numpunct", "std::num_get", "std::num_put", "std::numpunct_byname", "std::time_base", "std::codecvt", "std::codecvt_base", "std::codecvt_byname"} },

			 { "<regex>", {"std::basic_regex", "std::regex_traits"} },

			 { "<string>", {"std::basic_string", "std::char_traits"} },

			 { "<utility>", {"std::move"} },

			 { "<exception>", {"std::nested_exception"} },

			 { "<cwchar>", {"std::mbstate_t"} },

			 { "<memory>", {"std::uninitialized_copy"} },

			 { "<functional>", {"std::function"} },

			};

		for(auto const & include_types : include_types_map ) {
			for(auto const & type : include_types.second ) type_map.insert( make_pair(type, include_types.first) );
		}
	}

	static vector< std::pair<string, string> > const name_map_old = {
		make_pair("std::basic_ios",        "<ios>"),

		make_pair("std::list",             "<list>"),

		make_pair("std::map",              "<map>"),
		make_pair("std::allocator",        "<memory>"),

		make_pair("std::set",              "<set>"),
		make_pair("std::stack",            "<stack>"),

		make_pair("std::vector",           "<vector>"),

		make_pair("std::pair",             "<utility>"),

		make_pair("__gnu_cxx::__normal_iterator", "<iterator>"),

		make_pair("std::__1::basic_string<char,std::__1::char_traits<char>,std::__1::allocator<char>>", "<string>"),
		make_pair("std::__1::basic_streambuf<char,std::__1::char_traits<char>>",                        "<streambuf>"),
		make_pair("std::__1::basic_istream<char,std::__1::char_traits<char>>",                          "<istream>"),
		make_pair("std::__1::basic_iostream<char,std::__1::char_traits<char>>",                         "<ostream>"),
	};


	static vector< std::pair<string, string> > const include_map = {
		make_pair("<bits/ios_base.h>",     "<ios>"),
		make_pair("<bits/istream.tcc>",    "<istream>"),
		make_pair("<bits/ostream.tcc>",    "<ostream>"),
		make_pair("<bits/postypes.h>",     "<ios>"),

		make_pair("<bits/stl_function.h>", "<functional>"),
		make_pair("<bits/stl_tree.h>",     "<map>"),
		make_pair("<bits/stl_map.h>",      "<map>"),
		make_pair("<bits/streambuf.tcc>",  "<streambuf>"),
		make_pair("<bits/stl_bvector.h>",  "<vector>"),
		make_pair("<bits/stl_vector.h>",   "<vector>"),
		make_pair("<bits/algorithmfwd.h>", "<algorithm>"),
		make_pair("<bits/stl_algo.h>",     "<algorithm>"),
		make_pair("<bits/fstream.tcc>",    "<fstream>"),
		make_pair("<bits/sstream.tcc>",    "<sstream>"),
		make_pair("<bits/stl_list.h>",     "<list>"),
		make_pair("<bits/stl_deque.h>",    "<deque>"),
		make_pair("<bits/stl_queue.h>",    "<queue>"),
		make_pair("<bits/sched.h>",        "<unistd.h>"),
		make_pair("<bits/pthreadtypes.h>", "<pthread.h>"),
		make_pair("<bits/gthr-default.h>", "<pthread.h>"),
		make_pair("<bits/random.h>",       "<random>"),

		make_pair("<bits/basic_string.h>",  "<string>"),
		make_pair("<bits/basic_string.tcc>","<string>"),
		make_pair("<__string>",             "<string>"),
		make_pair("<bits/streambuf_iterator.h>", "<streambuf>"),

		make_pair("<bits/shared_ptr.h>",      "<memory>"),
		make_pair("<bits/unique_ptr.h>",      "<memory>"),
		make_pair("<bits/uses_allocator.h>",  "<memory>"),
		make_pair("<bits/shared_ptr_base.h>", "<memory>"),
		make_pair("<backward/auto_ptr.h>",    "<memory>"),
		make_pair("<ext/concurrence.h>",      "<memory>"),
		make_pair("<bits/ptr_traits.h>",      "<memory>"),
		make_pair("<bits/alloc_traits.h>",    "<memory>"),

		make_pair("<bits/error_constants.h>", "<system_error>"),

		make_pair("<bits/locale_classes.h>",   "<locale>"),
		make_pair("<bits/locale_classes.tcc>", "<locale>"),

		make_pair("<__tree>",              "<iterator>"),
		make_pair("<bits/stl_iterator.h>", "<iterator>"),

		make_pair("<__functional_base>", "<functional>"),

		make_pair("<_wctype.h>", "<cwctype>"),
		make_pair("<ctype.h>",   "<cctype>"),
		make_pair("<wchar.h>",   "<cwchar>"),

		make_pair("<bits/functional_hash.h>", "<functional>"),
		make_pair("<bits/unordered_set.h>",   "<unordered_set>"),
		make_pair("<bits/unordered_map.h>",   "<unordered_map>"),
		make_pair("<__hash_table>",           "<unordered_map>"),
		make_pair("<bits/hashtable_policy.h>", "<unordered_map>"),
		make_pair("<bits/hashtable.h>",        "<unordered_map>"),

		make_pair("<bits/stl_multiset.h>", "<set>"),
		make_pair("<bits/stl_multimap.h>", "<map>"),

		make_pair("<__locale>", "<locale>"),

		make_pair("<__bit_reference>", "<vector>"),

		make_pair("<bits/stl_stack.h>", "<stack>"),

		make_pair("<bits/regex_cursor.h>", "<regex>"),
		make_pair("<bits/regex_nfa.h>",    "<regex>"),

		make_pair("<bits/exception.h>", "<exception>"),

		make_pair("<bits/hashtable_policy.h>", "<unordered_map>"),

		make_pair("<__mutex_base>", "<mutex>"),

		make_pair("<bits/types/struct_FILE.h>", "<cstdio>"),

		make_pair("<bits/forward_list.h>", "<forward_list>"),

		make_pair("<bits/stl_heap.h>", "<algorithm>"),

		make_pair("<bits/types/__mbstate_t.h>", "<ios>"),

		// C headers
		make_pair("<bits/libio.h>", "<stdio.h>"),

		make_pair("<bits/types/struct_tm.h>",         "<time.h>"),
		make_pair("<bits/types/struct_timespec.h>",   "<time.h>"),
		make_pair("<bits/types/struct_itimerspec.h>", "<time.h>"),

		make_pair("<bits/pthreadtypes-arch.h>",        "<pthread.h>"),
		make_pair("<bits/thread-shared-types.h>",      "<pthread.h>"),
		make_pair("<bits/struct_mutex.h>",             "<pthread.h>"),
		make_pair("<bits/struct_rwlock.h>",            "<pthread.h>"),
		make_pair("<bits/types/struct_sched_param.h>", "<pthread.h>"),

	};

	string name;

	if( decl->isCXXClassMember() ) {
		NamedDecl const * D = decl;

		if( auto m = dyn_cast<CXXMethodDecl>(decl) ) {
			D = cast<CXXRecordDecl>( m->getParent() );
			name = D->getQualifiedNameAsString();
			//outs() << "CXXMethodDecl: looking for includes for type: " << name << " (was: " << decl->getQualifiedNameAsString() <<") \n";
		}

		if( D->isCXXClassMember() ) {
			if( auto c = dyn_cast<CXXRecordDecl>(D) ) {

				name = cast<CXXRecordDecl>( c->getParent() ) -> getQualifiedNameAsString();
				//outs() << "CXXRecordDecl: looking for includes for type: " << name << " (was: " << D->getQualifiedNameAsString() <<") \n";
			}
		}
	}
	else {
		name = decl->getQualifiedNameAsString();
	}

	name = standard_name(name);

	auto it = type_map.find(name);
	if( it != type_map.end() ) {
		includes.add_include( O_annotate_includes ? it->second + " // " + name : it->second );
		//outs() << "Found type map for: " << name << "\n";
		return;
	}

	// if( begins_with(name, "std::money_base") ) {
	// 	outs() << "Could not found type map for: " << name << "\n";
	// 	decl->dump();
	// }

	for(auto & p : name_map_old) {
		if( begins_with(name, p.first) ) {
			if(O_annotate_includes) includes.add_include( p.second + " // " + name );
			else includes.add_include(p.second);
			return;
		}
	}




	string include = relevant_include(decl);

	for(auto & i : include_map) {
		if( include == i.first ) { include = i.second; break; }
	}

	if( include.size() ) {
		if(O_annotate_includes) include += " // " + name;
		includes.add_include(include);
	}
}


/// extract include needed for this generator and add it to includes vector
void add_relevant_includes(QualType const &qt, /*const ASTContext &context,*/ IncludeSet &includes, int level)
{
	//QualType qt = qt.getDesugaredType(context);
	//outs() << "add_relevant_includes(qt): " << qt.getAsString() << "\n";
	if( clang::PointerType const *pt = dyn_cast<clang::PointerType>( qt.getTypePtr() ) ) add_relevant_includes(pt->getPointeeType(), includes, level);
	if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) add_relevant_includes(rt->getPointeeType(), includes, level);
	if( CXXRecordDecl *r = qt->getAsCXXRecordDecl() ) add_relevant_includes(r, includes, level);
	if( EnumDecl *e = dyn_cast_or_null<EnumDecl>( qt->getAsTagDecl() ) ) add_relevant_includes(e, includes, level);
}


// check if given QualType is bindable
bool is_bindable(QualType const &qt)
{
	bool r = true;

	r &= !qt->isFunctionPointerType()  and  !qt->isRValueReferenceType()  and  !qt->isInstantiationDependentType()  and  !qt->isArrayType();  //and  !qt->isConstantArrayType()  and  !qt->isIncompleteArrayType()  and  !qt->isVariableArrayType()  and  !qt->isDependentSizedArrayType()

	if( clang::PointerType const *pt = dyn_cast<clang::PointerType>( qt.getTypePtr() ) ) {
		QualType pqt = pt->getPointeeType();

		if( pqt->isPointerType() ) return false;  // refuse to bind 'value**...' types
		//if( pqt->isArithmeticType() ) return false;  // refuse to bind 'int*, doublle*...' types
		if( pqt->isArrayType() or pqt->isConstantArrayType() ) return false;  // refuse to bind 'T* v[]...' types

		string pqt_name = pqt.getAsString();
		if( begins_with(pqt_name, "struct std::pair")  or  begins_with(pqt_name, "struct std::tuple") ) return false;  // but we allow bindings for 'const std::tuple' and 'const std::pair'
		//qt->dump();
		r &= is_bindable( pt->getPointeeType()/*.getCanonicalType()*/ );
	}

	if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) {
		QualType pqt = rt->getPointeeType();
		//outs() << "#### " << pqt.getAsString() << "\n";

		// special handling for std::pair&  and  std::tuple&  whitch pybind11 can't pass by refference
		string pqt_name = standard_name( pqt.getAsString() );
		if( begins_with(pqt_name, "struct std::pair")  or  begins_with(pqt_name, "struct std::tuple") ) return false;  // but we allow bindings for 'const std::tuple' and 'const std::pair'

		//if( pqt_name == "char"  or  pqt_name == "wchar_t") return false; // WARNING only TEMPORARY, until Pybind11 upstream is fixed

		//rt->dump();
		//outs() << "Ref " << qt.getAsString() << " -> " << is_bindable( rt->getPointeeType().getCanonicalType() ) << "\n";
		r &= is_bindable( pqt/*.getCanonicalType()*/ );
	}

	if( Type const *tp = qt/*.getCanonicalType()*/.getTypePtrOrNull() ) {
		if( CXXRecordDecl *rd = tp->getAsCXXRecordDecl() ) {
			//outs() << "is_bindable qt CXXRecordDecl:" << rd->getQualifiedNameAsString() << " " << is_bindable(rd) << "\n";
			r &= is_bindable(rd);
		}
		if( TagDecl *td = tp->getAsTagDecl() ) {
			if( td->getAccess() == AS_protected  or  td->getAccess() == AS_private  ) return false;
		}
	}

	return r;
}



/// extract type info from QualType if any and bind relative type
void request_bindings(clang::QualType const &qt, Context &context)
{
	if( /*is_bindable(qt)  and*/  !is_skipping_requested(qt, Config::get()) ) {
		//outs() << "request_bindings(clang::QualType,...): " << qt.getAsString() << "\n";
		if( TagDecl *td = qt->getAsTagDecl() ) {
			if( td->isCompleteDefinition()  or  dyn_cast<ClassTemplateSpecializationDecl>(td) ) context.request_bindings( typename_from_type_decl(td) );
		}

		if( clang::PointerType const *pt = dyn_cast<clang::PointerType>( qt.getTypePtr() ) ) {
			request_bindings( pt->getPointeeType()/*.getCanonicalType()*/, context );
		}

		if( ReferenceType const *rt = dyn_cast<ReferenceType>( qt.getTypePtr() ) ) {
			request_bindings( rt->getPointeeType()/*.getCanonicalType()*/, context );
		}
	}
}


// transform give type name to standard form
string standard_name(string const &type)
{
	static vector< std::pair<string, string> > const name_map = {
		make_pair("std::__1::",     "std::"), // Mac libc++ put all STD objects into std::__1::  // WARNING: order is important here: we want to first replace std::__1:: so later we can change basic_string into string
		make_pair("std::__cxx11::", "std::"), // GCC libstdc++ 5.0+ puts all STD objects into std::__cxx11::

		make_pair("std::basic_string<char>",  "std::string"),
		make_pair("std::basic_ostream<char>", "std::ostream"),

		make_pair("class std::string",  "std::string"), // for return/paremeters types
		make_pair("class std::ostream", "std::ostream"),

		make_pair("nullptr_t",     "std::nullptr_t"),

		//make_pair("const class ", "const "),
		//make_pair("const struct ", "const "),
	};

	string r(type);
	for(auto & p : name_map) replace(r, p.first, p.second);

	// static vector< string > const prefixes = {
	// 	"enum ",
	// 	"class ",
	// 	"struct ",
	// };
	// for(auto & p : prefixes) {
	// 	if( begins_with(r, p) ) {
	// 		r = r.substr(p.size());
	// 		break;
	// 	}
	// }

	if( begins_with(r, "std::") ) r = "std::" + simplify_std_class_name( r.substr(5) );

	fix_boolean_types(r);

	return r;
}

/// Attempt to simplify std:: name by removing unneded template arguments. Function assume that there is no 'std::' namespaces prefix at the beginning of the argument string
string simplify_std_class_name(string const &type)
{
	static std::map<string, string> const std_typedef_map {
		{"basic_iostream<char,std::char_traits<char>>", "iostream"},
		{"basic_ostream<char,std::char_traits<char>>" ,  "ostream"},
		{"basic_istream<char,std::char_traits<char>>",   "istream"},

		{"basic_ostream<wchar_t,std::char_traits<wchar_t>>", "wostream"},
		{"basic_istream<wchar_t,std::char_traits<wchar_t>>", "wistream"},

		{"basic_stringstream<char,std::char_traits<char>,std::allocator<char>>",   "stringstream"},
		{"basic_istringstream<char,std::char_traits<char>,std::allocator<char>>", "istringstream"},
		{"basic_ostringstream<char,std::char_traits<char>,std::allocator<char>>", "ostringstream"},

		{"basic_filebuf<char,std::char_traits<char>>", "filebuf"},
		{"basic_stringbuf<char>", "stringbuf"},

		{"basic_ifstream<char,std::char_traits<char>>", "ifstream"},
		{"basic_ofstream<char,std::char_traits<char>>", "ofstream"},

		{"basic_stringbuf<char,std::char_traits<char>,std::allocator<char>>",            "stringbuf"},
		{"basic_stringbuf<wchar_t,std::wchar_traits<wchar_t>,std::allocator<wchar_t>>", "wstringbuf"},

		{"basic_streambuf<char,std::char_traits<char>>",        "streambuf"},
		{"basic_streambuf<wchar_t,std::char_traits<wchar_t>>", "wstreambuf"},
	};

	auto it = std_typedef_map.find(type);
	if( it != std_typedef_map.end() ) {
		return it->second;
	}

	// make_pair("class std::ostream", "std::ostream"),
	// make_pair("class std::istream", "std::istream"),
	// make_pair("class std::wostream", "std::wostream"),
	// make_pair("class std::wistream", "std::wistream"),
	// make_pair("class std::streambuf",  "std::streambuf"),
	// make_pair("class std::wstreambuf", "std::wstreambuf"),
	// make_pair("class std::filebuf",  "std::filebuf"),

	//llvm::Regex R("std::set<(.*),std::less<\\1>.*");
	//llvm::Regex R("std::set<(.*),std::less<\\1>,std::allocator<\\1>>");
	//r = R.sub("std::set<\\1>", r);

	string res = type;

	static vector< std::pair<llvm::Regex, string> > regex_map;

	if( regex_map.empty() ) {
		vector< std::pair<string, string> > regex_arg_map = {
			make_pair("^list<(.*),std::allocator<\\1>>$", "list<\\1>"),
			make_pair("^deque<(.*),std::allocator<\\1>>$", "deque<\\1>"),
			make_pair("^vector<(.*),std::allocator<\\1>>$", "vector<\\1>"),
			make_pair("^set<(.*),std::less<\\1>,std::allocator<\\1>>$", "set<\\1>"),
			make_pair("^forward_list<(.*),std::allocator<\\1>>$", "forward_list<\\1>"),
			make_pair("^map<(.*),(.*),std::less<\\1>,std::allocator<std::pair<const \\1, \\2> >>$", "map<\\1,\\2>"),

			make_pair("^multiset<(.*),std::less<(.*)>,std::allocator<(.*)>>$", "multiset<\\1>"),
			make_pair("^multimap<(.*),(.*),std::less<\\1>,std::allocator<std::pair<const \\1, \\2> >>$", "multimap<\\1,\\2>"),

			// LLVM-3.7
			//make_pair("^std::multimap<(.*),(.*),std::less<\\1>,std::allocator<std::pair<const \\1, \\2> >>", "multimap<\\1,\\2>"),

			make_pair("^unordered_set<(.*),std::hash<\\1>,std::equal_to<\\1>,std::allocator<\\1>>$", "unordered_set<\\1>"),
			make_pair("^unordered_map<(.*),(.*),std::hash<\\1>,std::equal_to<\\1>,std::allocator<std::pair<const \\1, \\2> >>$", "unordered_map<\\1,\\2>"),

			make_pair("^unordered_multiset<(.*),std::hash<\\1>,std::equal_to<\\1>,std::allocator<\\1>>$", "unordered_multiset<\\1>"),
			make_pair("^unordered_multimap<(.*),(.*),std::hash<\\1>,std::equal_to<\\1>,std::allocator<std::pair<const \\1, \\2> >>$", "unordered_multimap<\\1,\\2>"),
		};

		for(auto & p : regex_arg_map) regex_map.emplace_back(llvm::Regex(p.first), p.second);
	}

	for(auto & p : regex_map) {
		//llvm::Regex R(p.first);
		res = p.first.sub(p.second, res);
	}

	return res;
}


/// check if given class/struct is builtin in Python and therefor should not be binded
bool is_python_builtin(NamedDecl const *C)
{
	//outs() << "Considering: " << C->getQualifiedNameAsString() << "\n";
	string name = standard_name( C->getQualifiedNameAsString() );
	//if( begins_with(name, "class ") ) name = name.substr(6); // len("class ")

	static std::vector<string> const known_builtin = {//"std::nullptr_t", "nullptr_t",
													  "std::basic_string", "std::initializer_list",
													  "std::__1::basic_string",

													  "std::allocator", "std::__allocator_destructor",

													  "std::shared_ptr", "std::enable_shared_from_this",  "std::__shared_ptr", // "std::weak_ptr",  "std::__weak_ptr"
													  "std::unique_ptr",
													  //"std::__1::shared_ptr", "std::__1::weak_ptr", "std::__1::allocator",

													  "std::pair", "std::tuple",
													  //"std::__1::pair", "std::__1::tuple",

													  "std::_Rb_tree_iterator", "std::_Rb_tree_const_iterator", "__gnu_cxx::__normal_iterator",
													  "std::_List_iterator", "std::_List_const_iterator",
													  "std::__list_node",

													  "std::__wrap_iter",
													  //"std::__1::__wrap_iter",

													  "std::less",  // lead to an error in include detection code, probably could be fixed

													  //"std::iterator", "std::reverse_iterator",
													  //"std::vector", "std::map", "std::list", "std::set",

													  "std::__value_type",

													  "std::__detail::_Hash_node_base", "std::__detail::_Hash_node", "std::__detail::_Node_iterator", "std::__detail::_Node_iterator_base", "std::__detail::_Node_const_iterator",

													  "std::__hash_value_type",

													  "std::function",
 	};

	for(auto &k : known_builtin) {
		//if( begins_with(name, k) ) return true;
		if( name == k ) return true;
	}

	return false;
}

// check if class/struct/function/enum is in banned symbol lists
bool is_banned_symbol(clang::NamedDecl const *D)
{
	static std::unordered_set<string> const known_banned_symbols =
		{
		 "std::initializer_list",

		 "std::locale::facet", // nested base class

		 // we need allocator bindings for some default constructors in std:: // "std::allocator", "std::__allocator_destructor",

		 // "std::_Rb_tree_iterator", "std::_Rb_tree_const_iterator", "__gnu_cxx::__normal_iterator",
		 // "std::_List_iterator", "std::_List_const_iterator",
		 // "std::__detail::_Node_iterator", "std::__detail::_Node_iterator_base", "std::__detail::_Node_const_iterator",
		 // "std::_Deque_iterator",

		 // "std::__hash_base",
		};

	string name = standard_name( D->getQualifiedNameAsString() );

	if( begins_with(name, "std::_") ) return true;

	return known_banned_symbols.find(name) != known_banned_symbols.end();
}

// // check if class/struct is in banned type lists
// bool is_banned_type(clang::CXXRecordDecl const *C)
// {
// 	string name = C->getQualifiedNameAsString();

// 	static std::vector<string> const known_banned_types =
// 		{
// 		 "std::initializer_list",

// 		 "std::locale::facet", // nested base class

// 		 // we need allocator bindings for some default constructors in std:: // "std::allocator", "std::__allocator_destructor",

// 		 "std::_Rb_tree_iterator", "std::_Rb_tree_const_iterator", "__gnu_cxx::__normal_iterator",
// 		 "std::_List_iterator", "std::_List_const_iterator",
// 		 "std::__detail::_Node_iterator", "std::__detail::_Node_iterator_base", "std::__detail::_Node_const_iterator",
// 		 "std::_Deque_iterator",

// 		 "std::__hash_base",
// 		};

// 	if( begins_with(name, "std::_") ) return true;

// 	for(auto &k : known_banned_types) {
// 		if( name == k ) return true;
// 	}

// 	return false;
// }

} // namespace binder
