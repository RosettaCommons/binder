#include <fstream> // std::basic_filebuf
#include <fstream> // std::basic_ofstream
#include <functional> // std::less
#include <ios> // std::_Ios_Openmode
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

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown_12(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B275_[class std::vector<char, class std::allocator<char> > mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) file: line:109
	M("mmtf").def("encodeInt8ToByte", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeInt8ToByte, "encode 8 bit int to bytes encoding (type 2)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B276_[class std::vector<char, class std::allocator<char> > mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) file: line:115
	M("mmtf").def("encodeFourByteInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeFourByteInt, "encode 4 bytes to int encoding (type 4)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B277_[class std::vector<char, class std::allocator<char> > mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int)] ";
	// mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) file: line:122
	M("mmtf").def("encodeStringVector", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<std::string, class std::allocator<std::string > >, int)) &mmtf::encodeStringVector, "encode string vector encoding (type 5)\n \n\n         vector of strings\n \n\n     maximum length of string\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_sv"), pybind11::arg("CHAIN_LEN"));

	std::cout << "B278_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >)] ";
	// mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) file: line:129
	M("mmtf").def("encodeRunLengthChar", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<char, class std::allocator<char> >)) &mmtf::encodeRunLengthChar, "encode Run Length Char encoding (type 6)\n \n\n         vector for chars\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_cv"));

	std::cout << "B279_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) file: line:136
	M("mmtf").def("encodeRunLengthDeltaInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeRunLengthDeltaInt, "encode Run Length Delta Int encoding (type 8)\n \n\n       vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int_vec"));

	std::cout << "B280_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) file: line:143
	M("mmtf").def("encodeRunLengthFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeRunLengthFloat, "encode Run Length Float encoding (type 9)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B281_[class std::vector<char, class std::allocator<char> > mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) file: line:150
	M("mmtf").def("encodeDeltaRecursiveFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeDeltaRecursiveFloat, "encode Delta Recursive Float encoding (type 10)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B282_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) file: line:156
	M("mmtf").def("encodeRunLengthInt8", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeRunLengthInt8, "encode Run-Length 8bit int encoding (type 16)\n \n\n     vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int8_vec"));

	std::cout << "B283_[void mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int)] ";
	// mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) file: line:36
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1) -> void { return mmtf::encodeToFile(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("filename"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2) -> void { return mmtf::encodeToFile(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToFile(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToFile", (void (*)(const struct mmtf::StructureData &, const std::string &, int, int, int)) &mmtf::encodeToFile, "Encode an MMTF data structure into a file.\n \n\n          MMTF data structure to be stored\n \n\n      Path to file to load\n \n\n               Divisor for coordinates\n \n\n  Divisor for occupancy and b-factor\n \n\n       Max. length for chain name strings\n \n\n mmtf::EncodeError if an error occurred\n\n Common settings for the divisors are the default values for a loss-less\n encoding and both set to 10 for a lossy variant.\n\nC++: mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

	std::cout << "B284_[void mmtf::encodeToStream<std::basic_ofstream<char>>(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)] ";
	// mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) file: line:50
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1) -> void { return mmtf::encodeToStream(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("stream"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2) -> void { return mmtf::encodeToStream(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToStream(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToStream", (void (*)(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)) &mmtf::encodeToStream<std::basic_ofstream<char>>, "C++: mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

	std::cout << "B285_[class std::map<class std::__cxx11::basic_string<char>, struct msgpack::v2::object, struct std::less<class std::__cxx11::basic_string<char> >, class std::allocator<struct std::pair<const class std::__cxx11::basic_string<char>, struct msgpack::v2::object> > > mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int)] ";
	// mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int) file: line:64
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("m_zone"));
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1, int const & a2) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToMap", [](const struct mmtf::StructureData & a0, class msgpack::v1::zone & a1, int const & a2, int const & a3) -> std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > { return mmtf::encodeToMap(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToMap", (class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > (*)(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int)) &mmtf::encodeToMap, "Encode an MMTF data structure into a map of msgpack objects.\n \n\n     MMTF data structure to be stored\n \n\n   msgpack::zone object to use\n \n\n             Object which can be modified and passed to msgpack::pack\n\n Other parameters and behavior are as in ::encodeToFile, but this enables you\n to add additional fields before packing.\n\nC++: mmtf::encodeToMap(const struct mmtf::StructureData &, class msgpack::v1::zone &, int, int, int) --> class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > >", pybind11::arg("data"), pybind11::arg("m_zone"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

}
