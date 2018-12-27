#include <functional> // std::less
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::map
#include <memory> // std::allocator
#include <sstream> // __str__
#include <stdexcept> // std::runtime_error
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

// mmtf::DecodeError file: line:23
struct PyCallBack_mmtf_DecodeError : public mmtf::DecodeError {
	using mmtf::DecodeError::DecodeError;

	const char * what() const noexcept override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mmtf::DecodeError *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::overload_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return runtime_error::what();
	}
};

void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B211_[bool mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B212_[bool mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B213_[bool mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

	std::cout << "B214_[bool mmtf::isDefaultValue<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::isDefaultValue<signed char>, "C++: mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B215_[bool mmtf::isDefaultValue<int>(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::isDefaultValue<int>, "C++: mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) --> bool", pybind11::arg("value"));

	std::cout << "B216_[bool mmtf::isDefaultValue<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) --> bool", pybind11::arg("value"));

	std::cout << "B217_[bool mmtf::isDefaultValue<char>(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::isDefaultValue<char>, "C++: mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B218_[bool mmtf::isDefaultValue<float>(const class std::vector<float, class std::allocator<float> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<float, class std::allocator<float> > &)) &mmtf::isDefaultValue<float>, "C++: mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) --> bool", pybind11::arg("value"));

	std::cout << "B219_[bool mmtf::isDefaultValue<mmtf::BioAssembly>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<mmtf::BioAssembly>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B220_[bool mmtf::isDefaultValue<mmtf::Entity>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<mmtf::Entity>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B221_[bool mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

	std::cout << "B222_[bool mmtf::isDefaultValue<std::string>(const std::string &)] ";
	// mmtf::isDefaultValue(const std::string &) file: line:294
	M("mmtf").def("isDefaultValue", (bool (*)(const std::string &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const std::string &) --> bool", pybind11::arg("value"));

	std::cout << "B223_[bool mmtf::isDefaultValue<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)] ";
	// mmtf::isDefaultValue(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) file: line:296
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)) &mmtf::isDefaultValue<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: mmtf::isDefaultValue(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) --> bool", pybind11::arg("value"));

	std::cout << "B224_[bool mmtf::isDefaultValue(const struct msgpack::v2::object &)] ";
	// mmtf::isDefaultValue(const struct msgpack::v2::object &) file: line:297
	M("mmtf").def("isDefaultValue", (bool (*)(const struct msgpack::v2::object &)) &mmtf::isDefaultValue, "C++: mmtf::isDefaultValue(const struct msgpack::v2::object &) --> bool", pybind11::arg("value"));

	std::cout << "B225_[void mmtf::setDefaultValue<float>(float &)] ";
	// mmtf::setDefaultValue(float &) file: line:409
	M("mmtf").def("setDefaultValue", (void (*)(float &)) &mmtf::setDefaultValue<float>, "C++: mmtf::setDefaultValue(float &) --> void", pybind11::arg("value"));

	std::cout << "B226_[bool mmtf::is_hetatm(const char *)] ";
	// mmtf::is_hetatm(const char *) file: line:317
	M("mmtf").def("is_hetatm", (bool (*)(const char *)) &mmtf::is_hetatm, "Check if type is hetatm\n \n\n   cstring of group.chemCompType\n \n\n True if is a HETATM \n Used when printing this struct, also all chemCompTypes are listed, but\n the non-HETATM ones are commented out for reference\n Relevant threads:\n https://github.com/rcsb/mmtf/issues/28\n http://mmcif.wwpdb.org/dictionaries/mmcif_pdbx_v50.dic/Items/_chem_comp.type.html\n\nC++: mmtf::is_hetatm(const char *) --> bool", pybind11::arg("type"));

	std::cout << "B227_[bool mmtf::isValidDateFormatOptional(const std::string &)] ";
	// mmtf::isValidDateFormatOptional(const std::string &) file: line:328
	M("mmtf").def("isValidDateFormatOptional", (bool (*)(const std::string &)) &mmtf::isValidDateFormatOptional, "C++: mmtf::isValidDateFormatOptional(const std::string &) --> bool", pybind11::arg("s"));

	std::cout << "B228_[bool mmtf::hasRightSizeOptional<float>(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::hasRightSizeOptional<float>, "C++: mmtf::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B229_[bool mmtf::hasRightSizeOptional<int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::hasRightSizeOptional<int>, "C++: mmtf::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B230_[bool mmtf::hasRightSizeOptional<char>(const class std::vector<char, class std::allocator<char> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<char, class std::allocator<char> > &, int)) &mmtf::hasRightSizeOptional<char>, "C++: mmtf::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B231_[bool mmtf::hasRightSizeOptional<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &, int)) &mmtf::hasRightSizeOptional<signed char>, "C++: mmtf::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B232_[bool mmtf::hasRightSizeOptional<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &, int)) &mmtf::hasRightSizeOptional<std::string>, "C++: mmtf::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B233_[bool mmtf::hasValidIndices<int,int>(const int *, unsigned long, int)] ";
	// mmtf::hasValidIndices(const int *, unsigned long, int) file: line:354
	M("mmtf").def("hasValidIndices", (bool (*)(const int *, unsigned long, int)) &mmtf::hasValidIndices<int,int>, "C++: mmtf::hasValidIndices(const int *, unsigned long, int) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B234_[bool mmtf::hasValidIndices<int,unsigned long>(const int *, unsigned long, unsigned long)] ";
	// mmtf::hasValidIndices(const int *, unsigned long, unsigned long) file: line:354
	M("mmtf").def("hasValidIndices", (bool (*)(const int *, unsigned long, unsigned long)) &mmtf::hasValidIndices<int,unsigned long>, "C++: mmtf::hasValidIndices(const int *, unsigned long, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B235_[bool mmtf::hasValidIndices<int,int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) file: line:362
	M("mmtf").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::hasValidIndices<int,int>, "C++: mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("num"));

	std::cout << "B236_[bool mmtf::hasValidIndices<int,unsigned long>(const class std::vector<int, class std::allocator<int> > &, unsigned long)] ";
	// mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) file: line:362
	M("mmtf").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, unsigned long)) &mmtf::hasValidIndices<int,unsigned long>, "C++: mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("num"));

	std::cout << "B237_[mmtf::DecodeError] ";
	{ // mmtf::DecodeError file: line:23
		pybind11::class_<mmtf::DecodeError, std::shared_ptr<mmtf::DecodeError>, PyCallBack_mmtf_DecodeError, std::runtime_error> cl(M("mmtf"), "DecodeError", "Exception thrown when failing during decoding.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("m") );

		cl.def( pybind11::init( [](PyCallBack_mmtf_DecodeError const &o){ return new PyCallBack_mmtf_DecodeError(o); } ) );
		cl.def( pybind11::init( [](mmtf::DecodeError const &o){ return new mmtf::DecodeError(o); } ) );
		cl.def("assign", (class mmtf::DecodeError & (mmtf::DecodeError::*)(const class mmtf::DecodeError &)) &mmtf::DecodeError::operator=, "C++: mmtf::DecodeError::operator=(const class mmtf::DecodeError &) --> class mmtf::DecodeError &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
