#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
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

void bind_unknown_unknown_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B246_[bool mmtf::(anonymous namespace)::isValidDateFormatOptional(const std::string &)] ";
	// mmtf::(anonymous namespace)::isValidDateFormatOptional(const std::string &) file: line:328
	M("mmtf::(anonymous namespace)").def("isValidDateFormatOptional", (bool (*)(const std::string &)) &mmtf::(anonymous namespace)::isValidDateFormatOptional, "C++: mmtf::(anonymous namespace)::isValidDateFormatOptional(const std::string &) --> bool", pybind11::arg("s"));

	std::cout << "B247_[bool mmtf::(anonymous namespace)::hasRightSizeOptional<float>(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) file: line:348
	M("mmtf::(anonymous namespace)").def("hasRightSizeOptional", (bool (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::(anonymous namespace)::hasRightSizeOptional<float>, "C++: mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B248_[bool mmtf::(anonymous namespace)::hasRightSizeOptional<int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) file: line:348
	M("mmtf::(anonymous namespace)").def("hasRightSizeOptional", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::(anonymous namespace)::hasRightSizeOptional<int>, "C++: mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B249_[bool mmtf::(anonymous namespace)::hasRightSizeOptional<char>(const class std::vector<char, class std::allocator<char> > &, int)] ";
	// mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) file: line:348
	M("mmtf::(anonymous namespace)").def("hasRightSizeOptional", (bool (*)(const class std::vector<char, class std::allocator<char> > &, int)) &mmtf::(anonymous namespace)::hasRightSizeOptional<char>, "C++: mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B250_[bool mmtf::(anonymous namespace)::hasRightSizeOptional<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &, int)] ";
	// mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) file: line:348
	M("mmtf::(anonymous namespace)").def("hasRightSizeOptional", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &, int)) &mmtf::(anonymous namespace)::hasRightSizeOptional<signed char>, "C++: mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B251_[bool mmtf::(anonymous namespace)::hasRightSizeOptional<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &, int)] ";
	// mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) file: line:348
	M("mmtf::(anonymous namespace)").def("hasRightSizeOptional", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &, int)) &mmtf::(anonymous namespace)::hasRightSizeOptional<std::string>, "C++: mmtf::(anonymous namespace)::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B252_[bool mmtf::(anonymous namespace)::hasValidIndices<int,int>(const int *, unsigned long, int)] ";
	// mmtf::(anonymous namespace)::hasValidIndices(const int *, unsigned long, int) file: line:354
	M("mmtf::(anonymous namespace)").def("hasValidIndices", (bool (*)(const int *, unsigned long, int)) &mmtf::(anonymous namespace)::hasValidIndices<int,int>, "C++: mmtf::(anonymous namespace)::hasValidIndices(const int *, unsigned long, int) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B253_[bool mmtf::(anonymous namespace)::hasValidIndices<int,unsigned long>(const int *, unsigned long, unsigned long)] ";
	// mmtf::(anonymous namespace)::hasValidIndices(const int *, unsigned long, unsigned long) file: line:354
	M("mmtf::(anonymous namespace)").def("hasValidIndices", (bool (*)(const int *, unsigned long, unsigned long)) &mmtf::(anonymous namespace)::hasValidIndices<int,unsigned long>, "C++: mmtf::(anonymous namespace)::hasValidIndices(const int *, unsigned long, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B254_[bool mmtf::(anonymous namespace)::hasValidIndices<int,int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::(anonymous namespace)::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) file: line:362
	M("mmtf::(anonymous namespace)").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::(anonymous namespace)::hasValidIndices<int,int>, "C++: mmtf::(anonymous namespace)::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("num"));

	std::cout << "B255_[bool mmtf::(anonymous namespace)::hasValidIndices<int,unsigned long>(const class std::vector<int, class std::allocator<int> > &, unsigned long)] ";
	// mmtf::(anonymous namespace)::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) file: line:362
	M("mmtf::(anonymous namespace)").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, unsigned long)) &mmtf::(anonymous namespace)::hasValidIndices<int,unsigned long>, "C++: mmtf::(anonymous namespace)::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("num"));

}
