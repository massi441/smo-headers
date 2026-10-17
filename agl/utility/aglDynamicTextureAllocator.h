#pragma once

#include <basis/seadTypes.h>

#include "exl/types.h"

namespace agl {
    class DrawContext;
    class TextureData;
    enum class TextureFormat;
    struct GPUMemVoidAddr;
}

namespace sead {
    template<typename T>
    class SafeStringBase;
}

namespace agl::utl {
    class DynamicTextureAllocator {
    public:
        enum class AllocateType {
            READONLY = 0,
            WRITE = 1
        };

        static DynamicTextureAllocator* instance() { return sInstance; };

        // name        = debug name
        // format      = pixel format e.g. R8_uNorm
        // mipLevels   = number of mip levels
        // gpuMem      = optional pre-allocated GPU memory
        // allocType   = allocation type
        // bool, bool  = unknown flags (could use true, false)
        TextureData* alloc(
            DrawContext* drawCtx,
            const sead::SafeStringBase<char>& name,
            TextureFormat format,
            uint width,
            uint height,
            uint mipLevels,
            GPUMemVoidAddr* gpuMem,
            AllocateType allocType,
            bool unk0,
            bool unk1
        );

        void free(const TextureData* texture);

    private:
        static DynamicTextureAllocator* sInstance;
    };
}
