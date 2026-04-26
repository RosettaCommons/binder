// File: T80_custom_trampoline.cpp
#include <T80.custom_trampoline.hpp> // aaa::A
#include <T80.custom_trampoline.include> // +include_for_class
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

// aaa::A file:T80.custom_trampoline.hpp line:
struct PyCallBack_aaa_A_double_t : public aaa::A<double> {
	using aaa::A<double>::A;

	class aaa::A<double> foo() override {
		return myFoo<A,PyCallBack_aaa_A_double_t>(this, "aaa::A<double>", "foo");
	}
};

void bind_T80_custom_trampoline(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaa::A file:T80.custom_trampoline.hpp line:
		pybind11::class_<aaa::A<double>, std::shared_ptr<aaa::A<double>>, PyCallBack_aaa_A_double_t> cl(M("aaa"), "A_double_t", "");
		cl.def( pybind11::init( [](){ return new aaa::A<double>(); }, [](){ return new PyCallBack_aaa_A_double_t(); } ) );
		cl.def( pybind11::init( [](PyCallBack_aaa_A_double_t const &o){ return new PyCallBack_aaa_A_double_t(o); } ) );
		cl.def( pybind11::init( [](aaa::A<double> const &o){ return new aaa::A<double>(o); } ) );
		cl.def("foo", (class aaa::A<double> (aaa::A<double>::*)()) &aaa::A<double>::foo, "C++: aaa::A<double>::foo() --> class aaa::A<double>");
		cl.def("assign", (class aaa::A<double> & (aaa::A<double>::*)(const class aaa::A<double> &)) &aaa::A<double>::operator=, "C++: aaa::A<double>::operator=(const class aaa::A<double> &) --> class aaa::A<double> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
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

void bind_T80_custom_trampoline(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T80_custom_trampoline, root_module) {
	root_module.doc() = "T80_custom_trampoline module";

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
		{"", "aaa"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T80_custom_trampoline(M);

}

// Source list file: TEST/T80_custom_trampoline.sources
// T80_custom_trampoline.cpp
// T80_custom_trampoline.cpp

// Modules list file: TEST/T80_custom_trampoline.modules
// aaa 
