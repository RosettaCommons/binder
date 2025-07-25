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
		cl.def("assign", (struct std::binary_function<float, float, bool> & (std::binary_function<float,float,bool>::*)(const struct std::binary_function<float, float, bool> &)) &std::binary_function<float, float, bool>::operator=, "C++: std::binary_function<float, float, bool>::operator=(const struct std::binary_function<float, float, bool> &) --> struct std::binary_function<float, float, bool> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // std::equal_to file:bits/stl_function.h line:
		pybind11::class_<std::equal_to<float>, std::shared_ptr<std::equal_to<float>>, std::binary_function<float,float,bool>> cl(M("std"), "equal_to_float_t", "");
		cl.def( pybind11::init( [](){ return new std::equal_to<float>(); } ) );
		cl.def( pybind11::init( [](std::equal_to<float> const &o){ return new std::equal_to<float>(o); } ) );
		cl.def("__call__", (bool (std::equal_to<float>::*)(const float &, const float &) const) &std::equal_to<float>::operator(), "C++: std::equal_to<float>::operator()(const float &, const float &) const --> bool", pybind11::arg("__x"), pybind11::arg("__y"));
		cl.def("assign", (struct std::binary_function<float, float, bool> & (std::binary_function<float,float,bool>::*)(const struct std::binary_function<float, float, bool> &)) &std::binary_function<float, float, bool>::operator=, "C++: std::binary_function<float, float, bool>::operator=(const struct std::binary_function<float, float, bool> &) --> struct std::binary_function<float, float, bool> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}


// File: std/functional_hash.cpp
#include <deque> // std::deque
#include <forward_list> // std::forward_list
#include <functional> // std::equal_to
#include <functional> // std::hash
#include <functional> // std::less
#include <list> // std::list
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::multimap
#include <memory> // std::allocator
#include <sstream> // __str__
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_map> // std::unordered_multimap
#include <utility> // std::pair
#include <vector> // std::vector

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
	{ // std::multimap file:bits/stl_multimap.h line:
		pybind11::class_<std::multimap<float,int>, std::shared_ptr<std::multimap<float,int>>> cl(M("std"), "multimap_float_int_t", "");
		cl.def( pybind11::init( [](){ return new std::multimap<float,int>(); } ) );
		cl.def( pybind11::init( [](const struct std::less<float> & a0){ return new std::multimap<float,int>(a0); } ), "doc" , pybind11::arg("__comp"));
		cl.def( pybind11::init<const struct std::less<float> &, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::multimap<float,int> const &o){ return new std::multimap<float,int>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::multimap<float, int> &, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::multimap<float, int> & (std::multimap<float,int>::*)(const class std::multimap<float, int> &)) &std::multimap<float, int>::operator=, "C++: std::multimap<float, int>::operator=(const class std::multimap<float, int> &) --> class std::multimap<float, int> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const float, int> > (std::multimap<float,int>::*)() const) &std::multimap<float, int>::get_allocator, "C++: std::multimap<float, int>::get_allocator() const --> class std::allocator<struct std::pair<const float, int> >");
		cl.def("empty", (bool (std::multimap<float,int>::*)() const) &std::multimap<float, int>::empty, "C++: std::multimap<float, int>::empty() const --> bool");
		cl.def("size", (unsigned long (std::multimap<float,int>::*)() const) &std::multimap<float, int>::size, "C++: std::multimap<float, int>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::multimap<float,int>::*)() const) &std::multimap<float, int>::max_size, "C++: std::multimap<float, int>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::multimap<float,int>::*)(const float &)) &std::multimap<float, int>::erase, "C++: std::multimap<float, int>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("swap", (void (std::multimap<float,int>::*)(class std::multimap<float, int> &)) &std::multimap<float, int>::swap, "C++: std::multimap<float, int>::swap(class std::multimap<float, int> &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::multimap<float,int>::*)()) &std::multimap<float, int>::clear, "C++: std::multimap<float, int>::clear() --> void");
		cl.def("key_comp", (struct std::less<float> (std::multimap<float,int>::*)() const) &std::multimap<float, int>::key_comp, "C++: std::multimap<float, int>::key_comp() const --> struct std::less<float>");
		cl.def("count", (unsigned long (std::multimap<float,int>::*)(const float &) const) &std::multimap<float, int>::count, "C++: std::multimap<float, int>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const float, int> >, struct std::_Rb_tree_iterator<struct std::pair<const float, int> > > (std::multimap<float,int>::*)(const float &)) &std::multimap<float, int>::equal_range, "C++: std::multimap<float, int>::equal_range(const float &) --> struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const float, int> >, struct std::_Rb_tree_iterator<struct std::pair<const float, int> > >", pybind11::arg("__x"));
	}
	{ // std::multimap file:bits/stl_multimap.h line:
		pybind11::class_<std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>, std::shared_ptr<std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>>> cl(M("std"), "multimap_float_std_list_std_forward_list_std_deque_std_vector_double_t", "");
		cl.def( pybind11::init( [](){ return new std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(); } ) );
		cl.def( pybind11::init( [](const struct std::less<float> & a0){ return new std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(a0); } ), "doc" , pybind11::arg("__comp"));
		cl.def( pybind11::init<const struct std::less<float> &, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >> const &o){ return new std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > & (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &)) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::operator=, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::operator=(const class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &) --> class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::get_allocator, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::get_allocator() const --> class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > >");
		cl.def("empty", (bool (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::empty, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::empty() const --> bool");
		cl.def("size", (unsigned long (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::size, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_size, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &)) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::erase, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("swap", (void (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &)) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::swap, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::swap(class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)()) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::clear, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::clear() --> void");
		cl.def("key_comp", (struct std::less<float> (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::key_comp, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::key_comp() const --> struct std::less<float>");
		cl.def("count", (unsigned long (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &) const) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::count, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > >, struct std::_Rb_tree_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > > (std::multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &)) &std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::equal_range, "C++: std::multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::equal_range(const float &) --> struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > >, struct std::_Rb_tree_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > >", pybind11::arg("__x"));
	}
	{ // std::unordered_multimap file:bits/unordered_map.h line:
		pybind11::class_<std::unordered_multimap<float,int>, std::shared_ptr<std::unordered_multimap<float,int>>> cl(M("std"), "unordered_multimap_float_int_t", "");
		cl.def( pybind11::init( [](){ return new std::unordered_multimap<float,int>(); } ) );
		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::unordered_multimap<float,int>(a0); } ), "doc" , pybind11::arg("__n"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1){ return new std::unordered_multimap<float,int>(a0, a1); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1, const struct std::equal_to<float> & a2){ return new std::unordered_multimap<float,int>(a0, a1, a2); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"));
		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const struct std::equal_to<float> &, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::unordered_multimap<float,int> const &o){ return new std::unordered_multimap<float,int>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::unordered_multimap<float, int> &, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__ummap"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const class std::allocator<struct std::pair<const float, int> > &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__a") );

		cl.def("assign", (class std::unordered_multimap<float, int> & (std::unordered_multimap<float,int>::*)(const class std::unordered_multimap<float, int> &)) &std::unordered_multimap<float, int>::operator=, "C++: std::unordered_multimap<float, int>::operator=(const class std::unordered_multimap<float, int> &) --> class std::unordered_multimap<float, int> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const float, int> > (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::get_allocator, "C++: std::unordered_multimap<float, int>::get_allocator() const --> class std::allocator<struct std::pair<const float, int> >");
		cl.def("empty", (bool (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::empty, "C++: std::unordered_multimap<float, int>::empty() const --> bool");
		cl.def("size", (unsigned long (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::size, "C++: std::unordered_multimap<float, int>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::max_size, "C++: std::unordered_multimap<float, int>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::unordered_multimap<float,int>::*)(const float &)) &std::unordered_multimap<float, int>::erase, "C++: std::unordered_multimap<float, int>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("clear", (void (std::unordered_multimap<float,int>::*)()) &std::unordered_multimap<float, int>::clear, "C++: std::unordered_multimap<float, int>::clear() --> void");
		cl.def("swap", (void (std::unordered_multimap<float,int>::*)(class std::unordered_multimap<float, int> &)) &std::unordered_multimap<float, int>::swap, "C++: std::unordered_multimap<float, int>::swap(class std::unordered_multimap<float, int> &) --> void", pybind11::arg("__x"));
		cl.def("hash_function", (struct std::hash<float> (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::hash_function, "C++: std::unordered_multimap<float, int>::hash_function() const --> struct std::hash<float>");
		cl.def("key_eq", (struct std::equal_to<float> (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::key_eq, "C++: std::unordered_multimap<float, int>::key_eq() const --> struct std::equal_to<float>");
		cl.def("count", (unsigned long (std::unordered_multimap<float,int>::*)(const float &) const) &std::unordered_multimap<float, int>::count, "C++: std::unordered_multimap<float, int>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::__detail::_Node_iterator<struct std::pair<const float, int>, false, false>, struct std::__detail::_Node_iterator<struct std::pair<const float, int>, false, false> > (std::unordered_multimap<float,int>::*)(const float &)) &std::unordered_multimap<float, int>::equal_range, "C++: std::unordered_multimap<float, int>::equal_range(const float &) --> struct std::pair<struct std::__detail::_Node_iterator<struct std::pair<const float, int>, false, false>, struct std::__detail::_Node_iterator<struct std::pair<const float, int>, false, false> >", pybind11::arg("__x"));
		cl.def("bucket_count", (unsigned long (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::bucket_count, "C++: std::unordered_multimap<float, int>::bucket_count() const --> unsigned long");
		cl.def("max_bucket_count", (unsigned long (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::max_bucket_count, "C++: std::unordered_multimap<float, int>::max_bucket_count() const --> unsigned long");
		cl.def("bucket_size", (unsigned long (std::unordered_multimap<float,int>::*)(unsigned long) const) &std::unordered_multimap<float, int>::bucket_size, "C++: std::unordered_multimap<float, int>::bucket_size(unsigned long) const --> unsigned long", pybind11::arg("__n"));
		cl.def("bucket", (unsigned long (std::unordered_multimap<float,int>::*)(const float &) const) &std::unordered_multimap<float, int>::bucket, "C++: std::unordered_multimap<float, int>::bucket(const float &) const --> unsigned long", pybind11::arg("__key"));
		cl.def("load_factor", (float (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::load_factor, "C++: std::unordered_multimap<float, int>::load_factor() const --> float");
		cl.def("max_load_factor", (float (std::unordered_multimap<float,int>::*)() const) &std::unordered_multimap<float, int>::max_load_factor, "C++: std::unordered_multimap<float, int>::max_load_factor() const --> float");
		cl.def("max_load_factor", (void (std::unordered_multimap<float,int>::*)(float)) &std::unordered_multimap<float, int>::max_load_factor, "C++: std::unordered_multimap<float, int>::max_load_factor(float) --> void", pybind11::arg("__z"));
		cl.def("rehash", (void (std::unordered_multimap<float,int>::*)(unsigned long)) &std::unordered_multimap<float, int>::rehash, "C++: std::unordered_multimap<float, int>::rehash(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("reserve", (void (std::unordered_multimap<float,int>::*)(unsigned long)) &std::unordered_multimap<float, int>::reserve, "C++: std::unordered_multimap<float, int>::reserve(unsigned long) --> void", pybind11::arg("__n"));
	}
}


// File: std/unordered_map.cpp
#include <deque> // std::deque
#include <forward_list> // std::forward_list
#include <functional> // std::equal_to
#include <functional> // std::hash
#include <list> // std::list
#include <memory> // std::allocator
#include <sstream> // __str__
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_map> // std::unordered_multimap
#include <utility> // std::pair
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_std_unordered_map(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::unordered_multimap file:bits/unordered_map.h line:
		pybind11::class_<std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>, std::shared_ptr<std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>>> cl(M("std"), "unordered_multimap_float_std_list_std_forward_list_std_deque_std_vector_double_t", "");
		cl.def( pybind11::init( [](){ return new std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(); } ) );
		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(a0); } ), "doc" , pybind11::arg("__n"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1){ return new std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(a0, a1); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"));
		cl.def( pybind11::init( [](unsigned long const & a0, const struct std::hash<float> & a1, const struct std::equal_to<float> & a2){ return new std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(a0, a1, a2); } ), "doc" , pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"));
		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const struct std::equal_to<float> &, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__eql"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >> const &o){ return new std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__ummap"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init<unsigned long, const struct std::hash<float> &, const class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > &>(), pybind11::arg("__n"), pybind11::arg("__hf"), pybind11::arg("__a") );

		cl.def("assign", (class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > & (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::operator=, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::operator=(const class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &) --> class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > > (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::get_allocator, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::get_allocator() const --> class std::allocator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > >");
		cl.def("empty", (bool (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::empty, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::empty() const --> bool");
		cl.def("size", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::size, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_size, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::erase, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::erase(const float &) --> unsigned long", pybind11::arg("__x"));
		cl.def("clear", (void (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)()) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::clear, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::clear() --> void");
		cl.def("swap", (void (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::swap, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::swap(class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > > &) --> void", pybind11::arg("__x"));
		cl.def("hash_function", (struct std::hash<float> (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::hash_function, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::hash_function() const --> struct std::hash<float>");
		cl.def("key_eq", (struct std::equal_to<float> (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::key_eq, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::key_eq() const --> struct std::equal_to<float>");
		cl.def("count", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &) const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::count, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::count(const float &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::__detail::_Node_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >, false, false>, struct std::__detail::_Node_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >, false, false> > (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::equal_range, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::equal_range(const float &) --> struct std::pair<struct std::__detail::_Node_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >, false, false>, struct std::__detail::_Node_iterator<struct std::pair<const float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >, false, false> >", pybind11::arg("__x"));
		cl.def("bucket_count", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket_count, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket_count() const --> unsigned long");
		cl.def("max_bucket_count", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_bucket_count, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_bucket_count() const --> unsigned long");
		cl.def("bucket_size", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(unsigned long) const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket_size, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket_size(unsigned long) const --> unsigned long", pybind11::arg("__n"));
		cl.def("bucket", (unsigned long (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(const float &) const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::bucket(const float &) const --> unsigned long", pybind11::arg("__key"));
		cl.def("load_factor", (float (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::load_factor, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::load_factor() const --> float");
		cl.def("max_load_factor", (float (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)() const) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_load_factor, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_load_factor() const --> float");
		cl.def("max_load_factor", (void (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(float)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_load_factor, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::max_load_factor(float) --> void", pybind11::arg("__z"));
		cl.def("rehash", (void (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(unsigned long)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::rehash, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::rehash(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("reserve", (void (std::unordered_multimap<float,std::list<std::forward_list<std::deque<std::vector<double> > > >>::*)(unsigned long)) &std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::reserve, "C++: std::unordered_multimap<float, std::list<std::forward_list<std::deque<std::vector<double>>>>>::reserve(unsigned long) --> void", pybind11::arg("__n"));
	}
}


// File: T42_stl_names_multimap.cpp
#include <T42.stl.names.multimap.hpp> // foo
#include <deque> // std::deque
#include <forward_list> // std::forward_list
#include <functional> // std::equal_to
#include <functional> // std::hash
#include <functional> // std::less
#include <list> // std::list
#include <map> // std::_Rb_tree_const_iterator
#include <map> // std::_Rb_tree_iterator
#include <map> // std::multimap
#include <memory> // std::allocator
#include <unordered_map> // std::__detail::_Node_const_iterator
#include <unordered_map> // std::__detail::_Node_iterator
#include <unordered_map> // std::unordered_multimap
#include <utility> // std::pair
#include <vector> // std::vector

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>, false)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*, false)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_T42_stl_names_multimap(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// foo(class std::multimap<float, int>) file:T42.stl.names.multimap.hpp line:
	M("").def("foo", (void (*)(class std::multimap<float, int>)) &foo, "C++: foo(class std::multimap<float, int>) --> void", pybind11::arg(""));

	// foo(class std::unordered_multimap<float, int>) file:T42.stl.names.multimap.hpp line:
	M("").def("foo", (void (*)(class std::unordered_multimap<float, int>)) &foo, "C++: foo(class std::unordered_multimap<float, int>) --> void", pybind11::arg(""));

	// foo(class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >) file:T42.stl.names.multimap.hpp line:
	M("").def("foo", (void (*)(class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >)) &foo, "C++: foo(class std::multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >) --> void", pybind11::arg(""));

	// foo(class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >) file:T42.stl.names.multimap.hpp line:
	M("").def("foo", (void (*)(class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >)) &foo, "C++: foo(class std::unordered_multimap<float, class std::list<class std::forward_list<class std::deque<class std::vector<double> > > > >) --> void", pybind11::arg(""));

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
void bind_std_unordered_map(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_T42_stl_names_multimap(std::function< pybind11::module &(std::string const &namespace_) > &M);


PYBIND11_MODULE(T42_stl_names_multimap, root_module) {
	root_module.doc() = "T42_stl_names_multimap module";

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
	bind_std_unordered_map(M);
	bind_T42_stl_names_multimap(M);

}

// Source list file: TEST/T42_stl_names_multimap.sources
// T42_stl_names_multimap.cpp
// std/stl_function.cpp
// std/functional_hash.cpp
// std/unordered_map.cpp
// T42_stl_names_multimap.cpp

// Modules list file: TEST/T42_stl_names_multimap.modules
// std 
