#pragma once
#include "ResShaderOption.h"
#include "cstdint"

namespace nn::g3d {
    struct ShaderRange {
        void* mStart;
        void* mEnd;
    };

    class ResShadingModel {
    public:
        ResShaderOption* FindStaticOption(const char* option);

        uint64_t GetStaticKey(int) const;
        uint64_t GetDynamicKey(int) const;
        uint64_t GetKey(int) const;

        uint64_t FindProgramIndex(uint* keys) const;
        uint64_t FindProgramIndex(ShaderRange* shaderRange, uint* keys) const;
        bool FindProgramRange(ShaderRange* range, uint* keys) const;

        void WriteDefaultStaticKey(uint* keys) const;
        void WriteDefaultDynamicKey(uint* keys) const;
        void WriteInvalidDynamicKey(uint* keys) const;

    public:
        // 0x78 Program Array ?
    };
}
