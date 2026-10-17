#pragma once

#include "common/aglUniformBlock.h"

namespace al {
    class UniformBlock : public agl::UniformBlock {
    public:
        UniformBlock();
        ~UniformBlock() override;

        void swap();

    public:
        int mBufferIdx;
    };
}

static_assert(sizeof(al::UniformBlock) == 0x80);
