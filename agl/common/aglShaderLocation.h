#pragma once

#include <basis/seadTypes.h>
#include <prim/seadNamable.h>

#include "common/aglShaderEnum.h"

namespace agl {
class ShaderProgram;

class ShaderLocation {
public:
    // sets location for all
    void setLocation(s32 loc);
    void setLocation(ShaderType shaderType, s32 loc);
    void setRegisterLocation(ShaderType shaderType, s32 loc);

public:
    u8 mVertex = -1;
    u8 mFragment = -1;
    u8 mGeometry = -1;
    u8 mCompute = -1;
};

class UniformBlockLocation : public ShaderLocation, public sead::INamable {
    ~UniformBlockLocation() = default;
    void search(const ShaderProgram&);
};

}  // namespace agl
