// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2021 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/const.hpp
/// @brief  Binding generation for C++ constant expressions
/// @author Sergey Lyskov, Andrii Verbytskyi


#ifndef _INCLUDED_const_hpp_
#define _INCLUDED_const_hpp_

#include <context.hpp>

#include <clang/AST/Decl.h>

#include <string>

namespace binder {

/// check if generator can create binding
bool is_bindable(clang::VarDecl const *E);


// Generate binding for given function
std::string bind_const(std::string const & module, clang::VarDecl const *E);


class ConstBinder : public Binder
{
public:
	ConstBinder(clang::VarDecl const *e) : E(e) {}

	/// Generate string id that uniquly identify C++ binding object. For functions this is function prototype and for classes forward declaration.
	string id() const override;
	// return Clang AST NamedDecl pointer to original declaration used to create this Binder
	clang::NamedDecl const * named_decl() const override { return E; };

	/// check if generator can create binding
    bool bindable() const override;

	/// check if user requested binding for the given declaration
	virtual void request_bindings_and_skipping(Config const &) override;

	/// extract include needed for this generator and add it to includes vector
	void add_relevant_includes(IncludeSet &includes) const override;

	/// generate binding code for this object and all its dependencies
	void bind(Context &) override;


private:
	clang::VarDecl const *E;
};


} // namespace binder

#endif // _INCLUDED_const_hpp_
