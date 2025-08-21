// File: T07_class_with_const_members.cpp
#include <T07.class_with_const_members.hpp> // SampleNamespace::A
#include <T07.class_with_const_members.hpp> // SampleNamespace::B
#include <T07.class_with_const_members.hpp> // SampleNamespace::C
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T07_class_with_const_members(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // SampleNamespace::B file:T07.class_with_const_members.hpp line:
		pybind11::class_<SampleNamespace::B, std::shared_ptr<SampleNamespace::B>> cl(M("SampleNamespace"), "B", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::B(); } ) );
		cl.def( pybind11::init( [](SampleNamespace::B const &o){ return new SampleNamespace::B(o); } ) );
		cl.def_readonly("i", &SampleNamespace::B::i);
	}
	{ // SampleNamespace::A file:T07.class_with_const_members.hpp line:
		pybind11::class_<SampleNamespace::A, std::shared_ptr<SampleNamespace::A>> cl(M("SampleNamespace"), "A", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::A(); } ) );
		cl.def_readonly("instanceWithConstMember", &SampleNamespace::A::instanceWithConstMember);
	}
	{ // SampleNamespace::C file:T07.class_with_const_members.hpp line:
		pybind11::class_<SampleNamespace::C, std::shared_ptr<SampleNamespace::C>> cl(M("SampleNamespace"), "C", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::C(); } ) );
		cl.def_readwrite("muttable", &SampleNamespace::C::muttable);
	}
}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T07_class_with_const_members(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T07_class_with_const_members, root_module) {
	root_module.doc() = "T07_class_with_const_members module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "SampleNamespace"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T07_class_with_const_members(M);

}

// Source list file: TEST/T07_class_with_const_members.sources
// T07_class_with_const_members.cpp
// T07_class_with_const_members.cpp

// Modules list file: TEST/T07_class_with_const_members.modules
// SampleNamespace 
