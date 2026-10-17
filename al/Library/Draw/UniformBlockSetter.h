#pragma once
#include "iterator"

namespace al {
    class UniformBlock;

    class UniformBlockSetter {
    public:
        UniformBlockSetter(UniformBlock* uniformBlock, int bufferFlushOffset);
        ~UniformBlockSetter();

    public:
        UniformBlock* mUniformBlock;
        int mUnk1; // uniform index?
    };
}

static_assert(sizeof(al::UniformBlockSetter) == 0x10);