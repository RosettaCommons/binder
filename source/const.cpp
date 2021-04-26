// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2021 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/const.cpp
/// @brief  Binding generation for C++ constants
/// @author Sergey Lyskov, Andrii Verbytskyi


#include <const.hpp>

#include <type.hpp>
#include <util.hpp>

#include <fmt/format.h>

#include <clang/AST/ASTContext.h>

using namespace llvm;
using namespace clang;
#include <iostream>
using std::string;
using std::vector;

using namespace fmt::literals;

namespace binder {

/// check if generator can create binding
bool is_bindable(VarDecl const *E)
{
	if ( !E->getType().isConstQualified() )  return false;
	if ( !E->hasInit() ) return false; 
	if ( E->getType().getTypePtr()->isArrayType()) return false; 
	if( E->isCXXInstanceMember()  or  E->isCXXClassMember() ) return false;
	if( E->isCXXInstanceMember() ) return false;
	if ( standard_name( E->getType().getCanonicalType().getAsString() ) == "const std::string" ) return true;
	if (E->getType().getTypePtr()->isRealFloatingType() ) return true;
	if (E->getType().getTypePtr()->isIntegerType() ) return true;
	if (E->getType().getTypePtr()->isBooleanType() ) return true;
	return false;
}

// Generate binding for given function: py::enum_<MyEnum>(module, "MyEnum")...
std::string bind_const(std::string const & module, VarDecl const *E)
{
		string r=" ";
		clang::Expr const* init = E->getInit();
		if (init){
			string name { E->getNameAsString() };
			std::string type = E->getType().getCanonicalType().getAsString();
			std::string pytype = "";
			bool pytype_set = false;
//This is a list of types that can bi binded with pybind, see  https://pybind11.readthedocs.io/en/stable/advanced/pycpp/object.html*/
			if ( !pytype_set and standard_name( type ) == "const std::string" ) { pytype_set=true; pytype="str";}
			if ( !pytype_set and E->getType().getTypePtr()->isRealFloatingType() ) { pytype_set=true;  pytype="float_"; }
			if ( !pytype_set and E->getType().getTypePtr()->isIntegerType() ) { pytype_set=true; pytype="int_"; }
			if ( !pytype_set and E->getType().getTypePtr()->isBooleanType() ) { pytype_set=true; pytype="bool_"; }
			if (pytype_set) {
				std::string rhs;
				llvm::raw_string_ostream rso(rhs);
				clang::LangOptions lang_opts;
				lang_opts.CPlusPlus = true;
				clang::PrintingPolicy Policy(lang_opts);
				init->printPretty(rso, NULL, Policy);
				r = "\t{}.attr(\"{}\") = pybind11::{}({})\n"_format( module, name, pytype, rhs);
			}
		}
	r.pop_back();
	return r;
}


/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
string ConstBinder::id() const
{
	return E->getQualifiedNameAsString();
}


/// check if generator can create binding
bool ConstBinder::bindable() const
{
	return is_bindable(E);
}

/// check if user requested binding for the given declaration
void ConstBinder::request_bindings_and_skipping(Config const &config)
{
	if( config.is_namespace_binding_requested( namespace_from_named_decl(E) ) ) Binder::request_bindings();
}


/// extract include needed for this generator and add it to includes vector
void ConstBinder::add_relevant_includes(IncludeSet &includes) const
{
}

/// generate binding code for this object and all its dependencies
void ConstBinder::bind(Context &context)
{
	if( is_binded() ) return;

	string const module_variable_name = context.module_variable_name( namespace_from_named_decl(E) );

	code()  = "\t" + generate_comment_for_declaration(E);
	code() += bind_const(module_variable_name, E) + ";\n\n";
}

} // namespace binder
