// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Gabriel Studer, Gerardo Tauriello, and
// Daniel Farrell.
// 
// Based on mmtf_c developed by Julien Ferte (http://www.julienferte.com/),
// Anthony Bradley, Thomas Holder with contributions from Yana Valasatava,
// Gazal Kalyan, Alexander Rose.
//
// *************************************************************************

#ifndef MMTF_MAP_DECODER_H
#define MMTF_MAP_DECODER_H

#include "structure_data.hpp"
#include "binary_decoder.hpp"
#include "errors.hpp"

#include <msgpack.hpp>
#include <map>
#include <iostream>

namespace mmtf {

/**
 * @brief Helper class to decode msgpack maps into object fields.
 */
class MapDecoder {
public:
    /**
     * @brief Initialize object given a msgpack object.
     * Reads out all key-value pairs and converts key to string if possible
     * (warns otherwise).
     * @throw mmtf::DecodeError if obj is not a map.
     */
    MapDecoder(const msgpack::object& obj);

    /**
     * @brief Initialize object given a string to msgpack::object map.
     * Reads out all key-value pairs and converts key to string if possible
     * (warns otherwise).
     */
    MapDecoder(std::map<std::string, msgpack::object>& map_in);

    /**
     * @brief Extract value from map and decode into target.
     *
     * @param[in]  key      Key into msgpack map.
     * @param[in]  required True if field is required by MMTF specs.
     * @param[out] target   Store decoded value into this field.
     *
     * If msgpack type is not as expected, we write a warning to stderr.
     * If conversion to the target type fails, msgpack throws an exception.
     * If a required field is missing in the map or if binary decoding fails,
     * we throw an mmtf::DecodeError.
     */
    template<typename T>
    void decode(const std::string& key, bool required, T& target);

    /**
     * @brief Check if there are any keys, that were not decoded.
     * This is to be called after all expected fields have been decoded.
     * A warning is written to stderr for each non-decoded key.
     */
    void checkExtraKeys();

private:
    // key-value pairs extracted from msgpack map
    std::map<std::string, msgpack::object*> data_map_;
    // set of keys that were successfully decoded
    std::set<std::string> decoded_keys_;

    // type checking (note: doesn't check array elements)
    // -> only writes warning to cerr
    // -> exception thrown by msgpack if conversion fails
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    const float& target);
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    const int32_t& target);
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    const char& target);
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    const std::string& target);
    void checkType_(const std::string& key,
                    msgpack::type::object_type type,
                    const msgpack::object& target);
    void checkType_(const std::string& key,
                    msgpack::type::object_type type,
                    const std::map<std::string, msgpack::object>& target);
    template <typename T>
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    const std::vector<T>& target);
    template <typename T>
    void checkType_(const std::string& key, msgpack::type::object_type type,
                    T* target);
};

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************

inline MapDecoder::MapDecoder(const msgpack::object& obj) {
    // sanity checks
    if (obj.type != msgpack::type::MAP) {
        throw DecodeError("Expected msgpack type to be MAP");
    }
    // get data
    msgpack::object_kv* current_key_value = obj.via.map.ptr;
    msgpack::object_kv* last_key_value = current_key_value + obj.via.map.size;
    for (; current_key_value != last_key_value; ++current_key_value) { 
        msgpack::object* key = &(current_key_value->key); 
        msgpack::object* value = &(current_key_value->val); 
        if (key->type == msgpack::type::STR) {        
            std::string data_map_key(key->via.str.ptr, key->via.str.size);
            data_map_[data_map_key] = value;
        } else {
            std::cerr << "Warning: Found non-string key type " << key->type
                      << "! Skipping..." << std::endl;
        }
    }
}

inline MapDecoder::MapDecoder(std::map<std::string, msgpack::object>& map_in) {
    std::map<std::string, msgpack::object>::iterator it;
    for (it=map_in.begin(); it!= map_in.end(); ++it) {
        data_map_[it->first] = &(it->second);
    }
}

template<typename T>
void MapDecoder::decode(const std::string& key, bool required, T& target) {
    // note: cost of O(M*log(N)) string comparisons (M parsed, N in map)
    std::map<std::string, msgpack::object*>::iterator it;
    it = data_map_.find(key);
    if (it != data_map_.end()) {
        checkType_(key, it->second->type, target);
        if (it->second->type == msgpack::type::BIN) {
            BinaryDecoder bd(*it->second, key);
            bd.decode(target);
        } else {
            it->second->convert(target);
        }
        decoded_keys_.insert(key);
    }
    else if (required) {
        throw DecodeError("MsgPack MAP does not contain required entry "
                          + key);
    }
}

inline void MapDecoder::checkExtraKeys() {
    // note: cost of O(N*log(M))) string comparisons (M parsed, N in map)
    // simple set difference algorithm
    std::map<std::string, msgpack::object*>::iterator map_it;
    std::set<std::string>::iterator parsed_it;
    for (map_it = data_map_.begin(); map_it != data_map_.end(); ++map_it) {
         parsed_it = decoded_keys_.find(map_it->first);
         if (parsed_it == decoded_keys_.end()) {
            std::cerr << "Warning: Found non-parsed key " << map_it->first
                      << " in MsgPack MAP.\n";
         }
    }
}

inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const float& target) {
    if (type != msgpack::type::FLOAT32 && type != msgpack::type::FLOAT64) {
        std::cerr << "Warning: Non-float type " << type << " found for "
                     "entry " << key << std::endl;
    }
}
inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const int32_t& target) {
    if (   type != msgpack::type::POSITIVE_INTEGER
        && type != msgpack::type::NEGATIVE_INTEGER) {
        std::cerr << "Warning: Non-int type " << type << " found for "
                     "entry " << key << std::endl;
    }
}
inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const char& target) {
    if (type != msgpack::type::STR) {
        std::cerr << "Warning: Non-string type " << type << " found for "
                     "entry " << key << std::endl;
    }
}
inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const std::string& target) {
    if (type != msgpack::type::STR) {
        std::cerr << "Warning: Non-string type " << type << " found for "
                     "entry " << key << std::endl;
    }
}

inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const msgpack::object&)  {
    // Should we check Type of msgpack object? I don't think there's many
    // checks to be done here
}

inline void MapDecoder::checkType_(const std::string& key,
                                   msgpack::type::object_type type,
                                   const std::map<std::string, msgpack::object>& target)  {
    if (type != msgpack::type::MAP) {
        std::cerr << "Warning: Non-map type " << type << " found for "
                     "entry " << key << std::endl;
    }
}


template <typename T>
void MapDecoder::checkType_(const std::string& key,
                            msgpack::type::object_type type,
                            const std::vector<T>& target) {
    if (type != msgpack::type::ARRAY && type != msgpack::type::BIN) {
        std::cerr << "Warning: Non-array type " << type << " found for "
                     "entry " << key << std::endl;
    }
}
template <typename T>
void MapDecoder::checkType_(const std::string& key,
                            msgpack::type::object_type type,
                            T* target) {
    if (type != msgpack::type::ARRAY && type != msgpack::type::BIN) {
        std::cerr << "Warning: Non-array type " << type << " found for "
                     "entry " << key << std::endl;
    }
}

} // mmtf namespace

#endif
