// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/options.cpp
/// @brief  Options
/// @author Sergey Lyskov

#include "options.hpp"
#include <llvm/Support/CommandLine.h>

using namespace llvm;

// Apply a custom category to all command-line options so that they are the only ones displayed.
llvm::cl::OptionCategory BinderToolCategory("Binder options");

cl::opt<bool> O_annotate_includes("annotate-includes", cl::desc("Annotate each includes in generated code with type name that trigger it inclusion"), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_single_file("single-file", cl::desc("Concatenate all binder output into single file with name: root-module-name + '.cpp'. Use this for a small projects and for testing."),
							cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_trace("trace", cl::desc("Add tracer output for each binded object (i.e. for debugging)"), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_verbose("v", cl::desc("Increase verbosity of output"), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_flat("flat", cl::desc("When specified generated files into single directory. Generated files will be named as <root-module>.cpp, <root-module>_1.cpp, <root-module>_2.cpp, ... etc."),
					 cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_include_pybind11_stl("include-pybind11-stl", cl::desc("When specified bindings for STL classes in <pybind11/stl.h> will be used instead of generating custom STL bindings."),
					 cl::init(false), cl::cat(BinderToolCategory));


cl::opt<std::string> O_root_module("root-module", cl::desc("Name of root module"), /*cl::init("example"),*/ cl::cat(BinderToolCategory));

cl::opt<int> O_max_file_size("max-file-size", cl::desc("Specify maximum length of generated source files"), cl::init(1024 * 16), cl::cat(BinderToolCategory));

cl::opt<bool> O_skip_line_number("skip-line-number", cl::desc("Do not print line number in the comment to the generated code"), cl::init(false), cl::cat(BinderToolCategory));

cl::opt<std::string> O_prefix("prefix", cl::desc("Output path for all generated files. Specified path must exists."), cl::init(""), cl::cat(BinderToolCategory));

cl::list<std::string> O_bind("bind", cl::desc("Namespace to bind, could be specified more then once. Specify \"\" to bind all namespaces."), cl::cat(BinderToolCategory)); // , cl::OneOrMore
cl::list<std::string> O_skip("skip", cl::desc("Namespace to skip, could be specified more then once"), cl::cat(BinderToolCategory)); // , cl::OneOrMore

cl::opt<std::string> O_config("config", cl::desc("Specify config file from which bindings setting will be read"), cl::init(""), cl::cat(BinderToolCategory));

cl::opt<bool> O_suppress_errors("suppress-errors",
								cl::desc("Suppres all the compilers errors. This option could be useful when you want to tell Binder to ignore non-critical errors (for example due to missing "
										 "includes) and generate binding for part of code that Binder was able to parse"),
								cl::init(false), cl::cat(BinderToolCategory));

cl::opt<bool> O_bind_class_template_specialization("bind-class-template-specialization", cl::desc("attempt to bind class template specilizations"), cl::init(true), cl::cat(BinderToolCategory));
