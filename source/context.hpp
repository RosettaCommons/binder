// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/context.hpp
/// @brief  Class Context, to hold bindings info for whole TranslationUnit
/// @author Sergey Lyskov

#ifndef _INCLUDED_context_hpp_
#define _INCLUDED_context_hpp_

#include <binder.hpp>

#include <clang/AST/Decl.h>

#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace binder {


/// Context - root, hold bindings info for whole TranslationUnit
class Context
{
	typedef std::string string;

public:
	void add(BinderOP &);

	void generate(Config const &config);

	/// find binder related to given type name and bind it
	void request_bindings(std::string const &type);

	/// generate C++ expression for module variable for namespace_
	string module_variable_name(string const &namespace_);

	void add_insertion_operator(clang::FunctionDecl const *f);

	/// find global insertion operator for given type, otherwise return nullptr
	clang::FunctionDecl const *global_insertion_operator(clang::CXXRecordDecl const *);

	/// generate unique trace line containing `info` to insert into the code
	std::string trace_line(std::string const &info);

private:
	/// bind all objects residing in namespaces and their dependencies
	void bind(Config const &config);

	std::set<string> create_all_nested_namespaces();

	/// check if forward declaration for CXXRecordDecl needed
	bool is_forward_needed(clang::CXXRecordDecl const *);

	/// add given class to 'already binded' set
	void add_to_binded(clang::CXXRecordDecl const *);

	/// sort vector of binders by dependency so python imports could work
	void sort_binders();


	/// map of function-ptr -> Decl* for global instertion operators so we can determine for which types we can bind __repr__
	std::map<std::string, clang::FunctionDecl const *> insertion_operators;

	/// array of all binders from translation unit
	std::vector<BinderOP> binders;

	/// types → binder
	std::unordered_map<string, BinderOP> types;

	/// set of items unique id's to keep track of binders being added
	std::unordered_set<string> ids;

	/// set of items unique id's to keep track of what is binded and not
	std::set<string> binded;

	/// counter to generate unique trace lines for debug
	int trace_counter = -1;
};


} // namespace binder

#endif // _INCLUDED_context_hpp_
