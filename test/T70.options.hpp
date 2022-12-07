// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

#pragma once

namespace aaaa {

struct AAAA {};
void foo_aaaa() {}


namespace cccc {

struct CCCC {};
void foo_CCCC() {}

} // namespace cccc


namespace bbbb {

struct BBBB {};
void foo_bbbb() {}

struct BBBB_not_binded {};
void foo_bbbb_not_binded() {}

} // namespace bbbb


} // namespace aaaa
