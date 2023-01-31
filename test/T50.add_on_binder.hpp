// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2023 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T50.add_on_binder
/// @brief  Binder self-test file.
/// @author Sergey Lyskov


#pragma once


template<typename T> struct Matrix {};
template class Matrix<int>;

namespace details {

template<typename C>
void matrix_add_on_binder(C &)
{
}

} // namespace details
