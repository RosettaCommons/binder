// File: T17_anonymous.cpp
#include <T17.anonymous.hpp> // Anonymous
#include <T17.anonymous.hpp> // Anonymous::(anonymous)
#include <T17.anonymous.hpp> // S
#include <T17.anonymous.hpp> // S::_D
#include <T17.anonymous.hpp> // _S2
#include <T17.anonymous.hpp> // foo
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

void bind_T17_anonymous(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo() file:T17.anonymous.hpp line:
	M("").def("foo", (void (*)()) &foo, "C++: foo() --> void");

	{ // S file:T17.anonymous.hpp line:
		pybind11::class_<S, std::shared_ptr<S>> cl(M(""), "S", "");
		cl.def( pybind11::init( [](){ return new S(); } ) );
		cl.def_readwrite("a", &S::a);

		{ // S::(anonymous) file:T17.anonymous.hpp line:
			cl.def_readwrite("b", &S::b);
		}

		{ // S::_D file:T17.anonymous.hpp line:
			auto & enclosing_class = cl;
			pybind11::class_<S::_D, std::shared_ptr<S::_D>> cl(enclosing_class, "_D", "");
			cl.def( pybind11::init( [](){ return new S::_D(); } ) );
			cl.def_readwrite("d", &S::_D::d);
		}

	}
	{ // _S2 file:T17.anonymous.hpp line:
		pybind11::class_<_S2, std::shared_ptr<_S2>> cl(M(""), "_S2", "");
		cl.def( pybind11::init( [](){ return new _S2(); } ) );
		cl.def_readwrite("a", &_S2::a);
	}
	{ // Anonymous file:T17.anonymous.hpp line:
		pybind11::class_<Anonymous, std::shared_ptr<Anonymous>> cl(M(""), "Anonymous", "");
		cl.def( pybind11::init( [](){ return new Anonymous(); } ) );

		{ // Anonymous::(anonymous) file:T17.anonymous.hpp line:

			{ // Anonymous::(anonymous union)::(anonymous) file:T17.anonymous.hpp line:
				cl.def_readwrite("x", &Anonymous::x);
				cl.def_readwrite("y", &Anonymous::y);
			}

		}

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

void bind_T17_anonymous(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T17_anonymous, root_module) {
	root_module.doc() = "T17_anonymous module";

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
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T17_anonymous(M);

}

// Source list file: TEST/T17_anonymous.sources
// T17_anonymous.cpp
// T17_anonymous.cpp

// Modules list file: TEST/T17_anonymous.modules
// 
