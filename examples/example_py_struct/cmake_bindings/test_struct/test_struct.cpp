#include <iterator>
#include <memory>
#include <sstream> // __str__
#include <string>
#include <test_struct/test_struct.hpp>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <test_struct/binders.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_test_struct_test_struct(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // testers::test_my_struct file:test_struct/test_struct.hpp line:10
		pybind11::class_<testers::test_my_struct, std::shared_ptr<testers::test_my_struct>> cl(M("testers"), "test_my_struct", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new testers::test_my_struct(); } ) );
		cl.def_readwrite("an_int", &testers::test_my_struct::an_int);
		cl.def_readwrite("a_string", &testers::test_my_struct::a_string);
		cl.def_readwrite("a_vector", &testers::test_my_struct::a_vector);
		cl.def_readwrite("a_float", &testers::test_my_struct::a_float);
		cl.def("increment_int", (void (testers::test_my_struct::*)()) &testers::test_my_struct::increment_int, "C++: testers::test_my_struct::increment_int() --> void");
		cl.def("add_float", (void (testers::test_my_struct::*)()) &testers::test_my_struct::add_float, "C++: testers::test_my_struct::add_float() --> void");
		cl.def("append_vec", (void (testers::test_my_struct::*)()) &testers::test_my_struct::append_vec, "C++: testers::test_my_struct::append_vec() --> void");
	}
	// testers::thingy file:test_struct/test_struct.hpp line:40
	pybind11::detail::type_caster<testers::thingy>(M("testers"));

	// testers::get_thing(struct testers::thingy &) file:test_struct/test_struct.hpp line:47
	M("testers").def("get_thing", (struct testers::thingy (*)(struct testers::thingy &)) &testers::get_thing, "C++: testers::get_thing(struct testers::thingy &) --> struct testers::thingy", pybind11::arg("x"));

}
