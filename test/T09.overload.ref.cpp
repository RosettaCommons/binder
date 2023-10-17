// File: T09_overload.cpp
#include <T09.overload.hpp> // A1
#include <T09.overload.hpp> // A2
#include <T09.overload.hpp> // A3
#include <T09.overload.hpp> // A4
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

// A2 file:T09.overload.hpp line:20
struct PyCallBack_A2 : public A2 {
	using A2::A2;

	void f() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const A2 *>(this), "f");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return A2::f();
	}
};

// A3 file:T09.overload.hpp line:27
struct PyCallBack_A3 : public A3 {
	using A3::A3;

	void f() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const A3 *>(this), "f");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"A3::f\"");
	}
};

// A4 file:T09.overload.hpp line:33
struct PyCallBack_A4 : public A4 {
	using A4::A4;

	int operator=(int a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const A4 *>(this), "assign");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"A4::assign\"");
	}
};

void bind_T09_overload(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // A1 file:T09.overload.hpp line:15
		pybind11::class_<A1, std::shared_ptr<A1>> cl(M(""), "A1", "");
		cl.def( pybind11::init( [](){ return new A1(); } ), "doc" );
		cl.def( pybind11::init<int>(), pybind11::arg("a") );

	}
	{ // A2 file:T09.overload.hpp line:20
		pybind11::class_<A2, std::shared_ptr<A2>, PyCallBack_A2> cl(M(""), "A2", "");
		cl.def( pybind11::init( [](){ return new A2(); }, [](){ return new PyCallBack_A2(); } ), "doc");
		cl.def( pybind11::init<int>(), pybind11::arg("a") );

		cl.def("f", (void (A2::*)()) &A2::f, "C++: A2::f() --> void");
		cl.def("assign", (struct A2 & (A2::*)(const struct A2 &)) &A2::operator=, "C++: A2::operator=(const struct A2 &) --> struct A2 &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // A3 file:T09.overload.hpp line:27
		pybind11::class_<A3, std::shared_ptr<A3>, PyCallBack_A3> cl(M(""), "A3", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_A3(); } ), "doc");
		cl.def( pybind11::init<int>(), pybind11::arg("a") );

		cl.def("f", (void (A3::*)()) &A3::f, "C++: A3::f() --> void");
		cl.def("assign", (struct A3 & (A3::*)(const struct A3 &)) &A3::operator=, "C++: A3::operator=(const struct A3 &) --> struct A3 &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // A4 file:T09.overload.hpp line:33
		pybind11::class_<A4, std::shared_ptr<A4>, PyCallBack_A4> cl(M(""), "A4", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_A4(); } ), "doc");
		cl.def( pybind11::init<int>(), pybind11::arg("a") );

		cl.def("assign", (int (A4::*)(int)) &A4::operator=, "C++: A4::operator=(int) --> int", pybind11::arg(""));
		cl.def("assign", (struct A4 & (A4::*)(const struct A4 &)) &A4::operator=, "C++: A4::operator=(const struct A4 &) --> struct A4 &", pybind11::return_value_policy::automatic, pybind11::arg(""));
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

void bind_T09_overload(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T09_overload, root_module) {
	root_module.doc() = "T09_overload module";

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

	bind_T09_overload(M);

}

// Source list file: TEST/T09_overload.sources
// T09_overload.cpp
// T09_overload.cpp

// Modules list file: TEST/T09_overload.modules
// 
