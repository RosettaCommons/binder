// File: T60_const.cpp
#include <T60.const.hpp> // foo_char

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T60_const(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// global_int file:T60.const.hpp line:18
	M("").attr("global_int") = pybind11::int_(1);

	// global_long file:T60.const.hpp line:19
	M("").attr("global_long") = pybind11::int_(2);

	// global_unsigned_int file:T60.const.hpp line:21
	M("").attr("global_unsigned_int") = pybind11::int_(3);

	// global_unsigned_long file:T60.const.hpp line:22
	M("").attr("global_unsigned_long") = pybind11::int_(4);

	// global_float file:T60.const.hpp line:24
	M("").attr("global_float") = pybind11::float_(5.);

	// global_double file:T60.const.hpp line:25
	M("").attr("global_double") = pybind11::float_(6.);

	// global_string1 file:T60.const.hpp line:27
	M("").attr("global_string1") = pybind11::str("Some test string");

	// global_string2 file:T60.const.hpp line:29
	M("").attr("global_string2") = pybind11::str(std::string("Some test string"));

	// expression_global_double file:T60.const.hpp line:32
	M("").attr("expression_global_double") = pybind11::float_(8. + 1. / 5.);

	// foo_char(char *) file:T60.const.hpp line:38
	M("").def("foo_char", (int (*)(char *)) &foo_char, "C++: foo_char(char *) --> int", pybind11::arg(""));

}


// File: T60_const_1.cpp
#include <T60.const.hpp> // foo::foonamespaced_foo_char

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T60_const_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo::foonamespaced_global_double file:T60.const.hpp line:42
	M("foo").attr("foonamespaced_global_double") = pybind11::float_(7.);

	// foo::foonamespaced_foo_char(char *) file:T60.const.hpp line:44
	M("foo").def("foonamespaced_foo_char", (int (*)(char *)) &foo::foonamespaced_foo_char, "C++: foo::foonamespaced_foo_char(char *) --> int", pybind11::arg(""));

}


#include <map>
#include <memory>
#include <stdexcept>
#include <functional>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T60_const(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T60_const_1(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T60_const, root_module) {
	root_module.doc() = "T60_const module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "foo"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule(p.second.c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T60_const(M);
	bind_T60_const_1(M);

}

// Source list file: /home/andriish/Projects/binder/test//T60_const.sources
// T60_const.cpp
// T60_const.cpp
// T60_const_1.cpp

// Modules list file: /home/andriish/Projects/binder/test//T60_const.modules
// foo 
