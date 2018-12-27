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

// mmtf::EncodeError file: line:31
struct PyCallBack_mmtf_EncodeError : public mmtf::EncodeError {
	using mmtf::EncodeError::EncodeError;

	const char * what() const noexcept override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mmtf::EncodeError *>(this), "what");
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

void bind_unknown_unknown_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B238_[mmtf::EncodeError] ";
	{ // mmtf::EncodeError file: line:31
		pybind11::class_<mmtf::EncodeError, std::shared_ptr<mmtf::EncodeError>, PyCallBack_mmtf_EncodeError, std::runtime_error> cl(M("mmtf"), "EncodeError", "Exception thrown when failing during encoding.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("m") );

		cl.def( pybind11::init( [](PyCallBack_mmtf_EncodeError const &o){ return new PyCallBack_mmtf_EncodeError(o); } ) );
		cl.def( pybind11::init( [](mmtf::EncodeError const &o){ return new mmtf::EncodeError(o); } ) );
		cl.def("assign", (class mmtf::EncodeError & (mmtf::EncodeError::*)(const class mmtf::EncodeError &)) &mmtf::EncodeError::operator=, "C++: mmtf::EncodeError::operator=(const class mmtf::EncodeError &) --> class mmtf::EncodeError &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B239_[mmtf::BinaryDecoder] ";
	{ // mmtf::BinaryDecoder file: line:30
		pybind11::class_<mmtf::BinaryDecoder, std::shared_ptr<mmtf::BinaryDecoder>> cl(M("mmtf"), "BinaryDecoder", "Helper class to decode msgpack binary into a vector.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](const struct msgpack::v2::object & a0){ return new mmtf::BinaryDecoder(a0); } ), "doc");
		cl.def( pybind11::init<const struct msgpack::v2::object &, const std::string &>(), pybind11::arg("obj"), pybind11::arg("key") );

		cl.def( pybind11::init( [](mmtf::BinaryDecoder const &o){ return new mmtf::BinaryDecoder(o); } ) );
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<float, class std::allocator<float> > &)) &mmtf::BinaryDecoder::decode<std::vector<float, std::allocator<float> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::BinaryDecoder::decode<std::vector<signed char, std::allocator<signed char> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<signed char, class std::allocator<signed char> > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<short, class std::allocator<short> > &)) &mmtf::BinaryDecoder::decode<std::vector<short, std::allocator<short> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<short, class std::allocator<short> > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<int, class std::allocator<int> > &)) &mmtf::BinaryDecoder::decode<std::vector<int, std::allocator<int> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<int, class std::allocator<int> > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::BinaryDecoder::decode<std::vector<std::string, std::allocator<std::string > >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<std::string, class std::allocator<std::string > > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<char, class std::allocator<char> > &)) &mmtf::BinaryDecoder::decode<std::vector<char, std::allocator<char> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<char, class std::allocator<char> > &) --> void", pybind11::arg("output"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(std::string &)) &mmtf::BinaryDecoder::decode<std::string>, "C++: mmtf::BinaryDecoder::decode(std::string &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(char &)) &mmtf::BinaryDecoder::decode<char>, "C++: mmtf::BinaryDecoder::decode(char &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &)) &mmtf::BinaryDecoder::decode<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::BinaryDecoder::decode<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::BinaryDecoder::decode<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::BinaryDecoder::decode<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(float &)) &mmtf::BinaryDecoder::decode<float>, "C++: mmtf::BinaryDecoder::decode(float &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(int &)) &mmtf::BinaryDecoder::decode<int>, "C++: mmtf::BinaryDecoder::decode(int &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &)) &mmtf::BinaryDecoder::decode<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>, "C++: mmtf::BinaryDecoder::decode(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) --> void", pybind11::arg("target"));
		cl.def("decode", (void (mmtf::BinaryDecoder::*)(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)) &mmtf::BinaryDecoder::decode<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: mmtf::BinaryDecoder::decode(class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) --> void", pybind11::arg("target"));
	}
	std::cout << "B240_[void mmtf::assignBigendian4(void *, const char *)] ";
	// mmtf::assignBigendian4(void *, const char *) file: line:123
	M("mmtf").def("assignBigendian4", (void (*)(void *, const char *)) &mmtf::assignBigendian4, "C++: mmtf::assignBigendian4(void *, const char *) --> void", pybind11::arg("dst"), pybind11::arg("src"));

	std::cout << "B241_[void mmtf::assignBigendian2(void *, const char *)] ";
	// mmtf::assignBigendian2(void *, const char *) file: line:127
	M("mmtf").def("assignBigendian2", (void (*)(void *, const char *)) &mmtf::assignBigendian2, "C++: mmtf::assignBigendian2(void *, const char *) --> void", pybind11::arg("dst"), pybind11::arg("src"));

	std::cout << "B242_[void mmtf::arrayCopyBigendian4(void *, const char *, unsigned long)] ";
	// mmtf::arrayCopyBigendian4(void *, const char *, unsigned long) file: line:149
	M("mmtf").def("arrayCopyBigendian4", (void (*)(void *, const char *, unsigned long)) &mmtf::arrayCopyBigendian4, "C++: mmtf::arrayCopyBigendian4(void *, const char *, unsigned long) --> void", pybind11::arg("dst"), pybind11::arg("src"), pybind11::arg("n"));

	std::cout << "B243_[void mmtf::arrayCopyBigendian2(void *, const char *, unsigned long)] ";
	// mmtf::arrayCopyBigendian2(void *, const char *, unsigned long) file: line:155
	M("mmtf").def("arrayCopyBigendian2", (void (*)(void *, const char *, unsigned long)) &mmtf::arrayCopyBigendian2, "C++: mmtf::arrayCopyBigendian2(void *, const char *, unsigned long) --> void", pybind11::arg("dst"), pybind11::arg("src"), pybind11::arg("n"));

	std::cout << "B244_[mmtf::MapDecoder] ";
	{ // mmtf::MapDecoder file: line:30
		pybind11::class_<mmtf::MapDecoder, std::shared_ptr<mmtf::MapDecoder>> cl(M("mmtf"), "MapDecoder", "Helper class to decode msgpack maps into object fields.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const struct msgpack::v2::object &>(), pybind11::arg("obj") );

		cl.def( pybind11::init<class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &>(), pybind11::arg("map_in") );

		cl.def( pybind11::init( [](mmtf::MapDecoder const &o){ return new mmtf::MapDecoder(o); } ) );
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<int, class std::allocator<int> > &)) &mmtf::MapDecoder::decode<std::vector<int, std::allocator<int> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<int, class std::allocator<int> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::MapDecoder::decode<std::vector<std::string, std::allocator<std::string > >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<std::string, class std::allocator<std::string > > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::MapDecoder::decode<std::vector<signed char, std::allocator<signed char> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<signed char, class std::allocator<signed char> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, std::string &)) &mmtf::MapDecoder::decode<std::string>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, std::string &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, char &)) &mmtf::MapDecoder::decode<char>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, char &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &)) &mmtf::MapDecoder::decode<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<float, class std::allocator<float> > &)) &mmtf::MapDecoder::decode<std::vector<float, std::allocator<float> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::MapDecoder::decode<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::MapDecoder::decode<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::MapDecoder::decode<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, float &)) &mmtf::MapDecoder::decode<float>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, float &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, int &)) &mmtf::MapDecoder::decode<int>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, int &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &)) &mmtf::MapDecoder::decode<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::vector<char, class std::allocator<char> > &)) &mmtf::MapDecoder::decode<std::vector<char, std::allocator<char> >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::vector<char, class std::allocator<char> > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("decode", (void (mmtf::MapDecoder::*)(const std::string &, bool, class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)) &mmtf::MapDecoder::decode<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>, "C++: mmtf::MapDecoder::decode(const std::string &, bool, class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &) --> void", pybind11::arg("key"), pybind11::arg("required"), pybind11::arg("target"));
		cl.def("checkExtraKeys", (void (mmtf::MapDecoder::*)()) &mmtf::MapDecoder::checkExtraKeys, "Check if there are any keys, that were not decoded.\n This is to be called after all expected fields have been decoded.\n A warning is written to stderr for each non-decoded key.\n\nC++: mmtf::MapDecoder::checkExtraKeys() --> void");
	}
}
