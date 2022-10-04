// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

#pragma once

#include <string>
#include <pybind11/stl.h>

#define TEST_PY_FN(TYPE) \
	void test_py_##TYPE(pybind11::TYPE &) {}

TEST_PY_FN(handle);
TEST_PY_FN(object);
TEST_PY_FN(module);
TEST_PY_FN(iterator);
TEST_PY_FN(type);
TEST_PY_FN(module_);
TEST_PY_FN(iterator);
TEST_PY_FN(type);
TEST_PY_FN(iterable);
TEST_PY_FN(str);
TEST_PY_FN(bytes);
TEST_PY_FN(bytesarray);
TEST_PY_FN(none);
TEST_PY_FN(ellipsis);
TEST_PY_FN(bool_);
TEST_PY_FN(int_);
TEST_PY_FN(float_);
TEST_PY_FN(weakref);
TEST_PY_FN(slice);
TEST_PY_FN(capsule);
TEST_PY_FN(tuple);
TEST_PY_FN(args);
TEST_PY_FN(dict);
TEST_PY_FN(kwargs);
TEST_PY_FN(sequence);
TEST_PY_FN(list);
TEST_PY_FN(anyset);
TEST_PY_FN(frozenset);
TEST_PY_FN(set);
TEST_PY_FN(function);
TEST_PY_FN(function);
TEST_PY_FN(cpp_function);
TEST_PY_FN(staticmethod);
TEST_PY_FN(buffer);
TEST_PY_FN(memoryview);
TEST_PY_FN(array);
TEST_PY_FN(array_t);

#undef TEST_PY_FN
