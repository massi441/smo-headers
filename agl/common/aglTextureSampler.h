#pragma once

#include "aglTextureData.h"
#include "driver/aglNVNsampler.h"

namespace agl {
    class ShaderLocation;
    class DrawContext;
    class TextureData;

    class TextureSampler : driver::NVNsampler_ {
    public:
        TextureSampler();
        TextureSampler(const TextureData&);

        void applyTextureData(const agl::TextureData&);

        void setReference() const;
        void* activate(agl::DrawContext*, agl::ShaderLocation const&, int, bool) const;
        void initRegs_(uint) const;

    private:
        TextureData mTextureData; //0x10
        // SamplerObject // 0x138
        // CompSei // 0x15c
        // const char* // 0x168
        unsigned char mPadding[0x170 - sizeof(TextureData) - sizeof(driver::NVNsampler_)];
    };
}

static_assert(sizeof(agl::TextureSampler) == 0x170);
