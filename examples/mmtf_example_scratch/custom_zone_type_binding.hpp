
#ifndef _INCLUDED_std_binders_hpp_
#define _INCLUDED_std_binders_hpp_

#include <pybind11/stl_bind.h>

namespace my_binders {

template <typename T, class Allocator>
class msgpack_union_binder
{
public:
	msgpack_union_binder(pybind11::module &m, std::string const &name, std::string const & /*allocator name*/)
	{
		pybind11::class_<msgpack::v1::object::union_type, std::shared_ptr<msgpack::v1::object::union_type>> cl(m, "union_type", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](msgpack::v1::object::union_type const &o){ return new msgpack::v1::object::union_type(o); } ) );
		cl.def( pybind11::init( [](){ return new msgpack::v1::object::union_type(); } ) );
		/* cl.def_readwrite("boolean", &msgpack::v1::object::union_type::boolean); */
		/* cl.def_readwrite("u64", &msgpack::v1::object::union_type::u64); */
		/* cl.def_readwrite("i64", &msgpack::v1::object::union_type::i64); */
		/* cl.def_readwrite("f64", &msgpack::v1::object::union_type::f64); */
		/* cl.def_readwrite("array", &msgpack::v1::object::union_type::array); */
		/* cl.def_readwrite("map", &msgpack::v1::object::union_type::map); */
		/* cl.def_readwrite("str", &msgpack::v1::object::union_type::str); */
		/* cl.def_readwrite("bin", &msgpack::v1::object::union_type::bin); */
		/* cl.def_readwrite("ext", &msgpack::v1::object::union_type::ext); */
		/* cl.def("assign", (union msgpack::v1::object::union_type & (msgpack::v1::object::union_type::*)(const union msgpack::v1::object::union_type &)) &msgpack::v1::object::union_type::operator=, "C++: msgpack::v1::object::union_type::operator=(const union msgpack::v1::object::union_type &) --> union msgpack::v1::object::union_type &", pybind11::return_value_policy::automatic, pybind11::arg("")); */
	}
};

/* 	cl.def( pybind11::init( [](){ return new msgpack::v1::object(); } ) ); */
/* 	cl.def( pybind11::init<const struct msgpack_object &>(), pybind11::arg("o") ); */

/* 	cl.def( pybind11::init( [](msgpack::v1::object const &o){ return new msgpack::v1::object(o); } ) ); */
/* 	cl.def_readwrite("type", &msgpack::v1::object::type); */
/* 	cl.def_readwrite("via", &msgpack::v1::object::via); */
/* 	cl.def("as", (bool (msgpack::v1::object::*)() const) &msgpack::v1::object::as<bool>, "C++: msgpack::v1::object::as() const --> bool"); */
/* 	cl.def("as", (wchar_t (msgpack::v1::object::*)() const) &msgpack::v1::object::as<wchar_t>, "C++: msgpack::v1::object::as() const --> wchar_t"); */
/* 	cl.def("convert", (wchar_t & (msgpack::v1::object::*)(wchar_t &) const) &msgpack::v1::object::convert<wchar_t>, "C++: msgpack::v1::object::convert(wchar_t &) const --> wchar_t &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<int, class std::allocator<int> > & (msgpack::v1::object::*)(class std::vector<int, class std::allocator<int> > &) const) &msgpack::v1::object::convert<std::vector<int, std::allocator<int> >>, "C++: msgpack::v1::object::convert(class std::vector<int, class std::allocator<int> > &) const --> class std::vector<int, class std::allocator<int> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (int & (msgpack::v1::object::*)(int &) const) &msgpack::v1::object::convert<int>, "C++: msgpack::v1::object::convert(int &) const --> int &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (float & (msgpack::v1::object::*)(float &) const) &msgpack::v1::object::convert<float>, "C++: msgpack::v1::object::convert(float &) const --> float &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const --> class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct mmtf::Transform & (msgpack::v1::object::*)(struct mmtf::Transform &) const) &msgpack::v1::object::convert<mmtf::Transform>, "C++: msgpack::v1::object::convert(struct mmtf::Transform &) const --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > & (msgpack::v1::object::*)(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const) &msgpack::v1::object::convert<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: msgpack::v1::object::convert(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const --> class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct msgpack::v2::object & (msgpack::v1::object::*)(struct msgpack::v2::object &) const) &msgpack::v1::object::convert<msgpack::v2::object>, "C++: msgpack::v1::object::convert(struct msgpack::v2::object &) const --> struct msgpack::v2::object &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (std::string & (msgpack::v1::object::*)(std::string &) const) &msgpack::v1::object::convert<std::string>, "C++: msgpack::v1::object::convert(std::string &) const --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<std::string, class std::allocator<std::string > > & (msgpack::v1::object::*)(class std::vector<std::string, class std::allocator<std::string > > &) const) &msgpack::v1::object::convert<std::vector<std::string, std::allocator<std::string > >>, "C++: msgpack::v1::object::convert(class std::vector<std::string, class std::allocator<std::string > > &) const --> class std::vector<std::string, class std::allocator<std::string > > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<signed char, class std::allocator<signed char> > & (msgpack::v1::object::*)(class std::vector<signed char, class std::allocator<signed char> > &) const) &msgpack::v1::object::convert<std::vector<signed char, std::allocator<signed char> >>, "C++: msgpack::v1::object::convert(class std::vector<signed char, class std::allocator<signed char> > &) const --> class std::vector<signed char, class std::allocator<signed char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (signed char & (msgpack::v1::object::*)(signed char &) const) &msgpack::v1::object::convert<signed char>, "C++: msgpack::v1::object::convert(signed char &) const --> signed char &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (char & (msgpack::v1::object::*)(char &) const) &msgpack::v1::object::convert<char>, "C++: msgpack::v1::object::convert(char &) const --> char &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<float, class std::allocator<float> > & (msgpack::v1::object::*)(class std::vector<float, class std::allocator<float> > &) const) &msgpack::v1::object::convert<std::vector<float, std::allocator<float> >>, "C++: msgpack::v1::object::convert(class std::vector<float, class std::allocator<float> > &) const --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > & (msgpack::v1::object::*)(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const) &msgpack::v1::object::convert<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: msgpack::v1::object::convert(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const --> class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const --> class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct mmtf::BioAssembly & (msgpack::v1::object::*)(struct mmtf::BioAssembly &) const) &msgpack::v1::object::convert<mmtf::BioAssembly>, "C++: msgpack::v1::object::convert(struct mmtf::BioAssembly &) const --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const --> class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct mmtf::Entity & (msgpack::v1::object::*)(struct mmtf::Entity &) const) &msgpack::v1::object::convert<mmtf::Entity>, "C++: msgpack::v1::object::convert(struct mmtf::Entity &) const --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const --> class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct mmtf::GroupType & (msgpack::v1::object::*)(struct mmtf::GroupType &) const) &msgpack::v1::object::convert<mmtf::GroupType>, "C++: msgpack::v1::object::convert(struct mmtf::GroupType &) const --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (class std::vector<char, class std::allocator<char> > & (msgpack::v1::object::*)(class std::vector<char, class std::allocator<char> > &) const) &msgpack::v1::object::convert<std::vector<char, std::allocator<char> >>, "C++: msgpack::v1::object::convert(class std::vector<char, class std::allocator<char> > &) const --> class std::vector<char, class std::allocator<char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (struct mmtf::StructureData & (msgpack::v1::object::*)(struct mmtf::StructureData &) const) &msgpack::v1::object::convert<mmtf::StructureData>, "C++: msgpack::v1::object::convert(struct mmtf::StructureData &) const --> struct mmtf::StructureData &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("convert", (float * (msgpack::v1::object::*)(float *) const) &msgpack::v1::object::convert<float *>, "C++: msgpack::v1::object::convert(float *) const --> float *", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("assign", (struct msgpack::v1::object & (msgpack::v1::object::*)(const struct msgpack::v1::object &)) &msgpack::v1::object::operator=<msgpack::v1::object>, "C++: msgpack::v1::object::operator=(const struct msgpack::v1::object &) --> struct msgpack::v1::object &", pybind11::return_value_policy::automatic, pybind11::arg("v")); */
/* 	cl.def("is_nil", (bool (msgpack::v1::object::*)() const) &msgpack::v1::object::is_nil, "Cheking nil\n\n \n If the object is nil, then return true, else return false.\n\nC++: msgpack::v1::object::is_nil() const --> bool"); */
/* 	cl.def("assign", (struct msgpack::v1::object & (msgpack::v1::object::*)(const struct msgpack::v1::object &)) &msgpack::v1::object::operator=, "C++: msgpack::v1::object::operator=(const struct msgpack::v1::object &) --> struct msgpack::v1::object &", pybind11::return_value_policy::automatic, pybind11::arg("")); */
/* } */

/* template <typename T, class Allocator> */
/* class msgpack_object_binder */
/* { */

/* public: */
/* 	msgpack_object_binder(pybind11::module &m, std::string const &name, std::string const & /*allocator name*/) */
/* 	{ */
/* 		pybind11::class_<msgpack::v1::object, std::shared_ptr<msgpack::v1::object>> cl(M("msgpack::v1"), "object", */
/* 				"Object class that corresponding to MessagePack format object\n\n See https://github.com/msgpack/msgpack-c/wiki/v1_1_cpp_object"); */
/* 		pybind11::handle cl_type = cl; */


/* 		//cl.def(pybind11::init<size_type>()); */
/* 		//cl.def("resize", (void (Vector::*) (size_type count)) & Vector::resize, "changes the number of elements stored"); */

/* 		cl.def("empty",         &Vector::empty,         "checks whether the container is empty"); */
/* 		cl.def("max_size",      &Vector::max_size,      "returns the maximum possible number of elements"); */
/* 		cl.def("reserve",       &Vector::reserve,       "reserves storage"); */
/* 		cl.def("capacity",      &Vector::capacity,      "returns the number of elements that can be held in currently allocated storage"); */
/* 		cl.def("shrink_to_fit", &Vector::shrink_to_fit, "reduces memory usage by freeing unused memory"); */
/* 		cl.def("clear",         &Vector::clear,         "clears the contents"); */
/* 		cl.def("swap",          (void (Vector::*)(Vector &)) &Vector::swap,          "swaps the contents"); */



/* 		// cl.def("front", [](Vector &v) { */
/* 		// 		if (v.size()) return v.front(); */
/* 		// 		else throw pybind11::index_error(); */
/* 		// 	}, "access the first element"); */
/* 		// cl.def("back", [](Vector &v) { */
/* 		// 		if (v.size()) return v.back(); */
/* 		// 		else throw pybind11::index_error(); */
/* 		// 	}, "access the last element "); */
/* 	} */
/* }; */

} // my_binders

#endif // _INCLUDED_std_binders_hpp_
