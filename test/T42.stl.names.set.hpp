// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.set.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes.
/// @author Sergey Lyskov

/// The multimap/multiset classes are tested in the binder/test/T43.stl.names.multi.hpp to avoid
/// problems with different ordering of multiset/set and multimap/map bindings 
/// in the generated files on different platforms.
#ifndef _INCLUDED_T42_stl_names_set_hpp_
#define _INCLUDED_T42_stl_names_set_hpp_

#include <functional>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <unordered_set>

void foo(std::set<float> ) {}
void foo(std::list<double> ) {}
void foo(std::forward_list<float> ) {}
void foo(std::vector<double> ) {}
void foo(std::deque<int> ) {}


void foo(std::unordered_set<float> ) {}


#endif // _INCLUDED_T42_stl_names_set_hpp_
