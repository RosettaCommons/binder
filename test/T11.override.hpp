// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T10.override.hpp
/// @brief  Binder self-test file. Bindings tests for overriding classes in Python.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T10_override_hpp_
#define _INCLUDED_T10_override_hpp_
/// Please note that some systems provide dual C++ ABI, which might affect the  generated code.
/// The line below forces the usage of the older implementation of std::string on the systems with GNU libc.
/// See  https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_dual_abi.html for details.
#define _GLIBCXX_USE_CXX11_ABI 0 
#include <string>

class Base
{
public:
	std::string s_;

	virtual void foo_void() {}
	virtual void foo_void_pure() = 0;

	virtual int         foo_int() { return 0; }
	virtual std::string foo_sring() { return ""; }

	virtual std::string &foo_sring_r() { return s_; }
};

#endif // _INCLUDED_T10_override_hpp_
