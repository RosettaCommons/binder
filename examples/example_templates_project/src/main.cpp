// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <template_lib_impl.hpp>

#include <complex>
#include <vector>
#include <iostream>

int main(int argc, const char **argv)
{
  lib_namespace::StatVector<> stat_vector;    
  stat_vector.SetVector({1,2,3,4,5});
  stat_vector.PrintVector();
  std::cout << stat_vector.L2norm() << std::endl;
    
  lib_namespace::StatVector<std::complex<double> > complex_stat_vector;    
  complex_stat_vector.SetVector({0,1},5);
  complex_stat_vector.PrintVector();
  std::cout << complex_stat_vector.L2norm() << std::endl;
  
}
