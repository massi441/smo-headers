#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class ShaderHolder;
class DepthShadowMapDirector;
class DirLightParam;

class DirectionalLightKeeper {
public:
    DirectionalLightKeeper(ShaderHolder*, DepthShadowMapDirector*);
    ~DirectionalLightKeeper();

    void endInit();
    void clearRequest();
    void update();
    DirLightParam* getCurrentParam();
    bool requestParam(s32 priority, s32 frames, const DirLightParam& param);
    void calcLightDirFrom();
    sead::Vector3f* getTextureFetchPos();
};

}  // namespace al
