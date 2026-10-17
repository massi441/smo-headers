#pragma once

#include <prim/seadSafeString.h>
#include "detail/aglSurface.h"
#include "driver/aglNVNtexture.h"

namespace agl {

class TextureData {
public:
    class CompressToWork {
    public:
        explicit CompressToWork(const TextureData&);

        void* _0;
        void* _8;
        void* _10;
        void* _18;
        u32 _20;
        void* _28;
        void* _30;
        u32 _38;
        void* _40;
        detail::Surface mSurface;
        driver::NVNtexture_ mTexture;
    };

    TextureData();

    void setMipLevelNum_(s32, bool);
    u16 getMinSlice_() const;
    const char* getTextureFormatName() const;
    u32 calcMipByteSize(u32) const;
    bool isCompressedFormat() const;
    bool isRenderTargetCompressAvailable() const;
    bool isDepthFormat() const;
    bool hasStencil() const;
    void invalidateCPUCache();
    void flushCPUCache() const;
    void setDebugLabel(const sead::SafeString& debug_label);
    const char* getDebugLabel() const;

public:
    void* _0; //0x0
    u32 _8; // 0x08
    u32 _c; // 0x10
    void* _10; // 0x18
    void* _18; // 0x20
    void* _20; // 0x28
    void* _28; // 0x30
    detail::Surface mSurface; // 0x38
    TextureFormat mTextureFormat; // 0x54
    driver::NVNtexture_ mNvnTexture; // 0x58
    const char* mDebugLabel;  // "agl::TextureData string"
};

}  // namespace agl

static_assert(sizeof(agl::TextureData) == 0x128);
