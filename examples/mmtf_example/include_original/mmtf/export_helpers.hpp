// *************************************************************************
//
// Licensed under the MIT License (see accompanying LICENSE file).
//
// The authors of this code are: Thomas Holder
//
// *************************************************************************
//
// Helper functions and classes for exporting MMTF data.
// See "examples/tableexport.cpp" for example usage.
//
// *************************************************************************

#ifndef MMTF_EXPORT_HELPERS_H
#define MMTF_EXPORT_HELPERS_H

#include "errors.hpp"
#include "structure_data.hpp"

#include <vector>

namespace mmtf
{

/**
 * @brief Helper class for adding bonds to a group-redundant system
 *
 * @pre Atoms already exist in the system
 *
 * @pre groupTypeList has no duplicates (otherwise adding an inter-residue
 * bond will add it to all residues with the same group type)
 */
class BondAdder {
  StructureData* m_data;
  std::vector<int32_t> m_atom2groupType;
  std::vector<int32_t> m_atomOffsets;

public:
  /**
   * @param[in,out] data Consistent system with atoms
   *
   * @throw mmtf::EncodeError if groupTypeList has duplicates
   */
  BondAdder(StructureData& data)
      : m_data(&data), m_atomOffsets(data.groupTypeList.size(), -1)
  {
    m_atom2groupType.reserve(data.numAtoms);

    for (size_t i = 0; i < data.groupTypeList.size(); ++i) {
      int32_t groupType = data.groupTypeList[i];

      // sanity check
      if (m_atomOffsets[groupType] != -1) {
        throw EncodeError("groupTypeList has duplicates");
      }

      size_t atomOffset = m_atom2groupType.size();
      size_t groupSize = data.groupList[groupType].atomNameList.size();

      m_atomOffsets[groupType] = atomOffset;
      m_atom2groupType.resize(atomOffset + groupSize, groupType);
    }
  }

  /**
   * @brief Add one bond
   *
   * @param[in] atom1 Atom index 1 (zero-based)
   * @param[in] atom2 Atom index 2 (zero-based)
   * @param[in] order Bond order
   *
   * @return False if atom indices out of bounds
   */
  bool operator()(int32_t atom1, int32_t atom2, int8_t order)
  {
    if (atom1 >= m_atom2groupType.size() ||
        atom2 >= m_atom2groupType.size())
      return false;

    if (m_atom2groupType[atom1] == m_atom2groupType[atom2]) {
      int32_t groupType = m_atom2groupType[atom1];
      GroupType& group = m_data->groupList[groupType];
      group.bondAtomList.push_back(atom1 - m_atomOffsets[groupType]);
      group.bondAtomList.push_back(atom2 - m_atomOffsets[groupType]);
      group.bondOrderList.push_back(order);
    } else {
      m_data->bondAtomList.push_back(atom1);
      m_data->bondAtomList.push_back(atom2);
      m_data->bondOrderList.push_back(order);
    }

    ++m_data->numBonds;
    return true;
  }
};

/**
 * @brief Eliminate redundant groups from groupList
 *
 * Modifies groupList and groupTypeList
 *
 * @param[in,out] data Consistent system
 */
inline void compressGroupList(StructureData& data)
{
  size_t n_old = data.groupList.size();
  size_t i_free = 0;
  std::vector<size_t> idremap(n_old, 0);

  for (size_t i = 1; i < n_old; ++i) {
    size_t i_found = 0;

    while (i_found < i && !(data.groupList[i] == data.groupList[i_found])) {
      ++i_found;
    }

    if (i_found == i) {
      if (i_free != 0) {
        data.groupList[i_free] = data.groupList[i]; // std::move possible with C++11
        i_found = i_free;
        ++i_free;
      }
    } else if (i_free == 0) {
      i_free = i;
    }

    idremap[i] = i_found;
  }

  if (i_free != 0) {
    data.groupList.resize(i_free);

    for (size_t i = 0; i < data.groupTypeList.size(); ++i) {
      data.groupTypeList[i] = idremap[data.groupTypeList[i]];
    }
  }
}

} // namespace mmtf

#endif

// vi:sw=2:expandtab
