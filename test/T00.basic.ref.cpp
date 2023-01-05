// File: T00_basic.cpp
#include <T00.basic.hpp> // foo
#include <T00.basic.hpp> // foo_char
#include <T00.basic.hpp> // foo_double
#include <T00.basic.hpp> // foo_float
#include <T00.basic.hpp> // foo_int
#include <T00.basic.hpp> // foo_void_p

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T00_basic(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo() file:T00.basic.hpp line:25
	M("").def("foo", (void (*)()) &foo, "C++: foo() --> void");

	// foo_char(char) file:T00.basic.hpp line:29
	M("").def("foo_char", (int (*)(char)) &foo_char, "C++: foo_char(char) --> int", pybind11::arg(""));

	// foo_char(char &) file:T00.basic.hpp line:33
	M("").def("foo_char", (int (*)(char &)) &foo_char, "C++: foo_char(char &) --> int", pybind11::arg(""));

	// foo_char(char *) file:T00.basic.hpp line:37
	M("").def("foo_char", (int (*)(char *)) &foo_char, "C++: foo_char(char *) --> int", pybind11::arg(""));

	// foo_int(int) file:T00.basic.hpp line:42
	M("").def("foo_int", (int (*)(int)) &foo_int, "C++: foo_int(int) --> int", pybind11::arg(""));

	// foo_int(int &) file:T00.basic.hpp line:46
	M("").def("foo_int", (int (*)(int &)) &foo_int, "C++: foo_int(int &) --> int", pybind11::arg(""));

	// foo_int(int *) file:T00.basic.hpp line:50
	M("").def("foo_int", (int (*)(int *)) &foo_int, "C++: foo_int(int *) --> int", pybind11::arg(""));

	// foo_float(float) file:T00.basic.hpp line:55
	M("").def("foo_float", (float (*)(float)) &foo_float, "C++: foo_float(float) --> float", pybind11::arg(""));

	// foo_float(float &) file:T00.basic.hpp line:59
	M("").def("foo_float", (float (*)(float &)) &foo_float, "C++: foo_float(float &) --> float", pybind11::arg(""));

	// foo_float(float *) file:T00.basic.hpp line:63
	M("").def("foo_float", (float (*)(float *)) &foo_float, "C++: foo_float(float *) --> float", pybind11::arg(""));

	// foo_double(double) file:T00.basic.hpp line:68
	M("").def("foo_double", (double (*)(double)) &foo_double, "C++: foo_double(double) --> double", pybind11::arg(""));

	// foo_double(double &) file:T00.basic.hpp line:72
	M("").def("foo_double", (double (*)(double &)) &foo_double, "C++: foo_double(double &) --> double", pybind11::arg(""));

	// foo_double(double *) file:T00.basic.hpp line:76
	M("").def("foo_double", (double (*)(double *)) &foo_double, "C++: foo_double(double *) --> double", pybind11::arg(""));

	// foo_void_p(void *) file:T00.basic.hpp line:83
	M("").def("foo_void_p", (void * (*)(void *)) &foo_void_p, "C++: foo_void_p(void *) --> void *", pybind11::return_value_policy::automatic, pybind11::arg(""));

	// foo_void_p(void *const &) file:T00.basic.hpp line:87
	M("").def("foo_void_p", (void * (*)(void *const &)) &foo_void_p, "C++: foo_void_p(void *const &) --> void *", pybind11::return_value_policy::automatic, pybind11::arg(""));

	// foo_void_p(void *&) file:T00.basic.hpp line:91
	M("").def("foo_void_p", (void * (*)(void *&)) &foo_void_p, "C++: foo_void_p(void *&) --> void *", pybind11::return_value_policy::automatic, pybind11::arg(""));

}


// File: T00_basic_1.cpp
#include <T00.basic.hpp> // global::foo

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T00_basic_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// global::foo() file:T00.basic.hpp line:97
	M("global").def("foo", (void (*)()) &global::foo, "C++: global::foo() --> void");

}


// File: T00_basic_2.cpp
#include <T00.basic.hpp> // nonlocal::foo

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T00_basic_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// nonlocal::foo() file:T00.basic.hpp line:102
	M("nonlocal").def("foo", (void (*)()) &nonlocal::foo, "C++: nonlocal::foo() --> void");

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T00_basic(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T00_basic_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T00_basic_2(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T00_basic, root_module) {
	root_module.doc() = "T00_basic module";

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
		{"", "global"},
		{"", "nonlocal"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T00_basic(M);
	bind_T00_basic_1(M);
	bind_T00_basic_2(M);

}

// Source list file: TEST/T00_basic.sources
// T00_basic.cpp
// T00_basic.cpp
// T00_basic_1.cpp
// T00_basic_2.cpp

// Modules list file: TEST/T00_basic.modules
// global nonlocal 
