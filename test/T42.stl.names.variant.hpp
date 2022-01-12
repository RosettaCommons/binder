// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.variant.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T42_stl_names_variant_hpp_
#define _INCLUDED_T42_stl_names_variant_hpp_

#include <string>
#include <variant>
#include <vector>

void foo(std::variant<float> ) {}

void foo(std::variant<std::monostate, int, std::string> ) {}

void foo(std::variant<std::vector<int> > ) {}

#endif // _INCLUDED_T42_stl_names_variant_hpp_
