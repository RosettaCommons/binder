// File: T50_add_on_binder.cpp
#include <T50.add_on_binder.hpp> // Matrix
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

void bind_T50_add_on_binder(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Matrix file:T50.add_on_binder.hpp line:
		pybind11::class_<Matrix<int>, std::shared_ptr<Matrix<int>>> cl(M(""), "Matrix_int_t", "");
		cl.def( pybind11::init( [](){ return new Matrix<int>(); } ) );

		details::matrix_add_on_binder(cl);
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

void bind_T50_add_on_binder(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T50_add_on_binder, root_module) {
	root_module.doc() = "T50_add_on_binder module";

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

	bind_T50_add_on_binder(M);

}

// Source list file: TEST/T50_add_on_binder.sources
// T50_add_on_binder.cpp
// T50_add_on_binder.cpp

// Modules list file: TEST/T50_add_on_binder.modules
// 
