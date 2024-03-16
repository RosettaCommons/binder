// File: std/stl_vector.cpp
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <stl_binders.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_stl_vector(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// std::vector file:bits/stl_vector.h line:
	binder::vector_binder<int,std::allocator<int>>(M("std"), "int", "std_allocator_int_t");

}


// File: T40_stl.cpp
#include <T40.stl.hpp> // foo
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <stl_binders.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T40_stl(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(class std::vector<int, class std::allocator<int> >) file:T40.stl.hpp line:
	M("").def("foo", (void (*)(class std::vector<int, class std::allocator<int> >)) &foo, "C++: foo(class std::vector<int, class std::allocator<int> >) --> void", pybind11::arg(""));

}


// File: std/T40_stl.cpp
#include <iterator> // __gnu_cxx::__normal_iterator
#include <iterator> // std::move_iterator
#include <iterator> // std::reverse_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <stl_binders.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_T40_stl(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// std::vector file:T40.stl.hpp line:
	binder::vector_binder<float,std::allocator<float>>(M("std"), "float", "std_allocator_float_t");

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_std_stl_vector(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T40_stl(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_T40_stl(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T40_stl, root_module) {
	root_module.doc() = "T40_stl module";

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
		{"", "std"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_std_stl_vector(M);
	bind_T40_stl(M);
	bind_std_T40_stl(M);

}

// Source list file: TEST/T40_stl.sources
// T40_stl.cpp
// std/stl_vector.cpp
// T40_stl.cpp
// std/T40_stl.cpp

// Modules list file: TEST/T40_stl.modules
// std 
