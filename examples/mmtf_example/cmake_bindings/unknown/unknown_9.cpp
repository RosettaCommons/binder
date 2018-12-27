#include <functional> // std::less
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::map
#include <memory> // std::allocator
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

void bind_unknown_unknown_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B266_[class std::map<class std::__cxx11::basic_string<char>, struct msgpack::v2::object, struct std::less<class std::__cxx11::basic_string<char> >, class std::allocator<struct std::pair<const class std::__cxx11::basic_string<char>, struct msgpack::v2::object> > > mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int)] ";
	// mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int) file: line:64
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("m_zone"));
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1, int const & a2) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1, int const & a2, int const & a3) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToMap", (class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > (*)(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int)) &mmtf::encodeToMap, "Encode an MMTF data structure into a map of msgpack objects.\n \n\n     MMTF data structure to be stored\n \n\n   msgpack::zone object to use\n \n\n             Object which can be modified and passed to msgpack::pack\n\n Other parameters and behavior are as in ::encodeToFile, but this enables you\n to add additional fields before packing.\n\nC++: mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int) --> class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > >", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

}
