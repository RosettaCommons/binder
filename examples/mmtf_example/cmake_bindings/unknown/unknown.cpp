#include <iostream> // --trace
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <mmtf.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B186_[msgpack::v1::zone] ";
	{ // msgpack::v1::zone file: line:27
		pybind11::class_<msgpack::v1::zone, std::shared_ptr<msgpack::v1::zone>> cl(M("msgpack::v1"), "zone", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new msgpack::v1::zone(); } ), "doc");
		cl.def( pybind11::init<unsigned long>(), pybind11::arg("chunk_size") );

		cl.def("allocate_align", [](msgpack::v1::zone &o, unsigned long const & a0) -> void * { return o.allocate_align(a0); }, "", pybind11::return_value_policy::automatic, pybind11::arg("size"));
		cl.def("allocate_align", (void * (msgpack::v1::zone::*)(unsigned long, unsigned long)) &msgpack::v1::zone::allocate_align, "C++: msgpack::v1::zone::allocate_align(unsigned long, unsigned long) --> void *", pybind11::return_value_policy::automatic, pybind11::arg("size"), pybind11::arg("align"));
		cl.def("allocate_no_align", (void * (msgpack::v1::zone::*)(unsigned long)) &msgpack::v1::zone::allocate_no_align, "C++: msgpack::v1::zone::allocate_no_align(unsigned long) --> void *", pybind11::return_value_policy::automatic, pybind11::arg("size"));
		cl.def("clear", (void (msgpack::v1::zone::*)()) &msgpack::v1::zone::clear, "C++: msgpack::v1::zone::clear() --> void");
		cl.def("swap", (void (msgpack::v1::zone::*)(class msgpack::v1::zone &)) &msgpack::v1::zone::swap, "C++: msgpack::v1::zone::swap(class msgpack::v1::zone &) --> void", pybind11::arg("o"));
	}
}
