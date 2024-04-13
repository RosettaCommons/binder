// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/enum.hpp
/// @brief  Binding generation for C++ enums
/// @author Sergey Lyskov


#ifndef _INCLUDED_enum_hpp_
#define _INCLUDED_enum_hpp_

#include <context.hpp>

#include <clang/AST/Decl.h>

#include <string>

namespace binder {

/// extract include needed for this generator and add it to includes vector
void add_relevant_includes(clang::EnumDecl const *E, IncludeSet &includes, int level);


/// check if generator can create binding
bool is_bindable(clang::EnumDecl const *E);


/// check if user requested binding for the given declaration
bool is_binding_requested(clang::EnumDecl const *E, Config const &config);


/// check if user requested skipping for the given declaration
bool is_skipping_requested(clang::EnumDecl const *E, Config const &config);


// Generate binding for given function: py::enum_<MyEnum>(module, "MyEnum")...
std::string bind_enum(std::string const &module, clang::EnumDecl const *E);


class EnumBinder : public Binder
{
public:
	EnumBinder(clang::EnumDecl const *e) : E(e) {}

	/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
	string id() const override;

	// return Clang AST NamedDecl pointer to original declaration used to create this Binder
	clang::NamedDecl const *named_decl() const override { return E; };

	/// check if generator can create binding
	bool bindable() const override;

	/// check if user requested binding for the given declaration
	void request_bindings_and_skipping(Config const &, RequestFlags flags = RequestFlags::skipping | RequestFlags::binding) override;

	/// extract include needed for this generator and add it to includes vector
	void add_relevant_includes(IncludeSet &includes) const override;

	/// generate binding code for this object and all its dependencies
	void bind(Context &) override;


private:
	clang::EnumDecl const *E;
};


} // namespace binder

#endif // _INCLUDED_enum_hpp_
