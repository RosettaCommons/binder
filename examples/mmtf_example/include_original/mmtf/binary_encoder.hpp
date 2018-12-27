// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The author of this code is: Daniel Farrell
//
// Based on mmtf_python, adapted to c++ standards 2018
//
// *************************************************************************


#ifndef MMTF_BINARY_ENCODER_H
#define MMTF_BINARY_ENCODER_H
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

// byteorder functions
#ifdef WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

namespace mmtf {

// *************************************************************************
// PRIVATE FUNCTIONS (only visible in this header)
// *************************************************************************

namespace { // private helpers

/**
 * @brief Convert floats to ints via multiplier.
 * @param[in] vec_in        vector of floats
 * @param[in] multiplier    multiply float vector by this
 * @return vec_out          vec_in * multiplier and rounded
 */
inline std::vector<int32_t> convertFloatsToInts(std::vector<float> const & vec_in,
                                            int multiplier);

/**
 * @brief mmtf delta encode a vector of ints.
 * @param[in] vec_in        vector of ints
 * @return vec_out          delta encoded int vector
 */
inline std::vector<int32_t> deltaEncode(std::vector<int32_t> const & vec_in);


/**
 * @brief mmtf run length encode a vector of ints.
 * @param[in] vec_in        vector of ints
 * @return vec_out          run length encoded int vector
 */
inline std::vector<int32_t> runLengthEncode(std::vector<int32_t> const & vec_in );

/**
 * @brief mmtf run length encode a vector of ints.
 * @param[in] vec_in        vector of ints
 * @return vec_out          run length encoded int vector
 */
inline std::vector<int32_t> runLengthEncode(std::vector<int8_t> const & vec_in );

/**
 * @brief mmtf recursive index encode a vector of ints.
 * @param[in] vec_in        vector of ints
 * @param[in] max           maximum value of signed 16bit int
 * @param[in] min           minimum value of signed 16bit int
 * @return vec_out          recursive index encoded vector
 */
inline std::vector<int32_t> recursiveIndexEncode(std::vector<int32_t> const & vec_in,
                                             int max=32767, int min=-32768);

/**
 * @brief mmtf convert char to int
 * @param[in] vec_in        vector of chars
 * @return vec_out          vector of ints
 */
inline std::vector<int32_t> convertCharsToInts(std::vector<char> const & vec_in);


/**
 * @brief Add mmtf header to a stream
 * @param[in] ss            stringstream to add a header to
 * @param[in] array_size    size of array you're adding
 * @param[in] codec         the codec type number you're using to encode
 * @param[in] param         the param for the codec you're using (default 0)
 */
inline void add_header(std::stringstream & ss, uint32_t array_size, uint32_t codec, uint32_t param=0);

/**
 * @brief Convert stringstream to CharVector
 * @param[in] ss            ss to convert
 * @return                  converted ss
 */
inline std::vector<char> stringstreamToCharVector(std::stringstream & ss);

} // anon ns

// *************************************************************************
// PUBLIC FUNCTIONS
// *************************************************************************

/** encode 8 bit int to bytes encoding (type 2)
 * @param[in] vec_in        vector of ints to encode
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeInt8ToByte(std::vector<int8_t> vec_in);

/** encode 4 bytes to int encoding (type 4)
 * @param[in] vec_in        vector of ints to encode
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeFourByteInt(std::vector<int32_t> vec_in);

/** encode string vector encoding (type 5)
 * @param[in] in_sv         vector of strings
 * @param[in] CHAIN_LEN     maximum length of string
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeStringVector(std::vector<std::string> in_sv, int32_t CHAIN_LEN);


/** encode Run Length Char encoding (type 6)
 * @param[in] in_cv         vector for chars
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeRunLengthChar(std::vector<char> in_cv);


/** encode Run Length Delta Int encoding (type 8)
 * @param[in] int_vec       vector of ints
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeRunLengthDeltaInt(std::vector<int32_t> int_vec);

/** encode Run Length Float encoding (type 9)
 * @param[in] floats_in     vector of ints
 * @param[in] multiplier    float multiplier
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeRunLengthFloat(std::vector<float> floats_in, int32_t multiplier);

/** encode Delta Recursive Float encoding (type 10)
 * @param[in] floats_in     vector of ints
 * @param[in] multiplier    float multiplier
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeDeltaRecursiveFloat(std::vector<float> floats_in, int32_t multiplier);

/** encode Run-Length 8bit int encoding (type 16)
 * @param[in] floats_in     vector of ints
 * @return cv               char vector of encoded bytes
 */
inline std::vector<char> encodeRunLengthInt8(std::vector<int8_t> int8_vec);

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************

namespace { // private helpers

inline std::vector<int32_t> convertFloatsToInts(std::vector<float> const & vec_in,
                                            int multiplier) {
  std::vector<int32_t> vec_out;
  for (size_t i=0; i<vec_in.size(); ++i) {
    vec_out.push_back(static_cast<int32_t>(round(vec_in[i]*multiplier)));
  }
  return vec_out;
}


inline std::vector<int32_t> deltaEncode(std::vector<int32_t> const & vec_in) {
  std::vector<int32_t> vec_out;
  if (vec_in.size() == 0) return vec_out;
  vec_out.push_back(vec_in[0]);
  for (int32_t i=1; i< (int)vec_in.size(); ++i) {
    vec_out.push_back(vec_in[i]-vec_in[i-1]);
  }
  return vec_out;
}


inline std::vector<int32_t> runLengthEncode(std::vector<int32_t> const & vec_in ) {
  std::vector<int32_t> ret;
  if (vec_in.size()==0) return ret;
  int32_t curr = vec_in[0];
  ret.push_back(curr);
  int32_t counter = 1;
  for (std::size_t i = 1; i < vec_in.size(); ++i) {
    if ( vec_in[i] == curr ) {
      ++counter;
    } else {
      ret.push_back(counter);
      ret.push_back(vec_in[i]);
      curr = vec_in[i];
      counter = 1;
    }
  }
  ret.push_back(counter);
  return ret;
}


inline std::vector<int32_t> runLengthEncode(std::vector<int8_t> const & vec_in ) {
  std::vector<int32_t> ret;
  if (vec_in.size()==0) return ret;
  int32_t curr = vec_in[0];
  ret.push_back(curr);
  int32_t counter = 1;
  for (std::size_t i = 1; i < vec_in.size(); ++i) {
    if ( (int32_t)vec_in[i] == curr ) {
      ++counter;
    } else {
      ret.push_back(counter);
      ret.push_back((int32_t)vec_in[i]);
      curr = vec_in[i];
      counter = 1;
    }
  }
  ret.push_back(counter);
  return ret;
}


inline std::vector<int32_t> recursiveIndexEncode(
    std::vector<int32_t> const & vec_in,
    int max /* =32767 */, int min /*=-32768 */) {
  std::vector<int32_t> vec_out;
  for (int32_t i=0; i< (int)vec_in.size(); ++i) {
    int32_t x = vec_in[i];
    if ( x >= 0 ) {
      while (x >= max) {
        vec_out.push_back(max);
        x -= max;
      }
    } else {
      while (x <= min) {
        vec_out.push_back(min);
        x += std::abs(min);
      }
    }
    vec_out.push_back(x);
  }
  return vec_out;
}


inline std::vector<int32_t> convertCharsToInts(std::vector<char> const & vec_in) {
  std::vector<int32_t> vec_out;
  for (size_t i=0; i<vec_in.size(); ++i) {
    vec_out.push_back((int)vec_in[i]);
  }
  return vec_out;
}

inline void add_header(std::stringstream & ss, uint32_t array_size, uint32_t codec, uint32_t param /* =0 */) {
    uint32_t be_codec = htonl(codec);
    uint32_t be_array_size = htonl(array_size);
    uint32_t be_param = htonl(param);
    ss.write(reinterpret_cast< char * >(&be_codec), sizeof(be_codec));
    ss.write(reinterpret_cast< char * >(&be_array_size), sizeof(be_array_size));
    ss.write(reinterpret_cast< char * >(&be_param), sizeof(be_param));
}


inline std::vector<char> stringstreamToCharVector(std::stringstream & ss) {
  std::string s = ss.str();
  std::vector<char> ret(s.begin(), s.end());
  return ret;
}

} // anon ns


inline std::vector<char> encodeInt8ToByte(std::vector<int8_t> vec_in) {
  std::stringstream ss;
  add_header(ss, vec_in.size(), 2, 0);
  for (size_t i=0; i<vec_in.size(); ++i) {
    ss.write(reinterpret_cast< char * >(&vec_in[i]), sizeof(vec_in[i]));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeFourByteInt(std::vector<int32_t> vec_in) {
  std::stringstream ss;
  add_header(ss, vec_in.size(), 4, 0);
  for (size_t i=0; i<vec_in.size(); ++i) {
    int32_t be_x = htonl(vec_in[i]);
    ss.write(reinterpret_cast< char * >(&be_x), sizeof(be_x));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeStringVector(std::vector<std::string> in_sv, int32_t CHAIN_LEN) {
  char NULL_BYTE = 0x00;
  std::stringstream ss;
  add_header(ss, in_sv.size(), 5, CHAIN_LEN);
  std::vector<char> char_vec;
  for (size_t i=0; i<in_sv.size(); ++i) {
    char_vec.insert(char_vec.end(), in_sv[i].begin(), in_sv[i].end());
    for (size_t j=0; j<CHAIN_LEN-in_sv[i].size(); ++j) {
      char_vec.push_back(NULL_BYTE);
    }
  }
  for (size_t i=0; i<char_vec.size(); ++i) {
    ss.write(reinterpret_cast< char * >(&char_vec[i]), sizeof(char_vec[i]));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeRunLengthChar(std::vector<char> in_cv) {
  std::stringstream ss;
  add_header(ss, in_cv.size(), 6, 0);
  std::vector<int32_t> int_vec;
  int_vec = convertCharsToInts(in_cv);
  int_vec = runLengthEncode(int_vec);
  for (size_t i=0; i<int_vec.size(); ++i) {
    int32_t temp = htonl(int_vec[i]);
    ss.write(reinterpret_cast< char * >(&temp), sizeof(temp));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeRunLengthDeltaInt(std::vector<int32_t> int_vec) {
  std::stringstream ss;
  add_header(ss, int_vec.size(), 8, 0);
  int_vec = deltaEncode(int_vec);
  int_vec = runLengthEncode(int_vec);
  for (size_t i=0; i<int_vec.size(); ++i) {
    int32_t temp = htonl(int_vec[i]);
    ss.write(reinterpret_cast< char * >(&temp), sizeof(temp));
  }
  return stringstreamToCharVector(ss);
}

inline std::vector<char> encodeRunLengthFloat(std::vector<float> floats_in, int32_t multiplier) {
  std::stringstream ss;
  add_header(ss, floats_in.size(), 9, multiplier);
  std::vector<int32_t> int_vec = convertFloatsToInts(floats_in, multiplier);
  int_vec = runLengthEncode(int_vec);
  for (size_t i=0; i<int_vec.size(); ++i) {
    int32_t temp = htonl(int_vec[i]);
    ss.write(reinterpret_cast< char * >(&temp), sizeof(temp));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeDeltaRecursiveFloat(std::vector<float> floats_in, int32_t multiplier) {
  std::stringstream ss;
  add_header(ss, floats_in.size(), 10, multiplier);
  std::vector<int32_t> int_vec = convertFloatsToInts(floats_in, multiplier);
  int_vec = deltaEncode(int_vec);
  int_vec = recursiveIndexEncode(int_vec);
  for (size_t i=0; i<int_vec.size(); ++i) {
    int16_t temp = htons(int_vec[i]);
    ss.write(reinterpret_cast< char * >(&temp), sizeof(temp));
  }
  return stringstreamToCharVector(ss);
}


inline std::vector<char> encodeRunLengthInt8(std::vector<int8_t> int8_vec) {
  std::stringstream ss;
  add_header(ss, int8_vec.size(), 16, 0);
  std::vector<int32_t> int_vec = runLengthEncode(int8_vec);
  for (size_t i=0; i<int_vec.size(); ++i) {
    int32_t temp = htonl(int_vec[i]);
    ss.write(reinterpret_cast< char * >(&temp), sizeof(temp));
  }
  return stringstreamToCharVector(ss);
}

} // mmtf namespace
#endif
