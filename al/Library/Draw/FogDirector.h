#pragma once

#include <basis/seadTypes.h>

#include "Project/Base/ParamRequestInterp.h"

namespace al {
class ParameterBool;
class ParameterC4f;
class ParameterF32;
class ParameterObj;
class ParameterV3f;
class YFogParam;

class FogParam : public IUseRequestParam {
public:
    FogParam();

    const char* getParamName() const override;
    ParameterObj* getParamObj() override;
    const ParameterObj* getParamObj() const override;
    bool isEqual(const IUseRequestParam& other) const override;
    void copy(const IUseRequestParam& other) override;
    void copyInterp(const IUseRequestParam& start, const IUseRequestParam& end,
                    f32 rate) override;

    ParameterC4f* getColor() const { return mColor; }

    ParameterF32* getMax() const { return mMax; }

private:
    ParameterObj* mParameterObj;
    ParameterBool* mIsEnable;
    ParameterBool* mIsApplySky;
    ParameterBool* mIsApplySkyDefault;
    ParameterBool* mIsBlendMult;
    ParameterBool* mIsDeferredFog;
    ParameterBool* mIsInWater;
    ParameterBool* mIsUseDepthTgt;
    ParameterC4f* mColor;
    ParameterF32* mStart;
    ParameterF32* mSlope;
    ParameterF32* mMax;
    ParameterF32* mSkyMip;
    ParameterF32* mNoiseIntensity;
    ParameterF32* mNoiseDistCoef;
    ParameterF32* mNoiseTexCrdScale;
    ParameterV3f* mNoiseTexCrdVelocity;
};

static_assert(sizeof(FogParam) == 0x90);

class FogDirector {
public:
    void requestFogParam(s32 priority, s32 frames, const FogParam& param);
    void requestYFogParam(s32 priority, s32 frames, const YFogParam& param);
};

}  // namespace al
