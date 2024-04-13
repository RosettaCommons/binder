// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T15.copy.hpp
/// @brief  Binder self-test file. Binding for copy constuctors
/// @author Sergey Lyskov

#ifndef _INCLUDED_T15_copy_hpp_
#define _INCLUDED_T15_copy_hpp_

struct POD1
{
};

struct POD2
{
	POD2(POD2 const &){};
};


struct POD3
{
	POD3(POD3 const &) = default;
};

struct POD4
{
	int a;
	POD4(POD4 const &) = default;
};


struct POD5
{
	POD5(POD5 &&) = default;
};

struct POD6
{
	int a;
	POD6(POD6 &&) = default;
};


class Data1
{
public:
	Data1(Data1 const &) = default;

private:
	int a;
};



#endif // _INCLUDED_T15_copy_hpp_
