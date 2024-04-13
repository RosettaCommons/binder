// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// Copyright (c) 2016 Sergey Lyskov <sergey.lyskov@jhu.edu>
//
// All rights reserved. Use of this source code is governed by a
// MIT license that can be found in the LICENSE file.

/// @file   binder/context.cpp
/// @brief  Class Context, to hold bindings info for whole TranslationUnit
/// @author Sergey Lyskov

#include <context.hpp>

#include <class.hpp>
#include <fmt/format.h>
#include <function.hpp>
#include <options.hpp>
#include <type.hpp>
#include <util.hpp>

#include <clang/AST/ASTContext.h>

#include <cstdlib>
#include <fstream>
#include <set>
#include <sstream>

using llvm::errs;
using llvm::outs;

using namespace clang;
using std::string;
using std::unordered_map;
using std::vector;

using namespace fmt::literals;



namespace binder {

namespace { // functions and constants that are only used in this translation unit


/// Generate file name where binding for given generator should be stored
string file_name_prefix_for_binder(BinderOP &b)
{
	clang::NamedDecl const *decl = b->named_decl();

	string include = binder::relevant_include(decl);

	string exceptions = "_/<>.";
	include.erase(std::remove_if(include.begin(), include.end(), [&](unsigned char c) { return not(std::isalnum(c) or std::find(exceptions.begin(), exceptions.end(), c) != exceptions.end()); }),
				  include.end());

	if( include.size() <= 2 ) {
		include = "<unknown/unknown.hh>";
		// outs() << "Warning: file_name_prefix_for_binder could not determent file name for decl: " + string(*b) + ", result is too short!\n";
	} // throw std::runtime_error( "file_name_for_decl failed!!! include name for decl: " + string(*b) + " is too short!");
	include = include.substr(1, include.size() - 2);

	if( namespace_from_named_decl(decl) == "std" or begins_with(namespace_from_named_decl(decl), "std::") ) include = "std/" + (begins_with(include, "bits/") ? include.substr(5) : include);

	replace(include, ".hh", "");
	replace(include, ".hpp", "");
	replace(include, ".h", "");
	replace(include, ".", "_");
	return include;
}

// generate code for include directives and cleanup the includes vector
string generate_include_directives(IncludeSet const &include_set)
{
	string r;
	for( auto &i : std::set<string>(include_set.includes().begin(), include_set.includes().end()) )
		if( !Config::get().is_include_skipping_requested(i) ) r += "#include " + i + '\n';

	// includes.resize(0);
	return r;
}

const char *main_module_header = R"_(#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

{0}

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

{1}

PYBIND11_MODULE({2}, root_module) {{
	root_module.doc() = "{2} module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {{
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	}};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {{"nonlocal", "global", }};

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {{
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			return ns+'_';
		}}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {{
{3}	}};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

{4}
}}
)_";

const char *module_header = R"_(
#include <functional>
{0}
#include <string>
{1}
#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	{2}
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	{3}
#endif

)_";

const char *module_function_suffix = "(std::function< pybind11::module &(std::string const &namespace_) > &M)";

} // namespace

void Context::add(BinderOP &b)
{
	if( ids.count(b->id()) ) {
		// errs() << "Skipping adding duplicate binder for: " + b->id() + "...\n";
		return;
	}

	binders.push_back(b);
	ids.insert(b->id());

	if( TypeDecl const *type_decl = dyn_cast<TypeDecl>(b->named_decl()) ) types[typename_from_type_decl(type_decl)] = b;
}

void Context::add_insertion_operator(clang::FunctionDecl const *F)
{
	insertion_operators[function_pointer_type(F)] = F;
}

/// find global insertion operator for given type, return nullptr if not such operator find
clang::FunctionDecl const *Context::global_insertion_operator(clang::CXXRecordDecl const *C)
{
	string op_pointer = "std::ostream & (*)(std::ostream &, const " + (C->isStruct() ? string("struct ") : string("class ")) + class_qualified_name(C) + " &)";

	// outs() << "Looking for operator: " << op_pointer << "\n";

	auto it = insertion_operators.find(op_pointer);
	if( it != insertion_operators.end() ) return it->second;

	if( auto t = dyn_cast<ClassTemplateSpecializationDecl>(C) ) { // if operator<< is template it will have different form: std::ostream & (*)(std::ostream &, const A<type-parameter-0-0> &)
		op_pointer = "std::ostream & (*)(std::ostream &, const " + standard_name(C->getNameAsString()) +
					 "<"; // Note: we do not use `getQualifiedNameAsString` because if argument is templated it string representation will not have namespaces
		for( uint i = 0; i < t->getTemplateArgs().size(); ++i ) op_pointer += "type-parameter-0-" + std::to_string(i) + ", ";
		op_pointer.pop_back();
		op_pointer.back() = '>';
		fix_boolean_types(op_pointer);
		op_pointer += " &)";

		// outs() << "Looking for operator: " << op_pointer << "\n";

		auto it = insertion_operators.find(op_pointer);
		if( it != insertion_operators.end() ) return it->second;
	}

	// outs() << "Have not found... it\n";

	// outs() << "All global insertion operators:\n";
	// for(auto & f : insertion_operators) {
	// 	outs() << f.first << " -> " << f.second << "\n";
	// 	//f.second->dump();
	// }

	return nullptr;
}

/// check if forward declaration for CXXRecordDecl needed
bool Context::is_forward_needed(CXXRecordDecl const *C)
{
	return !binded.count(class_qualified_name(C)) and !is_python_builtin(C);
}


/// add given class to 'aleady binded' set
void Context::add_to_binded(CXXRecordDecl const *C)
{
	binded.insert(class_qualified_name(C));
}


/// examine binded objects and recursivly create all nested namespaces
std::set<string> Context::create_all_nested_namespaces()
{
	vector<string> namespaces;

	for( auto &b : binders ) {
		if( b->code().size() ) {
			string ns = namespace_from_named_decl(b->named_decl());

			while( ns.size() ) {
				namespaces.push_back(ns);
				ns = base_namespace(ns);
			}
		}
	}

	std::set<string> s(namespaces.begin(), namespaces.end());

	return s;
}

std::string Context::module_variable_name(std::string const &namespace_)
{
	return "M(\"" + namespace_ + "\")";
}


// find binder related to given object name and bind it
void Context::request_bindings(std::string const &type)
{
	if( types.count(type) and !types[type]->is_binded() and types[type]->bindable() and !types[type]->skipping_requested() and !is_python_builtin(types[type]->named_decl()) ) {
		types[type]->request_bindings();
	}
}


/// walk over all binders and bind one that belong to requested namespaces
void Context::bind(Config const &config)
{
	for( auto &sp : binders ) {
		Binder &b(*sp);
		if( b.bindable() ) {
			if( b.is_in_system_header() ) b.request_bindings_and_skipping(config, RequestFlags::skipping);
			else b.request_bindings_and_skipping(config);
		}
	}

	bool flag = true;
	int pass = 1;
	while( flag ) {
		flag = false;

		outs() << "Generate bindings, pass " << pass << "...\n";

		for( auto &sp : binders ) {
			Binder &b(*sp);
			if( !b.is_binded() and b.bindable() and b.binding_requested() ) {
				if( O_verbose ) outs() << "Binding: " << b.id() /*named_decl()->getQualifiedNameAsString()*/ << "\n";
				b.bind(*this);
				flag = true;
			}
		}

		++pass;
	}
}

/// sort vector of binders by dependency so python imports could work
void Context::sort_binders()
{
	outs() << "Sorting Binders...\n";

	bool repeat = true;
	std::set<string> forward;

	while( repeat ) {
		repeat = false;
		binded = forward;
		for( auto b = binders.begin(); b != binders.end(); ++b ) {
			if( CXXRecordDecl const *C = dyn_cast<CXXRecordDecl const >((*b)->named_decl()) ) { // right not only query dependency if we dealing with class
				std::vector<CXXRecordDecl const *> const dependencies = (*b)->dependencies();
				for( auto &c : dependencies ) {
					if( !is_forward_needed(c) ) continue;
					// outs() << "Pushing forward binding for " << class_qualified_name(c) << "...\n";
					auto e = find_if(b, binders.end(), [&c](BinderOP const &p) -> bool { return dyn_cast<CXXRecordDecl const >(p->named_decl()) == c; });
					if( e == binders.end() ) {
						if( !repeat ) {
							errs() << "ERROR: Could not find binder for type: " + class_qualified_name(c) +
										  "!\nUsually cause for this is that type was only forward declared. Please check that Binder input include file have full declaration of this class.\n";
							std::exit(1);

							// throw std::runtime_error( "ERROR: Could not find binder for type: " + class_qualified_name(c) + "!");
						}
						// just declare forward declaration for now instead
						// outs() << "Could not find binder for type: " + class_qualified_name(c) + "... will use forward declaration instead...\n";
						// forward.insert( class_qualified_name(c) );
						// add_to_binded(c);
					}
					else {
						rotate(b, e, binders.end());
						repeat = true;
					}
				}
				if( repeat ) break;
				add_to_binded(C);
			}
		}
	}
	binded.clear();
	outs() << "Sorting Binders... Done.\n";
}

void Context::generate(Config const &config)
{
	bind(config);

	vector<string> sources;
	vector<string> binding_function_names;

	std::map<string, int> file_names;
	std::map<string, int> namespace_entrance;

	string root_module_file_name = config.root_module + ".cpp";
	sources.push_back(root_module_file_name);

	string root_module_full_file_name = config.prefix + '/' + root_module_file_name;
	std::ofstream root_module_file_handle(root_module_full_file_name);
	if( root_module_file_handle.fail() ) throw std::runtime_error("ERROR: Can not open file " + root_module_full_file_name + " for writing...");

	sort_binders();

	outs() << "Writing code...\n";
	for( uint i = 0; i < binders.size(); ++i ) {
		if( binders[i]->code().empty() ) continue;

		string np, file_name;

		if( O_flat ) {
			np = config.root_module + "_";
			file_name = np + std::to_string(file_names[np]);
		}
		else {
			np = file_name_prefix_for_binder(binders[i]);
			file_name = np + (file_names[np] ? "_" + std::to_string(file_names[np]) : "");
		}
		++file_names[np];

		string function_name = "bind_" + replace_(file_name, "/", "_");
		file_name += ".cpp";

		sources.push_back(file_name);
		binding_function_names.push_back(function_name);
		// outs() << string(*binders[i]) << " → " << file_name << "\n";

		string code, prefix_code;
		string namespace_ = namespace_from_named_decl(binders[i]->named_decl());

		// vector<string> includes;
		// std::set<NamedDecl const *> stack;
		IncludeSet includes;

		bool skip = false;

		// outs() << namespace_ << ' ' << namespace_entrance[namespace_] << "\n";

		std::map<string, std::vector<string> > const &namespace_includes = Config::get().namespace_includes();
		if( namespace_includes.count(namespace_) ) {
			std::vector<string> const &n_includes = namespace_includes.at(namespace_);
			for( auto const &i : n_includes ) includes.add_include(i);
		}

		std::map<string, string> const &binder_for_namespaces = Config::get().binder_for_namespaces();
		if( binder_for_namespaces.count(namespace_) ) {
			if( namespace_entrance[namespace_] == 0 ) { code += "\n\t{}(M(\"{}\"));\n"_format(binder_for_namespaces.at(namespace_), namespace_); }
			skip = true;
		}

		std::map<string, string> const &add_on_binder_for_namespaces = Config::get().add_on_binder_for_namespaces();
		if( add_on_binder_for_namespaces.count(namespace_) and code.empty() ) {
			if( namespace_entrance[namespace_] == 0 ) code += "\n\t{}(M(\"{}\"));\n"_format(add_on_binder_for_namespaces.at(namespace_), namespace_);
		}

		for( ; code.size() < config.maximum_file_length and i < binders.size() and namespace_ == namespace_from_named_decl(binders[i]->named_decl()); ++i ) {
			// outs() << "Binding: " << string(*binders[i]) << "\n";
			//  if( ClassBinder * CB = dynamic_cast<ClassBinder*>( binders[i].get() ) ) {
			//  	std::vector<clang::CXXRecordDecl const *> const dependencies = CB->dependencies();
			//  	for(auto & c : dependencies ) {
			//  		if( is_forward_needed(c) ) {
			//  			code += bind_forward_declaration(c, *this);
			//  			add_to_binded(c);
			//  			outs() << "Adding forward binding for " << class_qualified_name(c) << "\n";
			//  		}
			//  	}
			//  	add_to_binded( dynamic_cast<CXXRecordDecl*>( CB->named_decl() ) );
			//  }

			// if( CXXRecordDecl const *C = dyn_cast<CXXRecordDecl const >( binders[i]->named_decl() ) ) { // right not only query dependency if we dealing with class
			// 	std::vector<clang::CXXRecordDecl const *> const dependencies = binders[i]->dependencies();
			// 	for(auto & c : dependencies ) {
			// 		if( is_forward_needed(c) ) {
			// 			code += bind_forward_declaration(c, *this);
			// 			add_to_binded(c);
			// 			outs() << "Adding forward binding for " << class_qualified_name(c) << "\n";
			// 		}
			// 	}
			// 	add_to_binded(C);
			// }
			if( skip ) continue;

			prefix_code += binders[i]->prefix_code();

			if( O_trace ) {
				code += trace_line(binders[i]->id());
				includes.add_include(O_annotate_includes ? "<iostream> // --trace" : "<iostream>");
			}

			string generated_code = binders[i]->code();
			if( generated_code.size() ) {
				code += generated_code;
				binders[i]->add_relevant_includes(includes);
			}
		}

		if( i < binders.size() ) --i;

		string const holder_type = Config::get().holder_type();

		string shared_declare = "PYBIND11_DECLARE_HOLDER_TYPE(T, "+holder_type+"<T>, false)";
		string shared_make_opaque = "PYBIND11_MAKE_OPAQUE("+holder_type+"<void>)";

		string const pybind11_include = "#include <" + Config::get().pybind11_include_file() + ">";
		code = generate_include_directives(includes) + fmt::format(module_header, pybind11_include, config.includes_code(), shared_declare, shared_make_opaque) + prefix_code + "void " + function_name + module_function_suffix + "\n{\n" + code + "}\n";

		if( O_single_file ) root_module_file_handle << "// File: " << file_name << '\n' << code << "\n\n";
		else update_source_file(config.prefix, file_name, code);

		++namespace_entrance[namespace_];
	}
	outs() << "Writing code... Done.\n";

	string modules;
	string namespace_pairs;
	std::set<string> namespaces = create_all_nested_namespaces();
	for( auto &n : namespaces ) {
		if( n.size() ) namespace_pairs += "\t\t{{\"{}\", \"{}\"}},\n"_format(base_namespace(n), last_namespace(n));
		modules += n;
		modules += ' ';
	}
	replace(modules, "::", ".");

	string binding_function_decls, binding_function_calls;
	for( auto &f : binding_function_names ) {
		binding_function_decls += "void " + f + module_function_suffix + ";\n";
		binding_function_calls += "\t" + f + "(M);\n";
	}

	string const pybind11_include = "#include <" + Config::get().pybind11_include_file() + ">";

	std::stringstream s;
	s << fmt::format(main_module_header, pybind11_include, binding_function_decls, config.root_module, namespace_pairs, binding_function_calls);

	root_module_file_handle << s.str();

	string root_module_prefix = config.prefix + '/' + config.root_module;

	if( O_single_file ) {
		root_module_file_handle << "\n// Source list file: " << root_module_prefix + ".sources\n";
		for( auto &s : sources ) root_module_file_handle << "// " << s << "\n";

		root_module_file_handle << "\n// Modules list file: " << root_module_prefix + ".modules\n// ";
		root_module_file_handle << modules;
		root_module_file_handle << "\n";
	}
	else {
		std::ofstream f(root_module_prefix + ".sources");
		for( auto &s : sources ) f << s << "\n";

		std::ofstream namespaces_file_handle(root_module_prefix + ".modules");
		namespaces_file_handle << modules;
	}
}

/// generate unique trace line containing `info` to insert into the code
std::string Context::trace_line(std::string const &info)
{
	return "\tstd::cout << \"B" + std::to_string(++trace_counter) + "_[" + info + "]\" << std::endl;\n";
}


} // namespace binder
