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
