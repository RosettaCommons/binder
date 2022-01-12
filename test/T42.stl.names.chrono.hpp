// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T42.stl.names.chrono.hpp
/// @brief  Binder self-test file. Tests for bindings of STL classes.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T42_stl_names_chrono_hpp_
#define _INCLUDED_T42_stl_names_chrono_hpp_

#include <chrono>

void foo(std::chrono::system_clock::time_point ) {}
void foo(std::chrono::steady_clock::time_point ) {}
void foo_high_res(std::chrono::high_resolution_clock::time_point ) {}

void foo(std::chrono::duration<long, std::ratio<10, 1> > ) {}
void foo(std::chrono::nanoseconds ) {}
void foo(std::chrono::microseconds ) {}
void foo(std::chrono::milliseconds ) {}
void foo(std::chrono::seconds ) {}
void foo(std::chrono::minutes ) {}
void foo(std::chrono::hours ) {}

void foo(std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<10, 1> > > ) {}


#endif // _INCLUDED_T42_stl_names_chrono_hpp_
