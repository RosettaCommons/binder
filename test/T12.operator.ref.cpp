// File: T12_operator.cpp
#include <T12.operator.hpp> // T
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

void bind_T12_operator(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // T file:T12.operator.hpp line:15
		pybind11::class_<T, std::shared_ptr<T>> cl(M(""), "T", "");
		cl.def( pybind11::init( [](){ return new T(); } ) );
		cl.def("__invert__", (struct T & (T::*)()) &T::operator~, "C++: T::operator~() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("__pos__", (struct T & (T::*)()) &T::operator+, "C++: T::operator+() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("__neg__", (struct T & (T::*)()) &T::operator-, "C++: T::operator-() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("dereference", (struct T & (T::*)()) &T::operator*, "C++: T::operator*() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("__add__", (struct T & (T::*)(int)) &T::operator+, "C++: T::operator+(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__sub__", (struct T & (T::*)(int)) &T::operator-, "C++: T::operator-(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__mul__", (struct T & (T::*)(int)) &T::operator*, "C++: T::operator*(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__truediv__", (struct T & (T::*)(int)) &T::operator/, "C++: T::operator/(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__mod__", (struct T & (T::*)(int)) &T::operator%, "C++: T::operator%(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__or__", (struct T & (T::*)(int)) &T::operator|, "C++: T::operator|(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__and__", (struct T & (T::*)(int)) &T::operator&, "C++: T::operator&(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__xor__", (struct T & (T::*)(int)) &T::operator^, "C++: T::operator^(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__lshift__", (struct T & (T::*)(int)) &T::operator<<, "C++: T::operator<<(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__rshift__", (struct T & (T::*)(int)) &T::operator>>, "C++: T::operator>>(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("__iadd__", (void (T::*)(int)) &T::operator+=, "C++: T::operator+=(int) --> void", pybind11::arg(""));
		cl.def("__isub__", (void (T::*)(int)) &T::operator-=, "C++: T::operator-=(int) --> void", pybind11::arg(""));
		cl.def("__imul__", (void (T::*)(int)) &T::operator*=, "C++: T::operator*=(int) --> void", pybind11::arg(""));
		cl.def("__itruediv__", (void (T::*)(int)) &T::operator/=, "C++: T::operator/=(int) --> void", pybind11::arg(""));
		cl.def("__imod__", (void (T::*)(int)) &T::operator%=, "C++: T::operator%=(int) --> void", pybind11::arg(""));
		cl.def("__ior__", (void (T::*)(int)) &T::operator|=, "C++: T::operator|=(int) --> void", pybind11::arg(""));
		cl.def("__iand__", (void (T::*)(int)) &T::operator&=, "C++: T::operator&=(int) --> void", pybind11::arg(""));
		cl.def("__ixor__", (void (T::*)(int)) &T::operator^=, "C++: T::operator^=(int) --> void", pybind11::arg(""));
		cl.def("__ilshift__", (void (T::*)(int)) &T::operator<<=, "C++: T::operator<<=(int) --> void", pybind11::arg(""));
		cl.def("__irshift__", (void (T::*)(int)) &T::operator>>=, "C++: T::operator>>=(int) --> void", pybind11::arg(""));
		cl.def("__call__", (void (T::*)(int)) &T::operator(), "C++: T::operator()(int) --> void", pybind11::arg(""));
		cl.def("__eq__", (bool (T::*)(const struct T &)) &T::operator==, "C++: T::operator==(const struct T &) --> bool", pybind11::arg(""));
		cl.def("__ne__", (bool (T::*)(const struct T &)) &T::operator!=, "C++: T::operator!=(const struct T &) --> bool", pybind11::arg(""));
		cl.def("__getitem__", (bool (T::*)(int)) &T::operator[], "C++: T::operator[](int) --> bool", pybind11::arg(""));
		cl.def("assign", (struct T & (T::*)(const struct T &)) &T::operator=, "C++: T::operator=(const struct T &) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("pre_increment", (struct T & (T::*)()) &T::operator++, "C++: T::operator++() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("pre_decrement", (struct T & (T::*)()) &T::operator--, "C++: T::operator--() --> struct T &", pybind11::return_value_policy::automatic);
		cl.def("post_increment", (struct T & (T::*)(int)) &T::operator++, "C++: T::operator++(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("post_decrement", (struct T & (T::*)(int)) &T::operator--, "C++: T::operator--(int) --> struct T &", pybind11::return_value_policy::automatic, pybind11::arg(""));
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

void bind_T12_operator(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T12_operator, root_module) {
	root_module.doc() = "T12_operator module";

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

	bind_T12_operator(M);

}

// Source list file: TEST/T12_operator.sources
// T12_operator.cpp
// T12_operator.cpp

// Modules list file: TEST/T12_operator.modules
// 
