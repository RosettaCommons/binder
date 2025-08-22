// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @author Sergey Lyskov
/// related issue: https://github.com/RosettaCommons/binder/issues/316

#pragma once

namespace SampleNamespace {

class OtherClass {};
template<typename T>
class PairClass {
	public:
		PairClass() {
			this->first  = T();
			this->second = T();
		}
		void printHello();

	private:
		T first;
		T second;
};

// template class PairClass<OtherClass>; // Binder generates code that does not compile with llvm18 but does with llvm14
template class PairClass<SampleNamespace::OtherClass>; // Works as expected on both llvm14 and llvm18

struct MyStruct {

	PairClass<OtherClass> pair;

	MyStruct() {
		pair = PairClass<OtherClass>();
	}
};
}
