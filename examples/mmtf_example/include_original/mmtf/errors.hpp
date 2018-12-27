// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Gerardo Tauriello
// 
// Based on mmtf_c developed by Julien Ferte (http://www.julienferte.com/),
// Anthony Bradley, Thomas Holder with contributions from Yana Valasatava,
// Gazal Kalyan, Alexander Rose. Updated 2018 by Daniel Farrell.
//
// *************************************************************************

#ifndef MMTF_ERRORS_H
#define MMTF_ERRORS_H

#include <stdexcept>

namespace mmtf {

/**
 * @brief Exception thrown when failing during decoding.
 */
class DecodeError: public std::runtime_error {
public:
    DecodeError(const std::string& m): std::runtime_error(m) { }
};

/**
 * @brief Exception thrown when failing during encoding.
 */
class EncodeError: public std::runtime_error {
public:
    EncodeError(const std::string& m): std::runtime_error(m) { }
};

} // mmtf namespace

#endif
