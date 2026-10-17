/**
 * @file Picture.h
 * @brief Picture pane for displaying textured quads.
 */
#pragma once

#include "nn/ui2d/Pane.h"
#include <nn/types.h>

namespace nn {
namespace util {
struct Float2;
class Unorm8x4;
}
}

namespace nn::ui2d {

class BuildResultInformation;
class BuildArgSet;
class ResPicture;
class Material;
class TextureInfo;
class DrawInfo;

class Picture : public Pane {
public:
    NN_RUNTIME_TYPEINFO(nn::ui2d::Pane);

    Picture(int);
    Picture(const TextureInfo&);
    
    virtual ~Picture();
    
    void Initialize(int);
    void InitializeMaterial(int);
    void SetMaterial(Material*);
    void ReserveTexCoord(int);
    void SetTexCoordCount(int);
    void SetTexCoord(int, const nn::util::Float2*);
    void SetVertexColor(int, const nn::util::Unorm8x4&);
    void SetVertexColorElement(int, u8);
    void Append(const TextureInfo&);
    void CopyShapeInfo(const Picture&);
    void CopyShapeVertexData(DrawInfo&);
};

}  // namespace nn::ui2d