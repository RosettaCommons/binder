// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Gabriel Studer, Gerardo Tauriellom and
// Daniel Farrell.
// 
// Based on mmtf_c developed by Julien Ferte (http://www.julienferte.com/),
// Anthony Bradley, Thomas Holder with contributions from Yana Valasatava,
// Gazal Kalyan, Alexander Rose.
//
// *************************************************************************

#ifndef MMTF_STRUCTURE_DATA_H
#define MMTF_STRUCTURE_DATA_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <sstream>
#include <limits>
#include <msgpack.hpp>
#include <iostream>
#include <iomanip>

namespace mmtf {

/**
 * @brief MMTF spec version which this library implements
 */
#define MMTF_SPEC_VERSION_MAJOR 1
#define MMTF_SPEC_VERSION_MINOR 1

/**
 * @brief Get string representation of MMTF spec version implemented here
 */
inline std::string getVersionString();

/**
 * @brief Check if version is supported (minor revisions ok, major ones not)
 * @return true if supported, false if not
 */
inline bool isVersionSupported(const std::string& version_string);

/**
 * @brief Group (residue) level data store
 *
 * https://github.com/rcsb/mmtf/blob/HEAD/spec.md#group-data
 */
struct GroupType { // NOTE: can't use MSGPACK_DEFINE_MAP due to char
    std::vector<int32_t>      formalChargeList;
    std::vector<std::string>  atomNameList;
    std::vector<std::string>  elementList;
    std::vector<int32_t>      bondAtomList;
    std::vector<int8_t>       bondOrderList;
    std::vector<int8_t>       bondResonanceList;
    std::string               groupName;
    char                      singleLetterCode;
    std::string               chemCompType;

    bool operator==(GroupType const & c) const {
      return(
        formalChargeList == c.formalChargeList &&
        atomNameList == c.atomNameList &&
        elementList == c.elementList &&
        bondAtomList == c.bondAtomList &&
        bondOrderList == c.bondOrderList &&
        bondResonanceList == c.bondResonanceList &&
        groupName == c.groupName &&
        singleLetterCode == c.singleLetterCode &&
        chemCompType == c.chemCompType);
    }
};

/**
 * @brief Entity type.
 *
 * https://github.com/rcsb/mmtf/blob/HEAD/spec.md#entitylist
 */
struct Entity {
    std::vector<int32_t> chainIndexList;
    std::string          description;
    std::string          type;
    std::string          sequence;

    bool operator==(Entity const & c) const {
      return(
        chainIndexList == c.chainIndexList &&
        description == c.description &&
        type == c.type &&
        sequence == c.sequence);
    }

    MSGPACK_DEFINE_MAP(
      chainIndexList,
      description,
      type,
      sequence);
};

/**
 * @brief Transformation definition for a set of chains.
 *
 * https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist
 */
struct Transform {
    std::vector<int32_t> chainIndexList;
    float                matrix[16];

    bool operator==(Transform const & c) const {
      bool comp = true;
      for(size_t i = 16; i--;) {
        if ( matrix[i] != c.matrix[i] ) {
          comp = false;
          break;
        }
      }
      return (chainIndexList == c.chainIndexList && comp);
    }

    MSGPACK_DEFINE_MAP(chainIndexList, matrix);
};

/**
 * @brief Data store for the biological assembly annotation.
 *
 * https://github.com/rcsb/mmtf/blob/HEAD/spec.md#bioassemblylist
 */
struct BioAssembly {
    std::vector<Transform> transformList;
    std::string            name;

    bool operator==(BioAssembly const & c) const {
        return (
            transformList == c.transformList &&
            name == c.name);
    }

    MSGPACK_DEFINE_MAP(transformList, name);
};

/**
 * @brief Top level MMTF data container.
 *
 * Default values (mmtf::isDefaultValue, mmtf::setDefaultValue) are set in
 * constructor and can be used to check if value was never set (only relevant
 * for optional values):
 * - default for vectors and strings: empty
 * - default for numeric types (incl. char): max. value of that type
 * - default for numXX = 0
 *
 * https://github.com/rcsb/mmtf/blob/HEAD/spec.md#fields
 */
struct StructureData {
    std::string                              mmtfVersion;
    std::string                              mmtfProducer;
    std::vector<float>                       unitCell;
    std::string                              spaceGroup;
    std::string                              structureId;
    std::string                              title;
    std::string                              depositionDate;
    std::string                              releaseDate;
    std::vector<std::vector<float> >         ncsOperatorList;
    std::vector<BioAssembly>                 bioAssemblyList;
    std::vector<Entity>                      entityList;
    std::vector<std::string>                 experimentalMethods;
    float                                    resolution;
    float                                    rFree;
    float                                    rWork;
    int32_t                                  numBonds;
    int32_t                                  numAtoms;
    int32_t                                  numGroups;
    int32_t                                  numChains;
    int32_t                                  numModels;
    std::vector<GroupType>                   groupList;
    std::vector<int32_t>                     bondAtomList;
    std::vector<int8_t>                      bondOrderList;
    std::vector<int8_t>                      bondResonanceList;
    std::vector<float>                       xCoordList;
    std::vector<float>                       yCoordList;
    std::vector<float>                       zCoordList;
    std::vector<float>                       bFactorList;
    std::vector<int32_t>                     atomIdList;
    std::vector<char>                        altLocList;
    std::vector<float>                       occupancyList;
    std::vector<int32_t>                     groupIdList;
    std::vector<int32_t>                     groupTypeList;
    std::vector<int8_t>                      secStructList;
    std::vector<char>                        insCodeList;
    std::vector<int32_t>                     sequenceIndexList;
    std::vector<std::string>                 chainIdList;
    std::vector<std::string>                 chainNameList;
    std::vector<int32_t>                     groupsPerChain;
    std::vector<int32_t>                     chainsPerModel;
    msgpack::zone                            msgpack_zone;
    std::map<std::string, msgpack::object>   bondProperties;
    std::map<std::string, msgpack::object>   atomProperties;
    std::map<std::string, msgpack::object>   groupProperties;
    std::map<std::string, msgpack::object>   chainProperties;
    std::map<std::string, msgpack::object>   modelProperties;
    std::map<std::string, msgpack::object>   extraProperties;

    /**
     * @brief Construct object with default values set.
     */
    StructureData();

    /**
     * @brief Check consistency of structural data.
     * @param verbose                 Print first error encountered (if any)
     * @param chain_name_max_length   Max allowed chain name length
     * @return True if all required fields are set and vector sizes and indices
     *         are consistent.
     */
    bool hasConsistentData(bool verbose=false, uint32_t chain_name_max_length = 4) const;


    /**
     * @brief Read out the contents of mmtf::StructureData in a PDB-like fashion
     * Columns are in order:
     * ATOM/HETATM AtomId Element AtomName AltLoc GroupId GroupType
     * InsCode ChainName x y z B-factor Occupancy Charge
     * @param delim what to split columns with
     */
    std::string print(std::string delim="\t");

    /**
     * @brief compare two StructureData classes
     * @param c what to compare to
     */
    bool operator==(StructureData const & c) const {
      return (
        mmtfVersion == c.mmtfVersion &&
        mmtfProducer == c.mmtfProducer &&
        unitCell == c.unitCell &&
        spaceGroup == c.spaceGroup &&
        structureId == c.structureId &&
        title == c.title &&
        depositionDate == c.depositionDate &&
        releaseDate == c.releaseDate &&
        ncsOperatorList == c.ncsOperatorList &&
        bioAssemblyList == c.bioAssemblyList &&
        entityList == c.entityList &&
        experimentalMethods == c.experimentalMethods &&
        resolution == c.resolution &&
        rFree == c.rFree &&
        rWork == c.rWork &&
        numBonds == c.numBonds &&
        numAtoms == c.numAtoms &&
        numGroups == c.numGroups &&
        numChains == c.numChains &&
        numModels == c.numModels &&
        groupList == c.groupList &&
        bondAtomList == c.bondAtomList &&
        bondOrderList == c.bondOrderList &&
        bondResonanceList == c.bondResonanceList &&
        xCoordList == c.xCoordList &&
        yCoordList == c.yCoordList &&
        zCoordList == c.zCoordList &&
        bFactorList == c.bFactorList &&
        atomIdList == c.atomIdList &&
        altLocList == c.altLocList &&
        occupancyList == c.occupancyList &&
        groupIdList == c.groupIdList &&
        groupTypeList == c.groupTypeList &&
        secStructList == c.secStructList &&
        insCodeList == c.insCodeList &&
        sequenceIndexList == c.sequenceIndexList &&
        chainIdList == c.chainIdList &&
        chainNameList == c.chainNameList &&
        groupsPerChain == c.groupsPerChain &&
        chainsPerModel == c.chainsPerModel);
    }
};


/**
 * @brief Get default value for given type.
 */
template <typename T>
inline T getDefaultValue();


/**
 * @return True if given value is default.
 * @tparam T Can be any numeric type, vector of string
 */
template <typename T>
inline bool isDefaultValue(const T& value);
template <typename T>
inline bool isDefaultValue(const std::vector<T>& value);
template <>
inline bool isDefaultValue(const std::string& value);
template <>
inline bool isDefaultValue(const std::map<std::string, msgpack::object>& value);
inline bool isDefaultValue(const msgpack::object& value);


/**
 * @brief Set default value to given type.
 * @tparam T Can be any numeric type (no need for vector or strings here)
 */
template <typename T>
inline void setDefaultValue(T& value);

/**
 * @brief Check if type is hetatm
 * @param type   cstring of group.chemCompType
 * @return True if is a HETATM 
 * Used when printing this struct, also all chemCompTypes are listed, but
 * the non-HETATM ones are commented out for reference
 * Relevant threads:
 * https://github.com/rcsb/mmtf/issues/28
 * http://mmcif.wwpdb.org/dictionaries/mmcif_pdbx_v50.dic/Items/_chem_comp.type.html
 */
inline bool is_hetatm(const char* type);

// *************************************************************************
// IMPLEMENTATION
// *************************************************************************

// helpers in anonymous namespace (only visible in this file)
/* namespace anon { */

// check optional date string
// -> either default or "YYYY-MM-DD" (only string format checked, not date)
bool isValidDateFormatOptional(const std::string& s) {
  // default?
  if (isDefaultValue(s)) return true;
  // check length
  if (s.length() != 10) return false;
  // check delimiters
  if (s[4] != '-' || s[7] != '-') return false;
  // check format
  std::istringstream is(s);
  int d, m, y;
  char dash1, dash2;
  if (is >> y >> dash1 >> m >> dash2 >> d) {
    return (dash1 == '-' && dash2 == '-');
  } else {
    return false;
  }
}

// check if optional vector has right size
template<typename T>
bool hasRightSizeOptional(const std::vector<T>& v, int exp_size) {
  return (isDefaultValue(v) || (int)v.size() == exp_size);
}

// check if all indices in vector are in [0, num-1] (T = integer type)
template<typename T, typename Tnum>
bool hasValidIndices(const T* v, size_t size, Tnum num) {
  T tnum = T(num);
  for (size_t i = 0; i < size; ++i) {
    if (v[i] < T(0) || v[i] >= tnum) return false;
  }
  return true;
}
template<typename T, typename Tnum>
bool hasValidIndices(const std::vector<T>& v, Tnum num) {
  if (v.empty()) return true;
  else           return hasValidIndices(&v[0], v.size(), num);
}

/* } // anon ns */

// VERSIONING

inline std::string getVersionString() {
  std::stringstream version;
  version << MMTF_SPEC_VERSION_MAJOR << "." << MMTF_SPEC_VERSION_MINOR;
  return version.str();
}

inline bool isVersionSupported(const std::string& version_string) {
  std::stringstream ss(version_string);
  int major = -1;
  return ((ss >> major) && (major <= MMTF_SPEC_VERSION_MAJOR));
}

// DEFAULT VALUES

template <typename T>
inline T getDefaultValue() { return std::numeric_limits<T>::max(); }

template <typename T>
inline bool isDefaultValue(const T& value) {
  return (value == getDefaultValue<T>());
}
template <typename T>
inline bool isDefaultValue(const std::vector<T>& value) {
  return value.empty();
}
template <>
inline bool isDefaultValue(const std::string& value) {
  return value.empty();
}
template <>
inline bool isDefaultValue(const std::map<std::string, msgpack::object>& value) {
  return value.empty();
}
inline bool isDefaultValue(const msgpack::object& value) {
  return value.is_nil();
}

template <typename T>
inline void setDefaultValue(T& value) {
  value = getDefaultValue<T>();
}

// HELPERS

/**
 * @brief Check if type is hetatm
 * @param type   cstring of group.chemCompType
 * @return True if is a HETATM 
 * Used when printing this struct, also all chemCompTypes are listed, but
 * the non-HETATM ones are commented out for reference
 * Relevant threads:
 * https://github.com/rcsb/mmtf/issues/28
 * http://mmcif.wwpdb.org/dictionaries/mmcif_pdbx_v50.dic/Items/_chem_comp.type.html
 */
bool is_hetatm(const char* type) {
  const char* hetatm_type[] = {
    "D-BETA-PEPTIDE, C-GAMMA LINKING",
    "D-GAMMA-PEPTIDE, C-DELTA LINKING",
    "D-PEPTIDE COOH CARBOXY TERMINUS",
    "D-PEPTIDE NH3 AMINO TERMINUS",
    "D-PEPTIDE LINKING",
    "D-SACCHARIDE",
    "D-SACCHARIDE 1,4 AND 1,4 LINKING",
    "D-SACCHARIDE 1,4 AND 1,6 LINKING",
    "DNA OH 3 PRIME TERMINUS",
    "DNA OH 5 PRIME TERMINUS",
    "DNA LINKING",
    "L-DNA LINKING",
    "L-RNA LINKING",
    "L-BETA-PEPTIDE, C-GAMMA LINKING",
    "L-GAMMA-PEPTIDE, C-DELTA LINKING",
    "L-PEPTIDE COOH CARBOXY TERMINUS",
    "L-PEPTIDE NH3 AMINO TERMINUS",
    //"L-PEPTIDE LINKING", // All canonical L AA
    "L-SACCHARIDE",
    "L-SACCHARIDE 1,4 AND 1,4 LINKING",
    "L-SACCHARIDE 1,4 AND 1,6 LINKING",
    "RNA OH 3 PRIME TERMINUS",
    "RNA OH 5 PRIME TERMINUS",
    "RNA LINKING",
    "NON-POLYMER",
    "OTHER",
    //"PEPTIDE LINKING", // GLY
    "PEPTIDE-LIKE",
    "SACCHARIDE",
    0 };
  for (int i=0; hetatm_type[i]; ++i) {
    if (strcmp(type,hetatm_type[i]) == 0) return true;
  }
  return false;
}

// CLASS StructureData

inline StructureData::StructureData() {
  // no need to do anything with strings and vectors
  setDefaultValue(resolution);
  setDefaultValue(rFree);
  setDefaultValue(rWork);
  // numXX set to 0 to have consistent data
  numBonds = 0;
  numAtoms = 0;
  numGroups = 0;
  numChains = 0;
  numModels = 0;
  // set version and producer
  mmtfVersion = getVersionString();
  mmtfProducer = "mmtf-cpp library (github.com/rcsb/mmtf-cpp)";
}

inline bool StructureData::hasConsistentData(bool verbose, uint32_t chain_name_max_length) const {
  std::vector<int8_t> allowed_bond_orders;
  allowed_bond_orders.push_back(-1);
  allowed_bond_orders.push_back(1);
  allowed_bond_orders.push_back(2);
  allowed_bond_orders.push_back(3);
  allowed_bond_orders.push_back(4);

  // check unitCell: if given, must be of length 6
  if (!hasRightSizeOptional(unitCell, 6)) {
    if (verbose) {
      std::cout << "inconsistent unitCell (unitCell length != 6)" << std::endl;
    }
    return false;
  }
  // check dates
  if (!isValidDateFormatOptional(depositionDate)) {
    if (verbose) {
      std::cout << "inconsistent depositionDate (does not match 'YYYY-MM-DD' "
          "or empty)" << std::endl;
    }
    return false;
  }
  if (!isValidDateFormatOptional(releaseDate)) {
    if (verbose) {
      std::cout << "inconsistent releaseDate (does not match 'YYYY-MM-DD' "
          "or empty)" << std::endl;
    }
    return false;
  }
  // check ncsOperatorList: all elements must have length 16
  for (size_t i = 0; i < ncsOperatorList.size(); ++i) {
    if ((int)ncsOperatorList[i].size() != 16) {
      if (verbose) {
        std::cout << "inconsistent ncsOperatorList idx: " << i << " found size: "
            << ncsOperatorList[i].size() << " != 16" << std::endl;
      }
      return false;
    }
  }
  // check chain indices in bioAssembly-transforms and entities
  for (size_t i = 0; i < bioAssemblyList.size(); ++i) {
    const BioAssembly& ba = bioAssemblyList[i];
    for (size_t j = 0; j < ba.transformList.size(); ++j) {
      const Transform & t = ba.transformList[j];
      if (!hasValidIndices(t.chainIndexList, numChains)) {
        if (verbose) {
          std::cout << "inconsistent BioAssemby transform i j: " << i
              << " " << j << std::endl;
        }
        return false;
      }
    }
  }
  for (size_t i = 0; i < entityList.size(); ++i) {
    const Entity& ent = entityList[i];
    if (!hasValidIndices(ent.chainIndexList, numChains)) {
      if (verbose) {
          std::cout << "inconsistent entity idx: " << i << std::endl;
      }
      return false;   
    }
  }
  // check groups
  for (size_t i = 0; i < groupList.size(); ++i) {
    const GroupType& g = groupList[i];
    const size_t num_atoms = g.formalChargeList.size();
    if (g.atomNameList.size() != num_atoms) {
      if (verbose) {
        std::cout << "inconsistent group::atomNameList size at idx: "
            << i << std::endl;
      }
      return false;
    }
    if (g.elementList.size() != num_atoms) {
      if (verbose) {
        std::cout << "inconsistent group::elementList size at idx: "
            << i << std::endl;
      }
      return false;
    }
    if (!isDefaultValue(g.bondOrderList)) {
      if (g.bondAtomList.size() != g.bondOrderList.size() * 2) {
        if (verbose) {
          std::cout << "inconsistent group::bondAtomList size: " <<
              g.bondAtomList.size() << " != group::bondOrderList size(*2): " <<
              g.bondOrderList.size()*2 << " at idx: " << i << std::endl;
        }
        return false;
      }
      for (size_t j = 0; j < g.bondOrderList.size(); ++j) {
        if (std::find(allowed_bond_orders.begin(), allowed_bond_orders.end(),
              g.bondOrderList[j]) == allowed_bond_orders.end()) {
          if (verbose) {
            std::cout << "Cannot have bond order of: " << g.bondOrderList[j]
                << " allowed bond orders are: -1, 1, 2, 3 or 4.  at idx: " << j << std::endl;
          }
          return false;
        }
      }
    }
    if (!isDefaultValue(g.bondResonanceList)) {
      if (isDefaultValue(g.bondOrderList) || isDefaultValue(g.bondAtomList)) {
        if (verbose) {
          std::cout << "Cannot have bondResonanceList without both " <<
              "bondOrderList and bondAtomList! at idx: " << i << std::endl;
        }
        return false;
      }
      if (g.bondOrderList.size() != g.bondResonanceList.size()) {
        if (verbose) {
          std::cout << "inconsistent group::bondOrderSize size: " <<
              g.bondOrderList.size() << " != group::bondResonanceList size(*2): " <<
              g.bondResonanceList.size()*2 << " at idx: " << i << std::endl;
        }
        return false;
      }
      if (g.bondAtomList.size() != g.bondResonanceList.size() * 2) {
        if (verbose) {
          std::cout << "inconsistent group::bondAtomList size: " <<
              g.bondAtomList.size() << " != group::bondResonanceList size(*2): " <<
              g.bondResonanceList.size()*2 << " at idx: " << i << std::endl;
        }
        return false;
      }
      // Check bond resonance matches
      for (size_t j = 0; j < g.bondResonanceList.size(); ++j) {
        if (g.bondResonanceList[j] < -1 || g.bondResonanceList[j] > 1) {
          if (verbose) {
            std::cout << "group::bondResonanceList had a Resonance of: "
              << g.bondResonanceList[j] << " and only -1, 0, or 1 are allowed"
              << std::endl;
          }
          return false;
        }
        if (g.bondOrderList[j] == -1 && g.bondResonanceList[j] != 1) {
          if (verbose) {
            std::cout << "group::bondResonanceList had a Resonance of: "
              << g.bondResonanceList[j] << " and group::bondOrderList had an order of "
              << g.bondOrderList[j] << " we require unknown bondOrders to have resonance"
              << std::endl;
          }
          return false;
        }
      }
    }
    if (!hasValidIndices(g.bondAtomList, num_atoms)) {
      if (verbose) {
        std::cout << "inconsistent group::bondAtomList indices (not all in [0, "
            << num_atoms - 1 << "]) at idx: " << i << std::endl;
      }
      return false;
    }
  }
  // check global bonds
  if (!isDefaultValue(bondOrderList)) {
    if (bondAtomList.size() != bondOrderList.size() * 2) {
      if (verbose) {
          std::cout << "inconsistent bondAtomList size: " <<
              bondAtomList.size() << " != bondOrderList size(*2): " <<
              bondOrderList.size()*2 << std::endl;
      }
      return false;
    }
    for (size_t i = 0; i < bondOrderList.size(); ++i) {
      if (std::find(allowed_bond_orders.begin(), allowed_bond_orders.end(),
            bondOrderList[i]) == allowed_bond_orders.end()) {
        if (verbose) {
          std::cout << "Cannot have bond order of: " << bondOrderList[i]
              << " allowed bond orders are: -1, 1, 2, 3 or 4.  at idx: " << i << std::endl;
        }
        return false;
      }
    }
  }
  if (!isDefaultValue(bondResonanceList)) {
    if (bondAtomList.size() != bondResonanceList.size() * 2) {
      if (verbose) {
          std::cout << "inconsistent bondAtomList size: " <<
              bondAtomList.size() << " != bondResonanceList size(*2): " <<
              bondResonanceList.size()*2 << std::endl;
      }
      return false;
    }
    for (size_t i = 0; i < bondResonanceList.size(); ++i) {
      if (bondResonanceList[i] < -1 || bondResonanceList[i] > 1) {
        if (verbose) {
          std::cout << "group::bondResonanceList had a Resonance of: "
            << bondResonanceList[i] << " and only -1, 0, or 1 are allowed"
            << std::endl;
        }
        return false;
      }
      if (bondOrderList[i] == -1 && bondResonanceList[i] != 1) {
        if (verbose) {
          std::cout << "group::bondResonanceList had a Resonance of: "
            << bondResonanceList[i] << " and group::bondOrderList had an order of "
            << bondOrderList[i] << " we require unknown bondOrders to have resonance"
            << std::endl;
        }
        return false;
      }
    }
  }
  if (!hasValidIndices(bondAtomList, numAtoms)) {
    if (verbose) {
      std::cout << "inconsistent bondAtomList indices (not all in [0, "
          << numAtoms - 1 << "])" << std::endl;
    }
    return false;
  }
  // check vector sizes
  if ((int)xCoordList.size() != numAtoms) {
    if (verbose) {
      std::cout << "inconsistent xCoordList size" << std::endl;
    }
    return false;
  }
  if ((int)yCoordList.size() != numAtoms) {
    if (verbose) {
      std::cout << "inconsistent yCoordList size" << std::endl;
    }
    return false;
  }
  if ((int)zCoordList.size() != numAtoms) {
    if (verbose) {
      std::cout << "inconsistent zCoordList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(bFactorList, numAtoms)) {
    if (verbose) {
      std::cout << "inconsistent bFactorList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(atomIdList, numAtoms)) {
    if (verbose) {
      std::cout << "inconsistent atomIdList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(altLocList, numAtoms)) {
    if (verbose) {
      std::cout << "inconsistent altLocList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(occupancyList, numAtoms)) {
    if (verbose) {
      std::cout << "inconsistent occupancyList size" << std::endl;
    }
    return false;
  }
  if ((int)groupIdList.size() != numGroups) {
    if (verbose) {
      std::cout << "inconsistent groupIdList size" << std::endl;
    }
    return false;
  }
  if ((int)groupTypeList.size() != numGroups) {
    if (verbose) {
      std::cout << "inconsistent groupTypeList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(secStructList, numGroups)) {
    if (verbose) {
      std::cout << "inconsistent secStructList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(insCodeList, numGroups)) {
    if (verbose) {
      std::cout << "inconsistent insCodeList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(sequenceIndexList, numGroups)) {
    if (verbose) {
      std::cout << "inconsistent sequenceIndexList size" << std::endl;
    }
    return false;
  }
  if ((int)chainIdList.size() != numChains) {
    if (verbose) {
      std::cout << "inconsistent chainIdList size" << std::endl;
    }
    return false;
  }
  if (!hasRightSizeOptional(chainNameList, numChains)) {
    if (verbose) {
      std::cout << "inconsistent chainNameList size" << std::endl;
    }
    return false;
  }
  if ((int)groupsPerChain.size() != numChains) {
    if (verbose) {
      std::cout << "inconsistent groupsPerChain size" << std::endl;
    }
    return false;
  }
  if ((int)chainsPerModel.size() != numModels) {
    if (verbose) {
      std::cout << "inconsistent chainsPerModel size" << std::endl;
    }
    return false;
  }
  // check indices
  if (!hasValidIndices(groupTypeList, groupList.size())) {
    if (verbose) {
      std::cout << "inconsistent groupTypeList indices (not all in [0, "
          << groupList.size() - 1 << "])" << std::endl;
    }
    return false;
  }
  // collect sequence lengths from entities and use to check
  std::vector<int32_t> sequenceIndexSize(numChains);
  for (size_t i = 0; i < entityList.size(); ++i) {
      const Entity& ent = entityList[i];
      for (size_t j = 0; j < ent.chainIndexList.size(); ++j) {
          sequenceIndexSize[ent.chainIndexList[j]] = ent.sequence.length();
      }
  }
  // traverse structure for more checks
  int bond_count_from_atom = 0;
  int bond_count_from_order = 0;
  int bond_count_from_resonance = 0;
  bool all_bond_orderLists_are_default = true;
  bool all_bond_resonanceLists_are_default = true;
  bool all_bond_atomLists_are_default = true;
  if (!isDefaultValue(bondOrderList)) {
    all_bond_orderLists_are_default = false;
    bond_count_from_order = bondOrderList.size();
  }
  if (!isDefaultValue(bondResonanceList)) {
    all_bond_resonanceLists_are_default = false;
    bond_count_from_resonance = bondOrderList.size();
  }
  if (!isDefaultValue(bondAtomList)) {
    all_bond_atomLists_are_default = false;
    bond_count_from_atom = bondAtomList.size()/2;
  }
  int chain_idx = 0; // will be count at end of loop
  int group_idx = 0; // will be count at end of loop
  int atom_idx = 0;  // will be count at end of loop
  // traverse models
  for (int model_idx = 0; model_idx < numModels; ++model_idx) {
    // traverse chains
    for (int j = 0; j < chainsPerModel[model_idx]; ++j, ++chain_idx) {
      // check chain names (fixed length)
      if (chainIdList[chain_idx].size() > chain_name_max_length) {
        if (verbose) {
          std::cout << "inconsistent chainIdList size at chain_idx: "
            << chain_idx << " size: "
            << chainIdList[chain_idx].size() << std::endl;
        }
        return false;
      }
      if (   !isDefaultValue(chainNameList)
        && chainNameList[chain_idx].size() > chain_name_max_length) {
        if (verbose) {
          std::cout << "inconsistent chainNameList size at chain_idx:"
            << chain_idx << " size: "
            << chainNameList[chain_idx].size() << std::endl;
        }
        return false;
      }
      // traverse groups
      for (int k = 0; k < groupsPerChain[chain_idx]; ++k, ++group_idx) {
        // check seq. idx
        if (!isDefaultValue(sequenceIndexList)) {
          const int32_t idx = sequenceIndexList[group_idx];
          // -1 is ok here
          if (idx < -1 || idx >= sequenceIndexSize[chain_idx]) {
            if (verbose) {
              std::cout << "inconsistent sequenceIndexSize at"
                " chain_idx: " << chain_idx << std::endl;
            }
            return false;
          }
        }
        // count atoms
        const GroupType& group = groupList[groupTypeList[group_idx]];
        atom_idx += group.atomNameList.size();
        // count bonds
        if (!isDefaultValue(group.bondOrderList)) {
          all_bond_orderLists_are_default = false;
          bond_count_from_order += group.bondOrderList.size();
        }
        if (!isDefaultValue(group.bondResonanceList)) {
          all_bond_resonanceLists_are_default = false;
          bond_count_from_resonance += group.bondResonanceList.size();
        }
        if (!isDefaultValue(group.bondAtomList)) {
          all_bond_atomLists_are_default = false;
          bond_count_from_atom += group.bondAtomList.size()/2;
        }

      }
    }
  }
  // check sizes
  if (!all_bond_orderLists_are_default) {
    if (bond_count_from_order != numBonds) {
      if (verbose) {
        std::cout << "inconsistent numBonds vs bond order count" << std::endl;
      }
      return false;
    }
  }
  if (!all_bond_resonanceLists_are_default) {
    if (bond_count_from_resonance != numBonds) {
      if (verbose) {
        std::cout << "inconsistent numBonds vs bond resonance count" << std::endl;
      }
      return false;
    }
  }
  if (!all_bond_atomLists_are_default) {
    if (bond_count_from_atom != numBonds) {
      if (verbose) {
        std::cout << "inconsistent numBonds vs bond atom list count" << std::endl;
      }
      return false;
    }
  }
  if (chain_idx != numChains) {
    if (verbose) {
      std::cout << "inconsistent numChains" << std::endl;
    }
    return false;
  }
  if (group_idx != numGroups) {
    if (verbose) {
      std::cout << "inconsistent numGroups size" << std::endl;
    }
    return false;
  }
  if (atom_idx != numAtoms) {
    if (verbose) {
      std::cout << "inconsistent numAtoms size" << std::endl;
    }
    return false;
  }
  // All looks good :)
  return true;
}

inline std::string StructureData::print(std::string delim) {
  std::ostringstream out;
  int modelIndex = 0;
  int chainIndex = 0;
  int groupIndex = 0;
  int atomIndex = 0;

  // traverse models
  for (int i = 0; i < numModels; i++, modelIndex++) {
    // traverse chains
    for (int j = 0; j < chainsPerModel[modelIndex]; j++, chainIndex++) {
      // traverse groups
      for (int k = 0; k < groupsPerChain[chainIndex]; k++, groupIndex++) {
        const mmtf::GroupType& group =
            groupList[groupTypeList[groupIndex]];
        int groupAtomCount = group.atomNameList.size();

        for (int l = 0; l < groupAtomCount; l++, atomIndex++) {
          // ATOM or HETATM
          if (is_hetatm(group.chemCompType.c_str()))
            out << "HETATM" << delim;
          else
            out << "ATOM" << delim;
          // Atom serial
          if ( !mmtf::isDefaultValue(atomIdList) ) {
            out << std::setfill('0') << std::internal << std::setw(6) <<
             std::right << atomIdList[atomIndex] << delim;
          } else out << "." << delim;
          // Atom name
          out << group.atomNameList[l] << delim;
          // Alternate location
          if ( !mmtf::isDefaultValue(altLocList) ) {
            if ( altLocList[atomIndex] == ' ' ||
              altLocList[atomIndex] == 0x00 )
                 out << "." << delim;
            else out << altLocList[atomIndex] << delim;
          } else out << "." << delim;
          // Group name
          out << group.groupName << delim;
          // Chain
          out << chainIdList[chainIndex] << delim;
          if ( !mmtf::isDefaultValue(chainNameList) ) {
            out << chainNameList[chainIndex];
            out << delim;
          } else out << "." << delim;
          // Group serial
          out << groupIdList[groupIndex] << delim;
          // Insertion code
          if ( !mmtf::isDefaultValue(insCodeList) ) {
            if ( insCodeList[groupIndex] == ' ' ||
              insCodeList[groupIndex] == 0x00 )
                 out << "." << delim;
            else out << int(insCodeList[groupIndex]) << delim;
          } else out << ". ";
          // x, y, z
          out << std::fixed << std::setprecision(3);
          out << xCoordList[atomIndex] << delim;
          out << yCoordList[atomIndex] << delim;
          out << zCoordList[atomIndex] << delim;

          // B-factor
          if ( !mmtf::isDefaultValue(bFactorList) ) {
            out << bFactorList[atomIndex] << delim;
          } else out << "." << delim;
          // Occupancy
          if ( !mmtf::isDefaultValue(occupancyList) ) {
            out << occupancyList[atomIndex] << delim;
          } else out << "." << delim;
          // Element
          out << group.elementList[l] << delim;
          // Charge
          out << group.formalChargeList[l] << "\n";
        }
      }
    }
  }
  return out.str();
}

} // mmtf namespace

#endif

