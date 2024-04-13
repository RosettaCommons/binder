// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

#pragma once

#include <string>
#include <tuple>

class MatchArgs
{
public:
	const std::tuple<std::string, std::string> __match_args__ =  std::make_tuple("var1", "var2");
	int var1;
	int var2;
};
