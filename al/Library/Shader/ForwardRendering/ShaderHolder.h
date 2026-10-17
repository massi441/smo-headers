#pragma once

#include <heap/seadDisposer.h>
#include <common/aglShaderProgram.h>

#include "Library/HostIO/HioNode.h"

namespace nn::g3d {
    class ResShadingModel;
}
namespace al {
    class ShaderHolder : public HioNode {
        SEAD_SINGLETON_DISPOSER(ShaderHolder)
    public:
        void init();

        static void initAndLoadAllFromDisk(const char*, sead::Heap*, sead::Heap);

        agl::ShaderProgram* getShaderProgram(const char* programName) const;
        agl::ShaderProgram* tryGetShaderProgram(const char* programName) const;
        nn::g3d::ResShadingModel* getShadingModel(const char* modelName, const char* suffix) const;
    };
}
