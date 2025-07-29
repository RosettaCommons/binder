// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2025 Lucas Czech <luc.czech@gmail.com>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

#pragma once

#include <utility>

struct A {
	int x;
	int y;
};

struct B {
	static A a_static;
	A a_member;

	// Test static members

	static A* get_static_pointer()
	{
		return new A();
	}

	static A& get_static_lvalue_ref()
	{
		return a_static;
	}

	static A&& get_static_rvalue_ref()
	{
		return std::move( a_static );
	}

	// Test non-static members

	A* get_member_pointer()
	{
		return new A();
	}

	A& get_member_lvalue_ref()
	{
		return a_member;
	}

	A&& get_member_rvalue_ref()
	{
		return std::move( a_member );
	}

	// Test customizations

	A const& get_custom()
	{
		return a_member;
	}

	A const& get_custom( int x, int y )
	{
		(void) x;
		(void) y;
		return a_member;
	}

	int get_custom( int x )
	{
		// An overload that does not return a reference, and hence should not get an rv policy set.
		return x;
	}

	// Test assignment operators

	B& operator=( B const& other ) = default;
	B& operator=( B&& other ) = default;

	B& operator +=( int i )
	{
		a_member.x += i;
		return *this;
	}

	B& operator -=( int i )
	{
		a_member.x -= i;
		return *this;
	}

};

// Test the defaults for free functions

inline A* get_pointer()
{
	return new A();
}

inline A& get_lvalue_ref()
{
	static A a{};
	return a;
}

inline A&& get_rvalue_ref()
{
	static A a{};
	return std::move( a );
}

// Test customization for free functions

inline A const& get_custom()
{
	static A a{ 0, 0 };
	return a;
}

inline A const& get_custom( int x, int y )
{
	// Ignores x and y after the first call. Not recommended in practice - just for testing.
	static A a{ x, y };
	return a;
}

inline int get_custom( int x )
{
	// An overload that does not return a reference, and hence should not get an rv policy set.
	return x;
}

// Static inits. This should of course be in a compilation unit instead of this header,
// but to keep the test setup simple, we assume here that this header is only every going
// to be included once in the compilation unit of the test, and not linked elsewhere.
// Do not try this at home!
A B::a_static = A{};
