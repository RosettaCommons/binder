// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The author of this code is: Daniel Farrell
// 
// Based on mmtf_python, adapted to c++ standards 2018
//
// *************************************************************************
//
#ifndef MMTF_OBJECT_ENCODERS_H
#define MMTF_OBJECT_ENCODERS_H

#include "structure_data.hpp"
#include <msgpack.hpp>

namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

/* *
 * @brief encode a mmtf::GroupType to a msgpack map type.
 *
 * We must use this method for packing because 'char' is treated as an int
 * by msgpack.  We cannot use the prepackaged intrusive method.
 *
 * Also we use this because 3 fields are optional!
 */
template <>
struct object_with_zone<mmtf::GroupType> {
  void operator()(msgpack::object::with_zone& o, mmtf::GroupType const& v) const {
    int this_size = 9;
    bool use_bondAtom = true, use_bondOrder = true, use_bondResonance = true;
    if (mmtf::isDefaultValue(v.bondAtomList)) {
      use_bondAtom = false;
      --this_size;
    }
    if (mmtf::isDefaultValue(v.bondOrderList)) {
      use_bondOrder = false;
      --this_size;
    }
    if (mmtf::isDefaultValue(v.bondResonanceList)) {
      use_bondResonance = false;
      --this_size;
    }
    o.type = type::MAP;
    o.via.map.size = this_size;
    o.via.map.ptr = static_cast<msgpack::object_kv*>(o.zone.allocate_align(sizeof(msgpack::object_kv)*this_size, MSGPACK_ZONE_ALIGNOF(msgpack::object_kv)));
    int current_size = 0;
    o.via.map.ptr[current_size].key = msgpack::object("formalChargeList", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(v.formalChargeList, o.zone);
    ++current_size;
    o.via.map.ptr[current_size].key = msgpack::object("atomNameList", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(v.atomNameList, o.zone);
    ++current_size;
    o.via.map.ptr[current_size].key = msgpack::object("elementList", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(v.elementList, o.zone);
    ++current_size;
    o.via.map.ptr[current_size].key = msgpack::object("groupName", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(v.groupName, o.zone);
    ++current_size;
    o.via.map.ptr[current_size].key = msgpack::object("singleLetterCode", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(std::string(1,v.singleLetterCode), o.zone);
    ++current_size;
    o.via.map.ptr[current_size].key = msgpack::object("chemCompType", o.zone);
    o.via.map.ptr[current_size].val = msgpack::object(v.chemCompType, o.zone);
    ++current_size;
    if (use_bondAtom) {
      o.via.map.ptr[current_size].key = msgpack::object("bondAtomList", o.zone);
      o.via.map.ptr[current_size].val = msgpack::object(v.bondAtomList, o.zone);
      ++current_size;
    }
    if (use_bondOrder) {
      o.via.map.ptr[current_size].key = msgpack::object("bondOrderList", o.zone);
      o.via.map.ptr[current_size].val = msgpack::object(v.bondOrderList, o.zone);
      ++current_size;
    }
    if (use_bondResonance) {
      o.via.map.ptr[current_size].key = msgpack::object("bondResonanceList", o.zone);
      o.via.map.ptr[current_size].val = msgpack::object(v.bondResonanceList, o.zone);
      ++current_size;
    }
  }
};

} // namespace adaptor
} // MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
} // namespace msgpack

#endif
