// File: T02_function.cpp
#include <T02.function.hpp> // A
#include <T02.function.hpp> // foo
#include <T02.function.hpp> // foo_cr
#include <T02.function.hpp> // foo_f1
#include <T02.function.hpp> // foo_f2
#include <T02.function.hpp> // foo_f3
#include <T02.function.hpp> // foo_f5
#include <T02.function.hpp> // foo_f7
#include <T02.function.hpp> // foo_f8
#include <T02.function.hpp> // foo_p
#include <T02.function.hpp> // foo_r
#include <functional> // std::function
#include <memory> // std::shared_ptr
#include <sstream> // __str__
#include <tuple> // std::tuple
#include <utility> // std::pair

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T02_function(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // A file:T02.function.hpp line:
		pybind11::class_<A, std::shared_ptr<A>> cl(M(""), "A", "");
		cl.def( pybind11::init( [](){ return new A(); } ) );
	}
	// foo(bool) file:T02.function.hpp line:
	M("").def("foo", (void (*)(bool)) &foo, "C++: foo(bool) --> void", pybind11::arg(""));

	// foo(int) file:T02.function.hpp line:
	M("").def("foo", (void (*)(int)) &foo, "C++: foo(int) --> void", pybind11::arg(""));

	// foo(long) file:T02.function.hpp line:
	M("").def("foo", (void (*)(long)) &foo, "C++: foo(long) --> void", pybind11::arg(""));

	// foo(float) file:T02.function.hpp line:
	M("").def("foo", (void (*)(float)) &foo, "C++: foo(float) --> void", pybind11::arg(""));

	// foo(double) file:T02.function.hpp line:
	M("").def("foo", (void (*)(double)) &foo, "C++: foo(double) --> void", pybind11::arg(""));

	// foo(class A) file:T02.function.hpp line:
	M("").def("foo", (void (*)(class A)) &foo, "C++: foo(class A) --> void", pybind11::arg(""));

	// foo(class std::shared_ptr<class A>) file:T02.function.hpp line:
	M("").def("foo", (void (*)(class std::shared_ptr<class A>)) &foo, "C++: foo(class std::shared_ptr<class A>) --> void", pybind11::arg(""));

	// foo_r(bool &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(bool &)) &foo_r, "C++: foo_r(bool &) --> void", pybind11::arg(""));

	// foo_r(int &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(int &)) &foo_r, "C++: foo_r(int &) --> void", pybind11::arg(""));

	// foo_r(long &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(long &)) &foo_r, "C++: foo_r(long &) --> void", pybind11::arg(""));

	// foo_r(float &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(float &)) &foo_r, "C++: foo_r(float &) --> void", pybind11::arg(""));

	// foo_r(double &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(double &)) &foo_r, "C++: foo_r(double &) --> void", pybind11::arg(""));

	// foo_r(class A &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(class A &)) &foo_r, "C++: foo_r(class A &) --> void", pybind11::arg(""));

	// foo_r(class std::shared_ptr<class A> &) file:T02.function.hpp line:
	M("").def("foo_r", (void (*)(class std::shared_ptr<class A> &)) &foo_r, "C++: foo_r(class std::shared_ptr<class A> &) --> void", pybind11::arg(""));

	// foo_cr(const bool &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const bool &)) &foo_cr, "C++: foo_cr(const bool &) --> void", pybind11::arg(""));

	// foo_cr(const int &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const int &)) &foo_cr, "C++: foo_cr(const int &) --> void", pybind11::arg(""));

	// foo_cr(const long &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const long &)) &foo_cr, "C++: foo_cr(const long &) --> void", pybind11::arg(""));

	// foo_cr(const float &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const float &)) &foo_cr, "C++: foo_cr(const float &) --> void", pybind11::arg(""));

	// foo_cr(const double &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const double &)) &foo_cr, "C++: foo_cr(const double &) --> void", pybind11::arg(""));

	// foo_cr(const class A &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const class A &)) &foo_cr, "C++: foo_cr(const class A &) --> void", pybind11::arg(""));

	// foo_cr(const class std::shared_ptr<class A> &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const class std::shared_ptr<class A> &)) &foo_cr, "C++: foo_cr(const class std::shared_ptr<class A> &) --> void", pybind11::arg(""));

	// foo_cr(const class std::shared_ptr<const class A> &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const class std::shared_ptr<const class A> &)) &foo_cr, "C++: foo_cr(const class std::shared_ptr<const class A> &) --> void", pybind11::arg(""));

	// foo_cr(const struct std::pair<int, int> &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const struct std::pair<int, int> &)) &foo_cr, "C++: foo_cr(const struct std::pair<int, int> &) --> void", pybind11::arg(""));

	// foo_cr(const class std::tuple<int, int> &) file:T02.function.hpp line:
	M("").def("foo_cr", (void (*)(const class std::tuple<int, int> &)) &foo_cr, "C++: foo_cr(const class std::tuple<int, int> &) --> void", pybind11::arg(""));

	// foo_p(bool *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(bool *)) &foo_p, "C++: foo_p(bool *) --> void", pybind11::arg(""));

	// foo_p(int *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(int *)) &foo_p, "C++: foo_p(int *) --> void", pybind11::arg(""));

	// foo_p(long *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(long *)) &foo_p, "C++: foo_p(long *) --> void", pybind11::arg(""));

	// foo_p(float *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(float *)) &foo_p, "C++: foo_p(float *) --> void", pybind11::arg(""));

	// foo_p(double *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(double *)) &foo_p, "C++: foo_p(double *) --> void", pybind11::arg(""));

	// foo_p(class A *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(class A *)) &foo_p, "C++: foo_p(class A *) --> void", pybind11::arg(""));

	// foo_p(class std::shared_ptr<class A> *) file:T02.function.hpp line:
	M("").def("foo_p", (void (*)(class std::shared_ptr<class A> *)) &foo_p, "C++: foo_p(class std::shared_ptr<class A> *) --> void", pybind11::arg(""));

	// foo_f1(const class std::function<bool (const std::string &)> &) file:T02.function.hpp line:
	M("").def("foo_f1", (void (*)(const class std::function<bool (const std::string &)> &)) &foo_f1, "C++: foo_f1(const class std::function<bool (const std::string &)> &) --> void", pybind11::arg("f"));

	// foo_f2(const class std::function<void (*(void))(void)> &) file:T02.function.hpp line:
	M("").def("foo_f2", (void (*)(const class std::function<void (*(void))(void)> &)) &foo_f2, "C++: foo_f2(const class std::function<void (*(void))(void)> &) --> void", pybind11::arg("f"));

	// foo_f3(const class std::function<bool (void (**)(void), int (&)[1])> &) file:T02.function.hpp line:
	M("").def("foo_f3", (void (*)(const class std::function<bool (void (**)(void), int (&)[1])> &)) &foo_f3, "C++: foo_f3(const class std::function<bool (void (**)(void), int (&)[1])> &) --> void", pybind11::arg("f"));

	// foo_f5(void (&)(void)) file:T02.function.hpp line:
	M("").def("foo_f5", (void (*)(void (&)(void))) &foo_f5, "C++: foo_f5(void (&)(void)) --> void", pybind11::arg(""));

	// foo_f7(void (&)(void)) file:T02.function.hpp line:
	M("").def("foo_f7", (void (*)(void (&)(void))) &foo_f7, "C++: foo_f7(void (&)(void)) --> void", pybind11::arg(""));

	// foo_f8(void (&)(void)) file:T02.function.hpp line:
	M("").def("foo_f8", (void (*)(void (&)(void))) &foo_f8, "C++: foo_f8(void (&)(void)) --> void", pybind11::arg("f"));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T02_function(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T02_function, root_module) {
	root_module.doc() = "T02_function module";

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

	bind_T02_function(M);

}

// Source list file: TEST/T02_function.sources
// T02_function.cpp
// T02_function.cpp

// Modules list file: TEST/T02_function.modules
// 
