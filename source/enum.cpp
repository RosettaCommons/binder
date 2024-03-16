// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/enum.cpp
/// @brief  Binding generation for C++ enums
/// @author Sergey Lyskov


#include <enum.hpp>

#include <type.hpp>
#include <util.hpp>

#include <fmt/format.h>

#include <clang/AST/ASTContext.h>

using namespace llvm;
using namespace clang;

using std::string;
using std::vector;

using namespace fmt::literals;

namespace binder {


/// extract include needed for this generator and add it to includes vector
void add_relevant_includes(clang::EnumDecl const *E, IncludeSet &includes, int level)
{
	if( !includes.add_decl(E, level) ) return;
	add_relevant_include_for_decl(E, includes);

	if( auto decl = E->getDefinition() ) add_relevant_include_for_decl(decl, includes);
}


/// check if generator can create binding
bool is_bindable(EnumDecl const *E)
{
	// if( E->isCXXInstanceMember()  or  E->isCXXClassMember() ) return false;
	// else return true;

	if( E->isCXXInstanceMember() ) return false;

	string name = E->getNameAsString(); // getQualifiedNameAsString(); //
	// if( name.rfind(')') != string::npos ) return false; // checking that this is not an "(anonymous)" enum
	if( name.empty() or name.rfind(')') != string::npos ) return false; // checking that this is not an "(anonymous)" enum

	return true;
}

/// check if user requested binding for the given declaration
bool is_binding_requested(clang::EnumDecl const *E, Config const &config)
{
	if( config.is_enum_binding_requested( E->getQualifiedNameAsString() ) ) return true;

	bool bind = config.is_namespace_binding_requested(namespace_from_named_decl(E));
	//for( auto &t : get_type_dependencies(E) ) bind &= !is_skipping_requested(t, config);
	return bind;
}

// check if user requested skipping for the given declaration
bool is_skipping_requested(clang::EnumDecl const *E, Config const &config)
{
	string qualified_name = standard_name(E->getQualifiedNameAsString());

	if( config.is_enum_skipping_requested(qualified_name) ) return true;
	if( config.is_enum_binding_requested(qualified_name) ) return false;

	bool skip = config.is_namespace_skipping_requested(namespace_from_named_decl(E));

	//for( auto &t : get_type_dependencies(E) ) skip |= is_skipping_requested(t, config);

	return skip;
}



// This function takes care about the LLVM/Clang bug which was fixed in LLVM6/Clang6.
// The body of the function is a backport from LLVM6.
std::string getQualifiedNameAsStringLLVM5Fix(NamedDecl const *E)
{
	std::string correct;
	llvm::raw_string_ostream OS(correct);
	DeclContext const *Ctx = E->getDeclContext();
	SmallVector<DeclContext const *, 10> Contexts;
	while( Ctx && isa<NamedDecl>(Ctx) ) {
		Contexts.push_back(Ctx);
		Ctx = Ctx->getParent();
	}
	for( const DeclContext *DC : reverse(Contexts) ) {
		if( const auto *ED = dyn_cast<EnumDecl>(DC) ) {
			if( ED->isScoped() ) {
				OS << *ED;
				OS << "::";
			}
			else continue;
		}
		else {
			OS << *cast<NamedDecl>(DC);
			OS << "::";
		}
	}
	if( (E->getDeclName() || isa<DecompositionDecl>(E)) ) OS << *E;
	else OS << "(anonymous)";
	return correct;
}

// Generate binding for given function: py::enum_<MyEnum>(module, "MyEnum")...
std::string bind_enum(std::string const &module, EnumDecl const *E)
{
	string name{E->getNameAsString()};
	string qualified_name{E->getQualifiedNameAsString()};

	string maybe_arithmetic = E->isScoped() ? "" : ", pybind11::arithmetic()";

	// Add module local if requested for the namespace
	std::string module_local_annotation = "";
	if (Config::get().is_module_local_requested(namespace_from_named_decl(E)))
		module_local_annotation = ", pybind11::module_local()";

	string r = "\tpybind11::enum_<{}>({}, \"{}\"{}, \"{}\"{})\n"_format(qualified_name, module, name, maybe_arithmetic, generate_documentation_string_for_declaration(E), module_local_annotation);

	// r += "\t // is_bindable " + E->getNameAsString() + " -> " + std::to_string(is_bindable(E)) + "\n";

	for( auto e = E->enumerator_begin(); e != E->enumerator_end(); ++e ) {
#if( LLVM_VERSION_MAJOR > 5 )
		r += "\t\t.value(\"{}\", {})\n"_format(e->getNameAsString(), e->getQualifiedNameAsString());
#else
		r += "\t\t.value(\"{}\", {})\n"_format(e->getNameAsString(), getQualifiedNameAsStringLLVM5Fix(*e));
#endif
	}
	r.pop_back();

	return r + (E->isScopedUsingClassTag() ? ";\n\n" : "\n\t\t.export_values();\n\n");
}


/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
string EnumBinder::id() const
{
	return E->getQualifiedNameAsString();
}


/// check if generator can create binding
bool EnumBinder::bindable() const
{
	return is_bindable(E) and !is_banned_symbol(E);
}


/// check if user requested binding for the given declaration
void EnumBinder::request_bindings_and_skipping(Config const &config, RequestFlags flags)
{
	if( (flags&RequestFlags::skipping) and is_skipping_requested(E, config) ) Binder::request_skipping();
	else if( (flags&RequestFlags::binding) and is_binding_requested(E, config) ) Binder::request_bindings();
}


/// extract include needed for this generator and add it to includes vector
void EnumBinder::add_relevant_includes(IncludeSet &includes) const
{
	binder::add_relevant_includes(E, includes, 0);
}

/// generate binding code for this object and all its dependencies
void EnumBinder::bind(Context &context)
{
	if( is_binded() ) return;

	string const module_variable_name = context.module_variable_name(namespace_from_named_decl(E));

	code() = "\t" + generate_comment_for_declaration(E);
	code() += bind_enum(module_variable_name, E) + ";\n\n";
}



} // namespace binder
