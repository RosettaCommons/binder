// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T00.basic.hpp
/// @brief  Binder self-test file. Basic functionality.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T60_basic_hpp_
#define _INCLUDED_T60_basic_hpp_
#include <string>
#include <vector>

int const global_int=1;
long const global_long=2;

unsigned int const global_unsigned_int=3;
unsigned long const global_unsigned_long=4;

float const  global_float=5.0;
double const global_double=6.0;

std::string const global_string1="Some test string";

std::string const global_string2=std::string("Some test string");


double const expression_global_double=8.0+1.0/5.0;

double const array_global_double_not_binded[5]={1.0,2.0,3.0,4.0,5.0};  //This should not appear in bindings so far.

std::vector<double> const vector_global_double_not_binded{1.0,2.0,3.0,4.0,5.0};  //This should not appear in bindings so far.

int foo_char(char *) { return 0; } //This is just for control.

namespace foo
{
double const foonamespaced_global_double=7.0;

int foonamespaced_foo_char(char *) { return 0; }

}

#endif // _INCLUDED_T60_basic_hpp_
