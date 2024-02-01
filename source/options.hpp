// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/options.hpp
/// @brief  Options
/// @author Sergey Lyskov

#ifndef _INCLUDED_options_hpp_
#define _INCLUDED_options_hpp_


#include "llvm/Config/llvm-config.h"
#include "llvm/Support/CommandLine.h"

extern llvm::cl::OptionCategory BinderToolCategory;

extern llvm::cl::opt<bool> O_annotate_includes;
extern llvm::cl::opt<bool> O_single_file;
extern llvm::cl::opt<bool> O_trace;
extern llvm::cl::opt<bool> O_verbose;
extern llvm::cl::opt<bool> O_flat;
extern llvm::cl::opt<bool> O_include_pybind11_stl;

extern llvm::cl::opt<std::string> O_root_module;
extern llvm::cl::opt<int> O_max_file_size;
extern llvm::cl::opt<bool> O_skip_line_number;
extern llvm::cl::opt<std::string> O_prefix;
extern llvm::cl::list<std::string> O_bind;
extern llvm::cl::list<std::string> O_skip;
extern llvm::cl::opt<std::string> O_config;
extern llvm::cl::opt<bool> O_suppress_errors;

extern llvm::cl::opt<bool> O_bind_class_template_specialization;

#endif // _INCLUDED_options_hpp_
