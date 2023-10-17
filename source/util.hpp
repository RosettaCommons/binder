// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/util.hpp
/// @brief  Various helper functions
/// @author Sergey Lyskov


#ifndef _INCLUDED_util_hpp_
#define _INCLUDED_util_hpp_

#include <context.hpp>

#include <clang/AST/Decl.h>
#include <clang/AST/DeclTemplate.h>

#include <string>
#include <vector>

namespace binder {


/// Split string using given separator
std::vector<std::string> split(std::string const &buffer, std::string const &separator = "\n");


/// Replace all occurrences of string in-place
void replace(std::string &r, std::string const &from, std::string const &to);

/// Replace all occurrences of string and return result as new string
std::string replace_(std::string const &s, std::string const &from, std::string const &to);

/// check if string begins with given prefix
bool begins_with(std::string const &source, std::string const &prefix);

/// check if string ends with given prefix
bool ends_with(std::string const &source, std::string const &prefix);

/// indent given code
std::string indent(std::string const &code, std::string const &indentation);

/// remove leading and trailing tabs and spaces
std::string trim(std::string const &s);

/// Try to read existing file. If file content does not match given code, overwrite the file with code. Also create nested dirs starting from prefix if nessesary.
void update_source_file(std::string const &prefix, std::string const &file_name, std::string const &code);



/// calculate namespace path from given NamedDecl, like: std, core::pose
std::string namespace_from_named_decl(clang::NamedDecl const *decl);


std::string typename_from_type_decl(clang::TypeDecl const *decl);


/// Calculate base (upper) namespace for given one: core::pose::motif --> core::pose
std::string base_namespace(std::string const &ns);


/// Calculate last namespace for given one: core::pose::motif --> motif
std::string last_namespace(std::string const &ns);

/// replace all _Bool types with bool
void fix_boolean_types(std::string &type);

/// Generate string representation of given expression
std::string expresion_to_string(clang::Expr *e);

/// Generate string representation of given TemplateArgument
std::string template_argument_to_string(clang::TemplateArgument const &);


/// calculate line in source file for NamedDecl
std::string line_number(clang::NamedDecl const *decl);

/// generate string represeting class name that could be used in python
std::string mangle_type_name(std::string const &name, bool mark_template = true);

/// generate C++ comment line for given declaration along with file path and line number
// core::scoring::vdwaals::VDWAtom file:core/scoring/vdwaals/VDWTrie.hh line:43
std::string generate_comment_for_declaration(clang::NamedDecl const *decl);

/// extract doc string (Doxygen comments) for given declaration and convert it to C++ code
std::string generate_documentation_string_for_declaration(clang::Decl const *);


} // namespace binder

#endif // _INCLUDED_util_hpp_
