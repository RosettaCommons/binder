// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Gerardo Tauriello, and Daniel Farrell.
//
// Based on mmtf_c developed by Julien Ferte (http://www.julienferte.com/),
// Anthony Bradley, Thomas Holder with contributions from Yana Valasatava,
// Gazal Kalyan, Alexander Rose
//
// *************************************************************************

#ifndef MMTF_BINARY_DECODER_H
#define MMTF_BINARY_DECODER_H

#include "structure_data.hpp"
#include "errors.hpp"

#include <msgpack.hpp>
#include <cstring> // low level mem
#include <sstream>
#include <limits>
#include <algorithm>

namespace mmtf {

/**
 * @brief Helper class to decode msgpack binary into a vector.
 */
class BinaryDecoder {
public:
    /**
     * @brief Initialize object given a msgpack object.
     * Reads out binary header to prepare for call of decode.
     * @param[in]  obj  Object to decode.
     * @param[in]  key  Key used to report errors.
     * @throw mmtf::DecodeError if obj is not a binary or is too short.
     */
    BinaryDecoder(const msgpack::object& obj,
                  const std::string& key = "UNNAMED_BINARY");

    /**
     * @brief Decode binary msgpack object into the given target.
     *
     * @param[out] target   Store decoded vector into this field.
     *
     * @tparam T Can be one of:
     *           - std::vector<float>       (strategies: 1, 9, 10, 11, 12, 13)
     *           - std::vector<int8_t>      (strategies: 2, 16)
     *           - std::vector<int16_t>     (strategies: 3)
     *           - std::vector<int32_t>     (strategies: 4, 7, 8, 14, 15)
     *           - std::vector<std::string> (strategies: 5)
     *           - std::vector<char>        (strategies: 6)
     *
     * @throw mmtf::DecodeError if we fail to decode.
     */
    template<typename T>
    void decode(T& target);

private:
    // for error reporting
    std::string key_;
    // data from binary header
    int32_t strategy_;
    int32_t length_;
    int32_t parameter_;
    const char* encodedData_;
    uint32_t encodedDataLength_;  // max. size for binary is 2^32 - 1

    // check length consistency (throws)
    void checkLength_(int32_t exp_length);
    // check if binary data is divisible by x (throws)
    void checkDivisibleBy_(int32_t item_size);

    // byte decoders
    void decodeFromBytes_(std::vector<float>& output);
    void decodeFromBytes_(std::vector<int8_t>& output);
    void decodeFromBytes_(std::vector<int16_t>& output);
    void decodeFromBytes_(std::vector<int32_t>& output);
    // special one: decode to vector of strings
    void decodeFromBytes_(std::vector<std::string>& output);

    // run length decoding
    // -> Int and IntOut can be any integer types
    // -> Int values are blindly converted to IntOut
    template<typename Int, typename IntOut>
    void runLengthDecode_(const std::vector<Int>& input,
                          std::vector<IntOut>& output);

    // delta decoding -> Int can be any integer type
    template<typename Int>
    void deltaDecode_(const std::vector<Int>& input, std::vector<Int>& output);
    // variant doing it in-place
    template<typename Int>
    void deltaDecode_(std::vector<Int>& in_out);

    // recursive indexing decode -> SmallInt must be smaller than Int
    template<typename SmallInt, typename Int>
    void recursiveIndexDecode_(const std::vector<SmallInt>& input,
                               std::vector<Int>& output);

    // decode integer to float -> Int can be any integer type
    template<typename Int>
    void decodeDivide_(const std::vector<Int>& input, float divisor,
                       std::vector<float>& output);
};

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************

// helpers in anonymous namespace (only visible in this file)
namespace {

// byteorder functions ("ntohl" etc.)
#ifdef WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#ifndef __EMSCRIPTEN__
void assignBigendian4(void* dst, const char* src) {
    *((uint32_t*)dst) = ntohl(*((uint32_t*)src));
}

void assignBigendian2(void* dst, const char* src) {
    *((uint16_t*)dst) = ntohs(*((uint16_t*)src));
}
#else
// Need to avoid how emscripten handles memory
// Note that this will only work on little endian machines, but this should not be a major
//      an issue as Emscripten only supports little endian hardware.
// see: https://kripken.github.io/emscripten-site/docs/porting/guidelines/portability_guidelines.html

void assignBigendian4(void* dst, const char* src) {
    ((uint8_t*)dst)[0] = src[3];
    ((uint8_t*)dst)[1] = src[2];
    ((uint8_t*)dst)[2] = src[1];
    ((uint8_t*)dst)[3] = src[0];
}

void assignBigendian2(void* dst, const char* src) {
    ((uint8_t*)dst)[0] = src[1];
    ((uint8_t*)dst)[1] = src[0];
}
#endif

void arrayCopyBigendian4(void* dst, const char* src, size_t n) {
    for (size_t i = 0; i < n; i += 4) {
        assignBigendian4(((char*)dst) + i, src + i);
    }
}

void arrayCopyBigendian2(void* dst, const char* src, size_t n) {
    for (size_t i = 0; i < n; i += 2) {
        assignBigendian2(((char*)dst) + i, src + i);
    }
}

} // anon ns

inline BinaryDecoder::BinaryDecoder(const msgpack::object& obj,
                                    const std::string& key)
                                   : key_(key) {
    // sanity checks
    if (obj.type != msgpack::type::BIN) {
        throw DecodeError("The '" + key + "' entry is not binary data");
    }
    if (obj.via.bin.size < 12) {
        std::stringstream err;
        err << "The '" + key + "' entry is too short " << obj.via.bin.size;
        throw DecodeError(err.str());
    }
    // get data (encoded data is only pointed to and not parsed here)
    const char* bytes = obj.via.bin.ptr;

    assignBigendian4(&strategy_, bytes);
    assignBigendian4(&length_, bytes + 4);
    assignBigendian4(&parameter_, bytes + 8);
    encodedData_ = bytes + 12;
    encodedDataLength_ = obj.via.bin.size - 12;
}

template<typename T>
void BinaryDecoder::decode(T& target) {
    throw mmtf::DecodeError("Invalid target type for binary '" + key_ + "'");
}

template<>
inline void BinaryDecoder::decode(std::vector<float>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 1: {
        decodeFromBytes_(output);
        break;
    }
    case 9: {
        std::vector<int32_t> step1;
        std::vector<int32_t> step2;
        decodeFromBytes_(step1);
        runLengthDecode_(step1, step2);
        decodeDivide_(step2, static_cast<float>(parameter_), output);
        break;
    }
    case 10: {
        std::vector<int16_t> step1;
        std::vector<int32_t> step2;
        decodeFromBytes_(step1);
        recursiveIndexDecode_(step1, step2);
        deltaDecode_(step2);
        decodeDivide_(step2, static_cast<float>(parameter_), output);
        break;
    }
    case 11: {
        std::vector<int16_t> step1;
        decodeFromBytes_(step1);
        decodeDivide_(step1, static_cast<float>(parameter_), output);
        break;
    }
    case 12: {
        std::vector<int16_t> step1;
        std::vector<int32_t> step2;
        decodeFromBytes_(step1);
        recursiveIndexDecode_(step1, step2);
        decodeDivide_(step2, static_cast<float>(parameter_), output);
        break;
    }
    case 13: {
        std::vector<int8_t> step1;
        std::vector<int32_t> step2;
        decodeFromBytes_(step1);
        recursiveIndexDecode_(step1, step2);
        decodeDivide_(step2, static_cast<float>(parameter_), output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to float array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

template<>
inline void BinaryDecoder::decode(std::vector<int8_t>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 2: {
        decodeFromBytes_(output);
        break;
    }
    case 16: {
        std::vector<int32_t> step1;
        decodeFromBytes_(step1);
        runLengthDecode_(step1, output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to int8 array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

template<>
inline void BinaryDecoder::decode(std::vector<int16_t>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 3: {
        decodeFromBytes_(output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to int16 array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

template<>
inline void BinaryDecoder::decode(std::vector<int32_t>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 4: {
        decodeFromBytes_(output);
        break;
    }
    case 7: {
        std::vector<int32_t> step1;
        decodeFromBytes_(step1);
        runLengthDecode_(step1, output);
        break;
    }
    case 8: {
        std::vector<int32_t> step1;
        decodeFromBytes_(step1);
        runLengthDecode_(step1, output);
        deltaDecode_(output);
        break;
    }
    case 14: {
        std::vector<int16_t> step1;
        decodeFromBytes_(step1);
        recursiveIndexDecode_(step1, output);
        break;
    }
    case 15: {
        std::vector<int8_t> step1;
        decodeFromBytes_(step1);
        recursiveIndexDecode_(step1, output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to int32 array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

template<>
inline void BinaryDecoder::decode(std::vector<std::string>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 5: {
        decodeFromBytes_(output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to string array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

template<>
inline void BinaryDecoder::decode(std::vector<char>& output) {

    // check strategy to parse
    switch (strategy_) {
    case 6: {
        std::vector<int32_t> step1;
        decodeFromBytes_(step1);
        runLengthDecode_(step1, output);
        break;
    }
    default: {
        std::stringstream err;
        err << "Invalid strategy " << strategy_ << " for binary '" + key_
            << "': does not decode to string array";
        throw DecodeError(err.str());
    }
    }

    // check size
    checkLength_(output.size());
}

// checks
inline void BinaryDecoder::checkLength_(int32_t exp_length) {
    if (length_ != exp_length) {
        std::stringstream err;
        err << "Length mismatch for binary '" + key_ + "': "
            << length_ << " vs " << exp_length;
        throw DecodeError(err.str());
    }
}

inline void BinaryDecoder::checkDivisibleBy_(int32_t item_size) {
    if (encodedDataLength_ % item_size != 0) {
        std::stringstream err;
        err << "Binary length of '" + key_ + "': "
            << encodedDataLength_ << " is not a multiple of " << item_size;
        throw DecodeError(err.str());
    }
}

// byte decoders
inline void BinaryDecoder::decodeFromBytes_(std::vector<float>& output) {
    checkDivisibleBy_(4);
    // prepare memory
    output.resize(encodedDataLength_ / 4);
    // get data
    if(!output.empty()) {
        arrayCopyBigendian4(&output[0], encodedData_, encodedDataLength_);
    }
}
inline void BinaryDecoder::decodeFromBytes_(std::vector<int8_t>& output) {
    // prepare memory
    output.resize(encodedDataLength_);
    // get data
    if (!output.empty()) {
        memcpy(&output[0], encodedData_, encodedDataLength_);
    }
}
inline void BinaryDecoder::decodeFromBytes_(std::vector<int16_t>& output) {
    checkDivisibleBy_(2);
    // prepare memory
    output.resize(encodedDataLength_ / 2);
    // get data
    if (!output.empty()) {
        arrayCopyBigendian2(&output[0], encodedData_, encodedDataLength_);
    }
}
inline void BinaryDecoder::decodeFromBytes_(std::vector<int32_t>& output) {
    checkDivisibleBy_(4);
    // prepare memory
    output.resize(encodedDataLength_ / 4);
    // get data
    if (!output.empty()) {
        arrayCopyBigendian4(&output[0], encodedData_, encodedDataLength_);
    }
}
// special one: decode to vector of strings
inline void BinaryDecoder::decodeFromBytes_(std::vector<std::string>& output) {
    char NULL_BYTE = 0x00;
    // check parameter
    const int32_t str_len = parameter_;
    checkDivisibleBy_(str_len);
    // prepare memory
    output.resize(encodedDataLength_ / str_len);
    // get data
    for (size_t i = 0; i < output.size(); ++i) {
        output[i].assign(encodedData_ + i * str_len, str_len);
        output[i].erase(std::remove(output[i].begin(), output[i].end(), NULL_BYTE), output[i].end());
    }
}

// run length decoding
template<typename Int, typename IntOut>
void BinaryDecoder::runLengthDecode_(const std::vector<Int>& input,
                      std::vector<IntOut>& output) {
    // we work with pairs of numbers
    checkDivisibleBy_(2);
    // find out size of resulting vector (for speed)
    size_t out_size = 0;
    for (size_t i = 0; i < input.size(); i += 2) {
        out_size += input[i + 1];
    }
    // reserve space (for speed)
    output.clear();
    output.reserve(out_size);
    // get data
    for (size_t i = 0; i < input.size(); i += 2) {
        const IntOut value = IntOut(input[i]);
        const Int number = input[i+1];
        for (Int j = 0; j < number; ++j) {
            output.push_back(value);
        }
    }
}

// delta decoding
template<typename Int>
void BinaryDecoder::deltaDecode_(const std::vector<Int>& input,
                                 std::vector<Int>& output) {
    // reserve space (for speed)
    output.clear();
    if (input.empty()) return; // ensure we have some values
    output.reserve(input.size());
    // get data
    output.push_back(input[0]);
    for (size_t i = 1; i < input.size(); ++i) {
        output.push_back(output[i - 1] + input[i]);
    }
}
template<typename Int>
void BinaryDecoder::deltaDecode_(std::vector<Int>& in_out) {
    for (size_t i = 1; i < in_out.size(); ++i) {
        in_out[i] = in_out[i - 1] + in_out[i];
    }
}

// recursive indexing decode
template<typename SmallInt, typename Int>
void BinaryDecoder::recursiveIndexDecode_(const std::vector<SmallInt>& input,
                                          std::vector<Int>& output) {
    // get limits
    const SmallInt min_int = std::numeric_limits<SmallInt>::min();
    const SmallInt max_int = std::numeric_limits<SmallInt>::max();
    // find out size of resulting vector (for speed)
    size_t out_size = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != min_int && input[i] != max_int) ++out_size;
    }
    // reserve space (for speed)
    output.clear();
    output.reserve(out_size);
    // get data
    Int cur_val = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        cur_val += input[i];
        if (input[i] != min_int && input[i] != max_int) {
            output.push_back(cur_val);
            cur_val = 0;
        }
    }
}

// decode integer to float
template<typename Int>
void BinaryDecoder::decodeDivide_(const std::vector<Int>& input, float divisor,
                                  std::vector<float>& output) {
    // reserve space and get inverted divisor (for speed)
    output.clear();
    output.reserve(input.size());
    float inv_div = float(1) / divisor;
    // get data
    for (size_t i = 0; i < input.size(); ++i) {
        output.push_back(float(input[i]) * inv_div);
    }
}

} // mmtf namespace

#endif
