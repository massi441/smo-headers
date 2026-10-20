#pragma once

#include <basis/seadTypes.h>

#include "Project/Base/ParamRequestInterp.h"

namespace al {
class GraphicsSystemInfo;
class ParameterF32;
class ParameterObj;
class ParameterS32;
class ParameterString64;
class ParameterV3f;
class Resource;

class HdrParam : public IUseRequestParam {
public:
    HdrParam();

    const char* getParamName() const override;
    ParameterObj* getParamObj() override;
    const ParameterObj* getParamObj() const override;
    bool isEqual(const IUseRequestParam& other) const override;
    void copy(const IUseRequestParam& other) override;
    void copyInterp(const IUseRequestParam& start, const IUseRequestParam& end,
                    f32 rate) override;

    ParameterF32* getExposure() const { return mExposure; }

    ParameterF32* getAutoExposureRangeMin() const { return mAutoExposureRangeMin; }

    ParameterF32* getAutoExposureRangeMax() const { return mAutoExposureRangeMax; }

private:
    ParameterObj* mParameterObj;
    ParameterS32* mToneMapType;
    ParameterF32* mExposure;
    ParameterV3f* mToneMapPowerBase;
    ParameterString64* mCameraEffectName;
    s32 mCameraEffectIndex;
    ParameterF32* mAutoExposureMid;
    ParameterF32* mAutoExposureRangeMax;
    ParameterF32* mAutoExposureRangeMin;
    ParameterF32* mAutoExposureIgnoreRangeMax;
    ParameterF32* mAutoExposureBlendRateUp;
    ParameterF32* mAutoExposureBlendRateDown;
    ParameterF32* mAutoExposureHistogramScale;
    ParameterF32* mAutoExposureIgnoreRangeMin;
    ParameterF32* mToonShadeRate;
    ParameterV3f* mToonStep;
    ParameterV3f* mToonWidth;
    ParameterF32* mShoulderStrength;
    ParameterF32* mLinearStrength;
    ParameterF32* mLinearAngle;
    ParameterF32* mToeStrength;
    ParameterF32* mToeNumerator;
    ParameterF32* mToeDenominator;
    ParameterF32* mBlackPoint;
    ParameterF32* mCrossOver;
    ParameterF32* mWhitePoint;
    ParameterF32* mToe;
    ParameterF32* mShoulder;
    void* _e8;
};

static_assert(sizeof(HdrParam) == 0xf0);

class HdrCompose {
public:
    HdrCompose(s32 viewNum, GraphicsSystemInfo* graphicsSystemInfo);
    virtual ~HdrCompose();

    void initProjectResource(const Resource* resource, const char* name);
    void initHdrParam(HdrParam* param);
    void endInit();
    void clearRequest();
    void requestParam(s32 priority, s32 frames, const HdrParam& param);
    void update();
    void preDrawGraphics();
    void calcGPU(s32 viewIndex);
    HdrParam* getCurrentParam();
    const HdrParam* getCurrentParam() const;
    f32 getExposure() const;
    f32 getExposureExp() const;
    bool isUsingAutoExposure() const;
};

}  // namespace al
