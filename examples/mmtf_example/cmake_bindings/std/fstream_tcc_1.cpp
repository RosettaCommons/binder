#include <fstream> // std::basic_filebuf
#include <fstream> // std::basic_fstream
#include <fstream> // std::basic_ifstream
#include <fstream> // std::basic_ofstream
#include <functional> // std::less
#include <ios> // std::_Ios_Openmode
#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <iterator> // std::move_iterator
#include <map> // std::map
#include <memory> // std::allocator
#include <memory> // std::uninitialized_copy
#include <sstream> // __str__
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

void bind_std_fstream_tcc_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B176_[std::ofstream] ";
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
		cl.def("rdstate", (enum std::_Ios_Iostate (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::rdstate, "C++: std::basic_ios<char, std::char_traits<char> >::rdstate() const --> enum std::_Ios_Iostate");
		cl.def("clear", [](std::basic_ios<char,std::char_traits<char>> &o) -> void { return o.clear(); }, "");
		cl.def("clear", (void (std::basic_ios<char,std::char_traits<char>>::*)(enum std::_Ios_Iostate)) &std::basic_ios<char, std::char_traits<char> >::clear, "C++: std::basic_ios<char, std::char_traits<char> >::clear(enum std::_Ios_Iostate) --> void", pybind11::arg("__state"));
		cl.def("setstate", (void (std::basic_ios<char,std::char_traits<char>>::*)(enum std::_Ios_Iostate)) &std::basic_ios<char, std::char_traits<char> >::setstate, "C++: std::basic_ios<char, std::char_traits<char> >::setstate(enum std::_Ios_Iostate) --> void", pybind11::arg("__state"));
		cl.def("_M_setstate", (void (std::basic_ios<char,std::char_traits<char>>::*)(enum std::_Ios_Iostate)) &std::basic_ios<char, std::char_traits<char> >::_M_setstate, "C++: std::basic_ios<char, std::char_traits<char> >::_M_setstate(enum std::_Ios_Iostate) --> void", pybind11::arg("__state"));
		cl.def("good", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::good, "C++: std::basic_ios<char, std::char_traits<char> >::good() const --> bool");
		cl.def("eof", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::eof, "C++: std::basic_ios<char, std::char_traits<char> >::eof() const --> bool");
		cl.def("fail", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::fail, "C++: std::basic_ios<char, std::char_traits<char> >::fail() const --> bool");
		cl.def("bad", (bool (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::bad, "C++: std::basic_ios<char, std::char_traits<char> >::bad() const --> bool");
		cl.def("exceptions", (enum std::_Ios_Iostate (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::exceptions, "C++: std::basic_ios<char, std::char_traits<char> >::exceptions() const --> enum std::_Ios_Iostate");
		cl.def("exceptions", (void (std::basic_ios<char,std::char_traits<char>>::*)(enum std::_Ios_Iostate)) &std::basic_ios<char, std::char_traits<char> >::exceptions, "C++: std::basic_ios<char, std::char_traits<char> >::exceptions(enum std::_Ios_Iostate) --> void", pybind11::arg("__except"));
		cl.def("tie", (std::ostream * (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::tie, "C++: std::basic_ios<char, std::char_traits<char> >::tie() const --> std::ostream *", pybind11::return_value_policy::automatic);
		cl.def("tie", (std::ostream * (std::basic_ios<char,std::char_traits<char>>::*)(std::ostream *)) &std::basic_ios<char, std::char_traits<char> >::tie, "C++: std::basic_ios<char, std::char_traits<char> >::tie(std::ostream *) --> std::ostream *", pybind11::return_value_policy::automatic, pybind11::arg("__tiestr"));
		cl.def("rdbuf", (class std::basic_streambuf<char> * (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ios<char, std::char_traits<char> >::rdbuf() const --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic);
		cl.def("rdbuf", (class std::basic_streambuf<char> * (std::basic_ios<char,std::char_traits<char>>::*)(class std::basic_streambuf<char> *)) &std::basic_ios<char, std::char_traits<char> >::rdbuf, "C++: std::basic_ios<char, std::char_traits<char> >::rdbuf(class std::basic_streambuf<char> *) --> class std::basic_streambuf<char> *", pybind11::return_value_policy::automatic, pybind11::arg("__sb"));
		cl.def("copyfmt", (class std::basic_ios<char> & (std::basic_ios<char,std::char_traits<char>>::*)(const class std::basic_ios<char> &)) &std::basic_ios<char, std::char_traits<char> >::copyfmt, "C++: std::basic_ios<char, std::char_traits<char> >::copyfmt(const class std::basic_ios<char> &) --> class std::basic_ios<char> &", pybind11::return_value_policy::automatic, pybind11::arg("__rhs"));
		cl.def("fill", (char (std::basic_ios<char,std::char_traits<char>>::*)() const) &std::basic_ios<char, std::char_traits<char> >::fill, "C++: std::basic_ios<char, std::char_traits<char> >::fill() const --> char");
		cl.def("fill", (char (std::basic_ios<char,std::char_traits<char>>::*)(char)) &std::basic_ios<char, std::char_traits<char> >::fill, "C++: std::basic_ios<char, std::char_traits<char> >::fill(char) --> char", pybind11::arg("__ch"));
		cl.def("imbue", (class std::locale (std::basic_ios<char,std::char_traits<char>>::*)(const class std::locale &)) &std::basic_ios<char, std::char_traits<char> >::imbue, "C++: std::basic_ios<char, std::char_traits<char> >::imbue(const class std::locale &) --> class std::locale", pybind11::arg("__loc"));
		cl.def("narrow", (char (std::basic_ios<char,std::char_traits<char>>::*)(char, char) const) &std::basic_ios<char, std::char_traits<char> >::narrow, "C++: std::basic_ios<char, std::char_traits<char> >::narrow(char, char) const --> char", pybind11::arg("__c"), pybind11::arg("__dfault"));
		cl.def("widen", (char (std::basic_ios<char,std::char_traits<char>>::*)(char) const) &std::basic_ios<char, std::char_traits<char> >::widen, "C++: std::basic_ios<char, std::char_traits<char> >::widen(char) const --> char", pybind11::arg("__c"));
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
	std::cout << "B177_[std::basic_fstream<char,std::char_traits<char>>] ";
	std::cout << "B178_[std::basic_filebuf<wchar_t,std::char_traits<wchar_t>>] ";
	std::cout << "B179_[std::basic_ifstream<wchar_t,std::char_traits<wchar_t>>] ";
	std::cout << "B180_[std::basic_ofstream<wchar_t,std::char_traits<wchar_t>>] ";
	std::cout << "B181_[std::basic_fstream<wchar_t,std::char_traits<wchar_t>>] ";
	std::cout << "B182_[class msgpack::v1::detail::unpack_stack * std::uninitialized_copy<std::move_iterator<msgpack::v1::detail::unpack_stack *>,msgpack::v1::detail::unpack_stack *>(class std::move_iterator<class msgpack::v1::detail::unpack_stack *>, class std::move_iterator<class msgpack::v1::detail::unpack_stack *>, class msgpack::v1::detail::unpack_stack *)] ";
	std::cout << "B183_[class msgpack::v1::detail::unpack_stack * std::uninitialized_copy<__gnu_cxx::__normal_iterator<const msgpack::v1::detail::unpack_stack *, std::vector<msgpack::v1::detail::unpack_stack, std::allocator<msgpack::v1::detail::unpack_stack> > >,msgpack::v1::detail::unpack_stack *>(class __gnu_cxx::__normal_iterator<const class msgpack::v1::detail::unpack_stack *, class std::vector<class msgpack::v1::detail::unpack_stack, class std::allocator<class msgpack::v1::detail::unpack_stack> > >, class __gnu_cxx::__normal_iterator<const class msgpack::v1::detail::unpack_stack *, class std::vector<class msgpack::v1::detail::unpack_stack, class std::allocator<class msgpack::v1::detail::unpack_stack> > >, class msgpack::v1::detail::unpack_stack *)] ";
	std::cout << "B184_[struct msgpack::v2::detail::context<class msgpack::v2::unpacker>::unpack_stack::stack_elem * std::uninitialized_copy<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *>,msgpack::v2::detail::context<msgpack::v2::unpacker>::unpack_stack::stack_elem *>(class std::move_iterator<struct msgpack::v2::detail::context<class msgpack::v2::unpacker>::unpack_stack::stack_elem *>, class std::move_iterator<struct msgpack::v2::detail::context<class msgpack::v2::unpacker>::unpack_stack::stack_elem *>, struct msgpack::v2::detail::context<class msgpack::v2::unpacker>::unpack_stack::stack_elem *)] ";
	std::cout << "B185_[struct msgpack::v2::detail::context<struct msgpack::v2::detail::parse_helper<class msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem * std::uninitialized_copy<std::move_iterator<msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>,msgpack::v2::detail::context<msgpack::v2::detail::parse_helper<msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>(class std::move_iterator<struct msgpack::v2::detail::context<struct msgpack::v2::detail::parse_helper<class msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>, class std::move_iterator<struct msgpack::v2::detail::context<struct msgpack::v2::detail::parse_helper<class msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *>, struct msgpack::v2::detail::context<struct msgpack::v2::detail::parse_helper<class msgpack::v2::detail::create_object_visitor> >::unpack_stack::stack_elem *)] ";
	std::cout << "B186_[char * std::uninitialized_copy<std::move_iterator<char *>,char *>(class std::move_iterator<char *>, class std::move_iterator<char *>, char *)] ";
	std::cout << "B187_[char * std::uninitialized_copy<const char *,char *>(const char *, const char *, char *)] ";
	std::cout << "B188_[struct mmtf::Transform * std::uninitialized_copy<std::move_iterator<mmtf::Transform *>,mmtf::Transform *>(class std::move_iterator<struct mmtf::Transform *>, class std::move_iterator<struct mmtf::Transform *>, struct mmtf::Transform *)] ";
	std::cout << "B189_[signed char * std::uninitialized_copy<std::move_iterator<signed char *>,signed char *>(class std::move_iterator<signed char *>, class std::move_iterator<signed char *>, signed char *)] ";
}
