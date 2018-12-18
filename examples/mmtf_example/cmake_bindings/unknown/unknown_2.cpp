#include <functional> // std::less
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::map
#include <memory> // std::allocator
#include <sstream> // __str__
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <utility> // std::pair
#include <vector> // std::vector

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B211_[msgpack::v1::object] ";
	{ // msgpack::v1::object file: line:75
		pybind11::class_<msgpack::v1::object, std::shared_ptr<msgpack::v1::object>> cl(M("msgpack::v1"), "object", "");
		pybind11::handle cl_type = cl;

		{ // msgpack::v1::object::union_type file: line:76
			auto & enclosing_class = cl;
			pybind11::class_<msgpack::v1::object::union_type, std::shared_ptr<msgpack::v1::object::union_type>> cl(enclosing_class, "union_type", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](msgpack::v1::object::union_type const &o){ return new msgpack::v1::object::union_type(o); } ) );
			cl.def( pybind11::init( [](){ return new msgpack::v1::object::union_type(); } ) );
			cl.def_readwrite("boolean", &msgpack::v1::object::union_type::boolean);
			cl.def_readwrite("u64", &msgpack::v1::object::union_type::u64);
			cl.def_readwrite("i64", &msgpack::v1::object::union_type::i64);
			cl.def_readwrite("f64", &msgpack::v1::object::union_type::f64);
			cl.def_readwrite("array", &msgpack::v1::object::union_type::array);
			cl.def_readwrite("map", &msgpack::v1::object::union_type::map);
			cl.def_readwrite("str", &msgpack::v1::object::union_type::str);
			cl.def_readwrite("bin", &msgpack::v1::object::union_type::bin);
			cl.def_readwrite("ext", &msgpack::v1::object::union_type::ext);
			cl.def("assign", (union msgpack::v1::object::union_type & (msgpack::v1::object::union_type::*)(const union msgpack::v1::object::union_type &)) &msgpack::v1::object::union_type::operator=, "C++: msgpack::v1::object::union_type::operator=(const union msgpack::v1::object::union_type &) --> union msgpack::v1::object::union_type &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		cl.def( pybind11::init( [](){ return new msgpack::v1::object(); } ) );
		cl.def( pybind11::init<const struct msgpack_object &>(), pybind11::arg("o") );

		cl.def( pybind11::init( [](msgpack::v1::object const &o){ return new msgpack::v1::object(o); } ) );
		cl.def_readwrite("type", &msgpack::v1::object::type);
		cl.def_readwrite("via", &msgpack::v1::object::via);
		cl.def("as", (bool (msgpack::v1::object::*)() const) &msgpack::v1::object::as<bool>, "C++: msgpack::v1::object::as() const --> bool");
		cl.def("convert", (class std::vector<int, class std::allocator<int> > & (msgpack::v1::object::*)(class std::vector<int, class std::allocator<int> > &) const) &msgpack::v1::object::convert<std::vector<int, std::allocator<int> >>, "C++: msgpack::v1::object::convert(class std::vector<int, class std::allocator<int> > &) const --> class std::vector<int, class std::allocator<int> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (int & (msgpack::v1::object::*)(int &) const) &msgpack::v1::object::convert<int>, "C++: msgpack::v1::object::convert(int &) const --> int &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (float & (msgpack::v1::object::*)(float &) const) &msgpack::v1::object::convert<float>, "C++: msgpack::v1::object::convert(float &) const --> float &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const --> class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::Transform & (msgpack::v1::object::*)(struct mmtf::Transform &) const) &msgpack::v1::object::convert<mmtf::Transform>, "C++: msgpack::v1::object::convert(struct mmtf::Transform &) const --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (std::string & (msgpack::v1::object::*)(std::string &) const) &msgpack::v1::object::convert<std::string>, "C++: msgpack::v1::object::convert(std::string &) const --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<std::string, class std::allocator<std::string > > & (msgpack::v1::object::*)(class std::vector<std::string, class std::allocator<std::string > > &) const) &msgpack::v1::object::convert<std::vector<std::string, std::allocator<std::string > >>, "C++: msgpack::v1::object::convert(class std::vector<std::string, class std::allocator<std::string > > &) const --> class std::vector<std::string, class std::allocator<std::string > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<signed char, class std::allocator<signed char> > & (msgpack::v1::object::*)(class std::vector<signed char, class std::allocator<signed char> > &) const) &msgpack::v1::object::convert<std::vector<signed char, std::allocator<signed char> >>, "C++: msgpack::v1::object::convert(class std::vector<signed char, class std::allocator<signed char> > &) const --> class std::vector<signed char, class std::allocator<signed char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (signed char & (msgpack::v1::object::*)(signed char &) const) &msgpack::v1::object::convert<signed char>, "C++: msgpack::v1::object::convert(signed char &) const --> signed char &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (char & (msgpack::v1::object::*)(char &) const) &msgpack::v1::object::convert<char>, "C++: msgpack::v1::object::convert(char &) const --> char &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<float, class std::allocator<float> > & (msgpack::v1::object::*)(class std::vector<float, class std::allocator<float> > &) const) &msgpack::v1::object::convert<std::vector<float, std::allocator<float> >>, "C++: msgpack::v1::object::convert(class std::vector<float, class std::allocator<float> > &) const --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > & (msgpack::v1::object::*)(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const) &msgpack::v1::object::convert<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: msgpack::v1::object::convert(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const --> class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const --> class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::BioAssembly & (msgpack::v1::object::*)(struct mmtf::BioAssembly &) const) &msgpack::v1::object::convert<mmtf::BioAssembly>, "C++: msgpack::v1::object::convert(struct mmtf::BioAssembly &) const --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const --> class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::Entity & (msgpack::v1::object::*)(struct mmtf::Entity &) const) &msgpack::v1::object::convert<mmtf::Entity>, "C++: msgpack::v1::object::convert(struct mmtf::Entity &) const --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > & (msgpack::v1::object::*)(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const) &msgpack::v1::object::convert<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>, "C++: msgpack::v1::object::convert(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const --> class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::GroupType & (msgpack::v1::object::*)(struct mmtf::GroupType &) const) &msgpack::v1::object::convert<mmtf::GroupType>, "C++: msgpack::v1::object::convert(struct mmtf::GroupType &) const --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<char, class std::allocator<char> > & (msgpack::v1::object::*)(class std::vector<char, class std::allocator<char> > &) const) &msgpack::v1::object::convert<std::vector<char, std::allocator<char> >>, "C++: msgpack::v1::object::convert(class std::vector<char, class std::allocator<char> > &) const --> class std::vector<char, class std::allocator<char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > & (msgpack::v1::object::*)(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const) &msgpack::v1::object::convert<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: msgpack::v1::object::convert(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const --> class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct msgpack::v2::object & (msgpack::v1::object::*)(struct msgpack::v2::object &) const) &msgpack::v1::object::convert<msgpack::v2::object>, "C++: msgpack::v1::object::convert(struct msgpack::v2::object &) const --> struct msgpack::v2::object &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::StructureData & (msgpack::v1::object::*)(struct mmtf::StructureData &) const) &msgpack::v1::object::convert<mmtf::StructureData>, "C++: msgpack::v1::object::convert(struct mmtf::StructureData &) const --> struct mmtf::StructureData &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (float * (msgpack::v1::object::*)(float *) const) &msgpack::v1::object::convert<float *>, "C++: msgpack::v1::object::convert(float *) const --> float *", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("assign", (struct msgpack::v1::object & (msgpack::v1::object::*)(const struct msgpack::v1::object &)) &msgpack::v1::object::operator=<msgpack::v1::object>, "C++: msgpack::v1::object::operator=(const struct msgpack::v1::object &) --> struct msgpack::v1::object &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("is_nil", (bool (msgpack::v1::object::*)() const) &msgpack::v1::object::is_nil, "C++: msgpack::v1::object::is_nil() const --> bool");
		cl.def("assign", (struct msgpack::v1::object & (msgpack::v1::object::*)(const struct msgpack::v1::object &)) &msgpack::v1::object::operator=, "C++: msgpack::v1::object::operator=(const struct msgpack::v1::object &) --> struct msgpack::v1::object &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B212_[msgpack::v1::type_error] ";
}
