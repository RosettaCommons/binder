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

const int global_int=1;
const long global_long=2;

const unsigned int global_unsigned_int=3;
const unsigned long global_unsigned_long=4;

const float global_float=5.0;
const double global_double=6.0;

const std::string global_string1="Some test string";

const std::string global_string2=std::string("Some test string");


const double expression_global_double=8.0+1.0/5.0;

const double array_global_double[5]={1.0,2.0,3.0,4.0,5.0};  //This should not appear in bindings so far.

const std::vector<double> vector_global_double{1.0,2.0,3.0,4.0,5.0};  //This should not appear in bindings so far.

int foo_char(char *) { return 0; }

namespace foo
{
const double foonamespaced_global_double=7.0;

int foonamespaced_foo_char(char *) { return 0; }

}

#endif // _INCLUDED_T60_basic_hpp_
