// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T15.inner_class.hpp
/// @brief  Binder self-test file. Bindings of classes data members with inner classes.
/// @author Sergey Lyskov

#pragma once


struct Base
{
	virtual void foo() {}
};

namespace n1 {
struct A : public Base {};

namespace n2 {
struct A: public n1::A {};
}

}
