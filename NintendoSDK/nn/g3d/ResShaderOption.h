#pragma once
#include "cstdint"

namespace nn::g3d {
    class ResShaderOption {
    public:
        uint64_t FindChoiceIndex(const char* optionName) const;
    };
}