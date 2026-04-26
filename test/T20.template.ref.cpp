// File: T20_template.cpp
#include <T20.template.hpp> // A
#include <T20.template.hpp> // TemplateSpecialization
#include <T20.template.hpp> // add
#include <T20.template.hpp> // fi
#include <T20.template.hpp> // fi_instantiated_by_use_in_function
#include <T20.template.hpp> // foo
#include <T20.template.hpp> // instantiate
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

void bind_T20_template(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo() file:T20.template.hpp line:
	M("").def("foo", (void (*)()) &foo<int>, "C++: foo() --> void");

	// foo() file:T20.template.hpp line:
	M("").def("foo", (void (*)()) &foo<double>, "C++: foo() --> void");

	{ // A file:T20.template.hpp line:
		pybind11::class_<A<int>, std::shared_ptr<A<int>>> cl(M(""), "A_int_t", "");
		cl.def( pybind11::init( [](){ return new A<int>(); } ) );
		cl.def_readwrite("t_value", &A<int>::t_value);
		cl.def("foo", (void (A<int>::*)(int &)) &A<int>::foo, "C++: A<int>::foo(int &) --> void", pybind11::arg(""));
	}
	// fi_instantiated_by_use_in_function(class A<int>) file:T20.template.hpp line:
	M("").def("fi_instantiated_by_use_in_function", (void (*)(class A<int>)) &fi_instantiated_by_use_in_function, "C++: fi_instantiated_by_use_in_function(class A<int>) --> void", pybind11::arg(""));

	// fi(class A<int> &) file:T20.template.hpp line:
	M("").def("fi", (void (*)(class A<int> &)) &fi, "C++: fi(class A<int> &) --> void", pybind11::arg(""));

	// fi(class A<int> *) file:T20.template.hpp line:
	M("").def("fi", (void (*)(class A<int> *)) &fi, "C++: fi(class A<int> *) --> void", pybind11::arg(""));

	// add(int) file:T20.template.hpp line:
	M("").def("add", (int (*)(int)) &add<int>, "C++: add(int) --> int", pybind11::arg("v"));

	// add(int, int, int) file:T20.template.hpp line:
	M("").def("add", (int (*)(int, int, int)) &add<int,int, int>, "C++: add(int, int, int) --> int", pybind11::arg("first"), pybind11::arg("as"), pybind11::arg("as"));

	// add(int, int) file:T20.template.hpp line:
	M("").def("add", (int (*)(int, int)) &add<int,int>, "C++: add(int, int) --> int", pybind11::arg("first"), pybind11::arg("as"));

	// foo() file:T20.template.hpp line:
	M("").def("foo", (void (*)()) &foo, "C++: foo() --> void");

	// foo(int) file:T20.template.hpp line:
	M("").def("foo", (void (*)(int)) &foo<int>, "C++: foo(int) --> void", pybind11::arg("as"));

	// foo(int, int) file:T20.template.hpp line:
	M("").def("foo", (void (*)(int, int)) &foo<int, int>, "C++: foo(int, int) --> void", pybind11::arg("as"), pybind11::arg("as"));

	// foo(int, int, int) file:T20.template.hpp line:
	M("").def("foo", (void (*)(int, int, int)) &foo<int, int, int>, "C++: foo(int, int, int) --> void", pybind11::arg("as"), pybind11::arg("as"), pybind11::arg("as"));

	// instantiate() file:T20.template.hpp line:
	M("").def("instantiate", (void (*)()) &instantiate, "C++: instantiate() --> void");

	{ // TemplateSpecialization file:T20.template.hpp line:
		pybind11::class_<TemplateSpecialization<float>, std::shared_ptr<TemplateSpecialization<float>>> cl(M(""), "TemplateSpecialization_float_t", "");
		cl.def( pybind11::init( [](){ return new TemplateSpecialization<float>(); } ) );
		cl.def_readwrite("data", &TemplateSpecialization<float>::data);
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

void bind_T20_template(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T20_template, root_module) {
	root_module.doc() = "T20_template module";

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
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T20_template(M);

}

// Source list file: TEST/T20_template.sources
// T20_template.cpp
// T20_template.cpp

// Modules list file: TEST/T20_template.modules
// 
