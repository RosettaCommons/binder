// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.multiset.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes multiset/multimap.
/// @author Sergey Lyskov/Andrii Verbytskyi

/// This test is separated from the binder/test/T42.stl.names.hpp to avoid
/// problems with different ordering of multiset/set and multimap/map bindings 
/// in the generated files on different platforms.
#ifndef _INCLUDED_T42_stl_names_multiset_hpp_
#define _INCLUDED_T42_stl_names_multiset_hpp_

#include <functional>
#include <set>
#include <forward_list>
#include <unordered_set>


void foo(std::multiset<float> ) {}

void foo(std::unordered_multiset<float> ) {}

#endif // _INCLUDED_T42_stl_names_multiset_hpp_
