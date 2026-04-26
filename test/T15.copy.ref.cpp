// File: T15_copy.cpp
#include <T15.copy.hpp> // Data1
#include <T15.copy.hpp> // POD1
#include <T15.copy.hpp> // POD2
#include <T15.copy.hpp> // POD3
#include <T15.copy.hpp> // POD4
#include <T15.copy.hpp> // POD5
#include <T15.copy.hpp> // POD6
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

void bind_T15_copy(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // POD1 file:T15.copy.hpp line:
		pybind11::class_<POD1, std::shared_ptr<POD1>> cl(M(""), "POD1", "");
		cl.def( pybind11::init( [](){ return new POD1(); } ) );
	}
	{ // POD2 file:T15.copy.hpp line:
		pybind11::class_<POD2, std::shared_ptr<POD2>> cl(M(""), "POD2", "");
		cl.def( pybind11::init( [](POD2 const &o){ return new POD2(o); } ) );
	}
	{ // POD3 file:T15.copy.hpp line:
		pybind11::class_<POD3, std::shared_ptr<POD3>> cl(M(""), "POD3", "");
		cl.def( pybind11::init( [](POD3 const &o){ return new POD3(o); } ) );
	}
	{ // POD4 file:T15.copy.hpp line:
		pybind11::class_<POD4, std::shared_ptr<POD4>> cl(M(""), "POD4", "");
		cl.def( pybind11::init( [](POD4 const &o){ return new POD4(o); } ) );
		cl.def_readwrite("a", &POD4::a);
	}
	{ // POD5 file:T15.copy.hpp line:
		pybind11::class_<POD5, std::shared_ptr<POD5>> cl(M(""), "POD5", "");
	}
	{ // POD6 file:T15.copy.hpp line:
		pybind11::class_<POD6, std::shared_ptr<POD6>> cl(M(""), "POD6", "");
		cl.def_readwrite("a", &POD6::a);
	}
	{ // Data1 file:T15.copy.hpp line:
		pybind11::class_<Data1, std::shared_ptr<Data1>> cl(M(""), "Data1", "");
		cl.def( pybind11::init( [](Data1 const &o){ return new Data1(o); } ) );
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

void bind_T15_copy(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T15_copy, root_module) {
	root_module.doc() = "T15_copy module";

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

	bind_T15_copy(M);

}

// Source list file: TEST/T15_copy.sources
// T15_copy.cpp
// T15_copy.cpp

// Modules list file: TEST/T15_copy.modules
// 
