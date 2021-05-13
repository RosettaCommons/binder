// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef T15_INNER_CLASS_FWD_H
#define T15_INNER_CLASS_FWD_H

/// @file   binder/test/T15.inner_class.fwd.hpp
/// @brief  Binder self-test file. Tests for bindings of forward declared inner functions.

struct outer {

	struct inner {
		int a;
	};

	struct inner2;

	struct inner3;

	void f( inner *i, inner2 *i2, inner3 *i3 ){};

	struct inner2 {
		int b;
	};
};

struct outer::inner3 {
	int c;
};

#endif