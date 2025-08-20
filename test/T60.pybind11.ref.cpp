// File: T60_pybind11.cpp
#include <T60.pybind11.hpp> // foo
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <pybind11/numpy.h> // pybind11::array
#include <pybind11/numpy.h> // pybind11::dtype
#include <string> // std::basic_string
#include <string> // std::char_traits
#include <utility> // std::pair
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T60_pybind11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(class pybind11::handle &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::handle &)) &foo, "C++: foo(class pybind11::handle &) --> void", pybind11::arg(""));

	// foo(class pybind11::object &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::object &)) &foo, "C++: foo(class pybind11::object &) --> void", pybind11::arg(""));

	// foo(class pybind11::module_ &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::module_ &)) &foo, "C++: foo(class pybind11::module_ &) --> void", pybind11::arg(""));

	// foo(class pybind11::iterator &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::iterator &)) &foo, "C++: foo(class pybind11::iterator &) --> void", pybind11::arg(""));

	// foo(class pybind11::iterable &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::iterable &)) &foo, "C++: foo(class pybind11::iterable &) --> void", pybind11::arg(""));

	// foo(class pybind11::str &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::str &)) &foo, "C++: foo(class pybind11::str &) --> void", pybind11::arg(""));

	// foo(class pybind11::bytes &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::bytes &)) &foo, "C++: foo(class pybind11::bytes &) --> void", pybind11::arg(""));

	// foo(class pybind11::none &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::none &)) &foo, "C++: foo(class pybind11::none &) --> void", pybind11::arg(""));

	// foo(class pybind11::ellipsis &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::ellipsis &)) &foo, "C++: foo(class pybind11::ellipsis &) --> void", pybind11::arg(""));

	// foo(class pybind11::bool_ &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::bool_ &)) &foo, "C++: foo(class pybind11::bool_ &) --> void", pybind11::arg(""));

	// foo(class pybind11::int_ &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::int_ &)) &foo, "C++: foo(class pybind11::int_ &) --> void", pybind11::arg(""));

	// foo(class pybind11::float_ &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::float_ &)) &foo, "C++: foo(class pybind11::float_ &) --> void", pybind11::arg(""));

	// foo(class pybind11::weakref &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::weakref &)) &foo, "C++: foo(class pybind11::weakref &) --> void", pybind11::arg(""));

	// foo(class pybind11::slice &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::slice &)) &foo, "C++: foo(class pybind11::slice &) --> void", pybind11::arg(""));

	// foo(class pybind11::capsule &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::capsule &)) &foo, "C++: foo(class pybind11::capsule &) --> void", pybind11::arg(""));

	// foo(class pybind11::tuple &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::tuple &)) &foo, "C++: foo(class pybind11::tuple &) --> void", pybind11::arg(""));

	// foo(class pybind11::dict &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::dict &)) &foo, "C++: foo(class pybind11::dict &) --> void", pybind11::arg(""));

	// foo(class pybind11::sequence &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::sequence &)) &foo, "C++: foo(class pybind11::sequence &) --> void", pybind11::arg(""));

	// foo(class pybind11::list &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::list &)) &foo, "C++: foo(class pybind11::list &) --> void", pybind11::arg(""));

	// foo(class pybind11::set &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::set &)) &foo, "C++: foo(class pybind11::set &) --> void", pybind11::arg(""));

	// foo(class pybind11::function &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::function &)) &foo, "C++: foo(class pybind11::function &) --> void", pybind11::arg(""));

	// foo(class pybind11::buffer &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::buffer &)) &foo, "C++: foo(class pybind11::buffer &) --> void", pybind11::arg(""));

	// foo(class pybind11::array &) file:T60.pybind11.hpp line:
	M("").def("foo", (void (*)(class pybind11::array &)) &foo, "C++: foo(class pybind11::array &) --> void", pybind11::arg(""));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T60_pybind11(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T60_pybind11, root_module) {
	root_module.doc() = "T60_pybind11 module";

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

	bind_T60_pybind11(M);

}

// Source list file: TEST/T60_pybind11.sources
// T60_pybind11.cpp
// T60_pybind11.cpp

// Modules list file: TEST/T60_pybind11.modules
// 
