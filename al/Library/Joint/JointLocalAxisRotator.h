#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/Joint/JointControllerBase.h"

namespace al {

class JointLocalAxisRotator : public JointControllerBase {
public:
    JointLocalAxisRotator(const f32*, const sead::Vector3f&, bool);

    void calcJointCallback(s32, sead::Matrix34f*) override;
    const char* getCtrlTypeName() const override;

    sead::Vector3f* getAxisPtr() { return &mAxis; }
    void setAxis(const sead::Vector3f& axis) { mAxis = axis; }

private:
    sead::Vector3f mAxis;
    f32* _38;
    bool _40;
};

}  // namespace al
