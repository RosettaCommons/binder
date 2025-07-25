// File: T71_module_local.cpp
#include <T71.module_local.hpp> // aaa::A
#include <T71.module_local.hpp> // aaa::E1
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

void bind_T71_module_local(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaa::A file:T71.module_local.hpp line:
		pybind11::class_<aaa::A, std::shared_ptr<aaa::A>> cl(M("aaa"), "A", "", pybind11::module_local());
		cl.def( pybind11::init( [](){ return new aaa::A(); } ) );
		cl.def("foo", (void (aaa::A::*)()) &aaa::A::foo, "C++: aaa::A::foo() --> void");
	}
	// aaa::E1 file:T71.module_local.hpp line:
	pybind11::enum_<aaa::E1>(M("aaa"), "E1", pybind11::arithmetic(), "", pybind11::module_local())
		.value("E1_V0", aaa::E1_V0)
		.value("E1_V1", aaa::E1_V1)
		.export_values();

;

}


// File: T71_module_local_1.cpp
#include <T71.module_local.hpp> // bbb::B
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

void bind_T71_module_local_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bbb::B file:T71.module_local.hpp line:
		pybind11::class_<bbb::B, std::shared_ptr<bbb::B>> cl(M("bbb"), "B", "");
		cl.def( pybind11::init( [](){ return new bbb::B(); } ) );
		cl.def("foo", (void (bbb::B::*)()) &bbb::B::foo, "C++: bbb::B::foo() --> void");
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

void bind_T71_module_local(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T71_module_local_1(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T71_module_local, root_module) {
	root_module.doc() = "T71_module_local module";

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
		{"", "bbb"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T71_module_local(M);
	bind_T71_module_local_1(M);

}

// Source list file: TEST/T71_module_local.sources
// T71_module_local.cpp
// T71_module_local.cpp
// T71_module_local_1.cpp

// Modules list file: TEST/T71_module_local.modules
// aaa bbb 
