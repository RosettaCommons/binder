

#ifndef _INCLUDED_xstd_binders_hpp_
#define _INCLUDED_xstd_binders_hpp_

#include <test_struct/test_struct.hpp>
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

namespace my_binders {

template<typename Module> void fakeie_binder(Module &M)
{
	pybind11::class_<testers::fakeie> cl(M, "fakeie");
	cl.def( pybind11::init( [](){ std::cout << "FUU" << std::endl; return new testers::fakeie(); } ) );
	cl.def_readwrite("an_int", &testers::fakeie::an_int);
	cl.def_readwrite("a_string", &testers::fakeie::a_string);
};

} // my_binders

#endif // _INCLUDED_std_binders_hpp_
