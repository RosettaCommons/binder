// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @author Sergey Lyskov
/// related issue: https://github.com/RosettaCommons/binder/issues/315

#pragma once
namespace SampleNamespace {

	class B{
		public:
			B() : i(0) {}
			int const i;
	};

	class A{
		public:
			A() : instanceWithConstMember(B())  {}
			B instanceWithConstMember;
	};

	class C{
		public:
			C() : muttable(0) {}
			int muttable;
	};

}
