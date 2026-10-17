#pragma once

#include "Library/Joint/JointControllerBase.h"

namespace al {
    class JointAimInfo;

    class JointAimController : public JointControllerBase {
    public:
        JointAimController(const JointAimInfo* info);

    private:
        unsigned char mPadding[0x40 - sizeof(JointControllerBase)];
    };
}

static_assert(sizeof(al::JointAimController) == 0x40);
