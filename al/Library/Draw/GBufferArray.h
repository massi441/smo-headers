#pragma once

namespace agl {
    class DrawContext;
    class TextureData;
    class RenderTargetDepth;
    class SamplerLocation;
    namespace lght {
        class LightPrePass;
    }
}

namespace sead {
    class Camera;
}

namespace al {
    class GraphicsSystemInfo;
    class Projection;

    class GBufferArray {
    public:
        GBufferArray(const agl::RenderTargetDepth* depthTarget, const GraphicsSystemInfo* graphicsSystemInfo);

        ~GBufferArray();

        void allocGBuffer(agl::DrawContext* drawCtx, int viewIndex);

        void clearGBuffer(agl::DrawContext* drawCtx);

        void bindRenderBuffer(agl::DrawContext* drawCtx, int targetCount);

        void bindRenderBufferAndContextMRT(agl::DrawContext* drawCtx);

        void bindRenderBufferLightBuf(agl::DrawContext* drawCtx);

        void createLightBufferAndCalcContext(agl::DrawContext* drawCtx, agl::lght::LightPrePass* lightPrePass, int unk0, int unk1, int unk2, const sead::Camera& camera, const Projection* projection);

        void freeGBuf(int index);

        void freeGBufBaseColor();
        void freeGBufNrmWorld();
        void freeGBufDepthView();
        void freeGBufMotionVec();

        agl::TextureData* getGBufBaseColor();
        agl::TextureData* getGBufNrmWorld();
        agl::TextureData* getGBufDepthView();
        agl::TextureData* getGBufMotionVec();
        agl::TextureData* getGBufLightBuffer();

        const agl::TextureData* getGBufBaseColorTex() const;
        const agl::TextureData* getGBufNrmWorldTex() const;
        const agl::TextureData* getGBufDepthViewTex() const;
        const agl::TextureData* getGBufMotionVecTex() const;
        const agl::TextureData* getGBufLightBufferTex() const;

        void activateSamplerBaseColor(agl::DrawContext* drawCtx, const agl::SamplerLocation& location, bool unk) const;
        void activateSamplerNrmWorld(agl::DrawContext* drawCtx, const agl::SamplerLocation& location, bool unk) const;
        void activateSamplerDepthView(agl::DrawContext* drawCtx, const agl::SamplerLocation& location, bool unk) const;
        void activateSamplerMotionVec(agl::DrawContext* drawCtx, const agl::SamplerLocation& location, bool unk) const;
        void activateSamplerLightBuffer(agl::DrawContext* drawCtx, const agl::SamplerLocation& location, bool unk) const;
    };

}