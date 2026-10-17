#pragma once

#include <basis/seadTypes.h>
#include <gfx/seadColor.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace agl {
class TextureSampler;
}

namespace al {
class GraphicsSystemInfo;
class PrePassLightBase;
class ShaderHolder;
class ShadowDirector;

class PrePassLightKeeper {
public:
    PrePassLightKeeper(GraphicsSystemInfo*, s32);
    ~PrePassLightKeeper();

    void initShader(ShaderHolder*);
    void endInit();
    void clear();
    void execute(ShadowDirector*);
    void preDrawGraphics();
    void updateViewGPU(s32, ShadowDirector*);

    void pushBackLight(PrePassLightBase*);
    void eraseLight(PrePassLightBase*);

    bool isForceReducedBufferRequest();

    void requestPointLight(const sead::Vector3f& pos, f32 radius, const sead::Color4f& color,
                           f32 intensity, bool castShadow);

    void requestSpotLight(const sead::Vector3f& pos, const sead::Vector3f& dir, f32 innerAngle,
                          f32 outerAngle, const sead::Color4f& color, f32 intensity, f32 range,
                          bool castShadow);

    void requestLineLight(const sead::Vector3f& posA, const sead::Vector3f& posB, f32 radius,
                          const sead::Color4f& color, f32 intensity, bool castShadow);

    void requestProjLight(const sead::Vector3f& pos, const sead::Vector3f& dir,
                          const sead::Vector3f& up, const sead::Color4f& color, f32 intensity,
                          f32 range, f32 fovX, f32 fovY, f32 near, bool castShadow,
                          agl::TextureSampler* texSampler, bool useTexture,
                          const sead::Vector2f& texOffset, const sead::Vector2f& texScale);

    void requestProjLightOrtho(const sead::Vector3f& pos, const sead::Vector3f& dir,
                               const sead::Vector3f& up, const sead::Color4f& color, f32 intensity,
                               f32 range, f32 sizeX, f32 sizeY, f32 sizeZ, f32 near, f32 far,
                               bool castShadow, agl::TextureSampler* texSampler, bool useTexture,
                               const sead::Vector2f& texOffset, const sead::Vector2f& texScale);

    void requestCausticsLight(const sead::Vector3f& pos, const sead::Vector3f& dir,
                              const sead::Quatf& rot, const sead::Color4f& color,
                              const sead::Vector3f& scale, f32 intensity, f32 range, f32 near,
                              bool castShadow);
};

}  // namespace al
