#include <iostream> // --trace
#include <iterator> // __gnu_cxx::__normal_iterator
#include <memory> // std::allocator
#include <sstream> // __str__
#include <string> // std::__cxx11::basic_string
#include <string> // std::char_traits
#include <vector> // std::vector

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <mmtf.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_std_stl_vector(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B167_[std::vector<char>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<char>, std::shared_ptr<std::vector<char>>> cl(M("std"), "vector_char_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<char>(); } ) );
		cl.def( pybind11::init<const class std::allocator<char> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<char>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<char> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const char & a1){ return new std::vector<char>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const char &, const class std::allocator<char> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<char> const &o){ return new std::vector<char>(o); } ) );
		cl.def( pybind11::init<const class std::vector<char, class std::allocator<char> > &, const class std::allocator<char> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char *, const char *)) &std::vector<char, std::allocator<char> >::insert<const char *,void>, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char *, const char *) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<char *, std::string >, class __gnu_cxx::__normal_iterator<char *, std::string >)) &std::vector<char, std::allocator<char> >::insert<__gnu_cxx::__normal_iterator<char *, std::string >,void>, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<char *, std::string >, class __gnu_cxx::__normal_iterator<char *, std::string >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("assign", (class std::vector<char, class std::allocator<char> > & (std::vector<char>::*)(const class std::vector<char, class std::allocator<char> > &)) &std::vector<char, std::allocator<char> >::operator=, "C++: std::vector<char, std::allocator<char> >::operator=(const class std::vector<char, class std::allocator<char> > &) --> class std::vector<char, class std::allocator<char> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<char>::*)(unsigned long, const char &)) &std::vector<char, std::allocator<char> >::assign, "C++: std::vector<char, std::allocator<char> >::assign(unsigned long, const char &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::begin, "C++: std::vector<char, std::allocator<char> >::begin() --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::end, "C++: std::vector<char, std::allocator<char> >::end() --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::cbegin, "C++: std::vector<char, std::allocator<char> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::cend, "C++: std::vector<char, std::allocator<char> >::cend() const --> class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >");
		cl.def("size", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::size, "C++: std::vector<char, std::allocator<char> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::max_size, "C++: std::vector<char, std::allocator<char> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::resize, "C++: std::vector<char, std::allocator<char> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<char>::*)(unsigned long, const char &)) &std::vector<char, std::allocator<char> >::resize, "C++: std::vector<char, std::allocator<char> >::resize(unsigned long, const char &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::shrink_to_fit, "C++: std::vector<char, std::allocator<char> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::capacity, "C++: std::vector<char, std::allocator<char> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<char>::*)() const) &std::vector<char, std::allocator<char> >::empty, "C++: std::vector<char, std::allocator<char> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::reserve, "C++: std::vector<char, std::allocator<char> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (char & (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::operator[], "C++: std::vector<char, std::allocator<char> >::operator[](unsigned long) --> char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (char & (std::vector<char>::*)(unsigned long)) &std::vector<char, std::allocator<char> >::at, "C++: std::vector<char, std::allocator<char> >::at(unsigned long) --> char &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (char & (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::front, "C++: std::vector<char, std::allocator<char> >::front() --> char &", pybind11::return_value_policy::automatic);
		cl.def("back", (char & (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::back, "C++: std::vector<char, std::allocator<char> >::back() --> char &", pybind11::return_value_policy::automatic);
		cl.def("data", (char * (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::data, "C++: std::vector<char, std::allocator<char> >::data() --> char *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<char>::*)(const char &)) &std::vector<char, std::allocator<char> >::push_back, "C++: std::vector<char, std::allocator<char> >::push_back(const char &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::pop_back, "C++: std::vector<char, std::allocator<char> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char &)) &std::vector<char, std::allocator<char> >::insert, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, const char &) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, unsigned long, const char &)) &std::vector<char, std::allocator<char> >::insert, "C++: std::vector<char, std::allocator<char> >::insert(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, unsigned long, const char &) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >)) &std::vector<char, std::allocator<char> >::erase, "C++: std::vector<char, std::allocator<char> >::erase(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > > (std::vector<char>::*)(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >)) &std::vector<char, std::allocator<char> >::erase, "C++: std::vector<char, std::allocator<char> >::erase(class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >, class __gnu_cxx::__normal_iterator<const char *, class std::vector<char, class std::allocator<char> > >) --> class __gnu_cxx::__normal_iterator<char *, class std::vector<char, class std::allocator<char> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<char>::*)(class std::vector<char, class std::allocator<char> > &)) &std::vector<char, std::allocator<char> >::swap, "C++: std::vector<char, std::allocator<char> >::swap(class std::vector<char, class std::allocator<char> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<char>::*)()) &std::vector<char, std::allocator<char> >::clear, "C++: std::vector<char, std::allocator<char> >::clear() --> void");
	}
	std::cout << "B168_[std::vector<int>] ";
	{ // std::vector file:bits/stl_vector.h line:216
		pybind11::class_<std::vector<int>, std::shared_ptr<std::vector<int>>> cl(M("std"), "vector_int_t", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new std::vector<int>(); } ) );
		cl.def( pybind11::init<const class std::allocator<int> &>(), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0){ return new std::vector<int>(a0); } ), "doc");
		cl.def( pybind11::init<unsigned long, const class std::allocator<int> &>(), pybind11::arg("__n"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](unsigned long const & a0, const int & a1){ return new std::vector<int>(a0, a1); } ), "doc");
		cl.def( pybind11::init<unsigned long, const int &, const class std::allocator<int> &>(), pybind11::arg("__n"), pybind11::arg("__value"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::vector<int> const &o){ return new std::vector<int>(o); } ) );
		cl.def( pybind11::init<const class std::vector<int, class std::allocator<int> > &, const class std::allocator<int> &>(), pybind11::arg("__x"), pybind11::arg("__a") );

		cl.def("assign", (class std::vector<int, class std::allocator<int> > & (std::vector<int>::*)(const class std::vector<int, class std::allocator<int> > &)) &std::vector<int, std::allocator<int> >::operator=, "C++: std::vector<int, std::allocator<int> >::operator=(const class std::vector<int, class std::allocator<int> > &) --> class std::vector<int, class std::allocator<int> > &", pybind11::return_value_policy::automatic, pybind11::arg("__x"));
		cl.def("assign", (void (std::vector<int>::*)(unsigned long, const int &)) &std::vector<int, std::allocator<int> >::assign, "C++: std::vector<int, std::allocator<int> >::assign(unsigned long, const int &) --> void", pybind11::arg("__n"), pybind11::arg("__val"));
		cl.def("begin", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::begin, "C++: std::vector<int, std::allocator<int> >::begin() --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("end", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::end, "C++: std::vector<int, std::allocator<int> >::end() --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("cbegin", (class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::cbegin, "C++: std::vector<int, std::allocator<int> >::cbegin() const --> class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("cend", (class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::cend, "C++: std::vector<int, std::allocator<int> >::cend() const --> class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >");
		cl.def("size", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::size, "C++: std::vector<int, std::allocator<int> >::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::max_size, "C++: std::vector<int, std::allocator<int> >::max_size() const --> unsigned long");
		cl.def("resize", (void (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::resize, "C++: std::vector<int, std::allocator<int> >::resize(unsigned long) --> void", pybind11::arg("__new_size"));
		cl.def("resize", (void (std::vector<int>::*)(unsigned long, const int &)) &std::vector<int, std::allocator<int> >::resize, "C++: std::vector<int, std::allocator<int> >::resize(unsigned long, const int &) --> void", pybind11::arg("__new_size"), pybind11::arg("__x"));
		cl.def("shrink_to_fit", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::shrink_to_fit, "C++: std::vector<int, std::allocator<int> >::shrink_to_fit() --> void");
		cl.def("capacity", (unsigned long (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::capacity, "C++: std::vector<int, std::allocator<int> >::capacity() const --> unsigned long");
		cl.def("empty", (bool (std::vector<int>::*)() const) &std::vector<int, std::allocator<int> >::empty, "C++: std::vector<int, std::allocator<int> >::empty() const --> bool");
		cl.def("reserve", (void (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::reserve, "C++: std::vector<int, std::allocator<int> >::reserve(unsigned long) --> void", pybind11::arg("__n"));
		cl.def("__getitem__", (int & (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::operator[], "C++: std::vector<int, std::allocator<int> >::operator[](unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("at", (int & (std::vector<int>::*)(unsigned long)) &std::vector<int, std::allocator<int> >::at, "C++: std::vector<int, std::allocator<int> >::at(unsigned long) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("__n"));
		cl.def("front", (int & (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::front, "C++: std::vector<int, std::allocator<int> >::front() --> int &", pybind11::return_value_policy::automatic);
		cl.def("back", (int & (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::back, "C++: std::vector<int, std::allocator<int> >::back() --> int &", pybind11::return_value_policy::automatic);
		cl.def("data", (int * (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::data, "C++: std::vector<int, std::allocator<int> >::data() --> int *", pybind11::return_value_policy::automatic);
		cl.def("push_back", (void (std::vector<int>::*)(const int &)) &std::vector<int, std::allocator<int> >::push_back, "C++: std::vector<int, std::allocator<int> >::push_back(const int &) --> void", pybind11::arg("__x"));
		cl.def("pop_back", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::pop_back, "C++: std::vector<int, std::allocator<int> >::pop_back() --> void");
		cl.def("insert", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, const int &)) &std::vector<int, std::allocator<int> >::insert, "C++: std::vector<int, std::allocator<int> >::insert(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, const int &) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"), pybind11::arg("__x"));
		cl.def("insert", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, unsigned long, const int &)) &std::vector<int, std::allocator<int> >::insert, "C++: std::vector<int, std::allocator<int> >::insert(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, unsigned long, const int &) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"), pybind11::arg("__n"), pybind11::arg("__x"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >)) &std::vector<int, std::allocator<int> >::erase, "C++: std::vector<int, std::allocator<int> >::erase(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__position"));
		cl.def("erase", (class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > > (std::vector<int>::*)(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >)) &std::vector<int, std::allocator<int> >::erase, "C++: std::vector<int, std::allocator<int> >::erase(class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >, class __gnu_cxx::__normal_iterator<const int *, class std::vector<int, class std::allocator<int> > >) --> class __gnu_cxx::__normal_iterator<int *, class std::vector<int, class std::allocator<int> > >", pybind11::arg("__first"), pybind11::arg("__last"));
		cl.def("swap", (void (std::vector<int>::*)(class std::vector<int, class std::allocator<int> > &)) &std::vector<int, std::allocator<int> >::swap, "C++: std::vector<int, std::allocator<int> >::swap(class std::vector<int, class std::allocator<int> > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::vector<int>::*)()) &std::vector<int, std::allocator<int> >::clear, "C++: std::vector<int, std::allocator<int> >::clear() --> void");
	}
}
