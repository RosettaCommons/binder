// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Gabriel Studer, Gerardo Tauriello
// 
// Based on mmtf_c developed by Julien Ferte (http://www.julienferte.com/),
// Anthony Bradley, Thomas Holder with contributions from Yana Valasatava,
// Gazal Kalyan, Alexander Rose.
//
// *************************************************************************

#ifndef MMTF_DECODER_H
#define MMTF_DECODER_H

#include "structure_data.hpp"
#include "errors.hpp"
#include "msgpack_decoder.hpp"

#include <msgpack.hpp>
#include <fstream>
#include <sstream>
#include <string>

namespace mmtf {

/**
 * @brief Decode an MMTF data structure from a byte buffer.
 * @param[out] data   MMTF data structure to be filled
 * @param[in]  buffer File contents
 * @param[in]  size   Size of buffer
 * @throw mmtf::DecodeError if an error occured
 */
inline void decodeFromBuffer(StructureData& data, const char* buffer,
                             size_t size);

/**
 * @brief Decode an MMTF data structure from a stream.
 *
 * Note that the full stream is read until the end before decoding it!
 *
 * @param[out] data   MMTF data structure to be filled
 * @param[in]  stream Any stream type compatible to std::ostream
 * @throw mmtf::DecodeError if an error occured
 */
template <typename Stream>
inline void decodeFromStream(StructureData& data, Stream& stream);

/**
 * @brief Decode an MMTF data structure from an existing file.
 * @param[out] data     MMTF data structure to be filled
 * @param[in]  filename Path to file to load
 * @throw mmtf::DecodeError if an error occured
 */
inline void decodeFromFile(StructureData& data, const std::string& filename);

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************

inline void decodeFromBuffer(StructureData& data, const char* buffer,
                             size_t size) {
    // load msgpack object and directly convert it
    msgpack::unpacked upd;
    msgpack::unpack(upd, buffer, size);
    msgpack::object obj(upd.get());
    obj.convert(data);
}

template <typename Stream>
inline void decodeFromStream(StructureData& data, Stream& stream) {
    // parse with stringstream
    std::stringstream buffer;
    buffer << stream.rdbuf();
    decodeFromBuffer(data, buffer.str().data(), buffer.str().size());
}

inline void decodeFromFile(StructureData& data, const std::string& filename) {
    // read file, ios::binary is required for windows
    std::ifstream ifs(filename.c_str(), std::ifstream::in | std::ios::binary);
    if (!ifs.is_open()) {
        throw DecodeError("Could not open file: " + filename);
    }
    decodeFromStream(data, ifs);
}

} // mmtf namespace

#endif
