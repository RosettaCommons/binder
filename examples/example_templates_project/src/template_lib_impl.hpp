// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
#ifndef _SRC_template_lib_impl_hpp_
#define _SRC_template_lib_impl_hpp_

#include <template_lib_h.hpp>
//#include <binder_explicit_instantiation.hpp>
#include <cmath>
#include <iostream>

namespace lib_namespace
{
  template<class T> inline T pow2(const T value) {return value*value;}

  template <typename FloatType>
  void StatVector<FloatType>::PrintVector()
  {
    for (auto e : data_vector_)
      std::cout << e << " ";
    std::cout << std::endl;
  }
                                        
  template <typename FloatType>
  void StatVector<FloatType>::SetVector(const std::vector<FloatType> &data_input)
  {
    data_vector_.resize(data_input.size());
    for (int i = 0; i < data_input.size(); ++i)
        data_vector_[i] = data_input[i];
  }

  template <typename FloatType>
  void StatVector<FloatType>::SetVector(FloatType data_input, int total_elements)
  {
    data_vector_.resize(total_elements);
    for (auto &element : data_vector_)
      element = data_input;
  }

  template <typename FloatType>
  FloatType StatVector<FloatType>::L2norm()
  {
    FloatType sum = 0; 
    for (auto &element : data_vector_)
      {
        sum += pow2(element);
      }
    return std::sqrt(sum);
  }
	
	StatVector <double> stat_vec;
	StatVector <std::complex<double> > stat_vec_complex;
	
	template class lib_namespace::StatVector<double>;
	template class lib_namespace::StatVector<std::complex<double> >;
	
}  // end of namespace lib_namespace

#endif // _SRC_template_lib_impl_hpp_
