// File: T15_inner_class.cpp
#include <T15.inner_class.hpp> // Base
#include <T15.inner_class.hpp> // Base::InnerBase
#include <T15.inner_class.hpp> // Base::InnerTemplate
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

// Base file:T15.inner_class.hpp line:16
struct PyCallBack_Base : public Base {
	using Base::Base;

	void foo() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Base *>(this), "foo");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Base::foo();
	}
};

void bind_T15_inner_class(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Base file:T15.inner_class.hpp line:16
		pybind11::class_<Base, std::shared_ptr<Base>, PyCallBack_Base> cl(M(""), "Base", "");
		cl.def( pybind11::init( [](){ return new Base(); }, [](){ return new PyCallBack_Base(); } ) );
		cl.def("foo", (void (Base::*)()) &Base::foo, "C++: Base::foo() --> void");
		cl.def("assign", (struct Base & (Base::*)(const struct Base &)) &Base::operator=, "C++: Base::operator=(const struct Base &) --> struct Base &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		{ // Base::(anonymous) file:T15.inner_class.hpp line:21
			cl.def_readwrite("a", &Base::a);
			cl.def_readwrite("b", &Base::b);
		}

		{ // Base::InnerBase file:T15.inner_class.hpp line:27
			auto & enclosing_class = cl;
			pybind11::class_<Base::InnerBase, std::shared_ptr<Base::InnerBase>> cl(enclosing_class, "InnerBase", "");
			cl.def( pybind11::init( [](){ return new Base::InnerBase(); } ) );
			cl.def_readwrite("ia", &Base::InnerBase::ia);
			cl.def_readwrite("ib", &Base::InnerBase::ib);
			cl.def("foo_i", (void (Base::InnerBase::*)()) &Base::InnerBase::foo_i, "C++: Base::InnerBase::foo_i() --> void");
		}

		{ // Base::InnerTemplate file:T15.inner_class.hpp line:36
			auto & enclosing_class = cl;
			pybind11::class_<Base::InnerTemplate<int>, std::shared_ptr<Base::InnerTemplate<int>>> cl(enclosing_class, "InnerTemplate_int_t", "");
			cl.def( pybind11::init( [](){ return new Base::InnerTemplate<int>(); } ) );
			cl.def_readwrite("value", &Base::InnerTemplate<int>::value);
		}

		{ // Base::InnerTemplate file:T15.inner_class.hpp line:36
			auto & enclosing_class = cl;
			pybind11::class_<Base::InnerTemplate<float>, std::shared_ptr<Base::InnerTemplate<float>>> cl(enclosing_class, "InnerTemplate_float_t", "");
			cl.def( pybind11::init( [](){ return new Base::InnerTemplate<float>(); } ) );
			cl.def_readwrite("value", &Base::InnerTemplate<float>::value);
		}

	}
}


// File: T15_inner_class_1.cpp
#include <T15.inner_class.hpp> // Base
#include <T15.inner_class.hpp> // n1::A
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

// n1::A file:T15.inner_class.hpp line:43
struct PyCallBack_n1_A : public n1::A {
	using n1::A::A;

	void foo() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const n1::A *>(this), "foo");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Base::foo();
	}
};

void bind_T15_inner_class_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // n1::A file:T15.inner_class.hpp line:43
		pybind11::class_<n1::A, std::shared_ptr<n1::A>, PyCallBack_n1_A, Base> cl(M("n1"), "A", "");
		cl.def( pybind11::init( [](){ return new n1::A(); }, [](){ return new PyCallBack_n1_A(); } ) );
		cl.def("assign", (struct n1::A & (n1::A::*)(const struct n1::A &)) &n1::A::operator=, "C++: n1::A::operator=(const struct n1::A &) --> struct n1::A &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}


// File: T15_inner_class_2.cpp
#include <T15.inner_class.hpp> // Base
#include <T15.inner_class.hpp> // n1::n2::A
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

// n1::n2::A file:T15.inner_class.hpp line:48
struct PyCallBack_n1_n2_A : public n1::n2::A {
	using n1::n2::A::A;

	void foo() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const n1::n2::A *>(this), "foo");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return Base::foo();
	}
};

void bind_T15_inner_class_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // n1::n2::A file:T15.inner_class.hpp line:48
		pybind11::class_<n1::n2::A, std::shared_ptr<n1::n2::A>, PyCallBack_n1_n2_A, n1::A> cl(M("n1::n2"), "A", "");
		cl.def( pybind11::init( [](){ return new n1::n2::A(); }, [](){ return new PyCallBack_n1_n2_A(); } ) );
		cl.def("assign", (struct n1::n2::A & (n1::n2::A::*)(const struct n1::n2::A &)) &n1::n2::A::operator=, "C++: n1::n2::A::operator=(const struct n1::n2::A &) --> struct n1::n2::A &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}


// File: T15_inner_class_3.cpp
#include <T15.inner_class.hpp> // Base
#include <T15.inner_class.hpp> // instantiate_templates

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T15_inner_class_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// instantiate_templates(struct Base::InnerTemplate<int>, struct Base::InnerTemplate<float>) file:T15.inner_class.hpp line:55
	M("").def("instantiate_templates", (void (*)(struct Base::InnerTemplate<int>, struct Base::InnerTemplate<float>)) &instantiate_templates, "C++: instantiate_templates(struct Base::InnerTemplate<int>, struct Base::InnerTemplate<float>) --> void", pybind11::arg(""), pybind11::arg(""));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T15_inner_class(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T15_inner_class_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T15_inner_class_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T15_inner_class_3(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T15_inner_class, root_module) {
	root_module.doc() = "T15_inner_class module";

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
		{"", "n1"},
		{"n1", "n2"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T15_inner_class(M);
	bind_T15_inner_class_1(M);
	bind_T15_inner_class_2(M);
	bind_T15_inner_class_3(M);

}

// Source list file: TEST/T15_inner_class.sources
// T15_inner_class.cpp
// T15_inner_class.cpp
// T15_inner_class_1.cpp
// T15_inner_class_2.cpp
// T15_inner_class_3.cpp

// Modules list file: TEST/T15_inner_class.modules
// n1 n1.n2 
