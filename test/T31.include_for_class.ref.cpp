// File: T31_include_for_class_incl_a_include.cpp
#include <T31.include_for_class.incl.a.include> // aaaa::A
#include <T31.include_for_class.incl.c.include> // aaaa::cccc::operator<<
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

void bind_T31_include_for_class_incl_a_include(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::A file:T31.include_for_class.incl.a.include line:
		pybind11::class_<aaaa::A, std::shared_ptr<aaaa::A>> cl(M("aaaa"), "A", "");
		cl.def( pybind11::init( [](){ return new aaaa::A(); } ) );

		cl.def("__str__", [](aaaa::A const &o) -> std::string { std::ostringstream s; using namespace aaaa::cccc; s << o; return s.str(); } );
	}
}


// File: T31_include_for_class_incl_b_include.cpp
#include <T31.include_for_class.incl.b.extra.include> // +include_for_class
#include <T31.include_for_class.incl.b.include> // bbbb::B
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T31_include_for_class_incl_b_include(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bbbb::B file:T31.include_for_class.incl.b.include line:
		pybind11::class_<bbbb::B, std::shared_ptr<bbbb::B>> cl(M("bbbb"), "B", "");
		cl.def( pybind11::init( [](){ return new bbbb::B(); } ) );
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

void bind_T31_include_for_class_incl_a_include(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T31_include_for_class_incl_b_include(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T31_include_for_class, root_module) {
	root_module.doc() = "T31_include_for_class module";

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
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T31_include_for_class_incl_a_include(M);
	bind_T31_include_for_class_incl_b_include(M);

}

// Source list file: TEST/T31_include_for_class.sources
// T31_include_for_class.cpp
// T31_include_for_class_incl_a_include.cpp
// T31_include_for_class_incl_b_include.cpp

// Modules list file: TEST/T31_include_for_class.modules
// aaaa bbbb 
