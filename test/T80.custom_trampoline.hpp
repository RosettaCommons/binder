// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T71.module_local.hpp
/// @author Sergey Lyskov

#ifndef _INCLUDED_T80_custom_trampoline_hpp_
#define _INCLUDED_T80_custom_trampoline_hpp_

namespace aaa {
	template <typename T>
	class A 
	{
		public:
			virtual A<T> foo(){
				return A<T>();
			};
	};
}

template class aaa::A<double>;

#endif // _INCLUDED_T80_custom_trampoline_hpp_
