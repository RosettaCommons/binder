// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T12.operator.hpp
/// @brief  Binder self-test file. Bindings of class operator member functions.
/// @author Sergey Lyskov

#pragma once

struct T
{
	T &operator~() { return *this; }

	T &operator+(int) { return *this; }
	T &operator-(int) { return *this; }
	T &operator*(int) { return *this; }
	T &operator/(int) { return *this; }
	T &operator%(int) { return *this; }
	T &operator|(int) { return *this; }
	T &operator&(int) { return *this; }
	T &operator^(int) { return *this; }
	T &operator<<(int) { return *this; }
	T &operator>>(int) { return *this; }

	void operator+=(int) {}
	void operator-=(int) {}
	void operator*=(int) {}
	void operator/=(int) {}
	void operator%=(int) {}
	void operator|=(int) {}
	void operator&=(int) {}
	void operator^=(int) {}
	void operator<<=(int) {}
	void operator>>=(int) {}

	void operator()(int) {}

	bool operator==(const T &) { return true; }
	bool operator!=(const T &) { return false; }
	bool operator[](int) { return true; }

	T &operator=(const T &) { return *this; }
	T &operator++() { return *this; }
	T &operator--() { return *this; }
};
