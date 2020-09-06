// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T50.namespace_binder
/// @brief  Binder self-test file. Tests for namespace incude, binder, add_on_binder functionality
/// @author Sergey Lyskov

#ifndef _INCLUDED_T50_namespace_binder_hpp_
#define _INCLUDED_T50_namespace_binder_hpp_

void foo_root() {}

namespace aaaa {
void foo_aaaa() {}
}

namespace aaaa {
namespace bbbb {
void foo_aaaa_bbbb_not_binded() {}
}
}

#endif // _INCLUDED_T50_namespace_binder_hpp_
