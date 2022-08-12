// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T20.template.variadic.hpp
/// @brief  Binder self-test file. Bindings of variadic temlate classes functionality.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T20_template_variadic_hpp_
#define _INCLUDED_T20_template_variadic_hpp_

#include <array>

namespace variadic_template
{
	template<class T,int N,int... Ns> struct Array : std::array<Array<T,Ns...>,N> {};

	template<class T,int N> struct Array<T,N> : std::array<T,N> {};

	// Needed to instanciate the class instance and bind it
	struct st2: public Array<int, 2,2> {};
}


#endif // _INCLUDED_T20_template_variadic_hpp_
