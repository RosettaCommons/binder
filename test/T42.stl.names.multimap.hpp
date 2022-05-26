// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.multimap.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes multiset/multimap.
/// @author Sergey Lyskov/Andrii Verbytskyi

/// This test is separated from the binder/test/T42.stl.names.hpp to avoid
/// problems with different ordering of multiset/set and multimap/map bindings
/// in the generated files on different platforms.
#ifndef _INCLUDED_T42_stl_names_multi_hpp_
#define _INCLUDED_T42_stl_names_multi_hpp_

#include <forward_list>
#include <functional>
#include <map>
#include <unordered_map>

#include <deque>
#include <forward_list>
#include <list>
#include <vector>

void foo(std::multimap<float, int>)
{
}

void foo(std::unordered_multimap<float, int>)
{
}

void foo(std::multimap<float, std::list< std::forward_list< std::deque< std::vector<double> > > > >)
{
}
void foo(std::unordered_multimap<float, std::list< std::forward_list< std::deque< std::vector<double> > > > >)
{
}

#endif // _INCLUDED_T42_stl_names_multi_hpp_
