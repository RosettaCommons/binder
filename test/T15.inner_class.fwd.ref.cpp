// File: T15_inner_class_fwd.cpp
#include <T15.inner_class.fwd.hpp> // outer
#include <T15.inner_class.fwd.hpp> // outer::inner
#include <T15.inner_class.fwd.hpp> // outer::inner2
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

void bind_T15_inner_class_fwd(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // outer file:T15.inner_class.fwd.hpp line:
		pybind11::class_<outer, std::shared_ptr<outer>> cl(M(""), "outer", "binder/test/T15.inner_class.fwd.hpp\n \n\n  Binder self-test file. Tests for bindings of forward declared inner functions.");
		cl.def( pybind11::init( [](){ return new outer(); } ) );
		cl.def("f", (void (outer::*)(struct outer::inner *, struct outer::inner2 *, struct outer::inner3 *)) &outer::f, "C++: outer::f(struct outer::inner *, struct outer::inner2 *, struct outer::inner3 *) --> void", pybind11::arg("i"), pybind11::arg("i2"), pybind11::arg("i3"));

		{ // outer::inner file:T15.inner_class.fwd.hpp line:
			auto & enclosing_class = cl;
			pybind11::class_<outer::inner, std::shared_ptr<outer::inner>> cl(enclosing_class, "inner", "");
			cl.def( pybind11::init( [](){ return new outer::inner(); } ) );
			cl.def_readwrite("a", &outer::inner::a);
		}

		{ // outer::inner2 file:T15.inner_class.fwd.hpp line:
			auto & enclosing_class = cl;
			pybind11::class_<outer::inner2, std::shared_ptr<outer::inner2>> cl(enclosing_class, "inner2", "");
			cl.def( pybind11::init( [](){ return new outer::inner2(); } ) );
			cl.def_readwrite("b", &outer::inner2::b);
		}

		{ // outer::inner3 file:T15.inner_class.fwd.hpp line:
			auto & enclosing_class = cl;
			pybind11::class_<outer::inner3, std::shared_ptr<outer::inner3>> cl(enclosing_class, "inner3", "");
			cl.def( pybind11::init( [](){ return new outer::inner3(); } ) );
			cl.def_readwrite("c", &outer::inner3::c);
		}

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

void bind_T15_inner_class_fwd(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T15_inner_class_fwd, root_module) {
	root_module.doc() = "T15_inner_class_fwd module";

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

	bind_T15_inner_class_fwd(M);

}

// Source list file: TEST/T15_inner_class_fwd.sources
// T15_inner_class_fwd.cpp
// T15_inner_class_fwd.cpp

// Modules list file: TEST/T15_inner_class_fwd.modules
// 
