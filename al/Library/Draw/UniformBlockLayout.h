#pragma once
#include "common/aglUniformBlock.h"

namespace al {
    class UniformBlockLayout {
    public:
        int mIndex;
        agl::UniformBlock::Type mType;
        int mCount;
    };
}

static_assert(sizeof(al::UniformBlockLayout) == 0xc);