// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/config.hpp
/// @brief  Support for Binder Config file
/// @author Sergey Lyskov


#ifndef _INCLUDED_config_hpp_
#define _INCLUDED_config_hpp_

#include <set>
#include <map>
#include <string>
#include <vector>

#ifdef _MSC_VER
#include <ciso646>
using uint = unsigned int;
#endif

namespace binder {

class Config
{
	typedef std::string string;

	Config() {}

	Config(string const &root_module_, std::vector<string> namespaces_to_bind_, std::vector<string> namespaces_to_skip_, string const &prefix_, std::size_t maximum_file_length_)
		: root_module(root_module_), namespaces_to_bind(namespaces_to_bind_), namespaces_to_skip(namespaces_to_skip_), prefix(prefix_), maximum_file_length(maximum_file_length_)
	{
	}

private:
	std::map<string, string> binders_, add_on_binders_;
	std::map<string, string> binder_for_namespaces_, add_on_binder_for_namespaces_;

	std::map<string, std::vector<string> > class_includes_, namespace_includes_;

	string default_static_pointer_return_value_policy_ = "pybind11::return_value_policy::automatic";
	string default_static_lvalue_reference_return_value_policy_ = "pybind11::return_value_policy::automatic";
	string default_static_rvalue_reference_return_value_policy_ = "pybind11::return_value_policy::automatic";

	string default_member_pointer_return_value_policy_ = "pybind11::return_value_policy::automatic";
	string default_member_lvalue_reference_return_value_policy_ = "pybind11::return_value_policy::automatic";
	string default_member_rvalue_reference_return_value_policy_ = "pybind11::return_value_policy::automatic";
	string default_call_guard_ = "";
	string holder_type_ = "std::shared_ptr";

public:
	static Config &get();

	/// Read config setting from the file
	void read(string const &file_name);

	string root_module;

	std::vector<string> namespaces_to_bind, classes_to_bind, functions_to_bind, namespaces_to_skip, classes_to_skip, functions_to_skip, includes_to_add, includes_to_skip;
	std::vector<string> buffer_protocols;

	std::map<string, string> const &binders() const { return binders_; }
	std::map<string, string> const &add_on_binders() const { return add_on_binders_; }

	std::map<string, string> const &binder_for_namespaces() const { return binder_for_namespaces_; }
	std::map<string, string> const &add_on_binder_for_namespaces() const { return add_on_binder_for_namespaces_; }

	std::set<string> python_builtins, not_python_builtins;

	std::map<string, std::vector<string> > const &class_includes() const { return class_includes_; }
	std::map<string, std::vector<string> > const &namespace_includes() const { return namespace_includes_; }

	string const &default_static_pointer_return_value_policy() { return default_static_pointer_return_value_policy_; }
	string const &default_static_lvalue_reference_return_value_policy() { return default_static_lvalue_reference_return_value_policy_; }
	string const &default_static_rvalue_reference_return_value_policy() { return default_static_rvalue_reference_return_value_policy_; }

	string const &default_member_pointer_return_value_policy() { return default_member_pointer_return_value_policy_; }
	string const &default_member_lvalue_reference_return_value_policy() { return default_member_lvalue_reference_return_value_policy_; }
	string const &default_member_rvalue_reference_return_value_policy() { return default_member_rvalue_reference_return_value_policy_; }
	string const &default_call_guard() { return default_call_guard_; }

	string const &holder_type() const { return holder_type_; }

	string prefix;

	std::size_t maximum_file_length;

	/// check if user requested binding for given declaration
	bool is_namespace_binding_requested(string const &namespace_) const;
	bool is_namespace_skipping_requested(string const &namespace_) const;

	bool is_function_binding_requested(string const &function) const;
	bool is_function_skipping_requested(string const &function) const;

	bool is_class_binding_requested(string const &class_) const;
	bool is_class_skipping_requested(string const &class_) const;
	bool is_buffer_protocol_requested(string const &class_) const;

	bool is_include_skipping_requested(string const &include) const;

	string includes_code() const;
};


} // namespace binder

#endif // _INCLUDED_config_hpp_
