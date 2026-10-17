#pragma once
#include "cstdint"

namespace nn::g3d {
    class ShadingModelObj {
    public:
        uint64_t FindStaticOptionIndex(const char* optionName) const;
        void WriteStaticKey(int option, int choice);
    };
}
