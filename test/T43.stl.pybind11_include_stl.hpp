#ifndef _INCLUDED_T40_pybind11_include_stl_hpp_
#define _INCLUDED_T40_pybind11_include_stl_hpp_

#include <vector>
#include <deque>
#include <list>
#include <array>
#include <valarray>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
	//C++17
	#include <optional>
	#include <variant>
#endif

// Not testing C++14 #include <experimental/optional> b/c it doesn't exist for everyone

void test_include_stl(
	std::vector<int>,
	std::deque<int>,
	std::list<int>,
	std::array<int,5>,
	std::valarray<int>,
	std::set<int>,
	std::unordered_set<int>,
	std::map<int,int>,
	std::unordered_map<int,int>
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
    // C++17
	,
	std::optional<int>,
	std::variant<int, bool>
#endif
) {}

#endif // _INCLUDED_T43_pybind11_include_stl_hpp_
