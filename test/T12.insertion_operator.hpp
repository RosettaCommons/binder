// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T12.insertion_operator.hpp
/// @brief  Binder self-test file. Bindings for insertion operator.
/// @author Sergey Lyskov

#pragma once

#include <ostream>

struct A
{
	friend std::ostream& operator<<(std::ostream& os, A const &) { return os << "hi..."; }
};

namespace aaaa {
struct T
{
    friend std::ostream & operator<<(std::ostream & s, T const &);
};

inline std::ostream & operator<<(std::ostream & s, T const &) { return s << "hi..."; }
}

// https://github.com/RosettaCommons/binder/issues/236
struct B { int b; };
namespace C {
	std::ostream & operator<<(std::ostream & s, const B & b) { return s; }
}
