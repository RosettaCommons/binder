// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/test/T01.enum.hpp
/// @brief  Binder self-test file. Bindings of enum's functionality.
/// @author Sergey Lyskov

#ifndef _INCLUDED_T01_enum_hpp_
#define _INCLUDED_T01_enum_hpp_

enum E1 { E1_V0, E1_V1 };

enum struct E2_struct { V0, V1 };
enum class E3_class { V0, V1 };

enum E4_not_binded { E4_V0, E4_V1 };

class A
{
public:
	enum AE1 { AE1_V0, AE1_V1 };
	enum struct AE2_struct { AE3_V0, AE3_V1 };
	enum class AE3_class { AE2_V0, AE2_V1 };

	int field1 = 0;
	int field2 = 0;

protected:
	enum AE3_not_binded { AE3_V0_not_binded, AE3_V1_not_binded };
	enum class AE4_not_binded { AE4_V0_not_binded, AE4_V1_not_binded };

private:
	enum AE5_not_binded { AE5_V0_not_binded, AE5_V1_not_binded };
	enum class AE6_not_binded { AE6_V0_not_binded, AE6_V1_not_binded };
};


enum class E6_class_not_binded { V0, V1 };


namespace aaaa {
enum class E7_class { V0, V1 };
enum class E8_class_not_binded { V0, V1 };
}

extern "C" {
typedef enum E9_extern_C {
  E5_V0 = 0,
} E9_extern_C;
}


#endif // _INCLUDED_T01_enum_hpp_
