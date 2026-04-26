// File: std/stl_function.cpp
#include <functional> // std::binary_function
#include <functional> // std::equal_to
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

void bind_std_stl_function(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::binary_function file:bits/stl_function.h line:
		pybind11::class_<std::binary_function<float,float,bool>, std::shared_ptr<std::binary_function<float,float,bool>>> cl(M("std"), "binary_function_float_float_bool_t", "");
		cl.def( pybind11::init( [](std::binary_function<float,float,bool> const &o){ return new std::binary_function<float,float,bool>(o); } ) );
		cl.def( pybind11::init( [](){ return new std::binary_function<float,float,bool>(); } ) );
	}
	{ // std::equal_to file:bits/stl_function.h line:
		pybind11::class_<std::equal_to<float>, std::shared_ptr<std::equal_to<float>>, std::binary_function<float,float,bool>> cl(M("std"), "equal_to_float_t", "");
		cl.def( pybind11::init( [](){ return new std::equal_to<float>(); } ) );
		cl.def( pybind11::init( [](std::equal_to<float> const &o){ return new std::equal_to<float>(o); } ) );
		cl.def("__call__", (bool (std::equal_to<float>::*)(const float &, const float &) const) &std::equal_to<float>::operator(), "C++: std::equal_to<float>::operator()(const float &, const float &) const --> bool", pybind11::arg("__x"), pybind11::arg("__y"));
	}
}


// File: std/functional_hash.cpp
#include <functional> // std::equal_to
#include <functional> // std::hash
#include <functional> // std::less
#include <map> // std::_Rb_tree_const_iterator
#include <memory> // std::allocator
#include <set> // std::multiset
#include <sstream> // __str__
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_set> // std::unordered_multiset
#include <utility> // std::pair

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_functional_hash(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::hash file:bits/functional_hash.h line:
		pybind11::class_<std::hash<float>, std::shared_ptr<std::hash<float>>> cl(M("std"), "hash_float_t", "");
		cl.def( pybind11::init( [](){ return new std::hash<float>(); } ) );
		cl.def( pybind11::init( [](std::hash<float> const &o){ return new std::hash<float>(o); } ) );
		cl.def("__call__", (std::size_t (std::hash<float>::*)(float) const) &std::hash<float>::operator(), "C++: std::hash<float>::operator()(float) const --> std::size_t", pybind11::arg("__val"));
	}
	{ // std::multiset file:bits/stl_multiset.h line:
		pybind11::class_<std::multiset<float>, std::shared_ptr<std::multiset<float>>> cl(M("std"), "multiset_float_t", "");
		cl.def( pybind11::init( [](){ return new std::multiset<float>(); } ) );
		cl.def( pybind11::init( [](const struct std::less<float> & a0){ return new std::multiset<float>(a0); } ), "doc" , pybind11::arg("__comp"));
		cl.def( pybind11::init<const struct std::less<float> &, const class std::allocator<float> &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::multiset<float> const &o){ return new std::multiset<float>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<float> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::multiset<float, struct std::less<float>, class std::allocator<float> > &, const class std::allocator<float> &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::multiset<float, struct std::less<float>, class std::allocator<float> > & (std::multiset<float>::*)(const class std::multiset<float, struct std::less<float>, class std::allocator<float> > &)) &std::multiset<float>::operator=, "C++: std::multiset<float>::operator=(const class std::multiset<float, struct std::less<float>, class std::allocator<float> > &) --> class std::multiset<float, struct std::less<float>, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("key_comp", (struct std::less<float> (std::multiset<float>::*)() const) &std::multiset<float>::key_comp, "C++: std::multiset<float>::key_comp() const --> struct std::less<float>");
		cl.def("value_comp", (struct std::less<float> (std::multiset<float>::*)() const) &std::multiset<float>::value_comp, "C++: std::multiset<float>::value_comp() const --> struct std::less<float>");
		cl.def("get_allocator", (class std::allocator<float> (std::multiset<float>::*)() const) &std::multiset<float>::get_allocator, "C++: std::multiset<float>::get_allocator() const --> class std::allocator<float>");
		cl.def("empty", (bool (std::multiset<float>::*)() const) &std::multiset<float>::empty, "C++: std::multiset<float>::empty() const --> bool");
		cl.def("size", (unsigned long (std::multiset<float>::*)() const) &std::multiset<float>::size, "C++: std::multiset<float>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::multiset<float>::*)() const) &std::multiset<float>::max_size, "C++: std::multiset<float>::max_size() const --> unsigned long");
		cl.def("swap", (void (std::multiset<float>::*)(class std::multiset<float, struct std::less<float>, class std::allocator<float> > &)) &std::multiset<float>::swap, "C++: std::multiset<float>::swap(class std::multiset<float, struct std::less<float>, class std::allocator<float> > &) --> void", pybind11::arg("__x"));
		cl.def("erase", (unsigned long (std::multiset<float>::*)(const float &)) &std::multiset<float>::erase, "C++: std::multiset<float>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("clear", (void (std::multiset<float>::*)()) &std::multiset<float>::clear, "C++: std::multiset<float>::clear() --> void");
		cl.def("count", (unsigned long (std::multiset<float>::*)(const float &) const) &std::multiset<float>::count, "C++: std::multiset<float>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::_Rb_tree_const_iterator<float>, struct std::_Rb_tree_const_iterator<float> > (std::multiset<float>::*)(const float &)) &std::multiset<float>::equal_range, "C++: std::multiset<float>::equal_range(const float &) --> struct std::pair<struct std::_Rb_tree_const_iterator<float>, struct std::_Rb_tree_const_iterator<float> >", pybind11::arg("__x"));
	}
	{ // std::unordered_multiset file:bits/unordered_set.h line:
		pybind11::class_<std::unordered_multiset<float>, std::shared_ptr<std::unordered_multiset<float>>> cl(M("std"), "unordered_multiset_float_t", "");
		cl.def( pybind11::init( [](){ return new std::unordered_multiset<float>(); } ) );
		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::unordered_multiset<float>(a0); } ), "doc" , pybind11::arg("__n"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1){ return new std::unordered_multiset<float>(a0, a1); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1, const struct std::equal_to<float> & a2){ return new std::unordered_multiset<float>(a0, a1, a2); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"));
		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const struct std::equal_to<float> &, const class std::allocator<float> &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::unordered_multiset<float> const &o){ return new std::unordered_multiset<float>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<float> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &, const class std::allocator<float> &>(), pybind11::arg("__umset"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const class std::allocator<float> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const class std::allocator<float> &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__a") );

		cl.def("assign", (class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > & (std::unordered_multiset<float>::*)(const class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &)) &std::unordered_multiset<float>::operator=, "C++: std::unordered_multiset<float>::operator=(const class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &) --> class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<float> (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::get_allocator, "C++: std::unordered_multiset<float>::get_allocator() const --> class std::allocator<float>");
		cl.def("empty", (bool (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::empty, "C++: std::unordered_multiset<float>::empty() const --> bool");
		cl.def("size", (unsigned long (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::size, "C++: std::unordered_multiset<float>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::max_size, "C++: std::unordered_multiset<float>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::unordered_multiset<float>::*)(const float &)) &std::unordered_multiset<float>::erase, "C++: std::unordered_multiset<float>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("clear", (void (std::unordered_multiset<float>::*)()) &std::unordered_multiset<float>::clear, "C++: std::unordered_multiset<float>::clear() --> void");
		cl.def("swap", (void (std::unordered_multiset<float>::*)(class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &)) &std::unordered_multiset<float>::swap, "C++: std::unordered_multiset<float>::swap(class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> > &) --> void", pybind11::arg("__x"));
		cl.def("hash_function", (struct std::hash<float> (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::hash_function, "C++: std::unordered_multiset<float>::hash_function() const --> struct std::hash<float>");
		cl.def("key_eq", (struct std::equal_to<float> (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::key_eq, "C++: std::unordered_multiset<float>::key_eq() const --> struct std::equal_to<float>");
		cl.def("count", (unsigned long (std::unordered_multiset<float>::*)(const float &) const) &std::unordered_multiset<float>::count, "C++: std::unordered_multiset<float>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::__detail::_Node_iterator<float, true, false>, struct std::__detail::_Node_iterator<float, true, false> > (std::unordered_multiset<float>::*)(const float &)) &std::unordered_multiset<float>::equal_range, "C++: std::unordered_multiset<float>::equal_range(const float &) --> struct std::pair<struct std::__detail::_Node_iterator<float, true, false>, struct std::__detail::_Node_iterator<float, true, false> >", pybind11::arg("__x"));
		cl.def("bucket_count", (unsigned long (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::bucket_count, "C++: std::unordered_multiset<float>::bucket_count() const --> unsigned long");
		cl.def("max_bucket_count", (unsigned long (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::max_bucket_count, "C++: std::unordered_multiset<float>::max_bucket_count() const --> unsigned long");
		cl.def("bucket_size", (unsigned long (std::unordered_multiset<float>::*)(unsigned long) const) &std::unordered_multiset<float>::bucket_size, "C++: std::unordered_multiset<float>::bucket_size(unsigned long) const --> unsigned long", pybind11::arg("__n"));
		cl.def("bucket", (unsigned long (std::unordered_multiset<float>::*)(const float &) const) &std::unordered_multiset<float>::bucket, "C++: std::unordered_multiset<float>::bucket(const float &) const --> unsigned long", pybind11::arg("__key"));
		cl.def("load_factor", (float (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::load_factor, "C++: std::unordered_multiset<float>::load_factor() const --> float");
		cl.def("max_load_factor", (float (std::unordered_multiset<float>::*)() const) &std::unordered_multiset<float>::max_load_factor, "C++: std::unordered_multiset<float>::max_load_factor() const --> float");
		cl.def("max_load_factor", (void (std::unordered_multiset<float>::*)(float)) &std::unordered_multiset<float>::max_load_factor, "C++: std::unordered_multiset<float>::max_load_factor(float) --> void", pybind11::arg("__z"));
		cl.def("rehash", (void (std::unordered_multiset<float>::*)(unsigned long)) &std::unordered_multiset<float>::rehash, "C++: std::unordered_multiset<float>::rehash(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("reserve", (void (std::unordered_multiset<float>::*)(unsigned long)) &std::unordered_multiset<float>::reserve, "C++: std::unordered_multiset<float>::reserve(unsigned long) --> void", pybind11::arg("__n"));
	}
}


// File: T42_stl_names_multiset.cpp
#include <T42.stl.names.multiset.hpp> // foo
#include <functional> // std::equal_to
#include <functional> // std::hash
#include <functional> // std::less
#include <map> // std::_Rb_tree_const_iterator
#include <memory> // std::allocator
#include <set> // std::multiset
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_set> // std::unordered_multiset
#include <utility> // std::pair

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T42_stl_names_multiset(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(class std::multiset<float, struct std::less<float>, class std::allocator<float> >) file:T42.stl.names.multiset.hpp line:
	M("").def("foo", (void (*)(class std::multiset<float, struct std::less<float>, class std::allocator<float> >)) &foo, "C++: foo(class std::multiset<float, struct std::less<float>, class std::allocator<float> >) --> void", pybind11::arg(""));

	// foo(class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> >) file:T42.stl.names.multiset.hpp line:
	M("").def("foo", (void (*)(class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> >)) &foo, "C++: foo(class std::unordered_multiset<float, struct std::hash<float>, struct std::equal_to<float>, class std::allocator<float> >) --> void", pybind11::arg(""));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_std_stl_function(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_std_functional_hash(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T42_stl_names_multiset(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T42_stl_names_multiset, root_module) {
	root_module.doc() = "T42_stl_names_multiset module";

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
		{"", "std"},
	};
	for(auto &p : sub_modules ) modules[ p.first.empty() ? p.second :  p.first+"::"+p.second ] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_std_stl_function(M);
	bind_std_functional_hash(M);
	bind_T42_stl_names_multiset(M);

}

// Source list file: TEST/T42_stl_names_multiset.sources
// T42_stl_names_multiset.cpp
// std/stl_function.cpp
// std/functional_hash.cpp
// T42_stl_names_multiset.cpp

// Modules list file: TEST/T42_stl_names_multiset.modules
// std 
