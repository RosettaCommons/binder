// File: T51_nested_namespace.cpp
#include <T51.nested_namespace.hpp> // aaaa::bbbb::cccc::foo_aaaa_bbbb_cccc

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T51_nested_namespace(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// aaaa::bbbb::cccc::foo_aaaa_bbbb_cccc() file:T51.nested_namespace.hpp line:6
	M("aaaa::bbbb::cccc").def("foo_aaaa_bbbb_cccc", (void (*)()) &aaaa::bbbb::cccc::foo_aaaa_bbbb_cccc, "C++: aaaa::bbbb::cccc::foo_aaaa_bbbb_cccc() --> void");

}


// File: T51_nested_namespace_1.cpp
#include <T51.nested_namespace.hpp> // aaaa::bbbb::cccc::dddd::bar_aaaa_bbbb_cccc_dddd

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T51_nested_namespace_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// aaaa::bbbb::cccc::dddd::bar_aaaa_bbbb_cccc_dddd() file:T51.nested_namespace.hpp line:8
	M("aaaa::bbbb::cccc::dddd").def("bar_aaaa_bbbb_cccc_dddd", (void (*)()) &aaaa::bbbb::cccc::dddd::bar_aaaa_bbbb_cccc_dddd, "C++: aaaa::bbbb::cccc::dddd::bar_aaaa_bbbb_cccc_dddd() --> void");

}


// File: T51_nested_namespace_2.cpp
#include <T51.nested_namespace.hpp> // aaaa::bbbb::cccc::eeee::baz_aaaa_bbbb_cccc_eeee

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T51_nested_namespace_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// aaaa::bbbb::cccc::eeee::baz_aaaa_bbbb_cccc_eeee() file:T51.nested_namespace.hpp line:11
	M("aaaa::bbbb::cccc::eeee").def("baz_aaaa_bbbb_cccc_eeee", (void (*)()) &aaaa::bbbb::cccc::eeee::baz_aaaa_bbbb_cccc_eeee, "C++: aaaa::bbbb::cccc::eeee::baz_aaaa_bbbb_cccc_eeee() --> void");

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T51_nested_namespace(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T51_nested_namespace_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T51_nested_namespace_2(std::function< pybind11::module &(std::string const &namespace_) > &M);


static std::vector<std::string> const reserved_python_words{
	"nonlocal",
	"global",
};
std::string mangle_namespace_name(std::string const &ns) {
	if( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
	return ns + '_';
}

void makeSubmodules(const std::vector<std::string> &moduleNames, std::map <std::string, pybind11::module> &modules) {
	std::string prevNamespace = "";
	std::string curNamespace = "";
	for (const auto &curMod : moduleNames) {
		std::cout << "making: " << curMod << std::endl;
		if (curNamespace.size() > 0)
			curNamespace += "::"; // don't add :: to the start
		const auto mangledMod = mangle_namespace_name(curMod);
		std::cout << "mangled: " << mangledMod << std::endl;
		curNamespace += mangledMod;
		if (modules.count(curNamespace) == 0) {
			std::cout << "defining namespace " << curNamespace << " in " << prevNamespace << std::endl;
			modules[curNamespace] = modules[prevNamespace].def_submodule(mangledMod.c_str(), ("Bindings for " + curNamespace + " namespace").c_str());
		}
		prevNamespace = curNamespace;
	}
}


PYBIND11_MODULE(T51_nested_namespace, root_module) {
	root_module.doc() = "T51_nested_namespace module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(mangle_namespace_name(namespace_));
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	std::vector< std::vector<std::string> > sub_modules {
		{"aaaa"},
		{"aaaa", "bbbb"},
		{"aaaa", "bbbb", "cccc"},
		{"aaaa", "bbbb", "cccc", "dddd"},
		{"aaaa", "bbbb", "cccc", "eeee"},
	};
	for(auto &p : sub_modules ) {
		makeSubmodules(p, modules);
	}

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T51_nested_namespace(M);
	bind_T51_nested_namespace_1(M);
	bind_T51_nested_namespace_2(M);

}

// Source list file: /home/matt/workspace/binder/build/test//T51_nested_namespace.sources
// T51_nested_namespace.cpp
// T51_nested_namespace.cpp
// T51_nested_namespace_1.cpp
// T51_nested_namespace_2.cpp

// Modules list file: /home/matt/workspace/binder/build/test//T51_nested_namespace.modules
// 
