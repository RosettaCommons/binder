#include <test_struct/test_struct.hpp>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_test_struct_test_struct(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// testers::(anonymous namespace)::print_an_int(const int &) file:test_struct/test_struct.hpp line:15
	M("testers::(anonymous namespace)").def("print_an_int", (void (*)(const int &)) &testers::(anonymous namespace)::print_an_int, "C++: testers::(anonymous namespace)::print_an_int(const int &) --> void", pybind11::arg("myint"));

}
