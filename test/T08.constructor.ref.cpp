// File: T08_constructor.cpp
#include <T08.constructor.hpp> // BaseA
#include <T08.constructor.hpp> // BaseB
#include <T08.constructor.hpp> // BaseC
#include <T08.constructor.hpp> // BaseD
#include <T08.constructor.hpp> // DerivedA
#include <T08.constructor.hpp> // DerivedB
#include <T08.constructor.hpp> // DerivedC
#include <T08.constructor.hpp> // DerivedD
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

void bind_T08_constructor(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // BaseA file:T08.constructor.hpp line:
		pybind11::class_<BaseA, std::shared_ptr<BaseA>> cl(M(""), "BaseA", "");
		cl.def( pybind11::init( [](){ return new BaseA(); } ) );
	}
	{ // DerivedA file:T08.constructor.hpp line:
		pybind11::class_<DerivedA, std::shared_ptr<DerivedA>, BaseA> cl(M(""), "DerivedA", "");
		cl.def( pybind11::init( [](){ return new DerivedA(); } ) );
	}
	{ // BaseB file:T08.constructor.hpp line:
		pybind11::class_<BaseB, std::shared_ptr<BaseB>> cl(M(""), "BaseB", "");
		cl.def( pybind11::init<int>(), pybind11::arg("") );

	}
	{ // DerivedB file:T08.constructor.hpp line:
		pybind11::class_<DerivedB, std::shared_ptr<DerivedB>, BaseB> cl(M(""), "DerivedB", "");
	}
	{ // BaseC file:T08.constructor.hpp line:
		pybind11::class_<BaseC, std::shared_ptr<BaseC>> cl(M(""), "BaseC", "");
		cl.def( pybind11::init<int>(), pybind11::arg("") );

	}
	{ // DerivedC file:T08.constructor.hpp line:
		pybind11::class_<DerivedC, std::shared_ptr<DerivedC>, BaseC> cl(M(""), "DerivedC", "");
	}
	{ // BaseD file:T08.constructor.hpp line:
		pybind11::class_<BaseD, std::shared_ptr<BaseD>> cl(M(""), "BaseD", "");
		cl.def( pybind11::init<int>(), pybind11::arg("") );

	}
	{ // DerivedD file:T08.constructor.hpp line:
		pybind11::class_<DerivedD, std::shared_ptr<DerivedD>, BaseD> cl(M(""), "DerivedD", "");
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

void bind_T08_constructor(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T08_constructor, root_module) {
	root_module.doc() = "T08_constructor module";

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

	bind_T08_constructor(M);

}

// Source list file: TEST/T08_constructor.sources
// T08_constructor.cpp
// T08_constructor.cpp

// Modules list file: TEST/T08_constructor.modules
// 
