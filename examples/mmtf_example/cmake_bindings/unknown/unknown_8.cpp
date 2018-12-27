#include <fstream> // std::basic_filebuf
#include <fstream> // std::basic_ofstream
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // std::__cxx11::basic_stringbuf
#include <sstream> // std::__cxx11::basic_stringstream
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
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

void bind_unknown_unknown_8(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B248_[class std::vector<int, class std::allocator<int> > mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) file: line:40
	M("mmtf").def("convertFloatsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::convertFloatsToInts, "Convert floats to ints via multiplier.\n \n\n        vector of floats\n \n\n    multiply float vector by this\n \n\n vec_out          vec_in * multiplier and rounded\n\nC++: mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("multiplier"));

	std::cout << "B249_[class std::vector<int, class std::allocator<int> > mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &) file: line:48
	M("mmtf").def("deltaEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::deltaEncode, "mmtf delta encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          delta encoded int vector\n\nC++: mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B250_[class std::vector<int, class std::allocator<int> > mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) file: line:56
	M("mmtf").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B251_[class std::vector<int, class std::allocator<int> > mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:63
	M("mmtf").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B252_[class std::vector<int, class std::allocator<int> > mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int)] ";
	// mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) file: line:72
	M("mmtf").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0) -> std::vector<int, class std::allocator<int> > { return mmtf::recursiveIndexEncode(a0); }, "", pybind11::arg("vec_in"));
	M("mmtf").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0, int const & a1) -> std::vector<int, class std::allocator<int> > { return mmtf::recursiveIndexEncode(a0, a1); }, "", pybind11::arg("vec_in"), pybind11::arg("max"));
	M("mmtf").def("recursiveIndexEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &, int, int)) &mmtf::recursiveIndexEncode, "mmtf recursive index encode a vector of ints.\n \n\n        vector of ints\n \n\n           maximum value of signed 16bit int\n \n\n           minimum value of signed 16bit int\n \n\n vec_out          recursive index encoded vector\n\nC++: mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("max"), pybind11::arg("min"));

	std::cout << "B253_[class std::vector<int, class std::allocator<int> > mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) file: line:80
	M("mmtf").def("convertCharsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::convertCharsToInts, "mmtf convert char to int\n \n\n        vector of chars\n \n\n vec_out          vector of ints\n\nC++: mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B254_[void mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)] ";
	// mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) file: line:90
	M("mmtf").def("add_header", [](class std::__cxx11::basic_stringstream<char> & a0, unsigned int const & a1, unsigned int const & a2) -> void { return mmtf::add_header(a0, a1, a2); }, "", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"));
	M("mmtf").def("add_header", (void (*)(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)) &mmtf::add_header, "Add mmtf header to a stream\n \n\n            stringstream to add a header to\n \n\n    size of array you're adding\n \n\n         the codec type number you're using to encode\n \n\n         the param for the codec you're using (default 0)\n\nC++: mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) --> void", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"), pybind11::arg("param"));

	std::cout << "B255_[class std::vector<char, class std::allocator<char> > mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &)] ";
	// mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &) file: line:97
	M("mmtf").def("stringstreamToCharVector", (class std::vector<char, class std::allocator<char> > (*)(class std::basic_stringstream<char> &)) &mmtf::stringstreamToCharVector, "Convert stringstream to CharVector\n \n\n            ss to convert\n \n\n                  converted ss\n\nC++: mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("ss"));

	std::cout << "B256_[class std::vector<char, class std::allocator<char> > mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) file: line:109
	M("mmtf").def("encodeInt8ToByte", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeInt8ToByte, "encode 8 bit int to bytes encoding (type 2)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B257_[class std::vector<char, class std::allocator<char> > mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) file: line:115
	M("mmtf").def("encodeFourByteInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeFourByteInt, "encode 4 bytes to int encoding (type 4)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B258_[class std::vector<char, class std::allocator<char> > mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int)] ";
	// mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) file: line:122
	M("mmtf").def("encodeStringVector", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<std::string, class std::allocator<std::string > >, int)) &mmtf::encodeStringVector, "encode string vector encoding (type 5)\n \n\n         vector of strings\n \n\n     maximum length of string\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_sv"), pybind11::arg("CHAIN_LEN"));

	std::cout << "B259_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >)] ";
	// mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) file: line:129
	M("mmtf").def("encodeRunLengthChar", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<char, class std::allocator<char> >)) &mmtf::encodeRunLengthChar, "encode Run Length Char encoding (type 6)\n \n\n         vector for chars\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_cv"));

	std::cout << "B260_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) file: line:136
	M("mmtf").def("encodeRunLengthDeltaInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeRunLengthDeltaInt, "encode Run Length Delta Int encoding (type 8)\n \n\n       vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int_vec"));

	std::cout << "B261_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) file: line:143
	M("mmtf").def("encodeRunLengthFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeRunLengthFloat, "encode Run Length Float encoding (type 9)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B262_[class std::vector<char, class std::allocator<char> > mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) file: line:150
	M("mmtf").def("encodeDeltaRecursiveFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeDeltaRecursiveFloat, "encode Delta Recursive Float encoding (type 10)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B263_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) file: line:156
	M("mmtf").def("encodeRunLengthInt8", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeRunLengthInt8, "encode Run-Length 8bit int encoding (type 16)\n \n\n     vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int8_vec"));

	std::cout << "B264_[void mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int)] ";
	// mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) file: line:36
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1) -> void { return mmtf::encodeToFile(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("filename"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2) -> void { return mmtf::encodeToFile(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToFile(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToFile", (void (*)(const struct mmtf::StructureData &, const std::string &, int, int, int)) &mmtf::encodeToFile, "Encode an MMTF data structure into a file.\n \n\n          MMTF data structure to be stored\n \n\n      Path to file to load\n \n\n               Divisor for coordinates\n \n\n  Divisor for occupancy and b-factor\n \n\n       Max. length for chain name strings\n \n\n mmtf::EncodeError if an error occurred\n\n Common settings for the divisors are the default values for a loss-less\n encoding and both set to 10 for a lossy variant.\n\nC++: mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

	std::cout << "B265_[void mmtf::encodeToStream<std::basic_ofstream<char>>(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)] ";
	// mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) file: line:50
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1) -> void { return mmtf::encodeToStream(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("stream"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2) -> void { return mmtf::encodeToStream(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToStream(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToStream", (void (*)(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)) &mmtf::encodeToStream<std::basic_ofstream<char>>, "C++: mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

}
