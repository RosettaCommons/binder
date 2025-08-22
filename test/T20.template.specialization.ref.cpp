// File: T20_template_specialization.cpp
#include <T20.template.specialization.hpp> // SampleNamespace::MyStruct
#include <T20.template.specialization.hpp> // SampleNamespace::OtherClass
#include <T20.template.specialization.hpp> // SampleNamespace::PairClass
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include "T20.template.specialization.impl.cpp"


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T20_template_specialization(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // SampleNamespace::OtherClass file:T20.template.specialization.hpp line:
		pybind11::class_<SampleNamespace::OtherClass, std::shared_ptr<SampleNamespace::OtherClass>> cl(M("SampleNamespace"), "OtherClass", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::OtherClass(); } ) );
		cl.def( pybind11::init( [](SampleNamespace::OtherClass const &o){ return new SampleNamespace::OtherClass(o); } ) );
		cl.def("assign", (class SampleNamespace::OtherClass & (SampleNamespace::OtherClass::*)(const class SampleNamespace::OtherClass &)) &SampleNamespace::OtherClass::operator=, "C++: SampleNamespace::OtherClass::operator=(const class SampleNamespace::OtherClass &) --> class SampleNamespace::OtherClass &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // SampleNamespace::PairClass file:T20.template.specialization.hpp line:
		pybind11::class_<SampleNamespace::PairClass<SampleNamespace::OtherClass>, std::shared_ptr<SampleNamespace::PairClass<SampleNamespace::OtherClass>>> cl(M("SampleNamespace"), "PairClass_SampleNamespace_OtherClass_t", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::PairClass<SampleNamespace::OtherClass>(); } ) );
		cl.def( pybind11::init( [](SampleNamespace::PairClass<SampleNamespace::OtherClass> const &o){ return new SampleNamespace::PairClass<SampleNamespace::OtherClass>(o); } ) );
		cl.def("printHello", (void (SampleNamespace::PairClass<SampleNamespace::OtherClass>::*)()) &SampleNamespace::PairClass<SampleNamespace::OtherClass>::printHello, "C++: SampleNamespace::PairClass<SampleNamespace::OtherClass>::printHello() --> void");
		cl.def("assign", (class SampleNamespace::PairClass<SampleNamespace::OtherClass> & (SampleNamespace::PairClass<SampleNamespace::OtherClass>::*)(const class SampleNamespace::PairClass<SampleNamespace::OtherClass> &)) &SampleNamespace::PairClass<SampleNamespace::OtherClass>::operator=, "C++: SampleNamespace::PairClass<SampleNamespace::OtherClass>::operator=(const class SampleNamespace::PairClass<SampleNamespace::OtherClass> &) --> class SampleNamespace::PairClass<SampleNamespace::OtherClass> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // SampleNamespace::MyStruct file:T20.template.specialization.hpp line:
		pybind11::class_<SampleNamespace::MyStruct, std::shared_ptr<SampleNamespace::MyStruct>> cl(M("SampleNamespace"), "MyStruct", "");
		cl.def( pybind11::init( [](){ return new SampleNamespace::MyStruct(); } ) );
		cl.def_readwrite("pair", &SampleNamespace::MyStruct::pair);
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

void bind_T20_template_specialization(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T20_template_specialization, root_module) {
	root_module.doc() = "T20_template_specialization module";

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

	bind_T20_template_specialization(M);

}

// Source list file: TEST/T20_template_specialization.sources
// T20_template_specialization.cpp
// T20_template_specialization.cpp

// Modules list file: TEST/T20_template_specialization.modules
// SampleNamespace 
