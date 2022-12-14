// File: T81_custom_trampoline_with_args.cpp
#include <T81.custom_trampoline_with_args.hpp> // aaa::A
#include <T81.custom_trampoline_with_args.include> // +include_for_class
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <string> // std::basic_string
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// aaa::A file:T81.custom_trampoline_with_args.hpp line:26
struct PyCallBack_aaa_A_double_t : public aaa::A<double> {
	using aaa::A<double>::A;

	void foo(int a0, std::string a1, float a2) override {
		return myFoo<A,PyCallBack_aaa_A_double_t>(this, "aaa::A<double>", "foo", a0, a1, a2);
	}
};

void bind_T81_custom_trampoline_with_args(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaa::A file:T81.custom_trampoline_with_args.hpp line:26
		pybind11::class_<aaa::A<double>, std::shared_ptr<aaa::A<double>>, PyCallBack_aaa_A_double_t> cl(M("aaa"), "A_double_t", "");
		cl.def( pybind11::init( [](){ return new aaa::A<double>(); }, [](){ return new PyCallBack_aaa_A_double_t(); } ) );
		cl.def("foo", (void (aaa::A<double>::*)(int, std::string, float)) &aaa::A<double>::foo, "C++: aaa::A<double>::foo(int, std::string, float) --> void", pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("d"));
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

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T81_custom_trampoline_with_args(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T81_custom_trampoline_with_args, root_module) {
	root_module.doc() = "T81_custom_trampoline_with_args module";

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
			else return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "aaa"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T81_custom_trampoline_with_args(M);

}

// Source list file: TEST/T81_custom_trampoline_with_args.sources
// T81_custom_trampoline_with_args.cpp
// T81_custom_trampoline_with_args.cpp

// Modules list file: TEST/T81_custom_trampoline_with_args.modules
// aaa 
