#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>
#include <utility/aglParameter.h>

namespace agl::utl {
class IParameterIO;
class IParameterObj;
}  // namespace agl::utl

namespace al {
class BloomParam;
class DepthOfFieldParam;
class DepthShadowClipParam;
class DepthShadowParam;
class DirLightParam;
class FlareFilterParam;
class FogParam;
class GodRayParam;
class GraphicsAreaDirector;
class HdrParam;
class LightStreakParam;
class MaterialCategoryKeeper;
class MaterialCategoryParam;
class MirrorParam;
class ParameterIo;
class ParameterObj;
class ParameterString64;
class ProgramTextureParam;
class Resource;
class SkyParam;
class VignettingParam;
class YFogParam;

class GraphicsPreset {
public:
    GraphicsPreset(const char* name, const Resource* resource);

    void endInit(MaterialCategoryKeeper* materialCategoryKeeper,
                 const GraphicsAreaDirector* graphicsAreaDirector);
    const char* getName() const;

    DirLightParam* getDirLightParam() const { return mDirLightParam; }

    HdrParam* getHdrParam() const { return mHdrParam; }

    FogParam* getFogParam() const { return mFogParam; }

    YFogParam* getYFogParam() const { return mYFogParam; }

    SkyParam* getSkyParam() const { return mSkyParam; }

private:
    bool mIsRegistered;
    ParameterObj* mParameterObj;
    ParameterString64* mName;
    ParameterIo* mParameterIo;
    agl::utl::IParameterObj* mAglParameterObj;
    agl::utl::Parameter<sead::FixedSafeString<64>> mAglName;
    agl::utl::IParameterIO* mAglParameterIo;
    DirLightParam* mDirLightParam;
    HdrParam* mHdrParam;
    MaterialCategoryParam* mMaterialCategoryParam;
    FogParam* mFogParam;
    YFogParam* mYFogParam;
    BloomParam* mBloomParam;
    SkyParam* mSkyParam;
    DepthOfFieldParam* mDepthOfFieldParam;
    DepthShadowParam* mDepthShadowParam;
    DepthShadowClipParam* mDepthShadowClipParam;
    LightStreakParam* mLightStreakParam;
    FlareFilterParam* mFlareFilterParam;
    GodRayParam* mGodRayParam;
    MirrorParam* mMirrorParam;
    VignettingParam* mVignettingParam;
    ProgramTextureParam* mProgramTextureParam;
    const void* mColorCorrection;
    const void* mShaderParam;
    const void* mSsao;
};

static_assert(sizeof(GraphicsPreset) == 0x138);

}  // namespace al
