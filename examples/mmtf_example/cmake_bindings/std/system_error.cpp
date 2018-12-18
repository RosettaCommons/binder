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
#include <stdexcept> // std::runtime_error
#include <streambuf> // std::basic_streambuf
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <system_error> // std::errc
#include <system_error> // std::error_code
#include <system_error> // std::error_condition
#include <system_error> // std::hash
#include <system_error> // std::make_error_condition
#include <system_error> // std::system_error

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

// std::system_error file:system_error line:341
struct PyCallBack_std_system_error : public std::system_error {
	using std::system_error::system_error;

	const char * what() const noexcept override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::system_error *>(this), "what");
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

// std::ios_base::failure file:bits/ios_base.h line:255
struct PyCallBack_std_ios_base_failure : public std::ios_base::failure {
	using std::ios_base::failure::failure;

	const char * what() const throw() override { 
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const std::ios_base::failure *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::overload_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return failure::what();
	}
};

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

void bind_std_system_error(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B124_[std::error_code] ";
	{ // std::error_code file:system_error line:146
		pybind11::class_<std::error_code, std::shared_ptr<std::error_code>> cl(M("std"), "error_code", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::error_code(); } ) );
		cl.def( pybind11::init( [](std::error_code const &o){ return new std::error_code(o); } ) );
		cl.def("clear", (void (std::error_code::*)()) &std::error_code::clear, "C++: std::error_code::clear() --> void");
		cl.def("value", (int (std::error_code::*)() const) &std::error_code::value, "C++: std::error_code::value() const --> int");
		cl.def("default_error_condition", (struct std::error_condition (std::error_code::*)() const) &std::error_code::default_error_condition, "C++: std::error_code::default_error_condition() const --> struct std::error_condition");
		cl.def("message", (std::string (std::error_code::*)() const) &std::error_code::message, "C++: std::error_code::message() const --> std::string");
		cl.def("assign", (struct std::error_code & (std::error_code::*)(const struct std::error_code &)) &std::error_code::operator=, "C++: std::error_code::operator=(const struct std::error_code &) --> struct std::error_code &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B125_[struct std::error_condition std::make_error_condition(enum std::errc)] ";
	std::cout << "B126_[std::error_condition] ";
	{ // std::error_condition file:system_error line:224
		pybind11::class_<std::error_condition, std::shared_ptr<std::error_condition>> cl(M("std"), "error_condition", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::error_condition(); } ) );
		cl.def( pybind11::init( [](std::error_condition const &o){ return new std::error_condition(o); } ) );
		cl.def("clear", (void (std::error_condition::*)()) &std::error_condition::clear, "C++: std::error_condition::clear() --> void");
		cl.def("value", (int (std::error_condition::*)() const) &std::error_condition::value, "C++: std::error_condition::value() const --> int");
		cl.def("message", (std::string (std::error_condition::*)() const) &std::error_condition::message, "C++: std::error_condition::message() const --> std::string");
	}
	std::cout << "B127_[std::system_error] ";
	{ // std::system_error file:system_error line:341
		pybind11::class_<std::system_error, std::shared_ptr<std::system_error>, PyCallBack_std_system_error, std::runtime_error> cl(M("std"), "system_error", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::system_error(); }, [](){ return new PyCallBack_std_system_error(); } ), "doc");
		cl.def( pybind11::init<struct std::error_code>(), pybind11::arg("__ec") );

		cl.def( pybind11::init<struct std::error_code, const std::string &>(), pybind11::arg("__ec"), pybind11::arg("__what") );

		cl.def( pybind11::init<struct std::error_code, const char *>(), pybind11::arg("__ec"), pybind11::arg("__what") );

		cl.def( pybind11::init( [](PyCallBack_std_system_error const &o){ return new PyCallBack_std_system_error(o); } ) );
		cl.def( pybind11::init( [](std::system_error const &o){ return new std::system_error(o); } ) );
		cl.def("code", (const struct std::error_code & (std::system_error::*)() const) &std::system_error::code, "C++: std::system_error::code() const --> const struct std::error_code &", pybind11::return_value_policy::automatic);
		cl.def("assign", (class std::system_error & (std::system_error::*)(const class std::system_error &)) &std::system_error::operator=, "C++: std::system_error::operator=(const class std::system_error &) --> class std::system_error &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	std::cout << "B128_[std::hash<std::error_code>] ";
	std::cout << "B129_[std::_Ios_Fmtflags] ";
	// std::_Ios_Fmtflags file:bits/ios_base.h line:57
	pybind11::enum_<std::_Ios_Fmtflags>(M("std"), "_Ios_Fmtflags", pybind11::arithmetic(), "")
		.value("_S_boolalpha", std::_Ios_Fmtflags::_S_boolalpha)
		.value("_S_dec", std::_Ios_Fmtflags::_S_dec)
		.value("_S_fixed", std::_Ios_Fmtflags::_S_fixed)
		.value("_S_hex", std::_Ios_Fmtflags::_S_hex)
		.value("_S_internal", std::_Ios_Fmtflags::_S_internal)
		.value("_S_left", std::_Ios_Fmtflags::_S_left)
		.value("_S_oct", std::_Ios_Fmtflags::_S_oct)
		.value("_S_right", std::_Ios_Fmtflags::_S_right)
		.value("_S_scientific", std::_Ios_Fmtflags::_S_scientific)
		.value("_S_showbase", std::_Ios_Fmtflags::_S_showbase)
		.value("_S_showpoint", std::_Ios_Fmtflags::_S_showpoint)
		.value("_S_showpos", std::_Ios_Fmtflags::_S_showpos)
		.value("_S_skipws", std::_Ios_Fmtflags::_S_skipws)
		.value("_S_unitbuf", std::_Ios_Fmtflags::_S_unitbuf)
		.value("_S_uppercase", std::_Ios_Fmtflags::_S_uppercase)
		.value("_S_adjustfield", std::_Ios_Fmtflags::_S_adjustfield)
		.value("_S_basefield", std::_Ios_Fmtflags::_S_basefield)
		.value("_S_floatfield", std::_Ios_Fmtflags::_S_floatfield)
		.value("_S_ios_fmtflags_end", std::_Ios_Fmtflags::_S_ios_fmtflags_end)
		.value("_S_ios_fmtflags_max", std::_Ios_Fmtflags::_S_ios_fmtflags_max)
		.value("_S_ios_fmtflags_min", std::_Ios_Fmtflags::_S_ios_fmtflags_min)
		.export_values();

;

	std::cout << "B130_[std::_Ios_Openmode] ";
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

	std::cout << "B131_[std::_Ios_Iostate] ";
	// std::_Ios_Iostate file:bits/ios_base.h line:153
	pybind11::enum_<std::_Ios_Iostate>(M("std"), "_Ios_Iostate", pybind11::arithmetic(), "")
		.value("_S_goodbit", std::_Ios_Iostate::_S_goodbit)
		.value("_S_badbit", std::_Ios_Iostate::_S_badbit)
		.value("_S_eofbit", std::_Ios_Iostate::_S_eofbit)
		.value("_S_failbit", std::_Ios_Iostate::_S_failbit)
		.value("_S_ios_iostate_end", std::_Ios_Iostate::_S_ios_iostate_end)
		.value("_S_ios_iostate_max", std::_Ios_Iostate::_S_ios_iostate_max)
		.value("_S_ios_iostate_min", std::_Ios_Iostate::_S_ios_iostate_min)
		.export_values();

;

	std::cout << "B132_[std::_Ios_Seekdir] ";
	// std::_Ios_Seekdir file:bits/ios_base.h line:193
	pybind11::enum_<std::_Ios_Seekdir>(M("std"), "_Ios_Seekdir", pybind11::arithmetic(), "")
		.value("_S_beg", std::_Ios_Seekdir::_S_beg)
		.value("_S_cur", std::_Ios_Seekdir::_S_cur)
		.value("_S_end", std::_Ios_Seekdir::_S_end)
		.value("_S_ios_seekdir_end", std::_Ios_Seekdir::_S_ios_seekdir_end)
		.export_values();

;

	std::cout << "B133_[std::io_errc] ";
	std::cout << "B134_[std::is_error_code_enum<std::io_errc>] ";
	std::cout << "B135_[struct std::error_code std::make_error_code(enum std::io_errc)] ";
	std::cout << "B136_[struct std::error_condition std::make_error_condition(enum std::io_errc)] ";
	std::cout << "B137_[std::ios_base] ";
	{ // std::ios_base file:bits/ios_base.h line:228
		pybind11::class_<std::ios_base, std::shared_ptr<std::ios_base>> cl(M("std"), "ios_base", "");
		pybind11::handle cl_type = cl;

		{ // std::ios_base::failure file:bits/ios_base.h line:255
			auto & enclosing_class = cl;
			pybind11::class_<std::ios_base::failure, std::shared_ptr<std::ios_base::failure>, PyCallBack_std_ios_base_failure, std::system_error> cl(enclosing_class, "failure", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init<const std::string &>(), pybind11::arg("__str") );

			cl.def( pybind11::init<const std::string &, const struct std::error_code &>(), pybind11::arg(""), pybind11::arg("") );

			cl.def( pybind11::init( [](const char * a0){ return new std::ios_base::failure(a0); }, [](const char * a0){ return new PyCallBack_std_ios_base_failure(a0); } ), "doc");
			cl.def( pybind11::init<const char *, const struct std::error_code &>(), pybind11::arg(""), pybind11::arg("") );

			cl.def("what", (const char * (std::ios_base::failure::*)() const) &std::ios_base::failure::what, "C++: std::ios_base::failure::what() const --> const char *", pybind11::return_value_policy::automatic);
			cl.def("assign", (class std::ios_base::failure & (std::ios_base::failure::*)(const class std::ios_base::failure &)) &std::ios_base::failure::operator=, "C++: std::ios_base::failure::operator=(const class std::ios_base::failure &) --> class std::ios_base::failure &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // std::ios_base::Init file:bits/ios_base.h line:601
			auto & enclosing_class = cl;
			pybind11::class_<std::ios_base::Init, std::shared_ptr<std::ios_base::Init>> cl(enclosing_class, "Init", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](){ return new std::ios_base::Init(); } ) );
			cl.def( pybind11::init( [](std::ios_base::Init const &o){ return new std::ios_base::Init(o); } ) );
		}


		pybind11::enum_<std::ios_base::event>(cl, "event", pybind11::arithmetic(), "")
			.value("erase_event", std::ios_base::event::erase_event)
			.value("imbue_event", std::ios_base::event::imbue_event)
			.value("copyfmt_event", std::ios_base::event::copyfmt_event)
			.export_values();

		cl.def("flags", (enum std::_Ios_Fmtflags (std::ios_base::*)() const) &std::ios_base::flags, "C++: std::ios_base::flags() const --> enum std::_Ios_Fmtflags");
		cl.def("flags", (enum std::_Ios_Fmtflags (std::ios_base::*)(enum std::_Ios_Fmtflags)) &std::ios_base::flags, "C++: std::ios_base::flags(enum std::_Ios_Fmtflags) --> enum std::_Ios_Fmtflags", pybind11::arg("__fmtfl"));
		cl.def("setf", (enum std::_Ios_Fmtflags (std::ios_base::*)(enum std::_Ios_Fmtflags)) &std::ios_base::setf, "C++: std::ios_base::setf(enum std::_Ios_Fmtflags) --> enum std::_Ios_Fmtflags", pybind11::arg("__fmtfl"));
		cl.def("setf", (enum std::_Ios_Fmtflags (std::ios_base::*)(enum std::_Ios_Fmtflags, enum std::_Ios_Fmtflags)) &std::ios_base::setf, "C++: std::ios_base::setf(enum std::_Ios_Fmtflags, enum std::_Ios_Fmtflags) --> enum std::_Ios_Fmtflags", pybind11::arg("__fmtfl"), pybind11::arg("__mask"));
		cl.def("unsetf", (void (std::ios_base::*)(enum std::_Ios_Fmtflags)) &std::ios_base::unsetf, "C++: std::ios_base::unsetf(enum std::_Ios_Fmtflags) --> void", pybind11::arg("__mask"));
		cl.def("precision", (long (std::ios_base::*)() const) &std::ios_base::precision, "C++: std::ios_base::precision() const --> long");
		cl.def("precision", (long (std::ios_base::*)(long)) &std::ios_base::precision, "C++: std::ios_base::precision(long) --> long", pybind11::arg("__prec"));
		cl.def("width", (long (std::ios_base::*)() const) &std::ios_base::width, "C++: std::ios_base::width() const --> long");
		cl.def("width", (long (std::ios_base::*)(long)) &std::ios_base::width, "C++: std::ios_base::width(long) --> long", pybind11::arg("__wide"));
		cl.def_static("sync_with_stdio", []() -> bool { return std::ios_base::sync_with_stdio(); }, "");
		cl.def_static("sync_with_stdio", (bool (*)(bool)) &std::ios_base::sync_with_stdio, "C++: std::ios_base::sync_with_stdio(bool) --> bool", pybind11::arg("__sync"));
		cl.def("imbue", (class std::locale (std::ios_base::*)(const class std::locale &)) &std::ios_base::imbue, "C++: std::ios_base::imbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("getloc", (class std::locale (std::ios_base::*)() const) &std::ios_base::getloc, "C++: std::ios_base::getloc() const --> class std::locale");
		cl.def("_M_getloc", (const class std::locale & (std::ios_base::*)() const) &std::ios_base::_M_getloc, "C++: std::ios_base::_M_getloc() const --> const class std::locale &", pybind11::return_value_policy::automatic);
		cl.def_static("xalloc", (int (*)()) &std::ios_base::xalloc, "C++: std::ios_base::xalloc() --> int");
		cl.def("iword", (long & (std::ios_base::*)(int)) &std::ios_base::iword, "C++: std::ios_base::iword(int) --> long &", pybind11::return_value_policy::automatic, pybind11::arg("__ix"));
		cl.def("pword", (void *& (std::ios_base::*)(int)) &std::ios_base::pword, "C++: std::ios_base::pword(int) --> void *&", pybind11::return_value_policy::automatic, pybind11::arg("__ix"));
	}
	std::cout << "B138_[class std::ios_base & std::boolalpha(class std::ios_base &)] ";
	std::cout << "B139_[class std::ios_base & std::noboolalpha(class std::ios_base &)] ";
	std::cout << "B140_[class std::ios_base & std::showbase(class std::ios_base &)] ";
	std::cout << "B141_[class std::ios_base & std::noshowbase(class std::ios_base &)] ";
	std::cout << "B142_[class std::ios_base & std::showpoint(class std::ios_base &)] ";
	std::cout << "B143_[class std::ios_base & std::noshowpoint(class std::ios_base &)] ";
	std::cout << "B144_[class std::ios_base & std::showpos(class std::ios_base &)] ";
	std::cout << "B145_[class std::ios_base & std::noshowpos(class std::ios_base &)] ";
	std::cout << "B146_[class std::ios_base & std::skipws(class std::ios_base &)] ";
	std::cout << "B147_[class std::ios_base & std::noskipws(class std::ios_base &)] ";
	std::cout << "B148_[class std::ios_base & std::uppercase(class std::ios_base &)] ";
	std::cout << "B149_[class std::ios_base & std::nouppercase(class std::ios_base &)] ";
	std::cout << "B150_[class std::ios_base & std::unitbuf(class std::ios_base &)] ";
	std::cout << "B151_[class std::ios_base & std::nounitbuf(class std::ios_base &)] ";
	std::cout << "B152_[class std::ios_base & std::internal(class std::ios_base &)] ";
	std::cout << "B153_[class std::ios_base & std::left(class std::ios_base &)] ";
	std::cout << "B154_[class std::ios_base & std::right(class std::ios_base &)] ";
	std::cout << "B155_[class std::ios_base & std::dec(class std::ios_base &)] ";
	std::cout << "B156_[class std::ios_base & std::hex(class std::ios_base &)] ";
	std::cout << "B157_[class std::ios_base & std::oct(class std::ios_base &)] ";
	std::cout << "B158_[class std::ios_base & std::fixed(class std::ios_base &)] ";
	std::cout << "B159_[class std::ios_base & std::scientific(class std::ios_base &)] ";
	std::cout << "B160_[class std::ios_base & std::hexfloat(class std::ios_base &)] ";
	std::cout << "B161_[class std::ios_base & std::defaultfloat(class std::ios_base &)] ";
	std::cout << "B162_[std::streambuf] ";
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
}
