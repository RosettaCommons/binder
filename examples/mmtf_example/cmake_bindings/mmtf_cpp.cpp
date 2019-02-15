// File: std/exception.cpp
#include <exception> // std::bad_exception
#include <exception> // std::exception
#include <exception> // std::terminate
#include <exception> // std::uncaught_exception
#include <exception> // std::unexpected
#include <iostream> // --trace
#include <sstream> // __str__

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

// std::exception file:bits/exception.h line:60
struct PyCallBack_std_exception : public std::exception {
	using std::exception::exception;

	const char * what() const noexcept override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::exception *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::overload_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return exception::what();
	}
};

void bind_std_exception(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B0_[std::exception] ";
	{ // std::exception file:bits/exception.h line:60
		pybind11::class_<std::exception, std::shared_ptr<std::exception>, PyCallBack_std_exception> cl(M("std"), "exception", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::exception(); }, [](){ return new PyCallBack_std_exception(); } ) );
		cl.def( pybind11::init( [](PyCallBack_std_exception const &o){ return new PyCallBack_std_exception(o); } ) );
		cl.def( pybind11::init( [](std::exception const &o){ return new std::exception(o); } ) );
		cl.def("what", (const char * (std::exception::*)() const) &std::exception::what, "C++: std::exception::what() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("assign", (class std::exception & (std::exception::*)(const class std::exception &)) &std::exception::operator=, "C++: std::exception::operator=(const class std::exception &) --> class std::exception &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B1_[std::bad_exception] ";
	std::cout << "B2_[void std::terminate()] ";
	std::cout << "B3_[void std::unexpected()] ";
	std::cout << "B4_[bool std::uncaught_exception()] ";
}


// File: std/locale_classes.cpp
#include <atomic> // std::atomic
#include <fstream> // std::basic_filebuf
#include <iomanip> // std::_Setfill
#include <iomanip> // std::_Setprecision
#include <iomanip> // std::_Setw
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <iterator> // std::move_iterator
#include <locale> // std::__cxx11::collate
#include <locale> // std::__cxx11::collate_byname
#include <locale> // std::locale
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <stdexcept> // std::domain_error
#include <stdexcept> // std::invalid_argument
#include <stdexcept> // std::length_error
#include <stdexcept> // std::logic_error
#include <stdexcept> // std::out_of_range
#include <stdexcept> // std::overflow_error
#include <stdexcept> // std::range_error
#include <stdexcept> // std::runtime_error
#include <stdexcept> // std::underflow_error
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <system_error> // std::_V2::error_category
#include <system_error> // std::errc
#include <system_error> // std::error_code
#include <system_error> // std::error_condition
#include <system_error> // std::is_error_code_enum
#include <system_error> // std::is_error_condition_enum
#include <typeinfo> // std::type_info
#include <utility> // std::pair
#include <vector> // std::_Bit_iterator
#include <vector> // std::_Bit_iterator_base
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

// std::runtime_error file:stdexcept line:197
struct PyCallBack_std_runtime_error : public std::runtime_error {
	using std::runtime_error::runtime_error;

	const char * what() const noexcept override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::runtime_error *>(this), "what");
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

void bind_std_locale_classes(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B5_[std::locale] ";
	{ // std::locale file:bits/locale_classes.h line:62
		pybind11::class_<std::locale, std::shared_ptr<std::locale>> cl(M("std"), "locale", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::locale(); } ) );
		cl.def( pybind11::init( [](std::locale const &o){ return new std::locale(o); } ) );
		cl.def( pybind11::init<const char *>(), pybind11::arg("__s") );

		cl.def( pybind11::init<const class std::locale &, const char *, int>(), pybind11::arg("__base"), pybind11::arg("__s"), pybind11::arg("__cat") );

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("__s") );

		cl.def( pybind11::init<const class std::locale &, const std::string &, int>(), pybind11::arg("__base"), pybind11::arg("__s"), pybind11::arg("__cat") );

		cl.def( pybind11::init<const class std::locale &, const class std::locale &, int>(), pybind11::arg("__base"), pybind11::arg("__add"), pybind11::arg("__cat") );

		cl.def("assign", (const class std::locale & (std::locale::*)(const class std::locale &)) &std::locale::operator=, "C++: std::locale::operator=(const class std::locale &) --> const class std::locale &", pybind11::return_value_policy::automatic, pybind11::arg("__other"));
		cl.def("name", (std::string (std::locale::*)() const) &std::locale::name, "C++: std::locale::name() const --> std::string");
		cl.def("__eq__", (bool (std::locale::*)(const class std::locale &) const) &std::locale::operator==, "C++: std::locale::operator==(const class std::locale &) const --> bool", pybind11::arg("__other"));
		cl.def("__ne__", (bool (std::locale::*)(const class std::locale &) const) &std::locale::operator!=, "C++: std::locale::operator!=(const class std::locale &) const --> bool", pybind11::arg("__other"));
		cl.def_static("global", (class std::locale (*)(const class std::locale &)) &std::locale::global, "C++: std::locale::global(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def_static("classic", (const class std::locale & (*)()) &std::locale::classic, "C++: std::locale::classic() --> const class std::locale &", pybind11::return_value_policy::automatic);
	}
	std::cout << "B6_[std::collate<char>] ";
	std::cout << "B7_[std::collate_byname<char>] ";
	std::cout << "B8_[std::collate<wchar_t>] ";
	std::cout << "B9_[std::collate_byname<wchar_t>] ";
	std::cout << "B10_[std::errc] ";
	std::cout << "B11_[std::logic_error] ";
	std::cout << "B12_[std::domain_error] ";
	std::cout << "B13_[std::invalid_argument] ";
	std::cout << "B14_[std::length_error] ";
	std::cout << "B15_[std::out_of_range] ";
	std::cout << "B16_[std::runtime_error] ";
	{ // std::runtime_error file:stdexcept line:197
		pybind11::class_<std::runtime_error, std::shared_ptr<std::runtime_error>, PyCallBack_std_runtime_error, std::exception> cl(M("std"), "runtime_error", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("__arg") );

		cl.def( pybind11::init<const char *>(), pybind11::arg("") );

		cl.def( pybind11::init( [](PyCallBack_std_runtime_error const &o){ return new PyCallBack_std_runtime_error(o); } ) );
		cl.def( pybind11::init( [](std::runtime_error const &o){ return new std::runtime_error(o); } ) );
		cl.def("assign", (class std::runtime_error & (std::runtime_error::*)(const class std::runtime_error &)) &std::runtime_error::operator=, "C++: std::runtime_error::operator=(const class std::runtime_error &) --> class std::runtime_error &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("what", (const char * (std::runtime_error::*)() const) &std::runtime_error::what, "C++: std::runtime_error::what() const --> const char *", pybind11::return_value_policy::automatic);
	}
	std::cout << "B17_[std::range_error] ";
	std::cout << "B18_[std::overflow_error] ";
	std::cout << "B19_[std::underflow_error] ";
	std::cout << "B20_[std::is_error_code_enum<std::error_code>] ";
	std::cout << "B21_[std::is_error_code_enum<std::_V2::error_category>] ";
	std::cout << "B22_[std::is_error_code_enum<int>] ";
	std::cout << "B23_[std::is_error_code_enum<std::error_condition>] ";
	std::cout << "B24_[std::is_error_code_enum<std::_Bit_iterator_base>] ";
	std::cout << "B25_[std::is_error_code_enum<std::_Bit_iterator>] ";
	std::cout << "B26_[std::is_error_code_enum<std::type_info>] ";
	std::cout << "B27_[std::is_error_code_enum<const char *>] ";
	std::cout << "B28_[std::is_error_code_enum<unsigned long>] ";
	std::cout << "B29_[std::is_error_code_enum<long>] ";
	std::cout << "B30_[std::is_error_code_enum<double>] ";
	std::cout << "B31_[std::is_error_code_enum<char>] ";
	std::cout << "B32_[std::is_error_code_enum<std::ios_base &(*)(std::ios_base &)>] ";
	std::cout << "B33_[std::is_error_code_enum<std::_Setw>] ";
	std::cout << "B34_[std::is_error_code_enum<std::_Setfill<char>>] ";
	std::cout << "B35_[std::is_error_code_enum<unsigned int>] ";
	std::cout << "B36_[std::is_error_code_enum<msgpack::v2::object>] ";
	std::cout << "B37_[std::is_error_code_enum<unsigned short>] ";
	std::cout << "B38_[std::is_error_code_enum<std::atomic<unsigned int>>] ";
	std::cout << "B39_[std::is_error_code_enum<std::vector<char, std::allocator<char> >>] ";
	std::cout << "B40_[std::is_error_code_enum<std::vector<int, std::allocator<int> >>] ";
	std::cout << "B41_[std::is_error_code_enum<std::vector<std::string, std::allocator<std::string > >>] ";
	std::cout << "B42_[std::is_error_code_enum<std::vector<signed char, std::allocator<signed char> >>] ";
	std::cout << "B43_[std::is_error_code_enum<std::string>] ";
	std::cout << "B44_[std::is_error_code_enum<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>] ";
	std::cout << "B45_[std::is_error_code_enum<std::vector<float, std::allocator<float> >>] ";
	std::cout << "B46_[std::is_error_code_enum<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>] ";
	std::cout << "B47_[std::is_error_code_enum<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>] ";
	std::cout << "B48_[std::is_error_code_enum<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>] ";
	std::cout << "B49_[std::is_error_code_enum<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>] ";
	std::cout << "B50_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<signed char *, std::vector<signed char, std::allocator<signed char> > >>] ";
	std::cout << "B51_[std::is_error_code_enum<signed char>] ";
	std::cout << "B52_[std::is_error_code_enum<std::_Setprecision>] ";
	std::cout << "B53_[std::is_error_code_enum<float>] ";
	std::cout << "B54_[std::is_error_code_enum<msgpack::v1::type::object_type>] ";
	std::cout << "B55_[std::is_error_code_enum<std::_Rb_tree_iterator<std::pair<const std::string, msgpack::v2::object> >>] ";
	std::cout << "B56_[std::is_error_code_enum<std::_Rb_tree_iterator<std::pair<const std::string, msgpack::v2::object *> >>] ";
	std::cout << "B57_[std::is_error_code_enum<std::_Rb_tree_const_iterator<std::string >>] ";
	std::cout << "B58_[std::is_error_code_enum<std::move_iterator<msgpack::v1::detail::unpack_stack *>>] ";
	std::cout << "B59_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const msgpack::v1::detail::unpack_stack *, std::vector<msgpack::v1::detail::unpack_stack, std::allocator<msgpack::v1::detail::unpack_stack> > >>] ";
	std::cout << "B60_[std::is_error_code_enum<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *>>] ";
	std::cout << "B61_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *, std::vector<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem, std::allocator<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem> > >>] ";
	std::cout << "B62_[std::is_error_code_enum<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>>] ";
	std::cout << "B63_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *, std::vector<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem, std::allocator<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem> > >>] ";
	std::cout << "B64_[std::is_error_code_enum<std::_Rb_tree_iterator<std::pair<const std::string, const msgpack::v2::object *> >>] ";
	std::cout << "B65_[std::is_error_code_enum<std::_Rb_tree_const_iterator<std::pair<const std::string, const msgpack::v2::object *> >>] ";
	std::cout << "B66_[std::is_error_code_enum<std::move_iterator<mmtf::Transform *>>] ";
	std::cout << "B67_[std::is_error_code_enum<std::allocator<char>>] ";
	std::cout << "B68_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const std::string *, std::vector<std::string, std::allocator<std::string > > >>] ";
	std::cout << "B69_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const char *, std::vector<char, std::allocator<char> > >>] ";
	std::cout << "B70_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const float *, std::vector<float, std::allocator<float> > >>] ";
	std::cout << "B71_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const signed char *, std::vector<signed char, std::allocator<signed char> > >>] ";
	std::cout << "B72_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const short *, std::vector<short, std::allocator<short> > >>] ";
	std::cout << "B73_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const int *, std::vector<int, std::allocator<int> > >>] ";
	std::cout << "B74_[std::is_error_code_enum<std::move_iterator<std::string *>>] ";
	std::cout << "B75_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<char *, std::string >>] ";
	std::cout << "B76_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const char *, std::string >>] ";
	std::cout << "B77_[std::is_error_code_enum<std::_Rb_tree_iterator<std::string >>] ";
	std::cout << "B78_[std::is_error_code_enum<std::ostream &(*)(std::ostream &)>] ";
	std::cout << "B79_[std::is_error_code_enum<std::move_iterator<std::vector<float, std::allocator<float> > *>>] ";
	std::cout << "B80_[std::is_error_code_enum<std::move_iterator<mmtf::BioAssembly *>>] ";
	std::cout << "B81_[std::is_error_code_enum<std::move_iterator<mmtf::Entity *>>] ";
	std::cout << "B82_[std::is_error_code_enum<std::move_iterator<mmtf::GroupType *>>] ";
	std::cout << "B83_[std::is_error_code_enum<std::basic_filebuf<char> *>] ";
	std::cout << "B84_[std::is_error_code_enum<std::_Rb_tree_const_iterator<std::pair<const std::string, msgpack::v2::object> >>] ";
	std::cout << "B85_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const mmtf::GroupType *, std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> > >>] ";
	std::cout << "B86_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const mmtf::BioAssembly *, std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> > >>] ";
	std::cout << "B87_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const mmtf::Transform *, std::vector<mmtf::Transform, std::allocator<mmtf::Transform> > >>] ";
	std::cout << "B88_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const mmtf::Entity *, std::vector<mmtf::Entity, std::allocator<mmtf::Entity> > >>] ";
	std::cout << "B89_[std::is_error_code_enum<__gnu_cxx::__normal_iterator<const std::vector<float, std::allocator<float> > *, std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > > >>] ";
	std::cout << "B90_[std::is_error_condition_enum<std::error_condition>] ";
	std::cout << "B91_[std::is_error_condition_enum<std::_V2::error_category>] ";
	std::cout << "B92_[std::is_error_condition_enum<std::error_code>] ";
	std::cout << "B93_[std::is_error_condition_enum<std::_Bit_iterator_base>] ";
	std::cout << "B94_[std::is_error_condition_enum<std::_Bit_iterator>] ";
	std::cout << "B95_[std::is_error_condition_enum<std::type_info>] ";
	std::cout << "B96_[std::is_error_condition_enum<std::atomic<unsigned int>>] ";
	std::cout << "B97_[std::is_error_condition_enum<std::vector<char, std::allocator<char> >>] ";
	std::cout << "B98_[std::is_error_condition_enum<std::vector<int, std::allocator<int> >>] ";
	std::cout << "B99_[std::is_error_condition_enum<std::vector<std::string, std::allocator<std::string > >>] ";
	std::cout << "B100_[std::is_error_condition_enum<std::vector<signed char, std::allocator<signed char> >>] ";
	std::cout << "B101_[std::is_error_condition_enum<std::string>] ";
	std::cout << "B102_[std::is_error_condition_enum<std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >>] ";
	std::cout << "B103_[std::is_error_condition_enum<std::vector<float, std::allocator<float> >>] ";
	std::cout << "B104_[std::is_error_condition_enum<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>] ";
	std::cout << "B105_[std::is_error_condition_enum<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>] ";
	std::cout << "B106_[std::is_error_condition_enum<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>] ";
	std::cout << "B107_[std::is_error_condition_enum<std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >>] ";
	std::cout << "B108_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<signed char *, std::vector<signed char, std::allocator<signed char> > >>] ";
	std::cout << "B109_[std::is_error_condition_enum<std::_Rb_tree_iterator<std::pair<const std::string, msgpack::v2::object> >>] ";
	std::cout << "B110_[std::is_error_condition_enum<std::_Rb_tree_iterator<std::pair<const std::string, msgpack::v2::object *> >>] ";
	std::cout << "B111_[std::is_error_condition_enum<std::_Rb_tree_const_iterator<std::string >>] ";
	std::cout << "B112_[std::is_error_condition_enum<std::move_iterator<msgpack::v1::detail::unpack_stack *>>] ";
	std::cout << "B113_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<const msgpack::v1::detail::unpack_stack *, std::vector<msgpack::v1::detail::unpack_stack, std::allocator<msgpack::v1::detail::unpack_stack> > >>] ";
	std::cout << "B114_[std::is_error_condition_enum<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *>>] ";
	std::cout << "B115_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<const msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *, std::vector<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem, std::allocator<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem> > >>] ";
	std::cout << "B116_[std::is_error_condition_enum<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>>] ";
	std::cout << "B117_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<const msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *, std::vector<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem, std::allocator<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem> > >>] ";
	std::cout << "B118_[std::is_error_condition_enum<std::_Rb_tree_iterator<std::pair<const std::string, const msgpack::v2::object *> >>] ";
	std::cout << "B119_[std::is_error_condition_enum<std::_Rb_tree_const_iterator<std::pair<const std::string, const msgpack::v2::object *> >>] ";
	std::cout << "B120_[std::is_error_condition_enum<std::move_iterator<mmtf::Transform *>>] ";
	std::cout << "B121_[std::is_error_condition_enum<std::allocator<char>>] ";
	std::cout << "B122_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<const std::string *, std::vector<std::string, std::allocator<std::string > > >>] ";
	std::cout << "B123_[std::is_error_condition_enum<__gnu_cxx::__normal_iterator<const char *, std::vector<char, std::allocator<char> > >>] ";
}


// File: std/ios_base.cpp
#include <ios> // std::_Ios_Fmtflags
#include <ios> // std::_Ios_Iostate
#include <ios> // std::_Ios_Openmode
#include <ios> // std::_Ios_Seekdir
#include <ios> // std::boolalpha
#include <ios> // std::dec
#include <ios> // std::defaultfloat
#include <ios> // std::fixed
#include <ios> // std::hex
#include <ios> // std::hexfloat
#include <ios> // std::internal
#include <ios> // std::io_errc
#include <ios> // std::ios_base
#include <ios> // std::is_error_code_enum
#include <ios> // std::left
#include <ios> // std::make_error_code
#include <ios> // std::make_error_condition
#include <ios> // std::noboolalpha
#include <ios> // std::noshowbase
#include <ios> // std::noshowpoint
#include <ios> // std::noshowpos
#include <ios> // std::noskipws
#include <ios> // std::nounitbuf
#include <ios> // std::nouppercase
#include <ios> // std::oct
#include <ios> // std::right
#include <ios> // std::scientific
#include <ios> // std::showbase
#include <ios> // std::showpoint
#include <ios> // std::showpos
#include <ios> // std::skipws
#include <ios> // std::unitbuf
#include <ios> // std::uppercase
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <locale> // std::locale
#include <memory> // std::allocator
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <system_error> // std::error_code
#include <system_error> // std::error_condition

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

// std::basic_streambuf file:bits/streambuf.tcc line:149
struct PyCallBack_std_streambuf : public std::streambuf {
	using std::streambuf::basic_streambuf;

	void imbue(const class std::locale & a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "imbue");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::overload_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return basic_streambuf::imbue(a0);
	}
	class std::basic_streambuf<char> * setbuf(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "setbuf");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::basic_streambuf<char> *>::value) {
				static pybind11::detail::overload_caster_t<class std::basic_streambuf<char> *> caster;
				return pybind11::detail::cast_ref<class std::basic_streambuf<char> *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::basic_streambuf<char> *>(std::move(o));
		}
		return basic_streambuf::setbuf(a0, a1);
	}
	int sync() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "sync");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::sync();
	}
	long showmanyc() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "showmanyc");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::showmanyc();
	}
	long xsgetn(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "xsgetn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsgetn(a0, a1);
	}
	int underflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "underflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::underflow();
	}
	int uflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "uflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::uflow();
	}
	int pbackfail(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "pbackfail");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::pbackfail(a0);
	}
	long xsputn(const char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "xsputn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsputn(a0, a1);
	}
	int overflow(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::streambuf *>(this), "overflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::overflow(a0);
	}
};

void bind_std_ios_base(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B124_[std::_Ios_Openmode] ";
	// std::_Ios_Openmode file:bits/ios_base.h line:111
	pybind11::enum_<std::_Ios_Openmode>(M("std"), "_Ios_Openmode", pybind11::arithmetic(), "")
		.value("_S_app", std::_Ios_Openmode::_S_app)
		.value("_S_ate", std::_Ios_Openmode::_S_ate)
		.value("_S_bin", std::_Ios_Openmode::_S_bin)
		.value("_S_in", std::_Ios_Openmode::_S_in)
		.value("_S_out", std::_Ios_Openmode::_S_out)
		.value("_S_trunc", std::_Ios_Openmode::_S_trunc)
		.value("_S_ios_openmode_end", std::_Ios_Openmode::_S_ios_openmode_end)
		.value("_S_ios_openmode_max", std::_Ios_Openmode::_S_ios_openmode_max)
		.value("_S_ios_openmode_min", std::_Ios_Openmode::_S_ios_openmode_min)
		.export_values();

;

	std::cout << "B125_[std::_Ios_Iostate] ";
	std::cout << "B126_[std::_Ios_Seekdir] ";
	// std::_Ios_Seekdir file:bits/ios_base.h line:193
	pybind11::enum_<std::_Ios_Seekdir>(M("std"), "_Ios_Seekdir", pybind11::arithmetic(), "")
		.value("_S_beg", std::_Ios_Seekdir::_S_beg)
		.value("_S_cur", std::_Ios_Seekdir::_S_cur)
		.value("_S_end", std::_Ios_Seekdir::_S_end)
		.value("_S_ios_seekdir_end", std::_Ios_Seekdir::_S_ios_seekdir_end)
		.export_values();

;

	std::cout << "B127_[std::io_errc] ";
	std::cout << "B128_[std::is_error_code_enum<std::io_errc>] ";
	std::cout << "B129_[struct std::error_code std::make_error_code(enum std::io_errc)] ";
	std::cout << "B130_[struct std::error_condition std::make_error_condition(enum std::io_errc)] ";
	std::cout << "B131_[std::ios_base] ";
	std::cout << "B132_[class std::ios_base & std::boolalpha(class std::ios_base &)] ";
	std::cout << "B133_[class std::ios_base & std::noboolalpha(class std::ios_base &)] ";
	std::cout << "B134_[class std::ios_base & std::showbase(class std::ios_base &)] ";
	std::cout << "B135_[class std::ios_base & std::noshowbase(class std::ios_base &)] ";
	std::cout << "B136_[class std::ios_base & std::showpoint(class std::ios_base &)] ";
	std::cout << "B137_[class std::ios_base & std::noshowpoint(class std::ios_base &)] ";
	std::cout << "B138_[class std::ios_base & std::showpos(class std::ios_base &)] ";
	std::cout << "B139_[class std::ios_base & std::noshowpos(class std::ios_base &)] ";
	std::cout << "B140_[class std::ios_base & std::skipws(class std::ios_base &)] ";
	std::cout << "B141_[class std::ios_base & std::noskipws(class std::ios_base &)] ";
	std::cout << "B142_[class std::ios_base & std::uppercase(class std::ios_base &)] ";
	std::cout << "B143_[class std::ios_base & std::nouppercase(class std::ios_base &)] ";
	std::cout << "B144_[class std::ios_base & std::unitbuf(class std::ios_base &)] ";
	std::cout << "B145_[class std::ios_base & std::nounitbuf(class std::ios_base &)] ";
	std::cout << "B146_[class std::ios_base & std::internal(class std::ios_base &)] ";
	std::cout << "B147_[class std::ios_base & std::left(class std::ios_base &)] ";
	std::cout << "B148_[class std::ios_base & std::right(class std::ios_base &)] ";
	std::cout << "B149_[class std::ios_base & std::dec(class std::ios_base &)] ";
	std::cout << "B150_[class std::ios_base & std::hex(class std::ios_base &)] ";
	std::cout << "B151_[class std::ios_base & std::oct(class std::ios_base &)] ";
	std::cout << "B152_[class std::ios_base & std::fixed(class std::ios_base &)] ";
	std::cout << "B153_[class std::ios_base & std::scientific(class std::ios_base &)] ";
	std::cout << "B154_[class std::ios_base & std::hexfloat(class std::ios_base &)] ";
	std::cout << "B155_[class std::ios_base & std::defaultfloat(class std::ios_base &)] ";
	std::cout << "B156_[std::streambuf] ";
	{ // std::basic_streambuf file:bits/streambuf.tcc line:149
		pybind11::class_<std::streambuf, std::shared_ptr<std::streambuf>, PyCallBack_std_streambuf> cl(M("std"), "streambuf", "");
		pybind11::handle cl_type = cl;

		cl.def("pubimbue", (class std::locale (std::streambuf::*)(const class std::locale &)) &std::basic_streambuf<char, std::char_traits<char> >::pubimbue, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubimbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::streambuf::*)() const) &std::basic_streambuf<char, std::char_traits<char> >::getloc, "C++: std::basic_streambuf<char, std::char_traits<char> >::getloc() const --> class std::locale");
		cl.def("pubsetbuf", (class std::basic_streambuf<char> * (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf(char *, long) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("pubsync", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::pubsync, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsync() --> int");
		cl.def("in_avail", (long (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::in_avail, "C++: std::basic_streambuf<char, std::char_traits<char> >::in_avail() --> long");
		cl.def("snextc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::snextc, "C++: std::basic_streambuf<char, std::char_traits<char> >::snextc() --> int");
		cl.def("sbumpc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sbumpc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sbumpc() --> int");
		cl.def("sgetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sgetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetc() --> int");
		cl.def("sgetn", (long (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sgetn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetn(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("sputbackc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputbackc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputbackc(char) --> int", pybind11::arg("__c"));
		cl.def("sungetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sungetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sungetc() --> int");
		cl.def("sputc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputc(char) --> int", pybind11::arg("__c"));
		cl.def("sputn", (long (std::streambuf::*)(const char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sputn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputn(const char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("stossc", (void (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::stossc, "C++: std::basic_streambuf<char, std::char_traits<char> >::stossc() --> void");
		cl.def("__safe_gbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump(long) --> void", pybind11::arg("__n"));
		cl.def("__safe_pbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump(long) --> void", pybind11::arg("__n"));
	}
	std::cout << "B157_[std::wstreambuf] ";
}


// File: std/ostream_tcc.cpp
#include <ios> // std::_Ios_Seekdir
#include <ios> // std::basic_iostream
#include <iostream> // --trace
#include <istream> // std::basic_istream
#include <istream> // std::ws
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
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

void bind_std_ostream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B158_[std::ostream] ";
	{ // std::basic_ostream file:bits/ostream.tcc line:359
		pybind11::class_<std::ostream, std::shared_ptr<std::ostream>> cl(M("std"), "ostream", "");
		pybind11::handle cl_type = cl;

		{ // std::basic_ostream<char, std::char_traits<char> >::sentry file:ostream line:96
			auto & enclosing_class = cl;
			pybind11::class_<std::basic_ostream<char, std::char_traits<char> >::sentry, std::shared_ptr<std::basic_ostream<char, std::char_traits<char> >::sentry>> cl(enclosing_class, "sentry", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init<std::ostream &>(), pybind11::arg("__os") );

		}

		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("put", (std::ostream & (std::ostream::*)(char)) &std::basic_ostream<char, std::char_traits<char> >::put, "C++: std::basic_ostream<char, std::char_traits<char> >::put(char) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("_M_write", (void (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::_M_write, "C++: std::basic_ostream<char, std::char_traits<char> >::_M_write(const char *, long) --> void", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("write", (std::ostream & (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::write, "C++: std::basic_ostream<char, std::char_traits<char> >::write(const char *, long) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("flush", (std::ostream & (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::flush, "C++: std::basic_ostream<char, std::char_traits<char> >::flush() --> std::ostream &", pybind11::return_value_policy::automatic);
		cl.def("seekp", (std::ostream & (std::ostream::*)(long, enum std::_Ios_Seekdir)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(long, enum std::_Ios_Seekdir) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
	std::cout << "B159_[std::wostream] ";
	std::cout << "B160_[class std::basic_istream<char> & std::ws<char,std::char_traits<char>>(class std::basic_istream<char> &)] ";
	std::cout << "B161_[class std::basic_istream<wchar_t> & std::ws<wchar_t,std::char_traits<wchar_t>>(class std::basic_istream<wchar_t> &)] ";
	std::cout << "B162_[std::istream] ";
	{ // std::basic_istream file:bits/istream.tcc line:1048
		pybind11::class_<std::istream, std::shared_ptr<std::istream>> cl(M("std"), "istream", "");
		pybind11::handle cl_type = cl;

		{ // std::basic_istream<char, std::char_traits<char> >::sentry file:istream line:107
			auto & enclosing_class = cl;
			pybind11::class_<std::basic_istream<char, std::char_traits<char> >::sentry, std::shared_ptr<std::basic_istream<char, std::char_traits<char> >::sentry>> cl(enclosing_class, "sentry", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](class std::basic_istream<char> & a0){ return new std::basic_istream<char, std::char_traits<char> >::sentry(a0); } ), "doc");
			cl.def( pybind11::init<class std::basic_istream<char> &, bool>(), pybind11::arg("__is"), pybind11::arg("__noskipws") );

		}

		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("gcount", (long (std::istream::*)() const) &std::basic_istream<char, std::char_traits<char> >::gcount, "C++: std::basic_istream<char, std::char_traits<char> >::gcount() const --> long");
		cl.def("get", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get() --> int");
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long, int)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long, int) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("peek", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::peek, "C++: std::basic_istream<char, std::char_traits<char> >::peek() --> int");
		cl.def("read", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::read, "C++: std::basic_istream<char, std::char_traits<char> >::read(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("readsome", (long (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::readsome, "C++: std::basic_istream<char, std::char_traits<char> >::readsome(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("putback", (class std::basic_istream<char> & (std::istream::*)(char)) &std::basic_istream<char, std::char_traits<char> >::putback, "C++: std::basic_istream<char, std::char_traits<char> >::putback(char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("unget", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::unget, "C++: std::basic_istream<char, std::char_traits<char> >::unget() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("sync", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::sync, "C++: std::basic_istream<char, std::char_traits<char> >::sync() --> int");
		cl.def("seekg", (class std::basic_istream<char> & (std::istream::*)(long, enum std::_Ios_Seekdir)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(long, enum std::_Ios_Seekdir) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
	std::cout << "B163_[std::iostream] ";
	{ // std::basic_iostream file:bits/istream.tcc line:1071
		pybind11::class_<std::iostream, std::shared_ptr<std::iostream>, std::istream, std::ostream> cl(M("std"), "iostream", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<class std::basic_streambuf<char> *>(), pybind11::arg("__sb") );

		cl.def("gcount", (long (std::istream::*)() const) &std::basic_istream<char, std::char_traits<char> >::gcount, "C++: std::basic_istream<char, std::char_traits<char> >::gcount() const --> long");
		cl.def("get", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get() --> int");
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long, int)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long, int) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("peek", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::peek, "C++: std::basic_istream<char, std::char_traits<char> >::peek() --> int");
		cl.def("read", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::read, "C++: std::basic_istream<char, std::char_traits<char> >::read(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("readsome", (long (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::readsome, "C++: std::basic_istream<char, std::char_traits<char> >::readsome(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("putback", (class std::basic_istream<char> & (std::istream::*)(char)) &std::basic_istream<char, std::char_traits<char> >::putback, "C++: std::basic_istream<char, std::char_traits<char> >::putback(char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("unget", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::unget, "C++: std::basic_istream<char, std::char_traits<char> >::unget() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("sync", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::sync, "C++: std::basic_istream<char, std::char_traits<char> >::sync() --> int");
		cl.def("seekg", (class std::basic_istream<char> & (std::istream::*)(long, enum std::_Ios_Seekdir)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(long, enum std::_Ios_Seekdir) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
		cl.def("put", (std::ostream & (std::ostream::*)(char)) &std::basic_ostream<char, std::char_traits<char> >::put, "C++: std::basic_ostream<char, std::char_traits<char> >::put(char) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("_M_write", (void (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::_M_write, "C++: std::basic_ostream<char, std::char_traits<char> >::_M_write(const char *, long) --> void", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("write", (std::ostream & (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::write, "C++: std::basic_ostream<char, std::char_traits<char> >::write(const char *, long) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("flush", (std::ostream & (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::flush, "C++: std::basic_ostream<char, std::char_traits<char> >::flush() --> std::ostream &", pybind11::return_value_policy::automatic);
		cl.def("seekp", (std::ostream & (std::ostream::*)(long, enum std::_Ios_Seekdir)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(long, enum std::_Ios_Seekdir) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
}


// File: std/fstream_tcc.cpp
#include <fstream> // std::basic_filebuf
#include <fstream> // std::basic_ifstream
#include <fstream> // std::basic_ofstream
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <locale> // std::locale
#include <memory> // std::allocator
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
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

// std::basic_filebuf file:bits/fstream.tcc line:1053
struct PyCallBack_std_filebuf : public std::filebuf {
	using std::filebuf::basic_filebuf;

	long showmanyc() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "showmanyc");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_filebuf::showmanyc();
	}
	int underflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "underflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_filebuf::underflow();
	}
	int pbackfail(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "pbackfail");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_filebuf::pbackfail(a0);
	}
	int overflow(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "overflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_filebuf::overflow(a0);
	}
	class std::basic_streambuf<char> * setbuf(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "setbuf");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::basic_streambuf<char> *>::value) {
				static pybind11::detail::overload_caster_t<class std::basic_streambuf<char> *> caster;
				return pybind11::detail::cast_ref<class std::basic_streambuf<char> *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::basic_streambuf<char> *>(std::move(o));
		}
		return basic_filebuf::setbuf(a0, a1);
	}
	int sync() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "sync");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_filebuf::sync();
	}
	void imbue(const class std::locale & a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "imbue");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::overload_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return basic_filebuf::imbue(a0);
	}
	long xsgetn(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "xsgetn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_filebuf::xsgetn(a0, a1);
	}
	long xsputn(const char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "xsputn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_filebuf::xsputn(a0, a1);
	}
	int uflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::filebuf *>(this), "uflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::uflow();
	}
};

void bind_std_fstream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B164_[std::filebuf] ";
	{ // std::basic_filebuf file:bits/fstream.tcc line:1053
		pybind11::class_<std::filebuf, std::shared_ptr<std::filebuf>, PyCallBack_std_filebuf, std::streambuf> cl(M("std"), "filebuf", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::filebuf(); }, [](){ return new PyCallBack_std_filebuf(); } ) );
		cl.def("swap", (void (std::filebuf::*)(class std::basic_filebuf<char> &)) &std::basic_filebuf<char, std::char_traits<char> >::swap, "C++: std::basic_filebuf<char, std::char_traits<char> >::swap(class std::basic_filebuf<char> &) --> void", pybind11::arg(""));
		cl.def("is_open", (bool (std::filebuf::*)() const) &std::basic_filebuf<char, std::char_traits<char> >::is_open, "C++: std::basic_filebuf<char, std::char_traits<char> >::is_open() const --> bool");
		cl.def("open", (class std::basic_filebuf<char> * (std::filebuf::*)(const char *, enum std::_Ios_Openmode)) &std::basic_filebuf<char, std::char_traits<char> >::open, "C++: std::basic_filebuf<char, std::char_traits<char> >::open(const char *, enum std::_Ios_Openmode) --> class std::basic_filebuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("open", (class std::basic_filebuf<char> * (std::filebuf::*)(const std::string &, enum std::_Ios_Openmode)) &std::basic_filebuf<char, std::char_traits<char> >::open, "C++: std::basic_filebuf<char, std::char_traits<char> >::open(const std::string &, enum std::_Ios_Openmode) --> class std::basic_filebuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("close", (class std::basic_filebuf<char> * (std::filebuf::*)()) &std::basic_filebuf<char, std::char_traits<char> >::close, "C++: std::basic_filebuf<char, std::char_traits<char> >::close() --> class std::basic_filebuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("pubimbue", (class std::locale (std::streambuf::*)(const class std::locale &)) &std::basic_streambuf<char, std::char_traits<char> >::pubimbue, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubimbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::streambuf::*)() const) &std::basic_streambuf<char, std::char_traits<char> >::getloc, "C++: std::basic_streambuf<char, std::char_traits<char> >::getloc() const --> class std::locale");
		cl.def("pubsetbuf", (class std::basic_streambuf<char> * (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf(char *, long) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("pubsync", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::pubsync, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsync() --> int");
		cl.def("in_avail", (long (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::in_avail, "C++: std::basic_streambuf<char, std::char_traits<char> >::in_avail() --> long");
		cl.def("snextc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::snextc, "C++: std::basic_streambuf<char, std::char_traits<char> >::snextc() --> int");
		cl.def("sbumpc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sbumpc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sbumpc() --> int");
		cl.def("sgetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sgetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetc() --> int");
		cl.def("sgetn", (long (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sgetn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetn(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("sputbackc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputbackc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputbackc(char) --> int", pybind11::arg("__c"));
		cl.def("sungetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sungetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sungetc() --> int");
		cl.def("sputc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputc(char) --> int", pybind11::arg("__c"));
		cl.def("sputn", (long (std::streambuf::*)(const char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sputn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputn(const char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("stossc", (void (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::stossc, "C++: std::basic_streambuf<char, std::char_traits<char> >::stossc() --> void");
		cl.def("__safe_gbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump(long) --> void", pybind11::arg("__n"));
		cl.def("__safe_pbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump(long) --> void", pybind11::arg("__n"));
	}
	std::cout << "B165_[std::ifstream] ";
	{ // std::basic_ifstream file:bits/fstream.tcc line:1054
		pybind11::class_<std::ifstream, std::shared_ptr<std::ifstream>, std::istream> cl(M("std"), "ifstream", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::ifstream(); } ) );
		cl.def( pybind11::init( [](const char * a0){ return new std::ifstream(a0); } ), "doc");
		cl.def( pybind11::init<const char *, enum std::_Ios_Openmode>(), pybind11::arg("__s"), pybind11::arg("__mode") );

		cl.def( pybind11::init( [](const class std::__cxx11::basic_string<char> & a0){ return new std::ifstream(a0); } ), "doc");
		cl.def( pybind11::init<const std::string &, enum std::_Ios_Openmode>(), pybind11::arg("__s"), pybind11::arg("__mode") );

		cl.def("swap", (void (std::ifstream::*)(class std::basic_ifstream<char> &)) &std::basic_ifstream<char, std::char_traits<char> >::swap, "C++: std::basic_ifstream<char, std::char_traits<char> >::swap(class std::basic_ifstream<char> &) --> void", pybind11::arg("__rhs"));
		cl.def("rdbuf", (class std::basic_filebuf<char> * (std::ifstream::*)() const) &std::basic_ifstream<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ifstream<char, std::char_traits<char> >::rdbuf() const --> class std::basic_filebuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("is_open", (bool (std::ifstream::*)()) &std::basic_ifstream<char, std::char_traits<char> >::is_open, "C++: std::basic_ifstream<char, std::char_traits<char> >::is_open() --> bool");
		cl.def("open", [](std::ifstream &o, const char * a0) -> void { return o.open(a0); }, "", pybind11::arg("__s"));
		cl.def("open", (void (std::ifstream::*)(const char *, enum std::_Ios_Openmode)) &std::basic_ifstream<char, std::char_traits<char> >::open, "C++: std::basic_ifstream<char, std::char_traits<char> >::open(const char *, enum std::_Ios_Openmode) --> void", pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("open", [](std::ifstream &o, const class std::__cxx11::basic_string<char> & a0) -> void { return o.open(a0); }, "", pybind11::arg("__s"));
		cl.def("open", (void (std::ifstream::*)(const std::string &, enum std::_Ios_Openmode)) &std::basic_ifstream<char, std::char_traits<char> >::open, "C++: std::basic_ifstream<char, std::char_traits<char> >::open(const std::string &, enum std::_Ios_Openmode) --> void", pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("close", (void (std::ifstream::*)()) &std::basic_ifstream<char, std::char_traits<char> >::close, "C++: std::basic_ifstream<char, std::char_traits<char> >::close() --> void");
		cl.def("gcount", (long (std::istream::*)() const) &std::basic_istream<char, std::char_traits<char> >::gcount, "C++: std::basic_istream<char, std::char_traits<char> >::gcount() const --> long");
		cl.def("get", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get() --> int");
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long, int)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long, int) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("peek", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::peek, "C++: std::basic_istream<char, std::char_traits<char> >::peek() --> int");
		cl.def("read", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::read, "C++: std::basic_istream<char, std::char_traits<char> >::read(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("readsome", (long (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::readsome, "C++: std::basic_istream<char, std::char_traits<char> >::readsome(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("putback", (class std::basic_istream<char> & (std::istream::*)(char)) &std::basic_istream<char, std::char_traits<char> >::putback, "C++: std::basic_istream<char, std::char_traits<char> >::putback(char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("unget", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::unget, "C++: std::basic_istream<char, std::char_traits<char> >::unget() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("sync", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::sync, "C++: std::basic_istream<char, std::char_traits<char> >::sync() --> int");
		cl.def("seekg", (class std::basic_istream<char> & (std::istream::*)(long, enum std::_Ios_Seekdir)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(long, enum std::_Ios_Seekdir) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
	std::cout << "B166_[std::ofstream] ";
	{ // std::basic_ofstream file:bits/fstream.tcc line:1055
		pybind11::class_<std::ofstream, std::shared_ptr<std::ofstream>, std::ostream> cl(M("std"), "ofstream", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::ofstream(); } ) );
		cl.def( pybind11::init( [](const char * a0){ return new std::ofstream(a0); } ), "doc");
		cl.def( pybind11::init<const char *, enum std::_Ios_Openmode>(), pybind11::arg("__s"), pybind11::arg("__mode") );

		cl.def( pybind11::init( [](const class std::__cxx11::basic_string<char> & a0){ return new std::ofstream(a0); } ), "doc");
		cl.def( pybind11::init<const std::string &, enum std::_Ios_Openmode>(), pybind11::arg("__s"), pybind11::arg("__mode") );

		cl.def("swap", (void (std::ofstream::*)(class std::basic_ofstream<char> &)) &std::basic_ofstream<char, std::char_traits<char> >::swap, "C++: std::basic_ofstream<char, std::char_traits<char> >::swap(class std::basic_ofstream<char> &) --> void", pybind11::arg("__rhs"));
		cl.def("rdbuf", (class std::basic_filebuf<char> * (std::ofstream::*)() const) &std::basic_ofstream<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ofstream<char, std::char_traits<char> >::rdbuf() const --> class std::basic_filebuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("is_open", (bool (std::ofstream::*)()) &std::basic_ofstream<char, std::char_traits<char> >::is_open, "C++: std::basic_ofstream<char, std::char_traits<char> >::is_open() --> bool");
		cl.def("open", [](std::ofstream &o, const char * a0) -> void { return o.open(a0); }, "", pybind11::arg("__s"));
		cl.def("open", (void (std::ofstream::*)(const char *, enum std::_Ios_Openmode)) &std::basic_ofstream<char, std::char_traits<char> >::open, "C++: std::basic_ofstream<char, std::char_traits<char> >::open(const char *, enum std::_Ios_Openmode) --> void", pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("open", [](std::ofstream &o, const class std::__cxx11::basic_string<char> & a0) -> void { return o.open(a0); }, "", pybind11::arg("__s"));
		cl.def("open", (void (std::ofstream::*)(const std::string &, enum std::_Ios_Openmode)) &std::basic_ofstream<char, std::char_traits<char> >::open, "C++: std::basic_ofstream<char, std::char_traits<char> >::open(const std::string &, enum std::_Ios_Openmode) --> void", pybind11::arg("__s"), pybind11::arg("__mode"));
		cl.def("close", (void (std::ofstream::*)()) &std::basic_ofstream<char, std::char_traits<char> >::close, "C++: std::basic_ofstream<char, std::char_traits<char> >::close() --> void");
		cl.def("put", (std::ostream & (std::ostream::*)(char)) &std::basic_ostream<char, std::char_traits<char> >::put, "C++: std::basic_ostream<char, std::char_traits<char> >::put(char) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("_M_write", (void (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::_M_write, "C++: std::basic_ostream<char, std::char_traits<char> >::_M_write(const char *, long) --> void", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("write", (std::ostream & (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::write, "C++: std::basic_ostream<char, std::char_traits<char> >::write(const char *, long) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("flush", (std::ostream & (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::flush, "C++: std::basic_ostream<char, std::char_traits<char> >::flush() --> std::ostream &", pybind11::return_value_policy::automatic);
		cl.def("seekp", (std::ostream & (std::ostream::*)(long, enum std::_Ios_Seekdir)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(long, enum std::_Ios_Seekdir) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
}


// File: std/stl_vector.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B167_[std::vector<char>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<char>, std::shared_ptr<std::vector<char>>> cl(M("std"), "vector_char_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<char>(); } ) );
		cl.def( pybind11::init<const class std::allocator<char> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<char>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<char> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const char & a1){ return new std::vector<char>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const char &, const class std::allocator<char> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<char> const &o){ return new std::vector<char>(o); } ) );
		cl.def( pybind11::init<const class std::vector<char, class std::allocator<char> > &, const class std::allocator<char> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char *, const char *)) &std::vector<char, std::allocator<char> >::insert<const char *,void>, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char *, const char *) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<char *, std::string >, class __gnu_cxx::__normal_iterator<char *, std::string >)) &std::vector<char, std::allocator<char> >::insert<__gnu_cxx::__normal_iterator<char *, std::string >,void>, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<char *, std::string >, class __gnu_cxx::__normal_iterator<char *, std::string >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("assign", (class std::vector<char, class std::allocator<char> > & (std::vector<char>::*)(const class std::vector<char, class std::allocator<char> > &)) &std::vector<char, std::allocator<char> >::operator=, "C++: std::vector<char, std::allocator<char> >::operator=(const class std::vector<char, class std::allocator<char> > &) --> class std::vector<char, class std::allocator<char> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<char>::*)(unsigned long, const char &)) &std::vector<char, std::allocator<char> >::assign, "C++: std::vector<char, std::allocator<char> >::assign(unsigned long, const char &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::begin, "C++: std::vector<char, std::allocator<char> >::begin() --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::end, "C++: std::vector<char, std::allocator<char> >::end() --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::cbegin, "C++: std::vector<char, std::allocator<char> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::cend, "C++: std::vector<char, std::allocator<char> >::cend() const --> class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("size", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::size, "C++: std::vector<char, std::allocator<char> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::max_size, "C++: std::vector<char, std::allocator<char> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::resize, "C++: std::vector<char, std::allocator<char> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<char>::*)(unsigned long, const char &)) &std::vector<char, std::allocator<char> >::resize, "C++: std::vector<char, std::allocator<char> >::resize(unsigned long, const char &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::shrink_to_fit, "C++: std::vector<char, std::allocator<char> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::capacity, "C++: std::vector<char, std::allocator<char> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::empty, "C++: std::vector<char, std::allocator<char> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::reserve, "C++: std::vector<char, std::allocator<char> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (char & (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::operator[], "C++: std::vector<char, std::allocator<char> >::operator[](unsigned long) --> char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (char & (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::at, "C++: std::vector<char, std::allocator<char> >::at(unsigned long) --> char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (char & (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::front, "C++: std::vector<char, std::allocator<char> >::front() --> char &", pybind11::return_value_policy::automatic);
		cl.def("back", (char & (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::back, "C++: std::vector<char, std::allocator<char> >::back() --> char &", pybind11::return_value_policy::automatic);
		cl.def("data", (char * (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::data, "C++: std::vector<char, std::allocator<char> >::data() --> char *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<char>::*)(const char &)) &std::vector<char, std::allocator<char> >::push_back, "C++: std::vector<char, std::allocator<char> >::push_back(const char &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::pop_back, "C++: std::vector<char, std::allocator<char> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char &)) &std::vector<char, std::allocator<char> >::insert, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char &) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, unsigned long, const char &)) &std::vector<char, std::allocator<char> >::insert, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, unsigned long, const char &) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >)) &std::vector<char, std::allocator<char> >::erase, "C++: std::vector<char, std::allocator<char> >::erase(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >)) &std::vector<char, std::allocator<char> >::erase, "C++: std::vector<char, std::allocator<char> >::erase(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<char>::*)(class std::vector<char, class std::allocator<char> > &)) &std::vector<char, std::allocator<char> >::swap, "C++: std::vector<char, std::allocator<char> >::swap(class std::vector<char, class std::allocator<char> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::clear, "C++: std::vector<char, std::allocator<char> >::clear() --> void");
	}
	std::cout << "B168_[std::vector<int>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<int>, std::shared_ptr<std::vector<int>>> cl(M("std"), "vector_int_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<int>(); } ) );
		cl.def( pybind11::init<const class std::allocator<int> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<int>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<int> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const int & a1){ return new std::vector<int>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const int &, const class std::allocator<int> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<int> const &o){ return new std::vector<int>(o); } ) );
		cl.def( pybind11::init<const class std::vector<int, class std::allocator<int> > &, const class std::allocator<int> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<int, class std::allocator<int> > & (std::vector<int>::*)(const class std::vector<int, class std::allocator<int> > &)) &std::vector<int, std::allocator<int> >::operator=, "C++: std::vector<int, std::allocator<int> >::operator=(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<int>::*)(unsigned long, const int &)) &std::vector<int, std::allocator<int> >::assign, "C++: std::vector<int, std::allocator<int> >::assign(unsigned long, const int &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::begin, "C++: std::vector<int, std::allocator<int> >::begin() --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::end, "C++: std::vector<int, std::allocator<int> >::end() --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::cbegin, "C++: std::vector<int, std::allocator<int> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::cend, "C++: std::vector<int, std::allocator<int> >::cend() const --> class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("size", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::size, "C++: std::vector<int, std::allocator<int> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::max_size, "C++: std::vector<int, std::allocator<int> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::resize, "C++: std::vector<int, std::allocator<int> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<int>::*)(unsigned long, const int &)) &std::vector<int, std::allocator<int> >::resize, "C++: std::vector<int, std::allocator<int> >::resize(unsigned long, const int &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::shrink_to_fit, "C++: std::vector<int, std::allocator<int> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::capacity, "C++: std::vector<int, std::allocator<int> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::empty, "C++: std::vector<int, std::allocator<int> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::reserve, "C++: std::vector<int, std::allocator<int> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (int & (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::operator[], "C++: std::vector<int, std::allocator<int> >::operator[](unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (int & (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::at, "C++: std::vector<int, std::allocator<int> >::at(unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (int & (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::front, "C++: std::vector<int, std::allocator<int> >::front() --> int &", pybind11::return_value_policy::automatic);
		cl.def("back", (int & (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::back, "C++: std::vector<int, std::allocator<int> >::back() --> int &", pybind11::return_value_policy::automatic);
		cl.def("data", (int * (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::data, "C++: std::vector<int, std::allocator<int> >::data() --> int *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<int>::*)(const int &)) &std::vector<int, std::allocator<int> >::push_back, "C++: std::vector<int, std::allocator<int> >::push_back(const int &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::pop_back, "C++: std::vector<int, std::allocator<int> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, const int &)) &std::vector<int, std::allocator<int> >::insert, "C++: std::vector<int, std::allocator<int> >::insert(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, const int &) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, unsigned long, const int &)) &std::vector<int, std::allocator<int> >::insert, "C++: std::vector<int, std::allocator<int> >::insert(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, unsigned long, const int &) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >)) &std::vector<int, std::allocator<int> >::erase, "C++: std::vector<int, std::allocator<int> >::erase(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >)) &std::vector<int, std::allocator<int> >::erase, "C++: std::vector<int, std::allocator<int> >::erase(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<int>::*)(class std::vector<int, class std::allocator<int> > &)) &std::vector<int, std::allocator<int> >::swap, "C++: std::vector<int, std::allocator<int> >::swap(class std::vector<int, class std::allocator<int> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::clear, "C++: std::vector<int, std::allocator<int> >::clear() --> void");
	}
}


// File: std/stl_vector_1.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B169_[std::vector<std::string,std::allocator<std::string >>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<std::string,std::allocator<std::string >>, std::shared_ptr<std::vector<std::string,std::allocator<std::string >>>> cl(M("std"), "vector_std_string_std_allocator_std_string_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<std::string,std::allocator<std::string >>(); } ) );
		cl.def( pybind11::init<const class std::allocator<std::string > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<std::string,std::allocator<std::string >>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<std::string > &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const class std::__cxx11::basic_string<char> & a1){ return new std::vector<std::string,std::allocator<std::string >>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const std::string &, const class std::allocator<std::string > &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<std::string,std::allocator<std::string >> const &o){ return new std::vector<std::string,std::allocator<std::string >>(o); } ) );
		cl.def( pybind11::init<const class std::vector<std::string, class std::allocator<std::string > > &, const class std::allocator<std::string > &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<std::string, class std::allocator<std::string > > & (std::vector<std::string,std::allocator<std::string >>::*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &std::vector<std::string, std::allocator<std::string > >::operator=, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::operator=(const class std::vector<std::string, class std::allocator<std::string > > &) --> class std::vector<std::string, class std::allocator<std::string > > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long, const std::string &)) &std::vector<std::string, std::allocator<std::string > >::assign, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::assign(unsigned long, const std::string &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::begin, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::begin() --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::end, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::end() --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::cbegin, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::cbegin() const --> class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::cend, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::cend() const --> class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >");
		cl.def("size", (unsigned long (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::size, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::max_size, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long)) &std::vector<std::string, std::allocator<std::string > >::resize, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long, const std::string &)) &std::vector<std::string, std::allocator<std::string > >::resize, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::resize(unsigned long, const std::string &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::shrink_to_fit, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::capacity, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<std::string,std::allocator<std::string >>::*)() const) &std::vector<std::string, std::allocator<std::string > >::empty, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long)) &std::vector<std::string, std::allocator<std::string > >::reserve, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (std::string & (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long)) &std::vector<std::string, std::allocator<std::string > >::operator[], "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::operator[](unsigned long) --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (std::string & (std::vector<std::string,std::allocator<std::string >>::*)(unsigned long)) &std::vector<std::string, std::allocator<std::string > >::at, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::at(unsigned long) --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (std::string & (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::front, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::front() --> std::string &", pybind11::return_value_policy::automatic);
		cl.def("back", (std::string & (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::back, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::back() --> std::string &", pybind11::return_value_policy::automatic);
		cl.def("data", (std::string * (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::data, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::data() --> std::string *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<std::string,std::allocator<std::string >>::*)(const std::string &)) &std::vector<std::string, std::allocator<std::string > >::push_back, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::push_back(const std::string &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::pop_back, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, const std::string &)) &std::vector<std::string, std::allocator<std::string > >::insert, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::insert(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, const std::string &) --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, unsigned long, const std::string &)) &std::vector<std::string, std::allocator<std::string > >::insert, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::insert(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, unsigned long, const std::string &) --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >)) &std::vector<std::string, std::allocator<std::string > >::erase, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::erase(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >) --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > > (std::vector<std::string,std::allocator<std::string >>::*)(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >)) &std::vector<std::string, std::allocator<std::string > >::erase, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::erase(class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >, class __gnu_cxx::__normal_iterator<const std::string *, class std::vector<std::string, class std::allocator<std::string > > >) --> class __gnu_cxx::__normal_iterator<std::string *, class std::vector<std::string, class std::allocator<std::string > > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<std::string,std::allocator<std::string >>::*)(class std::vector<std::string, class std::allocator<std::string > > &)) &std::vector<std::string, std::allocator<std::string > >::swap, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::swap(class std::vector<std::string, class std::allocator<std::string > > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<std::string,std::allocator<std::string >>::*)()) &std::vector<std::string, std::allocator<std::string > >::clear, "C++: std::vector<std::__cxx11::basic_string<char>, std::allocator<std::__cxx11::basic_string<char> > >::clear() --> void");
	}
	std::cout << "B170_[std::vector<signed char>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<signed char>, std::shared_ptr<std::vector<signed char>>> cl(M("std"), "vector_signed_char_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<signed char>(); } ) );
		cl.def( pybind11::init<const class std::allocator<signed char> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<signed char>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<signed char> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const signed char & a1){ return new std::vector<signed char>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const signed char &, const class std::allocator<signed char> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<signed char> const &o){ return new std::vector<signed char>(o); } ) );
		cl.def( pybind11::init<const class std::vector<signed char, class std::allocator<signed char> > &, const class std::allocator<signed char> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<signed char, class std::allocator<signed char> > & (std::vector<signed char>::*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &std::vector<signed char, std::allocator<signed char> >::operator=, "C++: std::vector<signed char, std::allocator<signed char> >::operator=(const class std::vector<signed char, class std::allocator<signed char> > &) --> class std::vector<signed char, class std::allocator<signed char> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<signed char>::*)(unsigned long, const signed char &)) &std::vector<signed char, std::allocator<signed char> >::assign, "C++: std::vector<signed char, std::allocator<signed char> >::assign(unsigned long, const signed char &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::begin, "C++: std::vector<signed char, std::allocator<signed char> >::begin() --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::end, "C++: std::vector<signed char, std::allocator<signed char> >::end() --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::cbegin, "C++: std::vector<signed char, std::allocator<signed char> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::cend, "C++: std::vector<signed char, std::allocator<signed char> >::cend() const --> class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >");
		cl.def("size", (unsigned long (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::size, "C++: std::vector<signed char, std::allocator<signed char> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::max_size, "C++: std::vector<signed char, std::allocator<signed char> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<signed char>::*)(unsigned long)) &std::vector<signed char, std::allocator<signed char> >::resize, "C++: std::vector<signed char, std::allocator<signed char> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<signed char>::*)(unsigned long, const signed char &)) &std::vector<signed char, std::allocator<signed char> >::resize, "C++: std::vector<signed char, std::allocator<signed char> >::resize(unsigned long, const signed char &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::shrink_to_fit, "C++: std::vector<signed char, std::allocator<signed char> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::capacity, "C++: std::vector<signed char, std::allocator<signed char> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<signed char>::*)() const) &std::vector<signed char, std::allocator<signed char> >::empty, "C++: std::vector<signed char, std::allocator<signed char> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<signed char>::*)(unsigned long)) &std::vector<signed char, std::allocator<signed char> >::reserve, "C++: std::vector<signed char, std::allocator<signed char> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (signed char & (std::vector<signed char>::*)(unsigned long)) &std::vector<signed char, std::allocator<signed char> >::operator[], "C++: std::vector<signed char, std::allocator<signed char> >::operator[](unsigned long) --> signed char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (signed char & (std::vector<signed char>::*)(unsigned long)) &std::vector<signed char, std::allocator<signed char> >::at, "C++: std::vector<signed char, std::allocator<signed char> >::at(unsigned long) --> signed char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (signed char & (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::front, "C++: std::vector<signed char, std::allocator<signed char> >::front() --> signed char &", pybind11::return_value_policy::automatic);
		cl.def("back", (signed char & (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::back, "C++: std::vector<signed char, std::allocator<signed char> >::back() --> signed char &", pybind11::return_value_policy::automatic);
		cl.def("data", (signed char * (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::data, "C++: std::vector<signed char, std::allocator<signed char> >::data() --> signed char *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<signed char>::*)(const signed char &)) &std::vector<signed char, std::allocator<signed char> >::push_back, "C++: std::vector<signed char, std::allocator<signed char> >::push_back(const signed char &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::pop_back, "C++: std::vector<signed char, std::allocator<signed char> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, const signed char &)) &std::vector<signed char, std::allocator<signed char> >::insert, "C++: std::vector<signed char, std::allocator<signed char> >::insert(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, const signed char &) --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, unsigned long, const signed char &)) &std::vector<signed char, std::allocator<signed char> >::insert, "C++: std::vector<signed char, std::allocator<signed char> >::insert(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, unsigned long, const signed char &) --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >)) &std::vector<signed char, std::allocator<signed char> >::erase, "C++: std::vector<signed char, std::allocator<signed char> >::erase(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >) --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > > (std::vector<signed char>::*)(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >)) &std::vector<signed char, std::allocator<signed char> >::erase, "C++: std::vector<signed char, std::allocator<signed char> >::erase(class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >, class __gnu_cxx::__normal_iterator<const signed char *, class std::vector<signed char, class std::allocator<signed char> > >) --> class __gnu_cxx::__normal_iterator<signed char *, class std::vector<signed char, class std::allocator<signed char> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<signed char>::*)(class std::vector<signed char, class std::allocator<signed char> > &)) &std::vector<signed char, std::allocator<signed char> >::swap, "C++: std::vector<signed char, std::allocator<signed char> >::swap(class std::vector<signed char, class std::allocator<signed char> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<signed char>::*)()) &std::vector<signed char, std::allocator<signed char> >::clear, "C++: std::vector<signed char, std::allocator<signed char> >::clear() --> void");
	}
}


// File: std/stl_vector_2.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B171_[std::vector<mmtf::Transform>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<mmtf::Transform>, std::shared_ptr<std::vector<mmtf::Transform>>> cl(M("std"), "vector_mmtf_Transform_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<mmtf::Transform>(); } ) );
		cl.def( pybind11::init<const class std::allocator<struct mmtf::Transform> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<mmtf::Transform>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<struct mmtf::Transform> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const struct mmtf::Transform & a1){ return new std::vector<mmtf::Transform>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const struct mmtf::Transform &, const class std::allocator<struct mmtf::Transform> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<mmtf::Transform> const &o){ return new std::vector<mmtf::Transform>(o); } ) );
		cl.def( pybind11::init<const class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &, const class std::allocator<struct mmtf::Transform> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > & (std::vector<mmtf::Transform>::*)(const class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::operator=, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::operator=(const class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) --> class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<mmtf::Transform>::*)(unsigned long, const struct mmtf::Transform &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::assign, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::assign(unsigned long, const struct mmtf::Transform &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::begin, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::begin() --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::end, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::end() --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::cbegin, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::cend, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::cend() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >");
		cl.def("size", (unsigned long (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::size, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::max_size, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<mmtf::Transform>::*)(unsigned long)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::resize, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<mmtf::Transform>::*)(unsigned long, const struct mmtf::Transform &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::resize, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::resize(unsigned long, const struct mmtf::Transform &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::shrink_to_fit, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::capacity, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<mmtf::Transform>::*)() const) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::empty, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<mmtf::Transform>::*)(unsigned long)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::reserve, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (struct mmtf::Transform & (std::vector<mmtf::Transform>::*)(unsigned long)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::operator[], "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::operator[](unsigned long) --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct mmtf::Transform & (std::vector<mmtf::Transform>::*)(unsigned long)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::at, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::at(unsigned long) --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct mmtf::Transform & (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::front, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::front() --> struct mmtf::Transform &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct mmtf::Transform & (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::back, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::back() --> struct mmtf::Transform &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct mmtf::Transform * (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::data, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::data() --> struct mmtf::Transform *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<mmtf::Transform>::*)(const struct mmtf::Transform &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::push_back, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::push_back(const struct mmtf::Transform &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::pop_back, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, const struct mmtf::Transform &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::insert, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, const struct mmtf::Transform &) --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, unsigned long, const struct mmtf::Transform &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::insert, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, unsigned long, const struct mmtf::Transform &) --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::erase, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > > (std::vector<mmtf::Transform>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::erase, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::Transform *, class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<mmtf::Transform>::*)(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &)) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::swap, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::swap(class std::vector<struct mmtf::Transform, class std::allocator<struct mmtf::Transform> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<mmtf::Transform>::*)()) &std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::clear, "C++: std::vector<mmtf::Transform, std::allocator<mmtf::Transform> >::clear() --> void");
	}
	std::cout << "B172_[std::vector<float>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<float>, std::shared_ptr<std::vector<float>>> cl(M("std"), "vector_float_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<float>(); } ) );
		cl.def( pybind11::init<const class std::allocator<float> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<float>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<float> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const float & a1){ return new std::vector<float>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const float &, const class std::allocator<float> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<float> const &o){ return new std::vector<float>(o); } ) );
		cl.def( pybind11::init<const class std::vector<float, class std::allocator<float> > &, const class std::allocator<float> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<float, class std::allocator<float> > & (std::vector<float>::*)(const class std::vector<float, class std::allocator<float> > &)) &std::vector<float, std::allocator<float> >::operator=, "C++: std::vector<float, std::allocator<float> >::operator=(const class std::vector<float, class std::allocator<float> > &) --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<float>::*)(unsigned long, const float &)) &std::vector<float, std::allocator<float> >::assign, "C++: std::vector<float, std::allocator<float> >::assign(unsigned long, const float &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::begin, "C++: std::vector<float, std::allocator<float> >::begin() --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::end, "C++: std::vector<float, std::allocator<float> >::end() --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::cbegin, "C++: std::vector<float, std::allocator<float> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::cend, "C++: std::vector<float, std::allocator<float> >::cend() const --> class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >");
		cl.def("size", (unsigned long (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::size, "C++: std::vector<float, std::allocator<float> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::max_size, "C++: std::vector<float, std::allocator<float> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<float>::*)(unsigned long)) &std::vector<float, std::allocator<float> >::resize, "C++: std::vector<float, std::allocator<float> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<float>::*)(unsigned long, const float &)) &std::vector<float, std::allocator<float> >::resize, "C++: std::vector<float, std::allocator<float> >::resize(unsigned long, const float &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::shrink_to_fit, "C++: std::vector<float, std::allocator<float> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::capacity, "C++: std::vector<float, std::allocator<float> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<float>::*)() const) &std::vector<float, std::allocator<float> >::empty, "C++: std::vector<float, std::allocator<float> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<float>::*)(unsigned long)) &std::vector<float, std::allocator<float> >::reserve, "C++: std::vector<float, std::allocator<float> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (float & (std::vector<float>::*)(unsigned long)) &std::vector<float, std::allocator<float> >::operator[], "C++: std::vector<float, std::allocator<float> >::operator[](unsigned long) --> float &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (float & (std::vector<float>::*)(unsigned long)) &std::vector<float, std::allocator<float> >::at, "C++: std::vector<float, std::allocator<float> >::at(unsigned long) --> float &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (float & (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::front, "C++: std::vector<float, std::allocator<float> >::front() --> float &", pybind11::return_value_policy::automatic);
		cl.def("back", (float & (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::back, "C++: std::vector<float, std::allocator<float> >::back() --> float &", pybind11::return_value_policy::automatic);
		cl.def("data", (float * (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::data, "C++: std::vector<float, std::allocator<float> >::data() --> float *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<float>::*)(const float &)) &std::vector<float, std::allocator<float> >::push_back, "C++: std::vector<float, std::allocator<float> >::push_back(const float &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::pop_back, "C++: std::vector<float, std::allocator<float> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, const float &)) &std::vector<float, std::allocator<float> >::insert, "C++: std::vector<float, std::allocator<float> >::insert(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, const float &) --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, unsigned long, const float &)) &std::vector<float, std::allocator<float> >::insert, "C++: std::vector<float, std::allocator<float> >::insert(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, unsigned long, const float &) --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >)) &std::vector<float, std::allocator<float> >::erase, "C++: std::vector<float, std::allocator<float> >::erase(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >) --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > > (std::vector<float>::*)(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >)) &std::vector<float, std::allocator<float> >::erase, "C++: std::vector<float, std::allocator<float> >::erase(class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >, class __gnu_cxx::__normal_iterator<const float *, class std::vector<float, class std::allocator<float> > >) --> class __gnu_cxx::__normal_iterator<float *, class std::vector<float, class std::allocator<float> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<float>::*)(class std::vector<float, class std::allocator<float> > &)) &std::vector<float, std::allocator<float> >::swap, "C++: std::vector<float, std::allocator<float> >::swap(class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<float>::*)()) &std::vector<float, std::allocator<float> >::clear, "C++: std::vector<float, std::allocator<float> >::clear() --> void");
	}
}


// File: std/stl_vector_3.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B173_[std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>, std::shared_ptr<std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>>> cl(M("std"), "vector_std_vector_float_std_allocator_float_std_allocator_std_vector_float_std_allocator_float_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>(); } ) );
		cl.def( pybind11::init<const class std::allocator<class std::vector<float, class std::allocator<float> > > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<class std::vector<float, class std::allocator<float> > > &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const class std::vector<float, class std::allocator<float> > & a1){ return new std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::vector<float, class std::allocator<float> > &, const class std::allocator<class std::vector<float, class std::allocator<float> > > &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >> const &o){ return new std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>(o); } ) );
		cl.def( pybind11::init<const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &, const class std::allocator<class std::vector<float, class std::allocator<float> > > &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > & (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::operator=, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::operator=(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long, const class std::vector<float, class std::allocator<float> > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::assign, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::assign(unsigned long, const class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::begin, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::begin() --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::end, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::end() --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::cbegin, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::cbegin() const --> class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::cend, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::cend() const --> class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >");
		cl.def("size", (unsigned long (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::size, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::max_size, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::resize, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long, const class std::vector<float, class std::allocator<float> > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::resize, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::resize(unsigned long, const class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::shrink_to_fit, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::capacity, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)() const) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::empty, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::reserve, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (class std::vector<float, class std::allocator<float> > & (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::operator[], "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::operator[](unsigned long) --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (class std::vector<float, class std::allocator<float> > & (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(unsigned long)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::at, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::at(unsigned long) --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (class std::vector<float, class std::allocator<float> > & (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::front, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::front() --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic);
		cl.def("back", (class std::vector<float, class std::allocator<float> > & (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::back, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::back() --> class std::vector<float, class std::allocator<float> > &", pybind11::return_value_policy::automatic);
		cl.def("data", (class std::vector<float, class std::allocator<float> > * (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::data, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::data() --> class std::vector<float, class std::allocator<float> > *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(const class std::vector<float, class std::allocator<float> > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::push_back, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::push_back(const class std::vector<float, class std::allocator<float> > &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::pop_back, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, const class std::vector<float, class std::allocator<float> > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::insert, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::insert(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, const class std::vector<float, class std::allocator<float> > &) --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, unsigned long, const class std::vector<float, class std::allocator<float> > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::insert, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::insert(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, unsigned long, const class std::vector<float, class std::allocator<float> > &) --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::erase, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::erase(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >) --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > > (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::erase, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::erase(class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >, class __gnu_cxx::__normal_iterator<const class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >) --> class __gnu_cxx::__normal_iterator<class std::vector<float, class std::allocator<float> > *, class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::swap, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::swap(class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<std::vector<float, std::allocator<float> >,std::allocator<std::vector<float, std::allocator<float> > >>::*)()) &std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::clear, "C++: std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >::clear() --> void");
	}
}


// File: std/stl_vector_4.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B174_[std::vector<mmtf::BioAssembly>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<mmtf::BioAssembly>, std::shared_ptr<std::vector<mmtf::BioAssembly>>> cl(M("std"), "vector_mmtf_BioAssembly_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<mmtf::BioAssembly>(); } ) );
		cl.def( pybind11::init<const class std::allocator<struct mmtf::BioAssembly> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<mmtf::BioAssembly>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<struct mmtf::BioAssembly> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const struct mmtf::BioAssembly & a1){ return new std::vector<mmtf::BioAssembly>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const struct mmtf::BioAssembly &, const class std::allocator<struct mmtf::BioAssembly> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<mmtf::BioAssembly> const &o){ return new std::vector<mmtf::BioAssembly>(o); } ) );
		cl.def( pybind11::init<const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &, const class std::allocator<struct mmtf::BioAssembly> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > & (std::vector<mmtf::BioAssembly>::*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::operator=, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::operator=(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<mmtf::BioAssembly>::*)(unsigned long, const struct mmtf::BioAssembly &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::assign, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::assign(unsigned long, const struct mmtf::BioAssembly &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::begin, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::begin() --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::end, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::end() --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::cbegin, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::cend, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::cend() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >");
		cl.def("size", (unsigned long (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::size, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::max_size, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<mmtf::BioAssembly>::*)(unsigned long)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::resize, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<mmtf::BioAssembly>::*)(unsigned long, const struct mmtf::BioAssembly &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::resize, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::resize(unsigned long, const struct mmtf::BioAssembly &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::shrink_to_fit, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::capacity, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<mmtf::BioAssembly>::*)() const) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::empty, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<mmtf::BioAssembly>::*)(unsigned long)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::reserve, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (struct mmtf::BioAssembly & (std::vector<mmtf::BioAssembly>::*)(unsigned long)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::operator[], "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::operator[](unsigned long) --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct mmtf::BioAssembly & (std::vector<mmtf::BioAssembly>::*)(unsigned long)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::at, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::at(unsigned long) --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct mmtf::BioAssembly & (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::front, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::front() --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct mmtf::BioAssembly & (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::back, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::back() --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct mmtf::BioAssembly * (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::data, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::data() --> struct mmtf::BioAssembly *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<mmtf::BioAssembly>::*)(const struct mmtf::BioAssembly &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::push_back, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::push_back(const struct mmtf::BioAssembly &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::pop_back, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, const struct mmtf::BioAssembly &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::insert, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, const struct mmtf::BioAssembly &) --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, unsigned long, const struct mmtf::BioAssembly &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::insert, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, unsigned long, const struct mmtf::BioAssembly &) --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::erase, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > > (std::vector<mmtf::BioAssembly>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::erase, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::BioAssembly *, class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<mmtf::BioAssembly>::*)(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::swap, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::swap(class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<mmtf::BioAssembly>::*)()) &std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::clear, "C++: std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >::clear() --> void");
	}
	std::cout << "B175_[std::vector<mmtf::Entity>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<mmtf::Entity>, std::shared_ptr<std::vector<mmtf::Entity>>> cl(M("std"), "vector_mmtf_Entity_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<mmtf::Entity>(); } ) );
		cl.def( pybind11::init<const class std::allocator<struct mmtf::Entity> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<mmtf::Entity>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<struct mmtf::Entity> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const struct mmtf::Entity & a1){ return new std::vector<mmtf::Entity>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const struct mmtf::Entity &, const class std::allocator<struct mmtf::Entity> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<mmtf::Entity> const &o){ return new std::vector<mmtf::Entity>(o); } ) );
		cl.def( pybind11::init<const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &, const class std::allocator<struct mmtf::Entity> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > & (std::vector<mmtf::Entity>::*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::operator=, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::operator=(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<mmtf::Entity>::*)(unsigned long, const struct mmtf::Entity &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::assign, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::assign(unsigned long, const struct mmtf::Entity &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::begin, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::begin() --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::end, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::end() --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::cbegin, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::cend, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::cend() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >");
		cl.def("size", (unsigned long (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::size, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::max_size, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<mmtf::Entity>::*)(unsigned long)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::resize, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<mmtf::Entity>::*)(unsigned long, const struct mmtf::Entity &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::resize, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::resize(unsigned long, const struct mmtf::Entity &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::shrink_to_fit, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::capacity, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<mmtf::Entity>::*)() const) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::empty, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<mmtf::Entity>::*)(unsigned long)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::reserve, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (struct mmtf::Entity & (std::vector<mmtf::Entity>::*)(unsigned long)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::operator[], "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::operator[](unsigned long) --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct mmtf::Entity & (std::vector<mmtf::Entity>::*)(unsigned long)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::at, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::at(unsigned long) --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct mmtf::Entity & (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::front, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::front() --> struct mmtf::Entity &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct mmtf::Entity & (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::back, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::back() --> struct mmtf::Entity &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct mmtf::Entity * (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::data, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::data() --> struct mmtf::Entity *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<mmtf::Entity>::*)(const struct mmtf::Entity &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::push_back, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::push_back(const struct mmtf::Entity &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::pop_back, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, const struct mmtf::Entity &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::insert, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, const struct mmtf::Entity &) --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, unsigned long, const struct mmtf::Entity &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::insert, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, unsigned long, const struct mmtf::Entity &) --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::erase, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > > (std::vector<mmtf::Entity>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::erase, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::Entity *, class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<mmtf::Entity>::*)(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::swap, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::swap(class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<mmtf::Entity>::*)()) &std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::clear, "C++: std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >::clear() --> void");
	}
}


// File: std/stl_vector_5.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_std_stl_vector_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B176_[std::vector<mmtf::GroupType>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<mmtf::GroupType>, std::shared_ptr<std::vector<mmtf::GroupType>>> cl(M("std"), "vector_mmtf_GroupType_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<mmtf::GroupType>(); } ) );
		cl.def( pybind11::init<const class std::allocator<struct mmtf::GroupType> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<mmtf::GroupType>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<struct mmtf::GroupType> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const struct mmtf::GroupType & a1){ return new std::vector<mmtf::GroupType>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const struct mmtf::GroupType &, const class std::allocator<struct mmtf::GroupType> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<mmtf::GroupType> const &o){ return new std::vector<mmtf::GroupType>(o); } ) );
		cl.def( pybind11::init<const class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &, const class std::allocator<struct mmtf::GroupType> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > & (std::vector<mmtf::GroupType>::*)(const class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::operator=, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::operator=(const class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) --> class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<mmtf::GroupType>::*)(unsigned long, const struct mmtf::GroupType &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::assign, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::assign(unsigned long, const struct mmtf::GroupType &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::begin, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::begin() --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::end, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::end() --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::cbegin, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::cend, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::cend() const --> class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >");
		cl.def("size", (unsigned long (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::size, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::max_size, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<mmtf::GroupType>::*)(unsigned long)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::resize, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<mmtf::GroupType>::*)(unsigned long, const struct mmtf::GroupType &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::resize, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::resize(unsigned long, const struct mmtf::GroupType &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::shrink_to_fit, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::capacity, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<mmtf::GroupType>::*)() const) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::empty, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<mmtf::GroupType>::*)(unsigned long)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::reserve, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (struct mmtf::GroupType & (std::vector<mmtf::GroupType>::*)(unsigned long)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::operator[], "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::operator[](unsigned long) --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (struct mmtf::GroupType & (std::vector<mmtf::GroupType>::*)(unsigned long)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::at, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::at(unsigned long) --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (struct mmtf::GroupType & (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::front, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::front() --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic);
		cl.def("back", (struct mmtf::GroupType & (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::back, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::back() --> struct mmtf::GroupType &", pybind11::return_value_policy::automatic);
		cl.def("data", (struct mmtf::GroupType * (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::data, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::data() --> struct mmtf::GroupType *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<mmtf::GroupType>::*)(const struct mmtf::GroupType &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::push_back, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::push_back(const struct mmtf::GroupType &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::pop_back, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, const struct mmtf::GroupType &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::insert, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, const struct mmtf::GroupType &) --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, unsigned long, const struct mmtf::GroupType &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::insert, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::insert(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, unsigned long, const struct mmtf::GroupType &) --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::erase, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > > (std::vector<mmtf::GroupType>::*)(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::erase, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::erase(class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >, class __gnu_cxx::__normal_iterator<const struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >) --> class __gnu_cxx::__normal_iterator<struct mmtf::GroupType *, class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<mmtf::GroupType>::*)(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &)) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::swap, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::swap(class std::vector<struct mmtf::GroupType, class std::allocator<struct mmtf::GroupType> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<mmtf::GroupType>::*)()) &std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::clear, "C++: std::vector<mmtf::GroupType, std::allocator<mmtf::GroupType> >::clear() --> void");
	}
	std::cout << "B177_[std::vector<short>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<short>, std::shared_ptr<std::vector<short>>> cl(M("std"), "vector_short_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<short>(); } ) );
		cl.def( pybind11::init<const class std::allocator<short> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<short>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<short> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const short & a1){ return new std::vector<short>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const short &, const class std::allocator<short> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<short> const &o){ return new std::vector<short>(o); } ) );
		cl.def( pybind11::init<const class std::vector<short, class std::allocator<short> > &, const class std::allocator<short> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<short, class std::allocator<short> > & (std::vector<short>::*)(const class std::vector<short, class std::allocator<short> > &)) &std::vector<short, std::allocator<short> >::operator=, "C++: std::vector<short, std::allocator<short> >::operator=(const class std::vector<short, class std::allocator<short> > &) --> class std::vector<short, class std::allocator<short> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<short>::*)(unsigned long, const short &)) &std::vector<short, std::allocator<short> >::assign, "C++: std::vector<short, std::allocator<short> >::assign(unsigned long, const short &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::begin, "C++: std::vector<short, std::allocator<short> >::begin() --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::end, "C++: std::vector<short, std::allocator<short> >::end() --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::cbegin, "C++: std::vector<short, std::allocator<short> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::cend, "C++: std::vector<short, std::allocator<short> >::cend() const --> class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >");
		cl.def("size", (unsigned long (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::size, "C++: std::vector<short, std::allocator<short> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::max_size, "C++: std::vector<short, std::allocator<short> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<short>::*)(unsigned long)) &std::vector<short, std::allocator<short> >::resize, "C++: std::vector<short, std::allocator<short> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<short>::*)(unsigned long, const short &)) &std::vector<short, std::allocator<short> >::resize, "C++: std::vector<short, std::allocator<short> >::resize(unsigned long, const short &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::shrink_to_fit, "C++: std::vector<short, std::allocator<short> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::capacity, "C++: std::vector<short, std::allocator<short> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<short>::*)() const) &std::vector<short, std::allocator<short> >::empty, "C++: std::vector<short, std::allocator<short> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<short>::*)(unsigned long)) &std::vector<short, std::allocator<short> >::reserve, "C++: std::vector<short, std::allocator<short> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (short & (std::vector<short>::*)(unsigned long)) &std::vector<short, std::allocator<short> >::operator[], "C++: std::vector<short, std::allocator<short> >::operator[](unsigned long) --> short &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (short & (std::vector<short>::*)(unsigned long)) &std::vector<short, std::allocator<short> >::at, "C++: std::vector<short, std::allocator<short> >::at(unsigned long) --> short &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (short & (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::front, "C++: std::vector<short, std::allocator<short> >::front() --> short &", pybind11::return_value_policy::automatic);
		cl.def("back", (short & (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::back, "C++: std::vector<short, std::allocator<short> >::back() --> short &", pybind11::return_value_policy::automatic);
		cl.def("data", (short * (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::data, "C++: std::vector<short, std::allocator<short> >::data() --> short *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<short>::*)(const short &)) &std::vector<short, std::allocator<short> >::push_back, "C++: std::vector<short, std::allocator<short> >::push_back(const short &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::pop_back, "C++: std::vector<short, std::allocator<short> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, const short &)) &std::vector<short, std::allocator<short> >::insert, "C++: std::vector<short, std::allocator<short> >::insert(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, const short &) --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, unsigned long, const short &)) &std::vector<short, std::allocator<short> >::insert, "C++: std::vector<short, std::allocator<short> >::insert(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, unsigned long, const short &) --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >)) &std::vector<short, std::allocator<short> >::erase, "C++: std::vector<short, std::allocator<short> >::erase(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >) --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > > (std::vector<short>::*)(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >)) &std::vector<short, std::allocator<short> >::erase, "C++: std::vector<short, std::allocator<short> >::erase(class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >, class __gnu_cxx::__normal_iterator<const short *, class std::vector<short, class std::allocator<short> > >) --> class __gnu_cxx::__normal_iterator<short *, class std::vector<short, class std::allocator<short> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<short>::*)(class std::vector<short, class std::allocator<short> > &)) &std::vector<short, std::allocator<short> >::swap, "C++: std::vector<short, std::allocator<short> >::swap(class std::vector<short, class std::allocator<short> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<short>::*)()) &std::vector<short, std::allocator<short> >::clear, "C++: std::vector<short, std::allocator<short> >::clear() --> void");
	}
}


// File: std/sstream_tcc.cpp
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <locale> // std::locale
#include <memory> // std::allocator
#include <sstream> // __str__
#include <sstream> // std::__cxx11::basic_istringstream
#include <sstream> // std::__cxx11::basic_ostringstream
#include <sstream> // std::__cxx11::basic_stringbuf
#include <sstream> // std::__cxx11::basic_stringstream
#include <streambuf> // std::basic_streambuf
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

// std::basic_stringbuf file:bits/sstream.tcc line:291
struct PyCallBack_std_stringbuf : public std::stringbuf {
	using std::stringbuf::basic_stringbuf;

	long showmanyc() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "showmanyc");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_stringbuf::showmanyc();
	}
	int underflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "underflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_stringbuf::underflow();
	}
	int pbackfail(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "pbackfail");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_stringbuf::pbackfail(a0);
	}
	int overflow(int a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "overflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_stringbuf::overflow(a0);
	}
	class std::basic_streambuf<char> * setbuf(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "setbuf");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<class std::basic_streambuf<char> *>::value) {
				static pybind11::detail::overload_caster_t<class std::basic_streambuf<char> *> caster;
				return pybind11::detail::cast_ref<class std::basic_streambuf<char> *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class std::basic_streambuf<char> *>(std::move(o));
		}
		return basic_stringbuf::setbuf(a0, a1);
	}
	void imbue(const class std::locale & a0) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "imbue");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::overload_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return basic_streambuf::imbue(a0);
	}
	int sync() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "sync");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::sync();
	}
	long xsgetn(char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "xsgetn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsgetn(a0, a1);
	}
	int uflow() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "uflow");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::overload_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		return basic_streambuf::uflow();
	}
	long xsputn(const char * a0, long a1) override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::stringbuf *>(this), "xsputn");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<long>::value) {
				static pybind11::detail::overload_caster_t<long> caster;
				return pybind11::detail::cast_ref<long>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<long>(std::move(o));
		}
		return basic_streambuf::xsputn(a0, a1);
	}
};

void bind_std_sstream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B178_[std::stringbuf] ";
	{ // std::basic_stringbuf file:bits/sstream.tcc line:291
		pybind11::class_<std::stringbuf, std::shared_ptr<std::stringbuf>, PyCallBack_std_stringbuf, std::streambuf> cl(M("std"), "stringbuf", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::stringbuf(); }, [](){ return new PyCallBack_std_stringbuf(); } ), "doc");
		cl.def( pybind11::init<enum std::_Ios_Openmode>(), pybind11::arg("__mode") );

		cl.def( pybind11::init( [](const class std::__cxx11::basic_string<char> & a0){ return new std::stringbuf(a0); }, [](const class std::__cxx11::basic_string<char> & a0){ return new PyCallBack_std_stringbuf(a0); } ), "doc");
		cl.def( pybind11::init<const std::string &, enum std::_Ios_Openmode>(), pybind11::arg("__str"), pybind11::arg("__mode") );

		cl.def("swap", (void (std::stringbuf::*)(class std::basic_stringbuf<char> &)) &std::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::swap, "C++: std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::swap(class std::basic_stringbuf<char> &) --> void", pybind11::arg("__rhs"));
		cl.def("str", (std::string (std::stringbuf::*)() const) &std::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::str, "C++: std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::str() const --> std::string");
		cl.def("str", (void (std::stringbuf::*)(const std::string &)) &std::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::str, "C++: std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::str(const std::string &) --> void", pybind11::arg("__s"));
		cl.def("pubimbue", (class std::locale (std::streambuf::*)(const class std::locale &)) &std::basic_streambuf<char, std::char_traits<char> >::pubimbue, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubimbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::streambuf::*)() const) &std::basic_streambuf<char, std::char_traits<char> >::getloc, "C++: std::basic_streambuf<char, std::char_traits<char> >::getloc() const --> class std::locale");
		cl.def("pubsetbuf", (class std::basic_streambuf<char> * (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsetbuf(char *, long) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("pubsync", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::pubsync, "C++: std::basic_streambuf<char, std::char_traits<char> >::pubsync() --> int");
		cl.def("in_avail", (long (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::in_avail, "C++: std::basic_streambuf<char, std::char_traits<char> >::in_avail() --> long");
		cl.def("snextc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::snextc, "C++: std::basic_streambuf<char, std::char_traits<char> >::snextc() --> int");
		cl.def("sbumpc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sbumpc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sbumpc() --> int");
		cl.def("sgetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sgetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetc() --> int");
		cl.def("sgetn", (long (std::streambuf::*)(char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sgetn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sgetn(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("sputbackc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputbackc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputbackc(char) --> int", pybind11::arg("__c"));
		cl.def("sungetc", (int (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::sungetc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sungetc() --> int");
		cl.def("sputc", (int (std::streambuf::*)(char)) &std::basic_streambuf<char, std::char_traits<char> >::sputc, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputc(char) --> int", pybind11::arg("__c"));
		cl.def("sputn", (long (std::streambuf::*)(const char *, long)) &std::basic_streambuf<char, std::char_traits<char> >::sputn, "C++: std::basic_streambuf<char, std::char_traits<char> >::sputn(const char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("stossc", (void (std::streambuf::*)()) &std::basic_streambuf<char, std::char_traits<char> >::stossc, "C++: std::basic_streambuf<char, std::char_traits<char> >::stossc() --> void");
		cl.def("__safe_gbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_gbump(long) --> void", pybind11::arg("__n"));
		cl.def("__safe_pbump", (void (std::streambuf::*)(long)) &std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump, "C++: std::basic_streambuf<char, std::char_traits<char> >::__safe_pbump(long) --> void", pybind11::arg("__n"));
	}
	std::cout << "B179_[std::istringstream] ";
	std::cout << "B180_[std::ostringstream] ";
	std::cout << "B181_[std::stringstream] ";
	{ // std::basic_stringstream file:bits/sstream.tcc line:294
		pybind11::class_<std::stringstream, std::shared_ptr<std::stringstream>, std::iostream> cl(M("std"), "stringstream", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::stringstream(); } ), "doc");
		cl.def( pybind11::init<enum std::_Ios_Openmode>(), pybind11::arg("__m") );

		cl.def( pybind11::init( [](const class std::__cxx11::basic_string<char> & a0){ return new std::stringstream(a0); } ), "doc");
		cl.def( pybind11::init<const std::string &, enum std::_Ios_Openmode>(), pybind11::arg("__str"), pybind11::arg("__m") );

		cl.def("swap", (void (std::stringstream::*)(class std::basic_stringstream<char> &)) &std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::swap, "C++: std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::swap(class std::basic_stringstream<char> &) --> void", pybind11::arg("__rhs"));
		cl.def("rdbuf", (class std::basic_stringbuf<char> * (std::stringstream::*)() const) &std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::rdbuf, "C++: std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::rdbuf() const --> class std::basic_stringbuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("str", (std::string (std::stringstream::*)() const) &std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::str, "C++: std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::str() const --> std::string");
		cl.def("str", (void (std::stringstream::*)(const std::string &)) &std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::str, "C++: std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::str(const std::string &) --> void", pybind11::arg("__s"));
		cl.def("gcount", (long (std::istream::*)() const) &std::basic_istream<char, std::char_traits<char> >::gcount, "C++: std::basic_istream<char, std::char_traits<char> >::gcount() const --> long");
		cl.def("get", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get() --> int");
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &, char)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"), pybind11::arg("__delim"));
		cl.def("get", (class std::basic_istream<char> & (std::istream::*)(class std::basic_streambuf<char> &)) &std::basic_istream<char, std::char_traits<char> >::get, "C++: std::basic_istream<char, std::char_traits<char> >::get(class std::basic_streambuf<char> &) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long, char)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long, char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("getline", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::getline, "C++: std::basic_istream<char, std::char_traits<char> >::getline(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long, int)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long, int) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"), pybind11::arg("__delim"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)(long)) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore(long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("ignore", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::ignore, "C++: std::basic_istream<char, std::char_traits<char> >::ignore() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("peek", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::peek, "C++: std::basic_istream<char, std::char_traits<char> >::peek() --> int");
		cl.def("read", (class std::basic_istream<char> & (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::read, "C++: std::basic_istream<char, std::char_traits<char> >::read(char *, long) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("readsome", (long (std::istream::*)(char *, long)) &std::basic_istream<char, std::char_traits<char> >::readsome, "C++: std::basic_istream<char, std::char_traits<char> >::readsome(char *, long) --> long", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("putback", (class std::basic_istream<char> & (std::istream::*)(char)) &std::basic_istream<char, std::char_traits<char> >::putback, "C++: std::basic_istream<char, std::char_traits<char> >::putback(char) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("unget", (class std::basic_istream<char> & (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::unget, "C++: std::basic_istream<char, std::char_traits<char> >::unget() --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic);
		cl.def("sync", (int (std::istream::*)()) &std::basic_istream<char, std::char_traits<char> >::sync, "C++: std::basic_istream<char, std::char_traits<char> >::sync() --> int");
		cl.def("seekg", (class std::basic_istream<char> & (std::istream::*)(long, enum std::_Ios_Seekdir)) &std::basic_istream<char, std::char_traits<char> >::seekg, "C++: std::basic_istream<char, std::char_traits<char> >::seekg(long, enum std::_Ios_Seekdir) --> class std::basic_istream<char> &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
		cl.def("put", (std::ostream & (std::ostream::*)(char)) &std::basic_ostream<char, std::char_traits<char> >::put, "C++: std::basic_ostream<char, std::char_traits<char> >::put(char) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__c"));
		cl.def("_M_write", (void (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::_M_write, "C++: std::basic_ostream<char, std::char_traits<char> >::_M_write(const char *, long) --> void", pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("write", (std::ostream & (std::ostream::*)(const char *, long)) &std::basic_ostream<char, std::char_traits<char> >::write, "C++: std::basic_ostream<char, std::char_traits<char> >::write(const char *, long) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg("__s"), pybind11::arg("__n"));
		cl.def("flush", (std::ostream & (std::ostream::*)()) &std::basic_ostream<char, std::char_traits<char> >::flush, "C++: std::basic_ostream<char, std::char_traits<char> >::flush() --> std::ostream &", pybind11::return_value_policy::automatic);
		cl.def("seekp", (std::ostream & (std::ostream::*)(long, enum std::_Ios_Seekdir)) &std::basic_ostream<char, std::char_traits<char> >::seekp, "C++: std::basic_ostream<char, std::char_traits<char> >::seekp(long, enum std::_Ios_Seekdir) --> std::ostream &", pybind11::return_value_policy::automatic, pybind11::arg(""), pybind11::arg(""));
	}
	std::cout << "B182_[std::basic_stringbuf<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>] ";
	std::cout << "B183_[std::basic_istringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>] ";
	std::cout << "B184_[std::basic_ostringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>] ";
	std::cout << "B185_[std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>] ";
}


// File: unknown/unknown.cpp
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
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

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B186_[class std::__cxx11::basic_string<char> mmtf::getVersionString()] ";
	// mmtf::getVersionString() file: line:38
	M("mmtf").def("getVersionString", (std::string (*)()) &mmtf::getVersionString, "Get string representation of MMTF spec version implemented here\n\nC++: mmtf::getVersionString() --> std::string");

	std::cout << "B187_[bool mmtf::isVersionSupported(const std::string &)] ";
	// mmtf::isVersionSupported(const std::string &) file: line:44
	M("mmtf").def("isVersionSupported", (bool (*)(const std::string &)) &mmtf::isVersionSupported, "Check if version is supported (minor revisions ok, major ones not)\n \n\n true if supported, false if not\n\nC++: mmtf::isVersionSupported(const std::string &) --> bool", pybind11::arg("version_string"));

	std::cout << "B188_[mmtf::GroupType] ";
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
	std::cout << "B189_[mmtf::Entity] ";
	{ // mmtf::Entity file: line:81
		pybind11::class_<mmtf::Entity, std::shared_ptr<mmtf::Entity>> cl(M("mmtf"), "Entity", "Entity type.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#entitylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::Entity(); } ) );
		cl.def( pybind11::init( [](mmtf::Entity const &o){ return new mmtf::Entity(o); } ) );
		cl.def_readwrite("chainIndexList", &mmtf::Entity::chainIndexList);
		cl.def_readwrite("description", &mmtf::Entity::description);
		cl.def_readwrite("type", &mmtf::Entity::type);
		cl.def_readwrite("sequence", &mmtf::Entity::sequence);
		cl.def("__eq__", (bool (mmtf::Entity::*)(const struct mmtf::Entity &) const) &mmtf::Entity::operator==, "C++: mmtf::Entity::operator==(const struct mmtf::Entity &) const --> bool", pybind11::arg("c"));
		cl.def("assign", (struct mmtf::Entity & (mmtf::Entity::*)(const struct mmtf::Entity &)) &mmtf::Entity::operator=, "C++: mmtf::Entity::operator=(const struct mmtf::Entity &) --> struct mmtf::Entity &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B190_[mmtf::Transform] ";
	{ // mmtf::Transform file: line:107
		pybind11::class_<mmtf::Transform, std::shared_ptr<mmtf::Transform>> cl(M("mmtf"), "Transform", "Transformation definition for a set of chains.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::Transform(); } ) );
		cl.def( pybind11::init( [](mmtf::Transform const &o){ return new mmtf::Transform(o); } ) );
		cl.def_readwrite("chainIndexList", &mmtf::Transform::chainIndexList);
		cl.def("__eq__", (bool (mmtf::Transform::*)(const struct mmtf::Transform &) const) &mmtf::Transform::operator==, "C++: mmtf::Transform::operator==(const struct mmtf::Transform &) const --> bool", pybind11::arg("c"));
		cl.def("assign", (struct mmtf::Transform & (mmtf::Transform::*)(const struct mmtf::Transform &)) &mmtf::Transform::operator=, "C++: mmtf::Transform::operator=(const struct mmtf::Transform &) --> struct mmtf::Transform &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B191_[mmtf::BioAssembly] ";
	{ // mmtf::BioAssembly file: line:130
		pybind11::class_<mmtf::BioAssembly, std::shared_ptr<mmtf::BioAssembly>> cl(M("mmtf"), "BioAssembly", "Data store for the biological assembly annotation.\n\n https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new mmtf::BioAssembly(); } ) );
		cl.def( pybind11::init( [](mmtf::BioAssembly const &o){ return new mmtf::BioAssembly(o); } ) );
		cl.def_readwrite("transformList", &mmtf::BioAssembly::transformList);
		cl.def_readwrite("name", &mmtf::BioAssembly::name);
		cl.def("__eq__", (bool (mmtf::BioAssembly::*)(const struct mmtf::BioAssembly &) const) &mmtf::BioAssembly::operator==, "C++: mmtf::BioAssembly::operator==(const struct mmtf::BioAssembly &) const --> bool", pybind11::arg("c"));
		cl.def("assign", (struct mmtf::BioAssembly & (mmtf::BioAssembly::*)(const struct mmtf::BioAssembly &)) &mmtf::BioAssembly::operator=, "C++: mmtf::BioAssembly::operator=(const struct mmtf::BioAssembly &) --> struct mmtf::BioAssembly &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B192_[mmtf::StructureData] ";
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
		// cl.def_readwrite("msgpack_zone", &mmtf::StructureData::msgpack_zone);
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
	std::cout << "B193_[float mmtf::getDefaultValue<float>()] ";
	// mmtf::getDefaultValue() file: line:386
	M("mmtf").def("getDefaultValue", (float (*)()) &mmtf::getDefaultValue<float>, "C++: mmtf::getDefaultValue() --> float");

	std::cout << "B194_[bool mmtf::isDefaultValue<std::vector<signed char, std::allocator<signed char> >>(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::isDefaultValue<std::vector<signed char, std::allocator<signed char> >>, "C++: mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B195_[bool mmtf::isDefaultValue<std::vector<int, std::allocator<int> >>(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::isDefaultValue<std::vector<int, std::allocator<int> >>, "C++: mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) --> bool", pybind11::arg("value"));

	std::cout << "B196_[bool mmtf::isDefaultValue<std::vector<std::string, std::allocator<std::string > >>(const class std::vector<std::string, class std::allocator<std::string > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::isDefaultValue<std::vector<std::string, std::allocator<std::string > >>, "C++: mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) --> bool", pybind11::arg("value"));

	std::cout << "B197_[bool mmtf::isDefaultValue<std::vector<char, std::allocator<char> >>(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::isDefaultValue<std::vector<char, std::allocator<char> >>, "C++: mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B198_[bool mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>(const class std::vector<float, class std::allocator<float> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<float, class std::allocator<float> > &)) &mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>, "C++: mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) --> bool", pybind11::arg("value"));

	std::cout << "B199_[bool mmtf::isDefaultValue<float>(const float &)] ";
	// mmtf::isDefaultValue(const float &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const float &)) &mmtf::isDefaultValue<float>, "C++: mmtf::isDefaultValue(const float &) --> bool", pybind11::arg("value"));

	std::cout << "B200_[bool mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<std::vector<mmtf::BioAssembly, std::allocator<mmtf::BioAssembly> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B201_[bool mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<std::vector<mmtf::Entity, std::allocator<mmtf::Entity> >>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B202_[bool mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:389
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

}


// File: unknown/unknown_1.cpp
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

void bind_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B203_[bool mmtf::isDefaultValue<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::isDefaultValue<signed char>, "C++: mmtf::isDefaultValue(const class std::vector<signed char, class std::allocator<signed char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B204_[bool mmtf::isDefaultValue<int>(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::isDefaultValue<int>, "C++: mmtf::isDefaultValue(const class std::vector<int, class std::allocator<int> > &) --> bool", pybind11::arg("value"));

	std::cout << "B205_[bool mmtf::isDefaultValue<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const class std::vector<std::string, class std::allocator<std::string > > &) --> bool", pybind11::arg("value"));

	std::cout << "B206_[bool mmtf::isDefaultValue<char>(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::isDefaultValue<char>, "C++: mmtf::isDefaultValue(const class std::vector<char, class std::allocator<char> > &) --> bool", pybind11::arg("value"));

	std::cout << "B207_[bool mmtf::isDefaultValue<float>(const class std::vector<float, class std::allocator<float> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<float, class std::allocator<float> > &)) &mmtf::isDefaultValue<float>, "C++: mmtf::isDefaultValue(const class std::vector<float, class std::allocator<float> > &) --> bool", pybind11::arg("value"));

	std::cout << "B208_[bool mmtf::isDefaultValue<mmtf::BioAssembly>(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &)) &mmtf::isDefaultValue<mmtf::BioAssembly>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::BioAssembly, class std::allocator<struct mmtf::BioAssembly> > &) --> bool", pybind11::arg("value"));

	std::cout << "B209_[bool mmtf::isDefaultValue<mmtf::Entity>(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)] ";
	// mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &)) &mmtf::isDefaultValue<mmtf::Entity>, "C++: mmtf::isDefaultValue(const class std::vector<struct mmtf::Entity, class std::allocator<struct mmtf::Entity> > &) --> bool", pybind11::arg("value"));

	std::cout << "B210_[bool mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)] ";
	// mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) file: line:393
	M("mmtf").def("isDefaultValue", (bool (*)(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &)) &mmtf::isDefaultValue<std::vector<float, std::allocator<float> >>, "C++: mmtf::isDefaultValue(const class std::vector<class std::vector<float, class std::allocator<float> >, class std::allocator<class std::vector<float, class std::allocator<float> > > > &) --> bool", pybind11::arg("value"));

	std::cout << "B211_[bool mmtf::isDefaultValue<std::string>(const std::string &)] ";
	// mmtf::isDefaultValue(const std::string &) file: line:294
	M("mmtf").def("isDefaultValue", (bool (*)(const std::string &)) &mmtf::isDefaultValue<std::string>, "C++: mmtf::isDefaultValue(const std::string &) --> bool", pybind11::arg("value"));

	std::cout << "B212_[bool mmtf::isDefaultValue<std::map<std::string, msgpack::v2::object, std::less<std::string >, std::allocator<std::pair<const std::string, msgpack::v2::object> > >>(const class std::map<std::string, struct msgpack::v2::object, struct std::less<std::string >, class std::allocator<struct std::pair<const std::string, struct msgpack::v2::object> > > &)] ";
	std::cout << "B213_[bool mmtf::isDefaultValue(const struct msgpack::v2::object &)] ";
	std::cout << "B214_[void mmtf::setDefaultValue<float>(float &)] ";
	// mmtf::setDefaultValue(float &) file: line:409
	M("mmtf").def("setDefaultValue", (void (*)(float &)) &mmtf::setDefaultValue<float>, "C++: mmtf::setDefaultValue(float &) --> void", pybind11::arg("value"));

	std::cout << "B215_[bool mmtf::is_hetatm(const char *)] ";
	// mmtf::is_hetatm(const char *) file: line:317
	M("mmtf").def("is_hetatm", (bool (*)(const char *)) &mmtf::is_hetatm, "Check if type is hetatm\n \n\n   cstring of group.chemCompType\n \n\n True if is a HETATM \n Used when printing this struct, also all chemCompTypes are listed, but\n the non-HETATM ones are commented out for reference\n Relevant threads:\n https://github.com/rcsb/mmtf/issues/28\n http://mmcif.wwpdb.org/dictionaries/mmcif_pdbx_v50.dic/Items/_chem_comp.type.html\n\nC++: mmtf::is_hetatm(const char *) --> bool", pybind11::arg("type"));

	std::cout << "B216_[bool mmtf::isValidDateFormatOptional(const std::string &)] ";
	// mmtf::isValidDateFormatOptional(const std::string &) file: line:328
	M("mmtf").def("isValidDateFormatOptional", (bool (*)(const std::string &)) &mmtf::isValidDateFormatOptional, "C++: mmtf::isValidDateFormatOptional(const std::string &) --> bool", pybind11::arg("s"));

	std::cout << "B217_[bool mmtf::hasRightSizeOptional<float>(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::hasRightSizeOptional<float>, "C++: mmtf::hasRightSizeOptional(const class std::vector<float, class std::allocator<float> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B218_[bool mmtf::hasRightSizeOptional<int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::hasRightSizeOptional<int>, "C++: mmtf::hasRightSizeOptional(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B219_[bool mmtf::hasRightSizeOptional<char>(const class std::vector<char, class std::allocator<char> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<char, class std::allocator<char> > &, int)) &mmtf::hasRightSizeOptional<char>, "C++: mmtf::hasRightSizeOptional(const class std::vector<char, class std::allocator<char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B220_[bool mmtf::hasRightSizeOptional<signed char>(const class std::vector<signed char, class std::allocator<signed char> > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<signed char, class std::allocator<signed char> > &, int)) &mmtf::hasRightSizeOptional<signed char>, "C++: mmtf::hasRightSizeOptional(const class std::vector<signed char, class std::allocator<signed char> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B221_[bool mmtf::hasRightSizeOptional<std::string>(const class std::vector<std::string, class std::allocator<std::string > > &, int)] ";
	// mmtf::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) file: line:348
	M("mmtf").def("hasRightSizeOptional", (bool (*)(const class std::vector<std::string, class std::allocator<std::string > > &, int)) &mmtf::hasRightSizeOptional<std::string>, "C++: mmtf::hasRightSizeOptional(const class std::vector<std::string, class std::allocator<std::string > > &, int) --> bool", pybind11::arg("v"), pybind11::arg("exp_size"));

	std::cout << "B222_[bool mmtf::hasValidIndices<int,int>(const int *, unsigned long, int)] ";
	// mmtf::hasValidIndices(const int *, unsigned long, int) file: line:354
	M("mmtf").def("hasValidIndices", (bool (*)(const int *, unsigned long, int)) &mmtf::hasValidIndices<int,int>, "C++: mmtf::hasValidIndices(const int *, unsigned long, int) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B223_[bool mmtf::hasValidIndices<int,unsigned long>(const int *, unsigned long, unsigned long)] ";
	// mmtf::hasValidIndices(const int *, unsigned long, unsigned long) file: line:354
	M("mmtf").def("hasValidIndices", (bool (*)(const int *, unsigned long, unsigned long)) &mmtf::hasValidIndices<int,unsigned long>, "C++: mmtf::hasValidIndices(const int *, unsigned long, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("size"), pybind11::arg("num"));

	std::cout << "B224_[bool mmtf::hasValidIndices<int,int>(const class std::vector<int, class std::allocator<int> > &, int)] ";
	// mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) file: line:362
	M("mmtf").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, int)) &mmtf::hasValidIndices<int,int>, "C++: mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, int) --> bool", pybind11::arg("v"), pybind11::arg("num"));

	std::cout << "B225_[bool mmtf::hasValidIndices<int,unsigned long>(const class std::vector<int, class std::allocator<int> > &, unsigned long)] ";
	// mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) file: line:362
	M("mmtf").def("hasValidIndices", (bool (*)(const class std::vector<int, class std::allocator<int> > &, unsigned long)) &mmtf::hasValidIndices<int,unsigned long>, "C++: mmtf::hasValidIndices(const class std::vector<int, class std::allocator<int> > &, unsigned long) --> bool", pybind11::arg("v"), pybind11::arg("num"));

	std::cout << "B226_[mmtf::DecodeError] ";
	{ // mmtf::DecodeError file: line:23
		pybind11::class_<mmtf::DecodeError, std::shared_ptr<mmtf::DecodeError>, PyCallBack_mmtf_DecodeError, std::runtime_error> cl(M("mmtf"), "DecodeError", "Exception thrown when failing during decoding.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("m") );

		cl.def( pybind11::init( [](PyCallBack_mmtf_DecodeError const &o){ return new PyCallBack_mmtf_DecodeError(o); } ) );
		cl.def( pybind11::init( [](mmtf::DecodeError const &o){ return new mmtf::DecodeError(o); } ) );
		cl.def("assign", (class mmtf::DecodeError & (mmtf::DecodeError::*)(const class mmtf::DecodeError &)) &mmtf::DecodeError::operator=, "C++: mmtf::DecodeError::operator=(const class mmtf::DecodeError &) --> class mmtf::DecodeError &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B227_[mmtf::EncodeError] ";
	{ // mmtf::EncodeError file: line:31
		pybind11::class_<mmtf::EncodeError, std::shared_ptr<mmtf::EncodeError>, PyCallBack_mmtf_EncodeError, std::runtime_error> cl(M("mmtf"), "EncodeError", "Exception thrown when failing during encoding.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init<const std::string &>(), pybind11::arg("m") );

		cl.def( pybind11::init( [](PyCallBack_mmtf_EncodeError const &o){ return new PyCallBack_mmtf_EncodeError(o); } ) );
		cl.def( pybind11::init( [](mmtf::EncodeError const &o){ return new mmtf::EncodeError(o); } ) );
		cl.def("assign", (class mmtf::EncodeError & (mmtf::EncodeError::*)(const class mmtf::EncodeError &)) &mmtf::EncodeError::operator=, "C++: mmtf::EncodeError::operator=(const class mmtf::EncodeError &) --> class mmtf::EncodeError &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B228_[mmtf::BinaryDecoder] ";
	{ // mmtf::BinaryDecoder file: line:30
		pybind11::class_<mmtf::BinaryDecoder, std::shared_ptr<mmtf::BinaryDecoder>> cl(M("mmtf"), "BinaryDecoder", "Helper class to decode msgpack binary into a vector.");
		pybind11::handle cl_type = cl;

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
	}
}


// File: unknown/unknown_2.cpp
#include <functional> // std::less
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
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

void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B229_[void mmtf::assignBigendian4(void *, const char *)] ";
	// mmtf::assignBigendian4(void *, const char *) file: line:122
	M("mmtf").def("assignBigendian4", (void (*)(void *, const char *)) &mmtf::assignBigendian4, "C++: mmtf::assignBigendian4(void *, const char *) --> void", pybind11::arg("dst"), pybind11::arg("src"));

	std::cout << "B230_[void mmtf::assignBigendian2(void *, const char *)] ";
	// mmtf::assignBigendian2(void *, const char *) file: line:126
	M("mmtf").def("assignBigendian2", (void (*)(void *, const char *)) &mmtf::assignBigendian2, "C++: mmtf::assignBigendian2(void *, const char *) --> void", pybind11::arg("dst"), pybind11::arg("src"));

	std::cout << "B231_[void mmtf::arrayCopyBigendian4(void *, const char *, unsigned long)] ";
	// mmtf::arrayCopyBigendian4(void *, const char *, unsigned long) file: line:130
	M("mmtf").def("arrayCopyBigendian4", (void (*)(void *, const char *, unsigned long)) &mmtf::arrayCopyBigendian4, "C++: mmtf::arrayCopyBigendian4(void *, const char *, unsigned long) --> void", pybind11::arg("dst"), pybind11::arg("src"), pybind11::arg("n"));

	std::cout << "B232_[void mmtf::arrayCopyBigendian2(void *, const char *, unsigned long)] ";
	// mmtf::arrayCopyBigendian2(void *, const char *, unsigned long) file: line:136
	M("mmtf").def("arrayCopyBigendian2", (void (*)(void *, const char *, unsigned long)) &mmtf::arrayCopyBigendian2, "C++: mmtf::arrayCopyBigendian2(void *, const char *, unsigned long) --> void", pybind11::arg("dst"), pybind11::arg("src"), pybind11::arg("n"));

	std::cout << "B233_[mmtf::MapDecoder] ";
	{ // mmtf::MapDecoder file: line:30
		pybind11::class_<mmtf::MapDecoder, std::shared_ptr<mmtf::MapDecoder>> cl(M("mmtf"), "MapDecoder", "Helper class to decode msgpack maps into object fields.");
		pybind11::handle cl_type = cl;

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
		cl.def("checkExtraKeys", (void (mmtf::MapDecoder::*)()) &mmtf::MapDecoder::checkExtraKeys, "Check if there are any keys, that were not decoded.\n This is to be called after all expected fields have been decoded.\n A warning is written to stderr for each non-decoded key.\n\nC++: mmtf::MapDecoder::checkExtraKeys() --> void");
	}
}


// File: unknown/unknown_3.cpp
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
	std::cout << "B234_[void mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long)] ";
	// mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long) file: line:34
	M("mmtf").def("decodeFromBuffer", (void (*)(struct mmtf::StructureData &, const char *, unsigned long)) &mmtf::decodeFromBuffer, "Decode an MMTF data structure from a byte buffer.\n \n\n   MMTF data structure to be filled\n \n\n File contents\n \n\n   Size of buffer\n \n\n mmtf::DecodeError if an error occured\n\nC++: mmtf::decodeFromBuffer(struct mmtf::StructureData &, const char *, unsigned long) --> void", pybind11::arg("data"), pybind11::arg("buffer"), pybind11::arg("size"));

	std::cout << "B235_[void mmtf::decodeFromStream<std::basic_ifstream<char>>(struct mmtf::StructureData &, class std::basic_ifstream<char> &)] ";
	// mmtf::decodeFromStream(struct mmtf::StructureData &, class std::basic_ifstream<char> &) file: line:71
	M("mmtf").def("decodeFromStream", (void (*)(struct mmtf::StructureData &, class std::basic_ifstream<char> &)) &mmtf::decodeFromStream<std::basic_ifstream<char>>, "C++: mmtf::decodeFromStream(struct mmtf::StructureData &, class std::basic_ifstream<char> &) --> void", pybind11::arg("data"), pybind11::arg("stream"));

	std::cout << "B236_[void mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &)] ";
	// mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &) file: line:55
	M("mmtf").def("decodeFromFile", (void (*)(struct mmtf::StructureData &, const std::string &)) &mmtf::decodeFromFile, "Decode an MMTF data structure from an existing file.\n \n\n     MMTF data structure to be filled\n \n\n Path to file to load\n \n\n mmtf::DecodeError if an error occured\n\nC++: mmtf::decodeFromFile(struct mmtf::StructureData &, const std::string &) --> void", pybind11::arg("data"), pybind11::arg("filename"));

}


// File: unknown/unknown_4.cpp
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

void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B237_[class std::vector<int, class std::allocator<int> > mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int)] ";
	// mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) file: line:40
	M("mmtf").def("convertFloatsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<float, class std::allocator<float> > &, int)) &mmtf::convertFloatsToInts, "Convert floats to ints via multiplier.\n \n\n        vector of floats\n \n\n    multiply float vector by this\n \n\n vec_out          vec_in * multiplier and rounded\n\nC++: mmtf::convertFloatsToInts(const class std::vector<float, class std::allocator<float> > &, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("multiplier"));

	std::cout << "B238_[class std::vector<int, class std::allocator<int> > mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &) file: line:48
	M("mmtf").def("deltaEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::deltaEncode, "mmtf delta encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          delta encoded int vector\n\nC++: mmtf::deltaEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B239_[class std::vector<int, class std::allocator<int> > mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &)] ";
	// mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) file: line:56
	M("mmtf").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &)) &mmtf::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::runLengthEncode(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B240_[class std::vector<int, class std::allocator<int> > mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &)] ";
	// mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) file: line:63
	M("mmtf").def("runLengthEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<signed char, class std::allocator<signed char> > &)) &mmtf::runLengthEncode, "mmtf run length encode a vector of ints.\n \n\n        vector of ints\n \n\n vec_out          run length encoded int vector\n\nC++: mmtf::runLengthEncode(const class std::vector<signed char, class std::allocator<signed char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B241_[class std::vector<int, class std::allocator<int> > mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int)] ";
	// mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) file: line:72
	M("mmtf").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0) -> std::vector<int, class std::allocator<int> > { return mmtf::recursiveIndexEncode(a0); }, "", pybind11::arg("vec_in"));
	M("mmtf").def("recursiveIndexEncode", [](const class std::vector<int, class std::allocator<int> > & a0, int const & a1) -> std::vector<int, class std::allocator<int> > { return mmtf::recursiveIndexEncode(a0, a1); }, "", pybind11::arg("vec_in"), pybind11::arg("max"));
	M("mmtf").def("recursiveIndexEncode", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<int, class std::allocator<int> > &, int, int)) &mmtf::recursiveIndexEncode, "mmtf recursive index encode a vector of ints.\n \n\n        vector of ints\n \n\n           maximum value of signed 16bit int\n \n\n           minimum value of signed 16bit int\n \n\n vec_out          recursive index encoded vector\n\nC++: mmtf::recursiveIndexEncode(const class std::vector<int, class std::allocator<int> > &, int, int) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"), pybind11::arg("max"), pybind11::arg("min"));

	std::cout << "B242_[class std::vector<int, class std::allocator<int> > mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &)] ";
	// mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) file: line:80
	M("mmtf").def("convertCharsToInts", (class std::vector<int, class std::allocator<int> > (*)(const class std::vector<char, class std::allocator<char> > &)) &mmtf::convertCharsToInts, "mmtf convert char to int\n \n\n        vector of chars\n \n\n vec_out          vector of ints\n\nC++: mmtf::convertCharsToInts(const class std::vector<char, class std::allocator<char> > &) --> class std::vector<int, class std::allocator<int> >", pybind11::arg("vec_in"));

	std::cout << "B243_[void mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)] ";
	// mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) file: line:90
	M("mmtf").def("add_header", [](class std::__cxx11::basic_stringstream<char> & a0, unsigned int const & a1, unsigned int const & a2) -> void { return mmtf::add_header(a0, a1, a2); }, "", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"));
	M("mmtf").def("add_header", (void (*)(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int)) &mmtf::add_header, "Add mmtf header to a stream\n \n\n            stringstream to add a header to\n \n\n    size of array you're adding\n \n\n         the codec type number you're using to encode\n \n\n         the param for the codec you're using (default 0)\n\nC++: mmtf::add_header(class std::basic_stringstream<char> &, unsigned int, unsigned int, unsigned int) --> void", pybind11::arg("ss"), pybind11::arg("array_size"), pybind11::arg("codec"), pybind11::arg("param"));

	std::cout << "B244_[class std::vector<char, class std::allocator<char> > mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &)] ";
	// mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &) file: line:97
	M("mmtf").def("stringstreamToCharVector", (class std::vector<char, class std::allocator<char> > (*)(class std::basic_stringstream<char> &)) &mmtf::stringstreamToCharVector, "Convert stringstream to CharVector\n \n\n            ss to convert\n \n\n                  converted ss\n\nC++: mmtf::stringstreamToCharVector(class std::basic_stringstream<char> &) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("ss"));

	std::cout << "B245_[class std::vector<char, class std::allocator<char> > mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) file: line:109
	M("mmtf").def("encodeInt8ToByte", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeInt8ToByte, "encode 8 bit int to bytes encoding (type 2)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeInt8ToByte(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B246_[class std::vector<char, class std::allocator<char> > mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) file: line:115
	M("mmtf").def("encodeFourByteInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeFourByteInt, "encode 4 bytes to int encoding (type 4)\n \n\n        vector of ints to encode\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeFourByteInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("vec_in"));

	std::cout << "B247_[class std::vector<char, class std::allocator<char> > mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int)] ";
	// mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) file: line:122
	M("mmtf").def("encodeStringVector", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<std::string, class std::allocator<std::string > >, int)) &mmtf::encodeStringVector, "encode string vector encoding (type 5)\n \n\n         vector of strings\n \n\n     maximum length of string\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeStringVector(class std::vector<std::string, class std::allocator<std::string > >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_sv"), pybind11::arg("CHAIN_LEN"));

	std::cout << "B248_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >)] ";
	// mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) file: line:129
	M("mmtf").def("encodeRunLengthChar", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<char, class std::allocator<char> >)) &mmtf::encodeRunLengthChar, "encode Run Length Char encoding (type 6)\n \n\n         vector for chars\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthChar(class std::vector<char, class std::allocator<char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("in_cv"));

	std::cout << "B249_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >)] ";
	// mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) file: line:136
	M("mmtf").def("encodeRunLengthDeltaInt", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<int, class std::allocator<int> >)) &mmtf::encodeRunLengthDeltaInt, "encode Run Length Delta Int encoding (type 8)\n \n\n       vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthDeltaInt(class std::vector<int, class std::allocator<int> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int_vec"));

	std::cout << "B250_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) file: line:143
	M("mmtf").def("encodeRunLengthFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeRunLengthFloat, "encode Run Length Float encoding (type 9)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B251_[class std::vector<char, class std::allocator<char> > mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int)] ";
	// mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) file: line:150
	M("mmtf").def("encodeDeltaRecursiveFloat", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<float, class std::allocator<float> >, int)) &mmtf::encodeDeltaRecursiveFloat, "encode Delta Recursive Float encoding (type 10)\n \n\n     vector of ints\n \n\n    float multiplier\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeDeltaRecursiveFloat(class std::vector<float, class std::allocator<float> >, int) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("floats_in"), pybind11::arg("multiplier"));

	std::cout << "B252_[class std::vector<char, class std::allocator<char> > mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >)] ";
	// mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) file: line:156
	M("mmtf").def("encodeRunLengthInt8", (class std::vector<char, class std::allocator<char> > (*)(class std::vector<signed char, class std::allocator<signed char> >)) &mmtf::encodeRunLengthInt8, "encode Run-Length 8bit int encoding (type 16)\n \n\n     vector of ints\n \n\n cv               char vector of encoded bytes\n\nC++: mmtf::encodeRunLengthInt8(class std::vector<signed char, class std::allocator<signed char> >) --> class std::vector<char, class std::allocator<char> >", pybind11::arg("int8_vec"));

	std::cout << "B253_[void mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int)] ";
	// mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) file: line:36
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1) -> void { return mmtf::encodeToFile(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("filename"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2) -> void { return mmtf::encodeToFile(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToFile", [](const struct mmtf::StructureData & a0, const class std::__cxx11::basic_string<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToFile(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToFile", (void (*)(const struct mmtf::StructureData &, const std::string &, int, int, int)) &mmtf::encodeToFile, "Encode an MMTF data structure into a file.\n \n\n          MMTF data structure to be stored\n \n\n      Path to file to load\n \n\n               Divisor for coordinates\n \n\n  Divisor for occupancy and b-factor\n \n\n       Max. length for chain name strings\n \n\n mmtf::EncodeError if an error occurred\n\n Common settings for the divisors are the default values for a loss-less\n encoding and both set to 10 for a lossy variant.\n\nC++: mmtf::encodeToFile(const struct mmtf::StructureData &, const std::string &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("filename"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

	std::cout << "B254_[void mmtf::encodeToStream<std::basic_ofstream<char>>(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)] ";
	// mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) file: line:50
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1) -> void { return mmtf::encodeToStream(a0, a1); }, "", pybind11::arg("data"), pybind11::arg("stream"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2) -> void { return mmtf::encodeToStream(a0, a1, a2); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"));
	M("mmtf").def("encodeToStream", [](const struct mmtf::StructureData & a0, class std::basic_ofstream<char> & a1, int const & a2, int const & a3) -> void { return mmtf::encodeToStream(a0, a1, a2, a3); }, "", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"));
	M("mmtf").def("encodeToStream", (void (*)(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int)) &mmtf::encodeToStream<std::basic_ofstream<char>>, "C++: mmtf::encodeToStream(const struct mmtf::StructureData &, class std::basic_ofstream<char> &, int, int, int) --> void", pybind11::arg("data"), pybind11::arg("stream"), pybind11::arg("coord_divider"), pybind11::arg("occupancy_b_factor_divider"), pybind11::arg("chain_name_max_length"));

}


#include <map>
#include <memory>
#include <stdexcept>
#include <functional>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_std_exception(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_locale_classes(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_ios_base(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_ostream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_fstream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector_4(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_stl_vector_5(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_sstream_tcc(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(mmtf_cpp, root_module) {
	root_module.doc() = "mmtf_cpp module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "mmtf"},
		{"", "std"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule(p.second.c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_std_exception(M);
	bind_std_locale_classes(M);
	bind_std_ios_base(M);
	bind_std_ostream_tcc(M);
	bind_std_fstream_tcc(M);
	bind_std_stl_vector(M);
	bind_std_stl_vector_1(M);
	bind_std_stl_vector_2(M);
	bind_std_stl_vector_3(M);
	bind_std_stl_vector_4(M);
	bind_std_stl_vector_5(M);
	bind_std_sstream_tcc(M);
	bind_unknown_unknown(M);
	bind_unknown_unknown_1(M);
	bind_unknown_unknown_2(M);
	bind_unknown_unknown_3(M);
	bind_unknown_unknown_4(M);

}

// Source list file: /home/danpf/git/binder/examples/mmtf_example/cmake_bindings/mmtf_cpp.sources
// mmtf_cpp.cpp
// std/exception.cpp
// std/locale_classes.cpp
// std/ios_base.cpp
// std/ostream_tcc.cpp
// std/fstream_tcc.cpp
// std/stl_vector.cpp
// std/stl_vector_1.cpp
// std/stl_vector_2.cpp
// std/stl_vector_3.cpp
// std/stl_vector_4.cpp
// std/stl_vector_5.cpp
// std/sstream_tcc.cpp
// unknown/unknown.cpp
// unknown/unknown_1.cpp
// unknown/unknown_2.cpp
// unknown/unknown_3.cpp
// unknown/unknown_4.cpp

// Modules list file: /home/danpf/git/binder/examples/mmtf_example/cmake_bindings/mmtf_cpp.modules
// mmtf std 
