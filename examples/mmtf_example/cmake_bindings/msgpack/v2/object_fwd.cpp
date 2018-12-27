#include <functional> // std::less
#include <ios> // std::_Ios_Seekdir
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <locale> // std::locale
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::map
#include <memory> // std::allocator
#include <msgpack/object.h> // msgpack_object
#include <msgpack/v1/detail/cpp11_zone.hpp> // msgpack::v1::zone
#include <msgpack/v1/object.hpp> // msgpack::v1::object
#include <msgpack/v1/object.hpp> // msgpack::v1::operator<<
#include <msgpack/v1/object_fwd.hpp> // msgpack::v1::object
#include <msgpack/v2/object_fwd.hpp> // msgpack::v2::object
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <utility> // std::pair
#include <vector> // std::vector

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

void bind_msgpack_v2_object_fwd(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B194_[msgpack::v2::object] ";
	{ // msgpack::v2::object file:msgpack/v2/object_fwd.hpp line:23
		pybind11::class_<msgpack::v2::object, std::shared_ptr<msgpack::v2::object>, msgpack::v1::object> cl(M("msgpack::v2"), "object", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new msgpack::v2::object(); } ) );
		cl.def( pybind11::init<const struct msgpack::v1::object &>(), pybind11::arg("o") );

		cl.def( pybind11::init( [](msgpack::v2::object const &o){ return new msgpack::v2::object(o); } ) );
		cl.def("convert", (std::string & (msgpack::v2::object::*)(std::string &) const) &msgpack::v2::object::convert<std::string>, "C++: msgpack::v2::object::convert(std::string &) const --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::StructureData & (msgpack::v2::object::*)(struct mmtf::StructureData &) const) &msgpack::v2::object::convert<mmtf::StructureData>, "C++: msgpack::v2::object::convert(struct mmtf::StructureData &) const --> struct mmtf::StructureData &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<int, class std::allocator<int> > & (msgpack::v2::object::*)(class std::vector<int, class std::allocator<int> > &) const) &msgpack::v2::object::convert<std::vector<int, std::allocator<int> >>, "C++: msgpack::v2::object::convert(class std::vector<int, class std::allocator<int> > &) const --> class std::vector<int, class std::allocator<int> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (int & (msgpack::v2::object::*)(int &) const) &msgpack::v2::object::convert<int>, "C++: msgpack::v2::object::convert(int &) const --> int &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (float & (msgpack::v2::object::*)(float &) const) &msgpack::v2::object::convert<float>, "C++: msgpack::v2::object::convert(float &) const --> float &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > & (msgpack::v2::object::*)(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const) &msgpack::v2::object::convert<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>, "C++: msgpack::v2::object::convert(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) const --> class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::Transform & (msgpack::v2::object::*)(struct mmtf::Transform &) const) &msgpack::v2::object::convert<mmtf::Transform>, "C++: msgpack::v2::object::convert(struct mmtf::Transform &) const --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<std::string, class std::allocator<std::string > > & (msgpack::v2::object::*)(class std::vector<std::string, class std::allocator<std::string > > &) const) &msgpack::v2::object::convert<std::vector<std::string, std::allocator<std::string > >>, "C++: msgpack::v2::object::convert(class std::vector<std::string, class std::allocator<std::string > > &) const --> class std::vector<std::string, class std::allocator<std::string > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<signed char, class std::allocator<signed char> > & (msgpack::v2::object::*)(class std::vector<signed char, class std::allocator<signed char> > &) const) &msgpack::v2::object::convert<std::vector<signed char, std::allocator<signed char> >>, "C++: msgpack::v2::object::convert(class std::vector<signed char, class std::allocator<signed char> > &) const --> class std::vector<signed char, class std::allocator<signed char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (signed char & (msgpack::v2::object::*)(signed char &) const) &msgpack::v2::object::convert<signed char>, "C++: msgpack::v2::object::convert(signed char &) const --> signed char &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (char & (msgpack::v2::object::*)(char &) const) &msgpack::v2::object::convert<char>, "C++: msgpack::v2::object::convert(char &) const --> char &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<float, class std::allocator<float> > & (msgpack::v2::object::*)(class std::vector<float, class std::allocator<float> > &) const) &msgpack::v2::object::convert<std::vector<float, std::allocator<float> >>, "C++: msgpack::v2::object::convert(class std::vector<float, class std::allocator<float> > &) const --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > & (msgpack::v2::object::*)(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const) &msgpack::v2::object::convert<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: msgpack::v2::object::convert(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) const --> class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > & (msgpack::v2::object::*)(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const) &msgpack::v2::object::convert<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: msgpack::v2::object::convert(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) const --> class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::BioAssembly & (msgpack::v2::object::*)(struct mmtf::BioAssembly &) const) &msgpack::v2::object::convert<mmtf::BioAssembly>, "C++: msgpack::v2::object::convert(struct mmtf::BioAssembly &) const --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > & (msgpack::v2::object::*)(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const) &msgpack::v2::object::convert<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: msgpack::v2::object::convert(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) const --> class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::Entity & (msgpack::v2::object::*)(struct mmtf::Entity &) const) &msgpack::v2::object::convert<mmtf::Entity>, "C++: msgpack::v2::object::convert(struct mmtf::Entity &) const --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > & (msgpack::v2::object::*)(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const) &msgpack::v2::object::convert<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>, "C++: msgpack::v2::object::convert(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) const --> class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct mmtf::GroupType & (msgpack::v2::object::*)(struct mmtf::GroupType &) const) &msgpack::v2::object::convert<mmtf::GroupType>, "C++: msgpack::v2::object::convert(struct mmtf::GroupType &) const --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::vector<char, class std::allocator<char> > & (msgpack::v2::object::*)(class std::vector<char, class std::allocator<char> > &) const) &msgpack::v2::object::convert<std::vector<char, std::allocator<char> >>, "C++: msgpack::v2::object::convert(class std::vector<char, class std::allocator<char> > &) const --> class std::vector<char, class std::allocator<char> > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > & (msgpack::v2::object::*)(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const) &msgpack::v2::object::convert<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: msgpack::v2::object::convert(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) const --> class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("convert", (struct msgpack::v2::object & (msgpack::v2::object::*)(struct msgpack::v2::object &) const) &msgpack::v2::object::convert<msgpack::v2::object>, "C++: msgpack::v2::object::convert(struct msgpack::v2::object &) const --> struct msgpack::v2::object &", pybind11::return_value_policy::automatic, pybind11::arg("v"));
		cl.def("assign", (struct msgpack::v2::object & (msgpack::v2::object::*)(const struct msgpack::v2::object &)) &msgpack::v2::object::operator=, "C++: msgpack::v2::object::operator=(const struct msgpack::v2::object &) --> struct msgpack::v2::object &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](msgpack::v2::object const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}
