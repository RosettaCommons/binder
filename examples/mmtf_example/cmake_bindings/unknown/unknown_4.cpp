#include <functional> // std::less
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
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
#include <mmtf.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B197_[class std::__cxx11::basic_string<char> mmtf::getVersionString()] ";
	// mmtf::getVersionString() file: line:38
	M("mmtf").def("getVersionString", (std::string (*)()) &mmtf::getVersionString, "Get string representation of MMTF spec version implemented here\n\nC++: mmtf::getVersionString() --> std::string");

	std::cout << "B198_[bool mmtf::isVersionSupported(const std::string &)] ";
	// mmtf::isVersionSupported(const std::string &) file: line:44
	M("mmtf").def("isVersionSupported", (bool (*)(const std::string &)) &mmtf::isVersionSupported, "Check if version is supported (minor revisions ok, major ones not)\n \n\n true if supported, false if not\n\nC++: mmtf::isVersionSupported(const std::string &) --> bool", pybind11::arg("version_string"));

	std::cout << "B199_[mmtf::GroupType] ";
	{ // mmtf::GroupType file: line:51
		pybind11::class_<mmtf::GroupType, std::shared_ptr<mmtf::GroupType>> cl(M("mmtf"), "GroupType", "Group (residue) level data store\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#group-data");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::GroupType(); } ) );
		cl.def( pybind11::init( [](mmtf::GroupType const &o){ return new mmtf::GroupType(o); } ) );
		cl.def_readwrite("formalChargeList", &mmtf::GroupType::formalChargeList);
		cl.def_readwrite("atomNameList", &mmtf::GroupType::atomNameList);
		cl.def_readwrite("elementList", &mmtf::GroupType::elementList);
		cl.def_readwrite("bondAtomList", &mmtf::GroupType::bondAtomList);
		cl.def_readwrite("bondOrderList", &mmtf::GroupType::bondOrderList);
		cl.def_readwrite("bondResonanceList", &mmtf::GroupType::bondResonanceList);
		cl.def_readwrite("groupName", &mmtf::GroupType::groupName);
		cl.def_readwrite("singleLetterCode", &mmtf::GroupType::singleLetterCode);
		cl.def_readwrite("chemCompType", &mmtf::GroupType::chemCompType);
		cl.def("__eq__", (bool (mmtf::GroupType::*)(const struct mmtf::GroupType &) const) &mmtf::GroupType::operator==, "C++: mmtf::GroupType::operator==(const struct mmtf::GroupType &) const --> bool", pybind11::arg("c"));
		cl.def("assign", (struct mmtf::GroupType & (mmtf::GroupType::*)(const struct mmtf::GroupType &)) &mmtf::GroupType::operator=, "C++: mmtf::GroupType::operator=(const struct mmtf::GroupType &) --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B200_[mmtf::Entity] ";
	{ // mmtf::Entity file: line:81
		pybind11::class_<mmtf::Entity, std::shared_ptr<mmtf::Entity>> cl(M("mmtf"), "Entity", "Entity type.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#entitylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::Entity(); } ) );
		cl.def( pybind11::init( [](mmtf::Entity const &o){ return new mmtf::Entity(o); } ) );
		cl.def_readwrite("chainIndexList", &mmtf::Entity::chainIndexList);
		cl.def_readwrite("description", &mmtf::Entity::description);
		cl.def_readwrite("type", &mmtf::Entity::type);
		cl.def_readwrite("sequence", &mmtf::Entity::sequence);
		cl.def("msgpack_object", (void (mmtf::Entity::*)(struct msgpack::v2::object *, class msgpack::v1::zone &) const) &mmtf::Entity::msgpack_object<msgpack::v2::object>, "C++: mmtf::Entity::msgpack_object(struct msgpack::v2::object *, class msgpack::v1::zone &) const --> void", pybind11::arg("o"), pybind11::arg("z"));
		cl.def("__eq__", (bool (mmtf::Entity::*)(const struct mmtf::Entity &) const) &mmtf::Entity::operator==, "C++: mmtf::Entity::operator==(const struct mmtf::Entity &) const --> bool", pybind11::arg("c"));
		cl.def("msgpack_unpack", (void (mmtf::Entity::*)(const struct msgpack::v2::object &)) &mmtf::Entity::msgpack_unpack, "C++: mmtf::Entity::msgpack_unpack(const struct msgpack::v2::object &) --> void", pybind11::arg("o"));
		cl.def("assign", (struct mmtf::Entity & (mmtf::Entity::*)(const struct mmtf::Entity &)) &mmtf::Entity::operator=, "C++: mmtf::Entity::operator=(const struct mmtf::Entity &) --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B201_[mmtf::Transform] ";
	{ // mmtf::Transform file: line:107
		pybind11::class_<mmtf::Transform, std::shared_ptr<mmtf::Transform>> cl(M("mmtf"), "Transform", "Transformation definition for a set of chains.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::Transform(); } ) );
		cl.def( pybind11::init( [](mmtf::Transform const &o){ return new mmtf::Transform(o); } ) );
		cl.def_readwrite("chainIndexList", &mmtf::Transform::chainIndexList);
		cl.def("msgpack_object", (void (mmtf::Transform::*)(struct msgpack::v2::object *, class msgpack::v1::zone &) const) &mmtf::Transform::msgpack_object<msgpack::v2::object>, "C++: mmtf::Transform::msgpack_object(struct msgpack::v2::object *, class msgpack::v1::zone &) const --> void", pybind11::arg("o"), pybind11::arg("z"));
		cl.def("__eq__", (bool (mmtf::Transform::*)(const struct mmtf::Transform &) const) &mmtf::Transform::operator==, "C++: mmtf::Transform::operator==(const struct mmtf::Transform &) const --> bool", pybind11::arg("c"));
		cl.def("msgpack_unpack", (void (mmtf::Transform::*)(const struct msgpack::v2::object &)) &mmtf::Transform::msgpack_unpack, "C++: mmtf::Transform::msgpack_unpack(const struct msgpack::v2::object &) --> void", pybind11::arg("o"));
		cl.def("assign", (struct mmtf::Transform & (mmtf::Transform::*)(const struct mmtf::Transform &)) &mmtf::Transform::operator=, "C++: mmtf::Transform::operator=(const struct mmtf::Transform &) --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B202_[mmtf::BioAssembly] ";
	{ // mmtf::BioAssembly file: line:130
		pybind11::class_<mmtf::BioAssembly, std::shared_ptr<mmtf::BioAssembly>> cl(M("mmtf"), "BioAssembly", "Data store for the biological assembly annotation.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::BioAssembly(); } ) );
		cl.def( pybind11::init( [](mmtf::BioAssembly const &o){ return new mmtf::BioAssembly(o); } ) );
		cl.def_readwrite("transformList", &mmtf::BioAssembly::transformList);
		cl.def_readwrite("name", &mmtf::BioAssembly::name);
		cl.def("msgpack_object", (void (mmtf::BioAssembly::*)(struct msgpack::v2::object *, class msgpack::v1::zone &) const) &mmtf::BioAssembly::msgpack_object<msgpack::v2::object>, "C++: mmtf::BioAssembly::msgpack_object(struct msgpack::v2::object *, class msgpack::v1::zone &) const --> void", pybind11::arg("o"), pybind11::arg("z"));
		cl.def("__eq__", (bool (mmtf::BioAssembly::*)(const struct mmtf::BioAssembly &) const) &mmtf::BioAssembly::operator==, "C++: mmtf::BioAssembly::operator==(const struct mmtf::BioAssembly &) const --> bool", pybind11::arg("c"));
		cl.def("msgpack_unpack", (void (mmtf::BioAssembly::*)(const struct msgpack::v2::object &)) &mmtf::BioAssembly::msgpack_unpack, "C++: mmtf::BioAssembly::msgpack_unpack(const struct msgpack::v2::object &) --> void", pybind11::arg("o"));
		cl.def("assign", (struct mmtf::BioAssembly & (mmtf::BioAssembly::*)(const struct mmtf::BioAssembly &)) &mmtf::BioAssembly::operator=, "C++: mmtf::BioAssembly::operator=(const struct mmtf::BioAssembly &) --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B203_[mmtf::StructureData] ";
	{ // mmtf::StructureData file: line:155
		pybind11::class_<mmtf::StructureData, std::shared_ptr<mmtf::StructureData>> cl(M("mmtf"), "StructureData", "Top level MMTF data container.\n\n Default values (mmtf::isDefaultValue, mmtf::setDefaultValue) are set in\n constructor and can be used to check if value was never set (only relevant\n for optional values):\n - default for vectors and strings: empty\n - default for numeric types (incl. char): max. value of that type\n - default for numXX = 0\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#fields");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::StructureData(); } ) );
		cl.def_readwrite("mmtfVersion", &mmtf::StructureData::mmtfVersion);
		cl.def_readwrite("mmtfProducer", &mmtf::StructureData::mmtfProducer);
		cl.def_readwrite("unitCell", &mmtf::StructureData::unitCell);
		cl.def_readwrite("spaceGroup", &mmtf::StructureData::spaceGroup);
		cl.def_readwrite("structureId", &mmtf::StructureData::structureId);
		cl.def_readwrite("title", &mmtf::StructureData::title);
		cl.def_readwrite("depositionDate", &mmtf::StructureData::depositionDate);
		cl.def_readwrite("releaseDate", &mmtf::StructureData::releaseDate);
		cl.def_readwrite("ncsOperatorList", &mmtf::StructureData::ncsOperatorList);
		cl.def_readwrite("bioAssemblyList", &mmtf::StructureData::bioAssemblyList);
		cl.def_readwrite("entityList", &mmtf::StructureData::entityList);
		cl.def_readwrite("experimentalMethods", &mmtf::StructureData::experimentalMethods);
		cl.def_readwrite("resolution", &mmtf::StructureData::resolution);
		cl.def_readwrite("rFree", &mmtf::StructureData::rFree);
		cl.def_readwrite("rWork", &mmtf::StructureData::rWork);
		cl.def_readwrite("numBonds", &mmtf::StructureData::numBonds);
		cl.def_readwrite("numAtoms", &mmtf::StructureData::numAtoms);
		cl.def_readwrite("numGroups", &mmtf::StructureData::numGroups);
		cl.def_readwrite("numChains", &mmtf::StructureData::numChains);
		cl.def_readwrite("numModels", &mmtf::StructureData::numModels);
		cl.def_readwrite("groupList", &mmtf::StructureData::groupList);
		cl.def_readwrite("bondAtomList", &mmtf::StructureData::bondAtomList);
		cl.def_readwrite("bondOrderList", &mmtf::StructureData::bondOrderList);
		cl.def_readwrite("bondResonanceList", &mmtf::StructureData::bondResonanceList);
		cl.def_readwrite("xCoordList", &mmtf::StructureData::xCoordList);
		cl.def_readwrite("yCoordList", &mmtf::StructureData::yCoordList);
		cl.def_readwrite("zCoordList", &mmtf::StructureData::zCoordList);
		cl.def_readwrite("bFactorList", &mmtf::StructureData::bFactorList);
		cl.def_readwrite("atomIdList", &mmtf::StructureData::atomIdList);
		cl.def_readwrite("altLocList", &mmtf::StructureData::altLocList);
		cl.def_readwrite("occupancyList", &mmtf::StructureData::occupancyList);
		cl.def_readwrite("groupIdList", &mmtf::StructureData::groupIdList);
		cl.def_readwrite("groupTypeList", &mmtf::StructureData::groupTypeList);
		cl.def_readwrite("secStructList", &mmtf::StructureData::secStructList);
		cl.def_readwrite("insCodeList", &mmtf::StructureData::insCodeList);
		cl.def_readwrite("sequenceIndexList", &mmtf::StructureData::sequenceIndexList);
		cl.def_readwrite("chainIdList", &mmtf::StructureData::chainIdList);
		cl.def_readwrite("chainNameList", &mmtf::StructureData::chainNameList);
		cl.def_readwrite("groupsPerChain", &mmtf::StructureData::groupsPerChain);
		cl.def_readwrite("chainsPerModel", &mmtf::StructureData::chainsPerModel);
		cl.def_readwrite("msgpack_zone", &mmtf::StructureData::msgpack_zone);
		cl.def_readwrite("bondProperties", &mmtf::StructureData::bondProperties);
		cl.def_readwrite("atomProperties", &mmtf::StructureData::atomProperties);
		cl.def_readwrite("groupProperties", &mmtf::StructureData::groupProperties);
		cl.def_readwrite("chainProperties", &mmtf::StructureData::chainProperties);
		cl.def_readwrite("modelProperties", &mmtf::StructureData::modelProperties);
		cl.def_readwrite("extraProperties", &mmtf::StructureData::extraProperties);
		cl.def("hasConsistentData", [](mmtf::StructureData const &o) -> bool { return o.hasConsistentData(); }, "");
		cl.def("hasConsistentData", [](mmtf::StructureData const &o, bool const & a0) -> bool { return o.hasConsistentData(a0); }, "", pybind11::arg("verbose"));
		cl.def("hasConsistentData", (bool (mmtf::StructureData::*)(bool, unsigned int) const) &mmtf::StructureData::hasConsistentData, "Check consistency of structural data.\n \n\n                 Print first error encountered (if any)\n \n\n   Max allowed chain name length\n \n\n True if all required fields are set and vector sizes and indices\n         are consistent.\n\nC++: mmtf::StructureData::hasConsistentData(bool, unsigned int) const --> bool", pybind11::arg("verbose"), pybind11::arg("chain_name_max_length"));
		cl.def("print", [](mmtf::StructureData &o) -> std::string { return o.print(); }, "");
		cl.def("print", (std::string (mmtf::StructureData::*)(std::string)) &mmtf::StructureData::print, "Read out the contents of mmtf::StructureData in a PDB-like fashion\n Columns are in order:\n ATOM/HETATM AtomId Element AtomName AltLoc GroupId GroupType\n InsCode ChainName x y z B-factor Occupancy Charge\n \n\n what to split columns with\n\nC++: mmtf::StructureData::print(std::string) --> std::string", pybind11::arg("delim"));
		cl.def("__eq__", (bool (mmtf::StructureData::*)(const struct mmtf::StructureData &) const) &mmtf::StructureData::operator==, "compare two StructureData classes\n \n\n what to compare to\n\nC++: mmtf::StructureData::operator==(const struct mmtf::StructureData &) const --> bool", pybind11::arg("c"));
	}
	std::cout << "B204_[float mmtf::getDefaultValue<float>()] ";
	// mmtf::getDefaultValue() file: line:386
	M("mmtf").def("getDefaultValue", (float (*)()) &mmtf::getDefaultValue<float>, "C++: mmtf::getDefaultValue() --> float");

	std::cout << "B205_[bool mmtf::isDefaultValue<std::vector<signed char, std::allocator<signed char> >>(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::isDefaultValue<std::vector<signed char, std::allocator<signed char> >>, "C++: mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B206_[bool mmtf::isDefaultValue<std::vector<int, std::allocator<int> >>(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::isDefaultValue<std::vector<int, std::allocator<int> >>, "C++: mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) --> bool", pybind11::arg("value"));

	std::cout << "B207_[bool mmtf::isDefaultValue<std::vector<std::string, std::allocator<std::string > >>(const class std::vector<std::string, class std::allocator<std::string > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::isDefaultValue<std::vector<std::string, std::allocator<std::string > >>, "C++: mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) --> bool", pybind11::arg("value"));

	std::cout << "B208_[bool mmtf::isDefaultValue<std::vector<char, std::allocator<char> >>(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::isDefaultValue<std::vector<char, std::allocator<char> >>, "C++: mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B209_[bool mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>(const class std::vector<float, class std::allocator<float> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<float, class std::allocator<float> > &)) &mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>, "C++: mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) --> bool", pybind11::arg("value"));

	std::cout << "B210_[bool mmtf::isDefaultValue<float>(const float &)] ";
	// mmtf::isDefaultValue(const float &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const float &)) &mmtf::isDefaultValue<float>, "C++: mmtf::isDefaultValue(const float &) --> bool", pybind11::arg("value"));

}
