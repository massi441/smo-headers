#pragma once

#include "math/seadVectorFwd.h"

namespace al {
    class JointAimInfo {
    public:
        void addPowerRate(float rate);
        void setPowerRate(float rate);
        void setTargetPos(const sead::Vector3f& pos);
        void subPowerRate(float rate);

    private:
        unsigned char mPadding[0x68];
    };
}

static_assert(sizeof(al::JointAimInfo) == 0x68);