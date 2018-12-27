#include <fstream> // std::basic_filebuf
#include <fstream> // std::basic_ifstream
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits

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

void bind_unknown_unknown_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B245_[void mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long)] ";
	// mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long) file: line:34
	M("mmtf").def("decodeFromBuffer", (void (*)(struct mmtf::StructureData &, const char *, unsigned long)) &mmtf::decodeFromBuffer, "Decode an MMTF data structure from a byte buffer.\n \n\n   MMTF data structure to be filled\n \n\n File contents\n \n\n   Size of buffer\n \n\n mmtf::DecodeError if an error occured\n\nC++: mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long) --> void", pybind11::arg("data"), pybind11::arg("buffer"), pybind11::arg("size"));

	std::cout << "B246_[void mmtf::decodeFromStream<std::basic_ifstream<char>>(struct mmtf::StructureData &, class std::basic_ifstream<char> &)] ";
	// mmtf::decodeFromStream(struct mmtf::StructureData &, class std::basic_ifstream<char> &) file: line:71
	M("mmtf").def("decodeFromStream", (void (*)(struct mmtf::StructureData &, class std::basic_ifstream<char> &)) &mmtf::decodeFromStream<std::basic_ifstream<char>>, "C++: mmtf::decodeFromStream(struct mmtf::StructureData &, class std::basic_ifstream<char> &) --> void", pybind11::arg("data"), pybind11::arg("stream"));

	std::cout << "B247_[void mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &)] ";
	// mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &) file: line:55
	M("mmtf").def("decodeFromFile", (void (*)(struct mmtf::StructureData &, const std::string &)) &mmtf::decodeFromFile, "Decode an MMTF data structure from an existing file.\n \n\n     MMTF data structure to be filled\n \n\n Path to file to load\n \n\n mmtf::DecodeError if an error occured\n\nC++: mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &) --> void", pybind11::arg("data"), pybind11::arg("filename"));

}
