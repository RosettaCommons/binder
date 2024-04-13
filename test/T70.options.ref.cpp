// File: T70_options.cpp
#include <T70.options.hpp> // aaaa::AAAA
#include <T70.options.hpp> // aaaa::E1
#include <T70.options.hpp> // aaaa::foo_aaaa
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

void bind_T70_options(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::AAAA file:T70.options.hpp line:
		pybind11::class_<aaaa::AAAA, std::shared_ptr<aaaa::AAAA>> cl(M("aaaa"), "AAAA", "");
		cl.def( pybind11::init( [](){ return new aaaa::AAAA(); } ) );
		cl.def("foo", (void (aaaa::AAAA::*)()) &aaaa::AAAA::foo, "C++: aaaa::AAAA::foo() --> void");
		cl.def_static("static_foo", (void (*)(int)) &aaaa::AAAA::foo, "C++: aaaa::AAAA::foo(int) --> void", pybind11::arg(""));
	}
	// aaaa::foo_aaaa() file:T70.options.hpp line:
	M("aaaa").def("foo_aaaa", (void (*)()) &aaaa::foo_aaaa, "C++: aaaa::foo_aaaa() --> void");

	// aaaa::E1 file:T70.options.hpp line:
	pybind11::enum_<aaaa::E1>(M("aaaa"), "E1", pybind11::arithmetic(), "")
		.value("E1_V0", aaaa::E1_V0)
		.value("E1_V1", aaaa::E1_V1)
		.export_values();

;

}


// File: T70_options_1.cpp
#include <T70.options.hpp> // aaaa::cccc::CCCC
#include <T70.options.hpp> // aaaa::cccc::foo_CCCC
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

void bind_T70_options_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::cccc::CCCC file:T70.options.hpp line:
		pybind11::class_<aaaa::cccc::CCCC, std::shared_ptr<aaaa::cccc::CCCC>> cl(M("aaaa::cccc"), "CCCC", "");
		cl.def( pybind11::init( [](){ return new aaaa::cccc::CCCC(); } ) );
	}
	// aaaa::cccc::foo_CCCC() file:T70.options.hpp line:
	M("aaaa::cccc").def("foo_CCCC", (void (*)()) &aaaa::cccc::foo_CCCC, "C++: aaaa::cccc::foo_CCCC() --> void");

}


// File: T70_options_2.cpp
#include <T70.options.hpp> // aaaa::bbbb::BBBB
#include <T70.options.hpp> // aaaa::bbbb::foo_bbbb
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

void bind_T70_options_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::bbbb::BBBB file:T70.options.hpp line:
		pybind11::class_<aaaa::bbbb::BBBB, std::shared_ptr<aaaa::bbbb::BBBB>> cl(M("aaaa::bbbb"), "BBBB", "");
		cl.def( pybind11::init( [](){ return new aaaa::bbbb::BBBB(); } ) );
	}
	// aaaa::bbbb::foo_bbbb() file:T70.options.hpp line:
	M("aaaa::bbbb").def("foo_bbbb", (void (*)()) &aaaa::bbbb::foo_bbbb, "C++: aaaa::bbbb::foo_bbbb() --> void");

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T70_options(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T70_options_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T70_options_2(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T70_options, root_module) {
	root_module.doc() = "T70_options module";

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
		{"aaaa", "bbbb"},
		{"aaaa", "cccc"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T70_options(M);
	bind_T70_options_1(M);
	bind_T70_options_2(M);

}

// Source list file: TEST/T70_options.sources
// T70_options.cpp
// T70_options.cpp
// T70_options_1.cpp
// T70_options_2.cpp

// Modules list file: TEST/T70_options.modules
// aaaa aaaa.bbbb aaaa.cccc 
