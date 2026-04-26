// File: T30_include_incl_a_include.cpp
#include <T30.include.incl.a.include> // aaaa::A
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T30_include_incl_a_include(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // aaaa::A file:T30.include.incl.a.include line:
		pybind11::class_<aaaa::A, std::shared_ptr<aaaa::A>> cl(M("aaaa"), "A", "");
		cl.def( pybind11::init( [](){ return new aaaa::A(); } ) );
	}
}


// File: T30_include_incl_b_include.cpp
#include <T30.include.incl.a.include> // aaaa::A
#include <T30.include.incl.b.include> // bbbb::B
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T30_include_incl_b_include(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bbbb::B file:T30.include.incl.b.include line:
		pybind11::class_<bbbb::B<aaaa::A>, std::shared_ptr<bbbb::B<aaaa::A>>> cl(M("bbbb"), "B_aaaa_A_t", "");
		cl.def( pybind11::init( [](){ return new bbbb::B<aaaa::A>(); } ) );
	}
}


// File: T30_include.cpp
#include <T30.include.hpp> // foo
#include <T30.include.incl.a.include> // aaaa::A
#include <T30.include.incl.b.include> // bbbb::B

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T30_include(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(class bbbb::B<class aaaa::A>) file:T30.include.hpp line:
	M("").def("foo", (void (*)(class bbbb::B<class aaaa::A>)) &foo, "C++: foo(class bbbb::B<class aaaa::A>) --> void", pybind11::arg(""));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T30_include_incl_a_include(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T30_include_incl_b_include(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T30_include(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T30_include, root_module) {
	root_module.doc() = "T30_include module";

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
			return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "aaaa"},
		{"", "bbbb"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T30_include_incl_a_include(M);
	bind_T30_include_incl_b_include(M);
	bind_T30_include(M);

}

// Source list file: TEST/T30_include.sources
// T30_include.cpp
// T30_include_incl_a_include.cpp
// T30_include_incl_b_include.cpp
// T30_include.cpp

// Modules list file: TEST/T30_include.modules
// aaaa bbbb 
