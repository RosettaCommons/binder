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

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown_11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B267_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::(anonymous namespace)::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) file: line:40
	M("mmtf::(anonymous namespace)").def("convertFloatsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::(anonymous namespace)::convertFloatsToInts, "Convert floats to ints via multiplier.\n \n\n        vector of floats\n \n\n    multiply float vector by this\n \n\n vec_out          vec_in * multiplier and rounded\n\nC++: mmtf::(anonymous namespace)::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("multiplier"));

	std::cout << "B268_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::deltaEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::(anonymous namespace)::deltaEncode(const class std::vector<int, class std::allocator<int> > &) file: line:48
	M("mmtf::(anonymous namespace)").def("deltaEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::(anonymous namespace)::deltaEncode, "mmtf delta encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          delta encoded int vector\n\nC++: mmtf::(anonymous namespace)::deltaEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B269_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) file: line:56
	M("mmtf::(anonymous namespace)").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::(anonymous namespace)::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B270_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:63
	M("mmtf::(anonymous namespace)").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::(anonymous namespace)::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::(anonymous namespace)::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B271_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int)] ";
	// mmtf::(anonymous namespace)::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) file: line:72
	M("mmtf::(anonymous namespace)").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0) -> std::vector<int, class std::allocator<int> > { return mmtf::(anonymous namespace)::recursiveIndexEncode(a0); }, "", pybind11::arg("vec_in"));
	M("mmtf::(anonymous namespace)").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0, int const & a1) -> std::vector<int, class std::allocator<int> > { return mmtf::(anonymous namespace)::recursiveIndexEncode(a0, a1); }, "", pybind11::arg("vec_in"), pybind11::arg("max"));
	M("mmtf::(anonymous namespace)").def("recursiveIndexEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &, int, int)) &mmtf::(anonymous namespace)::recursiveIndexEncode, "mmtf recursive index encode a vector of ints.\n \n\n        vector of ints\n \n\n           maximum value of signed 16bit int\n \n\n           minimum value of signed 16bit int\n \n\n vec_out          recursive index encoded vector\n\nC++: mmtf::(anonymous namespace)::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("max"), pybind11::arg("min"));

	std::cout << "B272_[class std::vector<int, class std::allocator<int> > mmtf::(anonymous namespace)::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::(anonymous namespace)::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) file: line:80
	M("mmtf::(anonymous namespace)").def("convertCharsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::(anonymous namespace)::convertCharsToInts, "mmtf convert char to int\n \n\n        vector of chars\n \n\n vec_out          vector of ints\n\nC++: mmtf::(anonymous namespace)::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B273_[void mmtf::(anonymous namespace)::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)] ";
	// mmtf::(anonymous namespace)::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) file: line:90
	M("mmtf::(anonymous namespace)").def("add_header", [](class std::__cxx11::basic_stringstream<char> & a0, unsigned int const & a1, unsigned int const & a2) -> void { return mmtf::(anonymous namespace)::add_header(a0, a1, a2); }, "", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"));
	M("mmtf::(anonymous namespace)").def("add_header", (void (*)(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)) &mmtf::(anonymous namespace)::add_header, "Add mmtf header to a stream\n \n\n            stringstream to add a header to\n \n\n    size of array you're adding\n \n\n         the codec type number you're using to encode\n \n\n         the param for the codec you're using (default 0)\n\nC++: mmtf::(anonymous namespace)::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) --> void", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"), pybind11::arg("param"));

	std::cout << "B274_[class std::vector<char, class std::allocator<char> > mmtf::(anonymous namespace)::stringstreamToCharVector(class std::basic_stringstream<char> &)] ";
	// mmtf::(anonymous namespace)::stringstreamToCharVector(class std::basic_stringstream<char> &) file: line:97
	M("mmtf::(anonymous namespace)").def("stringstreamToCharVector", (class std::vector<char, class std::allocator<char> > (*)(class std::basic_stringstream<char> &)) &mmtf::(anonymous namespace)::stringstreamToCharVector, "Convert stringstream to CharVector\n \n\n            ss to convert\n \n\n                  converted ss\n\nC++: mmtf::(anonymous namespace)::stringstreamToCharVector(class std::basic_stringstream<char> &) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("ss"));

}
