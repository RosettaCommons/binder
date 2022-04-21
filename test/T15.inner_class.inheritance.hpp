// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef T15_INNER_CLASS_INHERITANCE_H
#define T15_INNER_CLASS_INHERITANCE_H

/// @file   binder/test/T15.inner_class.inheritance.hpp
/// @brief  Binder self-test file. Tests for bindings of classes inheriting from inner classes.

struct outer {
	struct inner {
		int a;
	};
};

struct outer2 : public outer::inner {
	double b;
};

#endif