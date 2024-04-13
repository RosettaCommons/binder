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
#include <pybind11/numpy.h>

void foo(pybind11::handle &) {}
void foo(pybind11::object &) {}
void foo(pybind11::module &) {}
void foo(pybind11::iterator &) {}
//void foo(pybind11::type &) {}
void foo(pybind11::iterable &) {}
void foo(pybind11::str &) {}
void foo(pybind11::bytes &) {}
//void foo(pybind11::bytesarray &) {}
void foo(pybind11::none &) {}
void foo(pybind11::ellipsis &) {}
void foo(pybind11::bool_ &) {}
void foo(pybind11::int_ &) {}
void foo(pybind11::float_ &) {}
void foo(pybind11::weakref &) {}
void foo(pybind11::slice &) {}
void foo(pybind11::capsule &) {}
void foo(pybind11::tuple &) {}
//void foo(pybind11::args &) {}
//void foo(pybind11::kwargs &) {}
void foo(pybind11::dict &) {}
void foo(pybind11::sequence &) {}
void foo(pybind11::list &) {}
//void foo(pybind11::anyset &) {}
//void foo(pybind11::frozenset &) {}
void foo(pybind11::set &) {}
void foo(pybind11::function &) {}
void foo(pybind11::buffer &) {}
//void foo(pybind11::memoryview &) {}
void foo(pybind11::array &) {}
