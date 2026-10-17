#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace sead {
class Heap;
}

namespace al {
class GraphicsSystemInfo;

class SimpleModelEnv {
public:
    SimpleModelEnv();
    ~SimpleModelEnv();

    void initialize(s32, const GraphicsSystemInfo*, sead::Heap*);
    void setPrevViewProjMatrix(const sead::Matrix34f&, const sead::Matrix44f&);
    void updateEnv(s32, const sead::Matrix34f&, const sead::Matrix44f&, const sead::Vector2f&,
                   const sead::Vector2f&, f32, f32, f32, f32, f32, const char*);
};

}  // namespace al
