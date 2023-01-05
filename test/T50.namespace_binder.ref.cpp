// File: T50_namespace_binder.cpp
#include <T50.namespace_binder.hpp> // foo_root

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T50_namespace_binder(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo_root() file:T50.namespace_binder.hpp line:16
	M("").def("foo_root", (void (*)()) &foo_root, "C++: foo_root() --> void");

}


// File: T50_namespace_binder_1.cpp
#include <T50.namespace_binder.a.1.include>
#include <T50.namespace_binder.a.2.include>
#include <T50.namespace_binder.hpp> // aaaa::foo_aaaa

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T50_namespace_binder_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{

	add_on_binder_for_aaaa(M("aaaa"));
	// aaaa::foo_aaaa() file:T50.namespace_binder.hpp line:21
	M("aaaa").def("foo_aaaa", (void (*)()) &aaaa::foo_aaaa, "C++: aaaa::foo_aaaa() --> void");

}


// File: T50_namespace_binder_2.cpp
#include <T50.namespace_binder.a.b.include>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T50_namespace_binder_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{

	binder_for_aaaa_bbbb(M("aaaa::bbbb"));
}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T50_namespace_binder(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T50_namespace_binder_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T50_namespace_binder_2(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T50_namespace_binder, root_module) {
	root_module.doc() = "T50_namespace_binder module";

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
		{"", "aaaa"},
		{"aaaa", "bbbb"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T50_namespace_binder(M);
	bind_T50_namespace_binder_1(M);
	bind_T50_namespace_binder_2(M);

}

// Source list file: TEST/T50_namespace_binder.sources
// T50_namespace_binder.cpp
// T50_namespace_binder.cpp
// T50_namespace_binder_1.cpp
// T50_namespace_binder_2.cpp

// Modules list file: TEST/T50_namespace_binder.modules
// aaaa aaaa.bbbb 
