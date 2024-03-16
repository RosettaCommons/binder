// File: T12_insertion_operator.cpp
#include <T12.insertion_operator.hpp> // A
#include <T12.insertion_operator.hpp> // operator<<
#include <ios> // std::_Ios_Seekdir
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T12_insertion_operator(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // A file:T12.insertion_operator.hpp line:
		pybind11::class_<A, std::shared_ptr<A>> cl(M(""), "A", "");
		cl.def( pybind11::init( [](){ return new A(); } ) );

		cl.def("__str__", [](A const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}


// File: T12_insertion_operator_1.cpp
#include <T12.insertion_operator.hpp> // aaaa::T
#include <T12.insertion_operator.hpp> // aaaa::operator<<
#include <ios> // std::_Ios_Seekdir
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T12_insertion_operator_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::T file:T12.insertion_operator.hpp line:
		pybind11::class_<aaaa::T, std::shared_ptr<aaaa::T>> cl(M("aaaa"), "T", "");
		cl.def( pybind11::init( [](){ return new aaaa::T(); } ) );
		cl.def( pybind11::init( [](aaaa::T const &o){ return new aaaa::T(o); } ) );

		cl.def("__str__", [](aaaa::T const &o) -> std::string { std::ostringstream s; using namespace aaaa; s << o; return s.str(); } );
	}
}


// File: T12_insertion_operator_2.cpp
#include <T12.insertion_operator.hpp> // A1
#include <T12.insertion_operator.hpp> // bbbb::operator<<
#include <ios> // std::_Ios_Seekdir
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T12_insertion_operator_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // A1 file:T12.insertion_operator.hpp line:
		pybind11::class_<A1, std::shared_ptr<A1>> cl(M(""), "A1", "");
		cl.def( pybind11::init( [](){ return new A1(); } ) );
		cl.def_readwrite("a", &A1::a);

		cl.def("__str__", [](A1 const &o) -> std::string { std::ostringstream s; using namespace bbbb; s << o; return s.str(); } );
	}
}


// File: T12_insertion_operator_3.cpp
#include <T12.insertion_operator.hpp> // bbbb::B
#include <T12.insertion_operator.hpp> // bbbb::B2
#include <T12.insertion_operator.hpp> // bbbb::cccc::operator<<
#include <T12.insertion_operator.hpp> // bbbb::operator<<
#include <ios> // std::_Ios_Seekdir
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T12_insertion_operator_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bbbb::B file:T12.insertion_operator.hpp line:
		pybind11::class_<bbbb::B, std::shared_ptr<bbbb::B>> cl(M("bbbb"), "B", "");
		cl.def( pybind11::init( [](){ return new bbbb::B(); } ) );
		cl.def( pybind11::init( [](bbbb::B const &o){ return new bbbb::B(o); } ) );

		cl.def("__str__", [](bbbb::B const &o) -> std::string { std::ostringstream s; using namespace bbbb::cccc; s << o; return s.str(); } );
	}
	{ // bbbb::B2 file:T12.insertion_operator.hpp line:
		pybind11::class_<bbbb::B2, std::shared_ptr<bbbb::B2>> cl(M("bbbb"), "B2", "");
		cl.def( pybind11::init( [](){ return new bbbb::B2(); } ) );

		cl.def("__str__", [](bbbb::B2 const &o) -> std::string { std::ostringstream s; using namespace bbbb; s << o; return s.str(); } );
	}
}


// File: T12_insertion_operator_4.cpp
#include <T12.insertion_operator.hpp> // bbbb::cccc::C
#include <T12.insertion_operator.hpp> // bbbb::cccc::operator<<
#include <ios> // std::_Ios_Seekdir
#include <locale> // std::locale
#include <ostream> // std::basic_ostream
#include <sstream> // __str__
#include <streambuf> // std::basic_streambuf
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T12_insertion_operator_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bbbb::cccc::C file:T12.insertion_operator.hpp line:
		pybind11::class_<bbbb::cccc::C, std::shared_ptr<bbbb::cccc::C>> cl(M("bbbb::cccc"), "C", "");
		cl.def( pybind11::init( [](){ return new bbbb::cccc::C(); } ) );

		cl.def("__str__", [](bbbb::cccc::C const &o) -> std::string { std::ostringstream s; using namespace bbbb::cccc; s << o; return s.str(); } );
	}
}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T12_insertion_operator(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T12_insertion_operator_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T12_insertion_operator_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T12_insertion_operator_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T12_insertion_operator_4(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T12_insertion_operator, root_module) {
	root_module.doc() = "T12_insertion_operator module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			else return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "aaaa"},
		{"", "bbbb"},
		{"bbbb", "cccc"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T12_insertion_operator(M);
	bind_T12_insertion_operator_1(M);
	bind_T12_insertion_operator_2(M);
	bind_T12_insertion_operator_3(M);
	bind_T12_insertion_operator_4(M);

}

// Source list file: TEST/T12_insertion_operator.sources
// T12_insertion_operator.cpp
// T12_insertion_operator.cpp
// T12_insertion_operator_1.cpp
// T12_insertion_operator_2.cpp
// T12_insertion_operator_3.cpp
// T12_insertion_operator_4.cpp

// Modules list file: TEST/T12_insertion_operator.modules
// aaaa bbbb bbbb.cccc 
