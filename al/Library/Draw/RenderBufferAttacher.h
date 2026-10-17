#pragma once

#include "common/aglRenderTarget.h"

namespace agl {
    class DrawContext;
    class RenderBuffer;
    class RenderTargetColor;
    class RenderTargetDepth;
    class TextureData;
}

namespace sead {
    class Viewport;
}

namespace al {
    class RenderBufferAttacher {
    public:
        RenderBufferAttacher(agl::DrawContext* drawCtx,
                             agl::RenderBuffer* renderBuffer,
                             const agl::TextureData* color0,
                             const agl::TextureData* color1,
                             const agl::TextureData* color2,
                             const agl::TextureData* color3,
                             const agl::RenderTargetDepth* depth);

        RenderBufferAttacher(agl::DrawContext* drawCtx,
                             agl::RenderBuffer* renderBuffer,
                             const sead::Viewport* viewport,
                             const agl::TextureData* color0,
                             const agl::TextureData* color1,
                             const agl::TextureData* color2,
                             const agl::TextureData* color3,
                             const agl::RenderTargetDepth* depth);

        RenderBufferAttacher(agl::DrawContext* drawCtx,
                             agl::RenderBuffer* renderBuffer,
                             int unk,
                             const agl::TextureData* color0,
                             const agl::TextureData* color1,
                             const agl::TextureData* color2,
                             const agl::TextureData* color3,
                             const agl::RenderTargetDepth* depth);

        void invalidateGpuCacheWrite(agl::DrawContext* drawCtx);

    private:
        agl::DrawContext* mDrawCtx;            // 0x000
        agl::RenderBuffer* mRenderBuffer;      // 0x008
        agl::RenderTargetColor mColorTarget0;  // 0x010
        agl::RenderTargetColor mColorTarget1;  // 0x188
        agl::RenderTargetColor mColorTarget2;  // 0x300
        agl::RenderTargetColor mColorTarget3;  // 0x478
        void* mUnk1;
        void* mUnk2;
        void* mUnk3;
        void* mUnk4;
    };
}

static_assert(sizeof(al::RenderBufferAttacher) == 0x610);