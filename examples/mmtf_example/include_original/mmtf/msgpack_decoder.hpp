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

#ifndef MMTF_MSGPACK_DECODER_H
#define MMTF_MSGPACK_DECODER_H

#include "structure_data.hpp"
#include "map_decoder.hpp"
#include "errors.hpp"

#include <msgpack.hpp>

// here we specialize msgpack-c functionality so we can use obj.convert(..)

namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS) {
namespace adaptor {

// custom specialization for chars stored as strings
template <>
struct convert<char> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      char& c) const {
        // extract string
        std::string temp;
        obj.convert(temp);
        // ensure length
        if (temp.size() != 1) {
            throw mmtf::DecodeError("Observed single letter string not being "
                                    "of length one!");
        }
        c = temp[0];
        return obj;
    }
};

template <>
struct convert<mmtf::GroupType> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      mmtf::GroupType& group) const {

        mmtf::MapDecoder md(obj);
        md.decode("formalChargeList", true, group.formalChargeList);
        md.decode("atomNameList", true, group.atomNameList);
        md.decode("elementList", true, group.elementList);
        md.decode("bondAtomList", false, group.bondAtomList);
        md.decode("bondOrderList", false, group.bondOrderList);
        md.decode("bondResonanceList", false, group.bondResonanceList);
        md.decode("groupName", true, group.groupName);
        md.decode("singleLetterCode", true, group.singleLetterCode);
        md.decode("chemCompType", true, group.chemCompType);
        md.checkExtraKeys();
        return obj;
    }
};

template <>
struct convert<mmtf::Entity> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      mmtf::Entity& entity) const {

        mmtf::MapDecoder md(obj);
        md.decode("chainIndexList", true, entity.chainIndexList);
        md.decode("description", true, entity.description);
        md.decode("type", true, entity.type);
        md.decode("sequence", true, entity.sequence);
        md.checkExtraKeys();
        return obj;
    }
};

template <>
struct convert<mmtf::Transform> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      mmtf::Transform& transform) const {

        mmtf::MapDecoder md(obj);
        md.decode("chainIndexList", true, transform.chainIndexList);
        md.decode("matrix", true, transform.matrix);
        md.checkExtraKeys();
        return obj;
    }
};

template <>
struct convert<mmtf::BioAssembly> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      mmtf::BioAssembly& assembly) const {

        mmtf::MapDecoder md(obj);
        md.decode("transformList", true, assembly.transformList);
        md.decode("name", true, assembly.name);
        md.checkExtraKeys();
        return obj;
    }
};

template <>
struct convert<mmtf::StructureData> {
    const msgpack::object& operator()(const msgpack::object& obj, 
                                      mmtf::StructureData& data) const {

        mmtf::MapDecoder md(obj);
        md.decode("mmtfVersion", true, data.mmtfVersion);

        // check if version is compatible before continuing
        if (!mmtf::isVersionSupported(data.mmtfVersion)) {
            throw mmtf::DecodeError("Unsupported MMTF version "
                                    + data.mmtfVersion);
        }

        md.decode("mmtfProducer", true, data.mmtfProducer);
        md.decode("unitCell", false, data.unitCell);
        md.decode("spaceGroup", false, data.spaceGroup);
        md.decode("structureId", false, data.structureId);
        md.decode("title", false, data.title);
        md.decode("depositionDate", false, data.depositionDate);
        md.decode("releaseDate", false, data.releaseDate);
        md.decode("ncsOperatorList", false, data.ncsOperatorList);
        md.decode("bioAssemblyList", false, data.bioAssemblyList);
        md.decode("entityList", false, data.entityList);
        md.decode("experimentalMethods", false, data.experimentalMethods);
        md.decode("resolution", false, data.resolution);
        md.decode("rFree", false, data.rFree);
        md.decode("rWork", false, data.rWork);
        md.decode("numBonds", true, data.numBonds);
        md.decode("numAtoms", true, data.numAtoms);
        md.decode("numGroups", true, data.numGroups);
        md.decode("numChains", true, data.numChains);
        md.decode("numModels", true, data.numModels);
        md.decode("groupList", true, data.groupList);
        md.decode("bondAtomList", false, data.bondAtomList);
        md.decode("bondOrderList", false, data.bondOrderList);
        md.decode("bondResonanceList", false, data.bondResonanceList);
        md.decode("xCoordList", true, data.xCoordList);
        md.decode("yCoordList", true, data.yCoordList);
        md.decode("zCoordList", true, data.zCoordList);
        md.decode("bFactorList", false, data.bFactorList);
        md.decode("atomIdList", false, data.atomIdList);
        md.decode("altLocList", false, data.altLocList);
        md.decode("occupancyList", false, data.occupancyList);
        md.decode("groupIdList", true, data.groupIdList);
        md.decode("groupTypeList", true, data.groupTypeList);
        md.decode("secStructList", false, data.secStructList);
        md.decode("insCodeList", false, data.insCodeList);
        md.decode("sequenceIndexList", false, data.sequenceIndexList);
        md.decode("chainIdList", true, data.chainIdList);
        md.decode("chainNameList", false, data.chainNameList);
        md.decode("groupsPerChain", true, data.groupsPerChain);
        md.decode("chainsPerModel", true, data.chainsPerModel);
        // extraProperties (application specific stuff)
        // decoding only creates a shallow copy, make sure you pack everything
        // onto the StructureData's Zone
        md.decode("bondProperties", false, data.bondProperties);
        md.decode("atomProperties", false, data.atomProperties);
        md.decode("groupProperties", false, data.groupProperties);
        md.decode("chainProperties", false, data.chainProperties);
        md.decode("modelProperties", false, data.modelProperties);
        md.decode("extraProperties", false, data.extraProperties);
        md.checkExtraKeys();
        return obj;
    }
};

}}} // msgpack::VERSION::adaptor namespace

#endif
