// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The author of this code is: Daniel Farrell
// 
// Based on mmtf_python, adapted to c++ standards 2018
//
// *************************************************************************


#ifndef MMTF_ENCODER_H
#define MMTF_ENCODER_H

#include "structure_data.hpp"
#include "errors.hpp"
#include "object_encoders.hpp"
#include "binary_encoder.hpp"
#include <string>
#include <fstream>

namespace mmtf {

/**
 * @brief Encode an MMTF data structure into a file.
 * @param[in] data          MMTF data structure to be stored
 * @param[in] filename      Path to file to load
 * @param[in] coord_divider               Divisor for coordinates
 * @param[in] occupancy_b_factor_divider  Divisor for occupancy and b-factor
 * @param[in] chain_name_max_length       Max. length for chain name strings
 * @throw mmtf::EncodeError if an error occurred
 *
 * Common settings for the divisors are the default values for a loss-less
 * encoding and both set to 10 for a lossy variant.
 */
inline void encodeToFile(const StructureData& data,
    const std::string& filename, int32_t coord_divider = 1000,
    int32_t occupancy_b_factor_divider = 100,
    int32_t chain_name_max_length  = 4);

/**
 * @brief Encode an MMTF data structure into a stream.
 * @param[in] data          MMTF data structure to be stored
 * @param[in] stream        Stream to encode to
 *
 * Other parameters and behavior are as in ::encodeToFile, but this enables you
 * to store the data to other types of storage.
 */
template <typename Stream>
inline void encodeToStream(const StructureData& data, Stream& stream,
    int32_t coord_divider = 1000, int32_t occupancy_b_factor_divider = 100,
    int32_t chain_name_max_length = 4);

/**
 * @brief Encode an MMTF data structure into a map of msgpack objects.
 * @param[in] data     MMTF data structure to be stored
 * @param[in] m_zone   msgpack::zone object to use
 * @return             Object which can be modified and passed to msgpack::pack
 *
 * Other parameters and behavior are as in ::encodeToFile, but this enables you
 * to add additional fields before packing.
 */
inline std::map<std::string, msgpack::object>
encodeToMap(const StructureData& data, msgpack::zone& m_zone,
    int32_t coord_divider = 1000, int32_t occupancy_b_factor_divider = 100,
    int32_t chain_name_max_length = 4);

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************
inline void encodeToFile(const StructureData& data,
    const std::string& filename, int32_t coord_divider,
    int32_t occupancy_b_factor_divider, int32_t chain_name_max_length) {
    // encode to a file
    std::ofstream ofs(filename.c_str(), std::ios::binary | std::ios::out );
    if ( !ofs ) {
        throw EncodeError("Could not open >" + filename + "< for writing, exiting.");
    }
    encodeToStream(data, ofs, coord_divider,
      occupancy_b_factor_divider, chain_name_max_length);
}

template <typename Stream>
inline void encodeToStream(const StructureData& data, Stream& stream,
    int32_t coord_divider, int32_t occupancy_b_factor_divider,
    int32_t chain_name_max_length) {
  msgpack::zone _zone;
  msgpack::pack(stream, encodeToMap(data, _zone, coord_divider,
              occupancy_b_factor_divider, chain_name_max_length));
}

inline std::map<std::string, msgpack::object>
encodeToMap(const StructureData& data, msgpack::zone& m_zone,
    int32_t coord_divider, int32_t occupancy_b_factor_divider,
    int32_t chain_name_max_length) {
  if (!data.hasConsistentData(true, chain_name_max_length)) {
    throw mmtf::EncodeError("mmtf EncoderError, StructureData does not have Consistent data... exiting!");
  }


  std::map<std::string, msgpack::object> data_map;
  // std::string
  data_map["mmtfVersion"] = msgpack::object(data.mmtfVersion, m_zone);
  data_map["mmtfProducer"] = msgpack::object(data.mmtfProducer, m_zone);
  if (!mmtf::isDefaultValue(data.spaceGroup)) {
    data_map["spaceGroup"] = msgpack::object(data.spaceGroup, m_zone);
  }
  if (!mmtf::isDefaultValue(data.structureId)) {
    data_map["structureId"] = msgpack::object(data.structureId, m_zone);
  }
  if (!mmtf::isDefaultValue(data.title)) {
    data_map["title"] = msgpack::object(data.title, m_zone);
  }
  if (!mmtf::isDefaultValue(data.depositionDate)) {
    data_map["depositionDate"] = msgpack::object(data.depositionDate, m_zone);
  }
  if (!mmtf::isDefaultValue(data.releaseDate)) {
    data_map["releaseDate"] = msgpack::object(data.releaseDate, m_zone);
  }
  // std::vector<std::string>
  data_map["chainIdList"] = msgpack::object(mmtf::encodeStringVector(data.chainIdList, chain_name_max_length), m_zone);
  if (!mmtf::isDefaultValue(data.chainNameList)) {
    data_map["chainNameList"] = msgpack::object(mmtf::encodeStringVector(data.chainNameList, chain_name_max_length), m_zone);
  }
  if (!mmtf::isDefaultValue(data.experimentalMethods)) {
    data_map["experimentalMethods"] =
      msgpack::object(data.experimentalMethods, m_zone);
  }
  // std::vector<char>
  if (!mmtf::isDefaultValue(data.altLocList)) {
    data_map["altLocList"] =
      msgpack::object(mmtf::encodeRunLengthChar(data.altLocList), m_zone);
  }
  if (!mmtf::isDefaultValue(data.insCodeList)) {
    data_map["insCodeList"] = msgpack::object(mmtf::encodeRunLengthChar(data.insCodeList), m_zone);
  }
  // std::vector<int8_t>
  if (!mmtf::isDefaultValue(data.bondOrderList)) {
    data_map["bondOrderList"] =
      msgpack::object(mmtf::encodeInt8ToByte(data.bondOrderList), m_zone);
  }
  // std::vector<int8_t>
  if (!mmtf::isDefaultValue(data.bondResonanceList)) {
    data_map["bondResonanceList"] =
      msgpack::object(mmtf::encodeRunLengthInt8(data.bondResonanceList), m_zone);
  }
  if (!mmtf::isDefaultValue(data.secStructList)) {
    data_map["secStructList"] =
      msgpack::object(mmtf::encodeInt8ToByte(data.secStructList), m_zone);
  }
  // int32_t
  data_map["numBonds"] = msgpack::object(data.numBonds, m_zone);
  data_map["numAtoms"] = msgpack::object(data.numAtoms, m_zone);
  data_map["numGroups"] = msgpack::object(data.numGroups, m_zone);
  data_map["numChains"] = msgpack::object(data.numChains, m_zone);
  data_map["numModels"] = msgpack::object(data.numModels, m_zone);
  // std::vector<int32_t>
  data_map["groupTypeList"] = msgpack::object(mmtf::encodeFourByteInt(data.groupTypeList), m_zone);
  data_map["groupIdList"] = msgpack::object(mmtf::encodeRunLengthDeltaInt(data.groupIdList), m_zone);
  data_map["groupsPerChain"] = msgpack::object(data.groupsPerChain, m_zone);
  data_map["chainsPerModel"] = msgpack::object(data.chainsPerModel, m_zone);
  if (!mmtf::isDefaultValue(data.bondAtomList)) {
    data_map["bondAtomList"] = msgpack::object(mmtf::encodeFourByteInt(data.bondAtomList), m_zone);
  }
  if (!mmtf::isDefaultValue(data.atomIdList)) {
    data_map["atomIdList"] = msgpack::object(mmtf::encodeRunLengthDeltaInt(data.atomIdList), m_zone);
  }
  if (!mmtf::isDefaultValue(data.sequenceIndexList)) {
    data_map["sequenceIndexList"] = msgpack::object(mmtf::encodeRunLengthDeltaInt(data.sequenceIndexList), m_zone);
  }
  // float
  if (!mmtf::isDefaultValue(data.resolution)) {
    data_map["resolution"] = msgpack::object(data.resolution, m_zone);
  }
  if (!mmtf::isDefaultValue(data.rFree)) {
    data_map["rFree"] = msgpack::object(data.rFree, m_zone);
  }
  if (!mmtf::isDefaultValue(data.rWork)) {
    data_map["rWork"] = msgpack::object(data.rWork, m_zone);
  }
  // std::vector<float>
  data_map["xCoordList"] = msgpack::object(mmtf::encodeDeltaRecursiveFloat(data.xCoordList, coord_divider), m_zone);
  data_map["yCoordList"] = msgpack::object(mmtf::encodeDeltaRecursiveFloat(data.yCoordList, coord_divider), m_zone);
  data_map["zCoordList"] = msgpack::object(mmtf::encodeDeltaRecursiveFloat(data.zCoordList, coord_divider), m_zone);
  if (!mmtf::isDefaultValue(data.bFactorList)) {
    data_map["bFactorList"] = msgpack::object(mmtf::encodeDeltaRecursiveFloat(data.bFactorList, occupancy_b_factor_divider), m_zone);
  }
  if (!mmtf::isDefaultValue(data.occupancyList)) {
    data_map["occupancyList"] = msgpack::object(mmtf::encodeRunLengthFloat(data.occupancyList, occupancy_b_factor_divider), m_zone);
  }
  if (!mmtf::isDefaultValue(data.unitCell)) {
      data_map["unitCell"] = msgpack::object(data.unitCell, m_zone);
  }
  // std::vector<GroupType>
  data_map["groupList"] = msgpack::object(data.groupList, m_zone);
  // std::vector<BioAssembly>
  if (!mmtf::isDefaultValue(data.bioAssemblyList)) {
    data_map["bioAssemblyList"] = msgpack::object(data.bioAssemblyList, m_zone);
  }
  // std::vector<Entity>
  if (!mmtf::isDefaultValue(data.entityList)) {
    data_map["entityList"] = msgpack::object(data.entityList, m_zone);
  }
  // std::vector<std::vector<float>>
  if (!mmtf::isDefaultValue(data.ncsOperatorList)) {
    data_map["ncsOperatorList"] = msgpack::object(data.ncsOperatorList, m_zone);
  }
  // extraProperties
  if (!mmtf::isDefaultValue(data.bondProperties)) {
    data_map["bondProperties"] = msgpack::object(data.bondProperties, m_zone);
  }
  if (!mmtf::isDefaultValue(data.atomProperties)) {
    data_map["atomProperties"] = msgpack::object(data.atomProperties, m_zone);
  }
  if (!mmtf::isDefaultValue(data.groupProperties)) {
    data_map["groupProperties"] = msgpack::object(data.groupProperties, m_zone);
  }
  if (!mmtf::isDefaultValue(data.chainProperties)) {
    data_map["chainProperties"] = msgpack::object(data.chainProperties, m_zone);
  }
  if (!mmtf::isDefaultValue(data.modelProperties)) {
    data_map["modelProperties"] = msgpack::object(data.modelProperties, m_zone);
  }
  if (!mmtf::isDefaultValue(data.extraProperties)) {
    data_map["extraProperties"] = msgpack::object(data.extraProperties, m_zone);
  }
  return data_map;
}

} // mmtf namespace

#endif
