// File: T60_custom_shared.cpp
#include <T60.custom_shared.hpp> // A
#include <T60.custom_shared.hpp> // E1
#include <T60.custom_shared.hpp> // E2_struct
#include <T60.custom_shared.hpp> // E3_class
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, my_shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(my_shared_ptr<void>)
#endif

void bind_T60_custom_shared(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// E1 file:T60.custom_shared.hpp line:
	pybind11::enum_<E1>(M(""), "E1", pybind11::arithmetic(), "")
		.value("E1_V0", E1_V0)
		.value("E1_V1", E1_V1)
		.export_values();

;

	// E2_struct file:T60.custom_shared.hpp line:
	pybind11::enum_<E2_struct>(M(""), "E2_struct", "")
		.value("V0", E2_struct::V0)
		.value("V1", E2_struct::V1)
		.export_values();

;

	// E3_class file:T60.custom_shared.hpp line:
	pybind11::enum_<E3_class>(M(""), "E3_class", "")
		.value("V0", E3_class::V0)
		.value("V1", E3_class::V1);

;

	{ // A file:T60.custom_shared.hpp line:
		pybind11::class_<A, my_shared_ptr<A>> cl(M(""), "A", "");
		cl.def( pybind11::init( [](){ return new A(); } ) );

		pybind11::enum_<A::AE1>(cl, "AE1", pybind11::arithmetic(), "")
			.value("AE1_V0", A::AE1_V0)
			.value("AE1_V1", A::AE1_V1)
			.export_values();


		pybind11::enum_<A::AE2_struct>(cl, "AE2_struct", "")
			.value("AE3_V0", A::AE2_struct::AE3_V0)
			.value("AE3_V1", A::AE2_struct::AE3_V1)
			.export_values();


		pybind11::enum_<A::AE3_class>(cl, "AE3_class", "")
			.value("AE2_V0", A::AE3_class::AE2_V0)
			.value("AE2_V1", A::AE3_class::AE2_V1);

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

void bind_T60_custom_shared(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T60_custom_shared, root_module) {
	root_module.doc() = "T60_custom_shared module";

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

	bind_T60_custom_shared(M);

}

// Source list file: TEST/T60_custom_shared.sources
// T60_custom_shared.cpp
// T60_custom_shared.cpp

// Modules list file: TEST/T60_custom_shared.modules
// 
