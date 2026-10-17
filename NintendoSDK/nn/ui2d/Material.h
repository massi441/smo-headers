/**
 * @file Material.h
 * @brief UI Material implementation.
 */
#pragma once
#include <nn/types.h>

namespace nn {
namespace gfx {
template<typename T> class TDevice;
class ApiVariation;
}
namespace util {
namespace neon {
struct MatrixColumnMajor4x3fType;
}
}
}

namespace nn::ui2d {

class AnimTransform;
class BuildResultInformation;
class BuildArgSet;
class BuildResSet;
class DrawInfo;
class ResMaterial;
class ResTexSrt;
class TexMap;
class ResVec2;
class Size;
struct UserShaderInformation;
enum ShaderVariation;

class Material {
public:
    Material();
    Material(const Material&, nn::gfx::TDevice<nn::gfx::ApiVariation>*);
    Material(BuildResultInformation*, nn::gfx::TDevice<nn::gfx::ApiVariation>*, const ResMaterial*, const ResMaterial*, const BuildArgSet&);
    
    virtual ~Material();
    
    virtual void BindAnimation(AnimTransform*);
    virtual void UnbindAnimation(AnimTransform*);
    
    void Initialize();
    void Finalize(nn::gfx::TDevice<nn::gfx::ApiVariation>*);
    void ReserveMem(s32, s32, s32, s32, bool, s32, bool, s32, bool, bool);
    static s32 CalculateReserveMemSize(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    void SetupShader(nn::gfx::TDevice<nn::gfx::ApiVariation>*, const BuildArgSet&, const BuildResSet*);
    void SetupGraphics(DrawInfo&, u8, ShaderVariation, bool, const nn::util::neon::MatrixColumnMajor4x3fType&, const Size*);
    void SetupBlendState(const DrawInfo*);
    void SetupSubmaterialOf_TextureMatrix(DrawInfo&, const nn::util::neon::MatrixColumnMajor4x3fType&, const Size*);
    void SetColorElement(int, int);
    void CalculateTextureMtx(float (*)[3], const ResTexSrt&, const TexMap&);
    void CalculateIndirectMtx(float (*)[3], float, const ResVec2&);
    void AllocateConstantBuffer(DrawInfo&);
    void InitializeBlendInformation(nn::gfx::TDevice<nn::gfx::ApiVariation>*);
    void SetupUserShaderConstantBufferInformation(const UserShaderInformation&);
    void CopyUserShaderConstantBufferInformation(const Material&);
};

}  // namespace nn::ui2d