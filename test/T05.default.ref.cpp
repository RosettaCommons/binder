// File: T05_default.cpp
#include <T05.default.hpp> // A
#include <T05.default.hpp> // B
#include <T05.default.hpp> // foo
#include <T05.default.hpp> // foo_f0
#include <T05.default.hpp> // foo_f1
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

void bind_T05_default(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(int, int, int &, float, const double &, void *, int) file:T05.default.hpp line:
	M("").def("foo", [](int const & a0) -> double { return foo(a0); }, "", pybind11::arg("a"));
	M("").def("foo", [](int const & a0, int const & a1) -> double { return foo(a0, a1); }, "", pybind11::arg("a"), pybind11::arg("i1"));
	M("").def("foo", [](int const & a0, int const & a1, int & a2) -> double { return foo(a0, a1, a2); }, "", pybind11::arg("a"), pybind11::arg("i1"), pybind11::arg("i2"));
	M("").def("foo", [](int const & a0, int const & a1, int & a2, float const & a3) -> double { return foo(a0, a1, a2, a3); }, "", pybind11::arg("a"), pybind11::arg("i1"), pybind11::arg("i2"), pybind11::arg("f"));
	M("").def("foo", [](int const & a0, int const & a1, int & a2, float const & a3, const double & a4) -> double { return foo(a0, a1, a2, a3, a4); }, "", pybind11::arg("a"), pybind11::arg("i1"), pybind11::arg("i2"), pybind11::arg("f"), pybind11::arg("d"));
	M("").def("foo", [](int const & a0, int const & a1, int & a2, float const & a3, const double & a4, void * a5) -> double { return foo(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("a"), pybind11::arg("i1"), pybind11::arg("i2"), pybind11::arg("f"), pybind11::arg("d"), pybind11::arg("p"));
	M("").def("foo", (double (*)(int, int, int &, float, const double &, void *, int)) &foo, "C++: foo(int, int, int &, float, const double &, void *, int) --> double", pybind11::arg("a"), pybind11::arg("i1"), pybind11::arg("i2"), pybind11::arg("f"), pybind11::arg("d"), pybind11::arg("p"), pybind11::arg("q"));

	{ // A file:T05.default.hpp line:
		pybind11::class_<A, std::shared_ptr<A>> cl(M(""), "A", "");
		cl.def( pybind11::init( [](){ return new A(); } ) );
		cl.def( pybind11::init( [](A const &o){ return new A(o); } ) );
	}
	{ // B file:T05.default.hpp line:
		pybind11::class_<B, std::shared_ptr<B>> cl(M(""), "B", "");
		cl.def( pybind11::init( [](){ return new B(); } ), "doc" );
		cl.def( pybind11::init( [](const int & a0){ return new B(a0); } ), "doc" , pybind11::arg("a"));
		cl.def( pybind11::init( [](const int & a0, float const & a1){ return new B(a0, a1); } ), "doc" , pybind11::arg("a"), pybind11::arg("b"));
		cl.def( pybind11::init( [](const int & a0, float const & a1, struct A & a2){ return new B(a0, a1, a2); } ), "doc" , pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("a2"));
		cl.def( pybind11::init( [](const int & a0, float const & a1, struct A & a2, struct A * a3){ return new B(a0, a1, a2, a3); } ), "doc" , pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("a2"), pybind11::arg("a3"));
		cl.def( pybind11::init<const int, float, struct A &, struct A *, int>(), pybind11::arg("a"), pybind11::arg("b"), pybind11::arg("a2"), pybind11::arg("a3"), pybind11::arg("i") );

		cl.def("foo", [](B &o) -> void { return o.foo(); }, "");
		cl.def("foo", [](B &o, struct A const & a0) -> void { return o.foo(a0); }, "", pybind11::arg("a1"));
		cl.def("foo", [](B &o, struct A const & a0, struct A & a1) -> void { return o.foo(a0, a1); }, "", pybind11::arg("a1"), pybind11::arg("a2"));
		cl.def("foo", [](B &o, struct A const & a0, struct A & a1, struct A * a2) -> void { return o.foo(a0, a1, a2); }, "", pybind11::arg("a1"), pybind11::arg("a2"), pybind11::arg("a3"));
		cl.def("foo", (void (B::*)(struct A, struct A &, struct A *, int)) &B::foo, "C++: B::foo(struct A, struct A &, struct A *, int) --> void", pybind11::arg("a1"), pybind11::arg("a2"), pybind11::arg("a3"), pybind11::arg("i"));
		cl.def("foo_member", [](B &o) -> double { return o.foo_member(); }, "");
		cl.def("foo_member", [](B &o, const int & a0) -> double { return o.foo_member(a0); }, "", pybind11::arg("i"));
		cl.def("foo_member", [](B &o, const int & a0, float const & a1) -> double { return o.foo_member(a0, a1); }, "", pybind11::arg("i"), pybind11::arg("f"));
		cl.def("foo_member", (double (B::*)(const int, float, double)) &B::foo_member, "C++: B::foo_member(const int, float, double) --> double", pybind11::arg("i"), pybind11::arg("f"), pybind11::arg("d"));
		cl.def("foo_member_const", [](B const &o) -> double { return o.foo_member_const(); }, "");
		cl.def("foo_member_const", [](B const &o, int const & a0) -> double { return o.foo_member_const(a0); }, "", pybind11::arg("i"));
		cl.def("foo_member_const", [](B const &o, int const & a0, float const & a1) -> double { return o.foo_member_const(a0, a1); }, "", pybind11::arg("i"), pybind11::arg("f"));
		cl.def("foo_member_const", (double (B::*)(int, float, double) const) &B::foo_member_const, "C++: B::foo_member_const(int, float, double) const --> double", pybind11::arg("i"), pybind11::arg("f"), pybind11::arg("d"));
		cl.def_static("foo_static", []() -> double { return B::foo_static(); }, "");
		cl.def_static("foo_static", [](int const & a0) -> double { return B::foo_static(a0); }, "", pybind11::arg("i"));
		cl.def_static("foo_static", [](int const & a0, float const & a1) -> double { return B::foo_static(a0, a1); }, "", pybind11::arg("i"), pybind11::arg("f"));
		cl.def_static("foo_static", (double (*)(int, float, double)) &B::foo_static, "C++: B::foo_static(int, float, double) --> double", pybind11::arg("i"), pybind11::arg("f"), pybind11::arg("d"));
	}
	// foo_f0(void (void), int, float) file:T05.default.hpp line:
	M("").def("foo_f0", (void (*)(void (void), int, float)) &foo_f0, "C++: foo_f0(void (void), int, float) --> void", pybind11::arg("f"), pybind11::arg("a"), pybind11::arg("b"));

	// foo_f1(void (&)(void), int, float) file:T05.default.hpp line:
	M("").def("foo_f1", (void (*)(void (&)(void), int, float)) &foo_f1, "C++: foo_f1(void (&)(void), int, float) --> void", pybind11::arg("f"), pybind11::arg("a"), pybind11::arg("b"));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_T05_default(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T05_default, root_module) {
	root_module.doc() = "T05_default module";

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

	bind_T05_default(M);

}

// Source list file: TEST/T05_default.sources
// T05_default.cpp
// T05_default.cpp

// Modules list file: TEST/T05_default.modules
// 
