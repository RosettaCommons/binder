// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T17.anonymous.hpp
/// @brief  Binder self-test file. Bindings of classes/functions in anonymous namespace
/// @author Sergey Lyskov

#pragma once

namespace {
void foo_not_binded()
{
}

struct S_not_binded
{
};
} // namespace

struct
{
	int a;
} object;



void foo()
{
}

struct S
{
	int a;

	struct
	{
		int b;
	};

	typedef struct
	{
		float c_not_binded;
	} FL_not_binded;
	FL_not_binded fl;

	struct
	{
		float b4;
	} B_not_binded[4];

	struct
	{
		int c;
	} C_not_binded;

	typedef struct _D
	{
		int d;
	} D;
};

typedef struct _S2
{
	int a;
} S2;

struct Anonymous
{
	union {
		double coord[2];
		struct
		{
			double x;
			double y;
		};
	};
};
