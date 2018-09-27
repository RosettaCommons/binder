// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
#ifndef _SRC_template_lib_h_hpp_
#define _SRC_template_lib_h_hpp_
#include <complex>
#include <vector>

namespace lib_namespace {
  template <typename FloatType = double>
  class StatVector {    
  public:
    std::vector<FloatType> GetVector() {return data_vector_;};
    void SetVector(const std::vector<FloatType> &data_input);
    void SetVector(FloatType data_input, int total_elements);
    FloatType L2norm();
    void PrintVector();
  private:
    std::vector<FloatType> data_vector_;
  };  // end of class StatVector
}  // end of namespace lib_namespace


#endif // _SRC_template_lib_h_hpp_
