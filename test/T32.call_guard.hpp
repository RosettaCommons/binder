// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 University of Washington
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.
//
/// @file   binder/test/T07.class.hpp
/// @brief  Test gil-release guard configuration.
/// @author Alex Ford <fordas@uw.edu>
//
#ifndef _INCLUDED_T07_class_hpp_
#define _INCLUDED_T07_class_hpp_

void free(int)
{
}

struct Methods
{
	void foo(int) {}
};

#endif
