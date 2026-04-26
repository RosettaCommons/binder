// File: T43_stl_pybind11_include_stl.cpp
#include <T43.stl.pybind11_include_stl.hpp> // test_include_stl
#include <array> // std::array
#include <deque> // std::deque
#include <functional> // std::equal_to
#include <functional> // std::less
#include <iterator> // __gnu_cxx::__normal_iterator
#include <list> // std::list
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::map
#include <memory> // std::allocator
#include <set> // std::set
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_map> // std::unordered_map
#include <unordered_set> // std::unordered_set
#include <utility> // std::pair
#include <valarray> // std::valarray
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T43_stl_pybind11_include_stl(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// test_include_stl(class std::vector<int, class std::allocator<int> >, class std::deque<int, class std::allocator<int> >, class std::list<int, class std::allocator<int> >, struct std::array<int, 5>, class std::valarray<int>, class std::set<int, struct std::less<int>, class std::allocator<int> >, class std::unordered_set<int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<int> >, class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >, class std::unordered_map<int, int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<const int, int> > >) file:T43.stl.pybind11_include_stl.hpp line:
	M("").def("test_include_stl", (void (*)(class std::vector<int, class std::allocator<int> >, class std::deque<int, class std::allocator<int> >, class std::list<int, class std::allocator<int> >, struct std::array<int, 5>, class std::valarray<int>, class std::set<int, struct std::less<int>, class std::allocator<int> >, class std::unordered_set<int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<int> >, class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >, class std::unordered_map<int, int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<const int, int> > >)) &test_include_stl, "C++: test_include_stl(class std::vector<int, class std::allocator<int> >, class std::deque<int, class std::allocator<int> >, class std::list<int, class std::allocator<int> >, struct std::array<int, 5>, class std::valarray<int>, class std::set<int, struct std::less<int>, class std::allocator<int> >, class std::unordered_set<int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<int> >, class std::map<int, int, struct std::less<int>, class std::allocator<struct std::pair<const int, int> > >, class std::unordered_map<int, int, struct std::hash<int>, struct std::equal_to<int>, class std::allocator<struct std::pair<const int, int> > >) --> void", pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""), pybind11::arg(""));

}


#include <map>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

using ModuleGetter = std::function< pybind11::module & (std::string const &) >;

void bind_T43_stl_pybind11_include_stl(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T43_stl_pybind11_include_stl, root_module) {
	root_module.doc() = "T43_stl_pybind11_include_stl module";

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

	bind_T43_stl_pybind11_include_stl(M);

}

// Source list file: TEST/T43_stl_pybind11_include_stl.sources
// T43_stl_pybind11_include_stl.cpp
// T43_stl_pybind11_include_stl.cpp

// Modules list file: TEST/T43_stl_pybind11_include_stl.modules
// 
