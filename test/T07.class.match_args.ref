// File: T07_class_match_args.cpp
#include <T07.class.match_args.hpp> // MatchArgs
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T07_class_match_args(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // MatchArgs file:T07.class.match_args.hpp line:14
		pybind11::class_<MatchArgs, std::shared_ptr<MatchArgs>> cl(M(""), "MatchArgs", "");
		cl.def( pybind11::init( [](){ return new MatchArgs(); } ) );
		cl.def( pybind11::init( [](MatchArgs const &o){ return new MatchArgs(o); } ) );
		cl.def_readonly("__match_args__", &MatchArgs::__match_args__);
		cl.def_readwrite("var1", &MatchArgs::var1);
		cl.def_readwrite("var2", &MatchArgs::var2);
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

void bind_T07_class_match_args(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T07_class_match_args, root_module) {
	root_module.doc() = "T07_class_match_args module";

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
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T07_class_match_args(M);

}

// Source list file: TEST/T07_class_match_args.sources
// T07_class_match_args.cpp
// T07_class_match_args.cpp

// Modules list file: TEST/T07_class_match_args.modules
// 
