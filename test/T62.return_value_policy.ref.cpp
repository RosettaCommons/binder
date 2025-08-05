// File: T62_return_value_policy.cpp
#include <T62.return_value_policy.hpp> // A
#include <T62.return_value_policy.hpp> // B
#include <T62.return_value_policy.hpp> // C
#include <T62.return_value_policy.hpp> // D
#include <T62.return_value_policy.hpp> // E
#include <T62.return_value_policy.hpp> // F
#include <T62.return_value_policy.hpp> // get_custom
#include <T62.return_value_policy.hpp> // get_lvalue_ref
#include <T62.return_value_policy.hpp> // get_pointer
#include <T62.return_value_policy.hpp> // my_func_a
#include <T62.return_value_policy.hpp> // my_func_b
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <string> // std::basic_string
#include <string> // std::char_traits

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T62_return_value_policy(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // A file:T62.return_value_policy.hpp line:
		pybind11::class_<A, std::shared_ptr<A>> cl(M(""), "A", "");
		cl.def( pybind11::init( [](A const &o){ return new A(o); } ) );
		cl.def( pybind11::init( [](){ return new A(); } ) );
		cl.def_readwrite("x", &A::x);
		cl.def_readwrite("y", &A::y);
		cl.def("assign", (struct A & (A::*)(const struct A &)) &A::operator=, "C++: A::operator=(const struct A &) --> struct A &", pybind11::return_value_policy::reference_internal, pybind11::arg(""));
	}
	{ // B file:T62.return_value_policy.hpp line:
		pybind11::class_<B, std::shared_ptr<B>> cl(M(""), "B", "");
		cl.def( pybind11::init( [](){ return new B(); } ) );
		cl.def_readwrite("a_member", &B::a_member);
		cl.def_static("get_static_pointer", (struct A * (*)()) &B::get_static_pointer, "C++: B::get_static_pointer() --> struct A *", pybind11::return_value_policy::move);
		cl.def_static("get_static_lvalue_ref", (struct A & (*)()) &B::get_static_lvalue_ref, "C++: B::get_static_lvalue_ref() --> struct A &", pybind11::return_value_policy::reference_internal);
		cl.def("get_member_pointer", (struct A * (B::*)()) &B::get_member_pointer, "C++: B::get_member_pointer() --> struct A *", pybind11::return_value_policy::move);
		cl.def("get_member_lvalue_ref", (struct A & (B::*)()) &B::get_member_lvalue_ref, "C++: B::get_member_lvalue_ref() --> struct A &", pybind11::return_value_policy::reference_internal);
		cl.def("get_custom", (const struct A & (B::*)()) &B::get_custom, "C++: B::get_custom() --> const struct A &", pybind11::return_value_policy::reference);
		cl.def("get_custom", (const struct A & (B::*)(int, int)) &B::get_custom, "C++: B::get_custom(int, int) --> const struct A &", pybind11::return_value_policy::copy, pybind11::arg("x"), pybind11::arg("y"));
		cl.def("get_custom", (int (B::*)(int)) &B::get_custom, "C++: B::get_custom(int) --> int", pybind11::arg("x"));
		cl.def("assign", (struct B & (B::*)(const struct B &)) &B::operator=, "C++: B::operator=(const struct B &) --> struct B &", pybind11::return_value_policy::reference_internal, pybind11::arg("other"));
		cl.def("__iadd__", (struct B & (B::*)(int)) &B::operator+=, "C++: B::operator+=(int) --> struct B &", pybind11::return_value_policy::reference_internal, pybind11::arg("i"));
		cl.def("__isub__", (struct B & (B::*)(int)) &B::operator-=, "C++: B::operator-=(int) --> struct B &", pybind11::return_value_policy::automatic, pybind11::arg("i"));
	}
	// get_pointer() file:T62.return_value_policy.hpp line:
	M("").def("get_pointer", (struct A * (*)()) &get_pointer, "C++: get_pointer() --> struct A *", pybind11::return_value_policy::move);

	// get_lvalue_ref() file:T62.return_value_policy.hpp line:
	M("").def("get_lvalue_ref", (struct A & (*)()) &get_lvalue_ref, "C++: get_lvalue_ref() --> struct A &", pybind11::return_value_policy::copy);

	// get_custom() file:T62.return_value_policy.hpp line:
	M("").def("get_custom", (const struct A & (*)()) &get_custom, "C++: get_custom() --> const struct A &", pybind11::return_value_policy::reference);

	// get_custom(int, int) file:T62.return_value_policy.hpp line:
	M("").def("get_custom", (const struct A & (*)(int, int)) &get_custom, "C++: get_custom(int, int) --> const struct A &", pybind11::return_value_policy::copy, pybind11::arg("x"), pybind11::arg("y"));

	// get_custom(int) file:T62.return_value_policy.hpp line:
	M("").def("get_custom", (int (*)(int)) &get_custom, "C++: get_custom(int) --> int", pybind11::arg("x"));

	// my_func_a(int &) file:T62.return_value_policy.hpp line:
	M("").def("my_func_a", (int & (*)(int &)) &my_func_a<int>, "C++: my_func_a(int &) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("in"));

	// my_func_a(std::string &) file:T62.return_value_policy.hpp line:
	M("").def("my_func_a", (std::string & (*)(std::string &)) &my_func_a<std::string>, "C++: my_func_a(std::string &) --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("in"));

	// my_func_b(int &) file:T62.return_value_policy.hpp line:
	M("").def("my_func_b", (int & (*)(int &)) &my_func_b<int>, "C++: my_func_b(int &) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("in"));

	// my_func_b(std::string &) file:T62.return_value_policy.hpp line:
	M("").def("my_func_b", (std::string & (*)(std::string &)) &my_func_b<std::string>, "C++: my_func_b(std::string &) --> std::string &", pybind11::return_value_policy::copy, pybind11::arg("in"));

	{ // C file:T62.return_value_policy.hpp line:
		pybind11::class_<C, std::shared_ptr<C>> cl(M(""), "C", "");
		cl.def( pybind11::init( [](){ return new C(); } ) );
		cl.def_readwrite("x", &C::x);
		cl.def("get_x", (int & (C::*)()) &C::get_x, "C++: C::get_x() --> int &", pybind11::return_value_policy::copy);
		cl.def("get_x", (const int & (C::*)(int) const) &C::get_x, "C++: C::get_x(int) const --> const int &", pybind11::return_value_policy::copy, pybind11::arg("y"));
	}
	{ // D file:T62.return_value_policy.hpp line:
		pybind11::class_<D, std::shared_ptr<D>> cl(M(""), "D", "");
		cl.def( pybind11::init( [](){ return new D(); } ) );
		cl.def_readwrite("x", &D::x);
		cl.def("get_x", (int & (D::*)()) &D::get_x, "C++: D::get_x() --> int &", pybind11::return_value_policy::move);
		cl.def("get_x", (const int & (D::*)(int) const) &D::get_x, "C++: D::get_x(int) const --> const int &", pybind11::return_value_policy::copy, pybind11::arg("y"));
	}
	{ // E file:T62.return_value_policy.hpp line:
		pybind11::class_<E<int>, std::shared_ptr<E<int>>> cl(M(""), "E_int_t", "");
		cl.def( pybind11::init( [](){ return new E<int>(); } ) );
		cl.def_readwrite("x", &E<int>::x);
		cl.def("get_x", (int & (E<int>::*)()) &E<int>::get_x, "C++: E<int>::get_x() --> int &", pybind11::return_value_policy::copy);
		cl.def("get_x", (const int & (E<int>::*)(int) const) &E<int>::get_x, "C++: E<int>::get_x(int) const --> const int &", pybind11::return_value_policy::copy, pybind11::arg("y"));
	}
	{ // E file:T62.return_value_policy.hpp line:
		pybind11::class_<E<std::string>, std::shared_ptr<E<std::string>>> cl(M(""), "E_std_string_t", "");
		cl.def( pybind11::init( [](){ return new E<std::string>(); } ) );
		cl.def_readwrite("x", &E<std::string>::x);
		cl.def("get_x", (int & (E<std::string>::*)()) &E<std::string>::get_x, "C++: E<std::string>::get_x() --> int &", pybind11::return_value_policy::copy);
		cl.def("get_x", (const int & (E<std::string>::*)(int) const) &E<std::string>::get_x, "C++: E<std::string>::get_x(int) const --> const int &", pybind11::return_value_policy::copy, pybind11::arg("y"));
	}
	{ // F file:T62.return_value_policy.hpp line:
		pybind11::class_<F<int>, std::shared_ptr<F<int>>> cl(M(""), "F_int_t", "");
		cl.def( pybind11::init( [](){ return new F<int>(); } ) );
		cl.def_readwrite("x", &F<int>::x);
		cl.def("get_x", (int & (F<int>::*)()) &F<int>::get_x, "C++: F<int>::get_x() --> int &", pybind11::return_value_policy::copy);
		cl.def("get_x", (const int & (F<int>::*)(int) const) &F<int>::get_x, "C++: F<int>::get_x(int) const --> const int &", pybind11::return_value_policy::copy, pybind11::arg("y"));
	}
	{ // F file:T62.return_value_policy.hpp line:
		pybind11::class_<F<std::string>, std::shared_ptr<F<std::string>>> cl(M(""), "F_std_string_t", "");
		cl.def( pybind11::init( [](){ return new F<std::string>(); } ) );
		cl.def_readwrite("x", &F<std::string>::x);
		cl.def("get_x", (int & (F<std::string>::*)()) &F<std::string>::get_x, "C++: F<std::string>::get_x() --> int &", pybind11::return_value_policy::reference_internal);
		cl.def("get_x", (const int & (F<std::string>::*)(int) const) &F<std::string>::get_x, "C++: F<std::string>::get_x(int) const --> const int &", pybind11::return_value_policy::reference_internal, pybind11::arg("y"));
	}
}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T62_return_value_policy(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T62_return_value_policy, root_module) {
	root_module.doc() = "T62_return_value_policy module";

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
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_T62_return_value_policy(M);

}

// Source list file: TEST/T62_return_value_policy.sources
// T62_return_value_policy.cpp
// T62_return_value_policy.cpp

// Modules list file: TEST/T62_return_value_policy.modules
// 
