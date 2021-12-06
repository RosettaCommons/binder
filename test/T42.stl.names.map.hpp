// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.map.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes.
/// @author Sergey Lyskov

/// The multimap/multiset classes are tested in the binder/test/T43.stl.names.multi.hpp to avoid
/// problems with different ordering of multiset/set and multimap/map bindings
/// in the generated files on different platforms.
#ifndef _INCLUDED_T42_stl_names_map_hpp_
#define _INCLUDED_T42_stl_names_map_hpp_

#include <functional>
#include <map>
#include <unordered_map>

#include <string>
#include <list>
#include <vector>
#include <deque>
#include <vector>
#include <forward_list>

void foo(std::map<float,int> ) {}

void foo(std::unordered_map<float,int> ) {}

void foo(std::map<std::string, std::list< std::forward_list< std::deque< std::vector<double> > > > >) {}
void foo(std::unordered_map<std::string, std::list< std::forward_list< std::deque< std::vector<double> > > > >) {}

#endif // _INCLUDED_T42_stl_names_map_hpp_
