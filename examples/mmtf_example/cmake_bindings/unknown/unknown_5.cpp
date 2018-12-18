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

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B230_[bool mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B231_[bool mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B232_[bool mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

	std::cout << "B233_[bool mmtf::isDefaultValue<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::isDefaultValue<signed char>, "C++: mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B234_[bool mmtf::isDefaultValue<int>(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::isDefaultValue<int>, "C++: mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) --> bool", pybind11::arg("value"));

	std::cout << "B235_[bool mmtf::isDefaultValue<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) --> bool", pybind11::arg("value"));

	std::cout << "B236_[bool mmtf::isDefaultValue<char>(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::isDefaultValue<char>, "C++: mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B237_[bool mmtf::isDefaultValue<float>(const class std::vector<float, class std::allocator<float> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<float, class std::allocator<float> > &)) &mmtf::isDefaultValue<float>, "C++: mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) --> bool", pybind11::arg("value"));

	std::cout << "B238_[bool mmtf::isDefaultValue<mmtf::BioAssembly>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<mmtf::BioAssembly>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B239_[bool mmtf::isDefaultValue<mmtf::Entity>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<mmtf::Entity>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B240_[bool mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

	std::cout << "B241_[bool mmtf::isDefaultValue<std::string>(const std::string &)] ";
	// mmtf::isDefaultValue(const std::string &) file: line:294
	M("mmtf").def("isDefaultValue", (bool (*)(const std::string &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const std::string &) --> bool", pybind11::arg("value"));

	std::cout << "B242_[bool mmtf::isDefaultValue<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)] ";
	// mmtf::isDefaultValue(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) file: line:296
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)) &mmtf::isDefaultValue<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: mmtf::isDefaultValue(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) --> bool", pybind11::arg("value"));

	std::cout << "B243_[bool mmtf::isDefaultValue(const struct msgpack::v2::object &)] ";
	// mmtf::isDefaultValue(const struct msgpack::v2::object &) file: line:297
	M("mmtf").def("isDefaultValue", (bool (*)(const struct msgpack::v2::object &)) &mmtf::isDefaultValue, "C++: mmtf::isDefaultValue(const struct msgpack::v2::object &) --> bool", pybind11::arg("value"));

	std::cout << "B244_[void mmtf::setDefaultValue<float>(float &)] ";
	// mmtf::setDefaultValue(float &) file: line:409
	M("mmtf").def("setDefaultValue", (void (*)(float &)) &mmtf::setDefaultValue<float>, "C++: mmtf::setDefaultValue(float &) --> void", pybind11::arg("value"));

	std::cout << "B245_[bool mmtf::is_hetatm(const char *)] ";
	// mmtf::is_hetatm(const char *) file: line:317
	M("mmtf").def("is_hetatm", (bool (*)(const char *)) &mmtf::is_hetatm, "Check if type is hetatm\n \n\n   cstring of group.chemCompType\n \n\n True if is a HETATM \n Used when printing this struct, also all chemCompTypes are listed, but\n the non-HETATM ones are commented out for reference\n Relevant threads:\n https://github.com/rcsb/mmtf/issues/28\n http://mmcif.wwpdb.org/dictionaries/mmcif_pdbx_v50.dic/Items/_chem_comp.type.html\n\nC++: mmtf::is_hetatm(const char *) --> bool", pybind11::arg("type"));

}
