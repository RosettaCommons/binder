// File: std/array.cpp
#include <T20.template.variadic.hpp> // variadic_template::Array
#include <array> // std::array
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

void bind_std_array(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::array file:array line:
		pybind11::class_<std::array<variadic_template::Array<int, 2>,2>, std::shared_ptr<std::array<variadic_template::Array<int, 2>,2>>> cl(M("std"), "array_variadic_template_Array_int_2_2_t", "");
		cl.def( pybind11::init( [](){ return new std::array<variadic_template::Array<int, 2>,2>(); } ) );
		cl.def("fill", (void (std::array<variadic_template::Array<int, 2>,2>::*)(const struct variadic_template::Array<int, 2> &)) &std::array<variadic_template::Array<int, 2>, 2>::fill, "C++: std::array<variadic_template::Array<int, 2>, 2>::fill(const struct variadic_template::Array<int, 2> &) --> void", pybind11::arg("__u"));
		cl.def("swap", (void (std::array<variadic_template::Array<int, 2>,2>::*)(struct std::array<struct variadic_template::Array<int, 2>, 2> &)) &std::array<variadic_template::Array<int, 2>, 2>::swap, "C++: std::array<variadic_template::Array<int, 2>, 2>::swap(struct std::array<struct variadic_template::Array<int, 2>, 2> &) --> void", pybind11::arg("__other"));
		cl.def("begin", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::begin, "C++: std::array<variadic_template::Array<int, 2>, 2>::begin() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("end", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::end, "C++: std::array<variadic_template::Array<int, 2>, 2>::end() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("cbegin", (const struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::cbegin, "C++: std::array<variadic_template::Array<int, 2>, 2>::cbegin() const --> const struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("cend", (const struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::cend, "C++: std::array<variadic_template::Array<int, 2>, 2>::cend() const --> const struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::size, "C++: std::array<variadic_template::Array<int, 2>, 2>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::max_size, "C++: std::array<variadic_template::Array<int, 2>, 2>::max_size() const --> unsigned long");
		cl.def("empty", (bool (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::empty, "C++: std::array<variadic_template::Array<int, 2>, 2>::empty() const --> bool");
		cl.def("__getitem__", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)(unsigned long)) &std::array<variadic_template::Array<int, 2>, 2>::operator[], "C++: std::array<variadic_template::Array<int, 2>, 2>::operator[](unsigned long) --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)(unsigned long)) &std::array<variadic_template::Array<int, 2>, 2>::at, "C++: std::array<variadic_template::Array<int, 2>, 2>::at(unsigned long) --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::front, "C++: std::array<variadic_template::Array<int, 2>, 2>::front() --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::back, "C++: std::array<variadic_template::Array<int, 2>, 2>::back() --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::data, "C++: std::array<variadic_template::Array<int, 2>, 2>::data() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
	}
	{ // std::array file:array line:
		pybind11::class_<std::array<int,2>, std::shared_ptr<std::array<int,2>>> cl(M("std"), "array_int_2_t", "");
		cl.def( pybind11::init( [](){ return new std::array<int,2>(); } ) );
		cl.def("fill", (void (std::array<int,2>::*)(const int &)) &std::array<int, 2>::fill, "C++: std::array<int, 2>::fill(const int &) --> void", pybind11::arg("__u"));
		cl.def("swap", (void (std::array<int,2>::*)(struct std::array<int, 2> &)) &std::array<int, 2>::swap, "C++: std::array<int, 2>::swap(struct std::array<int, 2> &) --> void", pybind11::arg("__other"));
		cl.def("begin", (int * (std::array<int,2>::*)()) &std::array<int, 2>::begin, "C++: std::array<int, 2>::begin() --> int *", pybind11::return_value_policy::automatic);
		cl.def("end", (int * (std::array<int,2>::*)()) &std::array<int, 2>::end, "C++: std::array<int, 2>::end() --> int *", pybind11::return_value_policy::automatic);
		cl.def("cbegin", (const int * (std::array<int,2>::*)() const) &std::array<int, 2>::cbegin, "C++: std::array<int, 2>::cbegin() const --> const int *", pybind11::return_value_policy::automatic);
		cl.def("cend", (const int * (std::array<int,2>::*)() const) &std::array<int, 2>::cend, "C++: std::array<int, 2>::cend() const --> const int *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (std::array<int,2>::*)() const) &std::array<int, 2>::size, "C++: std::array<int, 2>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::array<int,2>::*)() const) &std::array<int, 2>::max_size, "C++: std::array<int, 2>::max_size() const --> unsigned long");
		cl.def("empty", (bool (std::array<int,2>::*)() const) &std::array<int, 2>::empty, "C++: std::array<int, 2>::empty() const --> bool");
		cl.def("__getitem__", (int & (std::array<int,2>::*)(unsigned long)) &std::array<int, 2>::operator[], "C++: std::array<int, 2>::operator[](unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (int & (std::array<int,2>::*)(unsigned long)) &std::array<int, 2>::at, "C++: std::array<int, 2>::at(unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (int & (std::array<int,2>::*)()) &std::array<int, 2>::front, "C++: std::array<int, 2>::front() --> int &", pybind11::return_value_policy::automatic);
		cl.def("back", (int & (std::array<int,2>::*)()) &std::array<int, 2>::back, "C++: std::array<int, 2>::back() --> int &", pybind11::return_value_policy::automatic);
		cl.def("data", (int * (std::array<int,2>::*)()) &std::array<int, 2>::data, "C++: std::array<int, 2>::data() --> int *", pybind11::return_value_policy::automatic);
	}
}


// File: T20_template_variadic.cpp
#include <T20.template.variadic.hpp> // variadic_template::Array
#include <T20.template.variadic.hpp> // variadic_template::st2
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

void bind_T20_template_variadic(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // variadic_template::Array file:T20.template.variadic.hpp line:
		pybind11::class_<variadic_template::Array<int,2,2>, std::shared_ptr<variadic_template::Array<int,2,2>>, std::array<variadic_template::Array<int, 2>,2>> cl(M("variadic_template"), "Array_int_2_2_t", "");
		cl.def( pybind11::init( [](){ return new variadic_template::Array<int,2,2>(); } ) );
		cl.def("fill", (void (std::array<variadic_template::Array<int, 2>,2>::*)(const struct variadic_template::Array<int, 2> &)) &std::array<variadic_template::Array<int, 2>, 2>::fill, "C++: std::array<variadic_template::Array<int, 2>, 2>::fill(const struct variadic_template::Array<int, 2> &) --> void", pybind11::arg("__u"));
		cl.def("swap", (void (std::array<variadic_template::Array<int, 2>,2>::*)(struct std::array<struct variadic_template::Array<int, 2>, 2> &)) &std::array<variadic_template::Array<int, 2>, 2>::swap, "C++: std::array<variadic_template::Array<int, 2>, 2>::swap(struct std::array<struct variadic_template::Array<int, 2>, 2> &) --> void", pybind11::arg("__other"));
		cl.def("begin", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::begin, "C++: std::array<variadic_template::Array<int, 2>, 2>::begin() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("end", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::end, "C++: std::array<variadic_template::Array<int, 2>, 2>::end() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("cbegin", (const struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::cbegin, "C++: std::array<variadic_template::Array<int, 2>, 2>::cbegin() const --> const struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("cend", (const struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::cend, "C++: std::array<variadic_template::Array<int, 2>, 2>::cend() const --> const struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::size, "C++: std::array<variadic_template::Array<int, 2>, 2>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::max_size, "C++: std::array<variadic_template::Array<int, 2>, 2>::max_size() const --> unsigned long");
		cl.def("empty", (bool (std::array<variadic_template::Array<int, 2>,2>::*)() const) &std::array<variadic_template::Array<int, 2>, 2>::empty, "C++: std::array<variadic_template::Array<int, 2>, 2>::empty() const --> bool");
		cl.def("__getitem__", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)(unsigned long)) &std::array<variadic_template::Array<int, 2>, 2>::operator[], "C++: std::array<variadic_template::Array<int, 2>, 2>::operator[](unsigned long) --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)(unsigned long)) &std::array<variadic_template::Array<int, 2>, 2>::at, "C++: std::array<variadic_template::Array<int, 2>, 2>::at(unsigned long) --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::front, "C++: std::array<variadic_template::Array<int, 2>, 2>::front() --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct variadic_template::Array<int, 2> & (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::back, "C++: std::array<variadic_template::Array<int, 2>, 2>::back() --> struct variadic_template::Array<int, 2> &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct variadic_template::Array<int, 2> * (std::array<variadic_template::Array<int, 2>,2>::*)()) &std::array<variadic_template::Array<int, 2>, 2>::data, "C++: std::array<variadic_template::Array<int, 2>, 2>::data() --> struct variadic_template::Array<int, 2> *", pybind11::return_value_policy::automatic);
	}
	{ // variadic_template::Array file:T20.template.variadic.hpp line:
		pybind11::class_<variadic_template::Array<int,2>, std::shared_ptr<variadic_template::Array<int,2>>, std::array<int,2>> cl(M("variadic_template"), "Array_int_2_t", "");
		cl.def( pybind11::init( [](){ return new variadic_template::Array<int,2>(); } ) );
		cl.def("fill", (void (std::array<int,2>::*)(const int &)) &std::array<int, 2>::fill, "C++: std::array<int, 2>::fill(const int &) --> void", pybind11::arg("__u"));
		cl.def("swap", (void (std::array<int,2>::*)(struct std::array<int, 2> &)) &std::array<int, 2>::swap, "C++: std::array<int, 2>::swap(struct std::array<int, 2> &) --> void", pybind11::arg("__other"));
		cl.def("begin", (int * (std::array<int,2>::*)()) &std::array<int, 2>::begin, "C++: std::array<int, 2>::begin() --> int *", pybind11::return_value_policy::automatic);
		cl.def("end", (int * (std::array<int,2>::*)()) &std::array<int, 2>::end, "C++: std::array<int, 2>::end() --> int *", pybind11::return_value_policy::automatic);
		cl.def("cbegin", (const int * (std::array<int,2>::*)() const) &std::array<int, 2>::cbegin, "C++: std::array<int, 2>::cbegin() const --> const int *", pybind11::return_value_policy::automatic);
		cl.def("cend", (const int * (std::array<int,2>::*)() const) &std::array<int, 2>::cend, "C++: std::array<int, 2>::cend() const --> const int *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (std::array<int,2>::*)() const) &std::array<int, 2>::size, "C++: std::array<int, 2>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::array<int,2>::*)() const) &std::array<int, 2>::max_size, "C++: std::array<int, 2>::max_size() const --> unsigned long");
		cl.def("empty", (bool (std::array<int,2>::*)() const) &std::array<int, 2>::empty, "C++: std::array<int, 2>::empty() const --> bool");
		cl.def("__getitem__", (int & (std::array<int,2>::*)(unsigned long)) &std::array<int, 2>::operator[], "C++: std::array<int, 2>::operator[](unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (int & (std::array<int,2>::*)(unsigned long)) &std::array<int, 2>::at, "C++: std::array<int, 2>::at(unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (int & (std::array<int,2>::*)()) &std::array<int, 2>::front, "C++: std::array<int, 2>::front() --> int &", pybind11::return_value_policy::automatic);
		cl.def("back", (int & (std::array<int,2>::*)()) &std::array<int, 2>::back, "C++: std::array<int, 2>::back() --> int &", pybind11::return_value_policy::automatic);
		cl.def("data", (int * (std::array<int,2>::*)()) &std::array<int, 2>::data, "C++: std::array<int, 2>::data() --> int *", pybind11::return_value_policy::automatic);
	}
	{ // variadic_template::st2 file:T20.template.variadic.hpp line:
		pybind11::class_<variadic_template::st2, std::shared_ptr<variadic_template::st2>, variadic_template::Array<int,2,2>> cl(M("variadic_template"), "st2", "");
		cl.def( pybind11::init( [](){ return new variadic_template::st2(); } ) );
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

void bind_std_array(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T20_template_variadic(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T20_template_variadic, root_module) {
	root_module.doc() = "T20_template_variadic module";

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
		{"", "std"},
		{"", "variadic_template"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_std_array(M);
	bind_T20_template_variadic(M);

}

// Source list file: TEST/T20_template_variadic.sources
// T20_template_variadic.cpp
// std/array.cpp
// T20_template_variadic.cpp

// Modules list file: TEST/T20_template_variadic.modules
// std variadic_template 
