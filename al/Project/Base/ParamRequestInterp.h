#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/HioNode.h"

namespace al {
class ParameterObj;
class SkyParam;

class IUseRequestParam : public HioNode {
public:
    virtual const char* getParamName() const = 0;
    virtual ParameterObj* getParamObj() = 0;
    virtual const ParameterObj* getParamObj() const = 0;
    virtual bool isEqual(const IUseRequestParam& requestParam) const;
    virtual void copy(const IUseRequestParam& requestParam);
    virtual void copyInterp(const IUseRequestParam& requestParamStart,
                            const IUseRequestParam& requestParamEnd, f32 rate);
};

static_assert(sizeof(IUseRequestParam) == 0x8);

class ParamRequestInterp {
public:
    ParamRequestInterp();

public:
    s32 mRequestIndex;
    s32 mCurrentIndex;
    s32 mInterpMode;
    u32 mInterpFrames;
    SkyParam* mSkyParam1;
    SkyParam* mSkyParam2;
    SkyParam* mSkyParam3;
    s32 mPreviousIndex;
    SkyParam* mSkyParam4;
};

static_assert(sizeof(ParamRequestInterp) == 0x38);

}  // namespace al
