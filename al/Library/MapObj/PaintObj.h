#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "container/seadPtrArray.h"
#include "gfx/seadColor.h"
#include "math/seadVector.h"

namespace agl {
    class DrawContext;
    class TextureData;
}

namespace sead {
    class Color4u8;
}

enum class DrawRequestType : u32 {
    TextureDraw = 1,
    PlotDraw = 2,
    PlotDrawSmall = 3,
    PlotDrawLarge = 4,
    TextureDraw2 = 5,
    TextureDraw2S = 6,
    TextureDraw2L = 7,
    LineDraw = 8,
    QuadDraw = 9,
    CircleDraw = 10,
    NrmDraw = 11,
};

class PaintObj : public al::LiveActor {
public:
    class DrawRequest {
    public:
        DrawRequestType mDrawType;
        int _04;
        al::LiveActor* mSensorHost;
        agl::TextureData* mRenderTarget;
        agl::TextureData* mSourceTexture;
        sead::Vector2i mPixelPosStart;
        sead::Vector2i mPixelPosEnd;
        int mBrushSize;
        sead::Color4u8 mColor;
        sead::Vector2f mScale;
        float mRotation;
        sead::Vector2f mTargetPos;
    };

    PaintObj(const char* name);

    virtual void onClipped();
    virtual ~PaintObj();

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;

    void appendNrmDrawRequest(const sead::Vector2i&, int, al::HitSensor*);
    void medianFilter(agl::TextureData*, const sead::Vector2i&, const sead::Vector2i&);
    void reset();
    void switchOn();
    void switchOff();
    void switchKill();
    void switchStop();

    // checks if a uv is at least 128 (at least half bright)
    bool checkPaintAlpha(const sead::Vector2i& uv) const;
    bool checkPaintClear(const sead::Vector3f&, const sead::Color4u8&, int) const;
    void requestDrawPlot(const DrawRequest*) const;
    void drawBlurAndNormal() const;
    void requestDrawTexture(const DrawRequest*) const;
    void drawLabelingAndVanish(const sead::Vector2i&, const sead::Vector2i&, agl::DrawContext*, const sead::Vector2i&, const sead::Vector2i&) const;
    void draw() const override;
    void drawNrm(agl::TextureData*, agl::TextureData*, int, int, int, int) const;
    void calcCoord(sead::Vector2i*, const sead::Vector3f&, const sead::Vector2i&) const;

    void exeWait();

private:
    unsigned char mPadding[0x207bd0 - sizeof(al::LiveActor)];

    // sead::PtrArrayImpl mActiveDrawRequests;

    //TODO: pad fields at correct offsets

    // 0x207ba8 : stop flag
    // 0x7ab0 to 0x7af8 : material names
    // 0x7968 : TextureData -> RenderTarget
    // 0x7988 : TextureData -> mBlurBuffer
    // 0x79b0 : TextureData
    // 0x7a90 : TextureData -> from PenText.szs
    // 0x79a8 : TextureData -> BlurredCanvas
    // 0x79c8 : TextureData -> mNrmCanvas
    // 0x7b60 : RippleCtrl
    // 0x7b58 : MtxConnector
    // 0x7a58 : AreaObjGroup (EnablePaintArea)
    // 0x7a60 : AreaObjGroup (DisablePaintDamageArea)
    // 0x7a40 : agl::DrawContext (from graphics system info)

    // --- Params --- //
    // 0x7a14 : OrthoW
    // 0x7a18 : OrthoH
    // 0x7a1c : OffsetX
    // 0x7a24 : OffsetZ
    // 0x7ab0 : MaterialName
    // 0x7b00 : TexturenName
    // 0x7a30 : TextureWidth (0x7a38 too?)
    // 0x7a34 : TextureHeight (0x7a3c too?)
    // 0x7b50 : NerveStateBase
    // 0x7b50: MapPartsStateCapRotate
    // 0x207bbc : LabelinRangeOffsetMinX
    // 0x207bc0 : LabelinRangeOffsetMinY
    // 0x207bc4 : LabelinRangeOffsetMaxX
    // 0x207bc8 : LabelinRangeOffsetMaxY

    // 0x7b58 : MtxConnector
    // 0x7b60 : RippleCtrl
    // 0x207bb0 : FixMapParts (AdditionalCollision map part, if present)

    // Verify these:
    // 0x7a08 : IsEnableDrawMario
    // 0x7a09 : IsEnableDrawCap
    // 0x7a13 : ColorResetR
    // 0x7a12 : ColorResetG
    // 0x7a11 : ColorResetB
    // 0x7a10 : ColorResetA
    // 0x7a0f : ColorR
    // 0x7a0e : ColorG
    // 0x7a0d : ColorB
    // 0x7a0c : ColorA
    // 0x7a28 : IsImpossibleWalkTransparent
    // 0x7a68 : DamageType
    // 0x7a54 : IsDrawAdd
    // 0x7a55 : IsDrawSub
    // 0x7a9c : SensorOffsetY
    // 0x7aa8 : IsReplaceDrcTexture
    // 0x207bb8 : IsEnableVanishLabeling

    // InitPaintTextureInfo.byml
};

static_assert(sizeof(PaintObj) == 0x207bd0);
static_assert(sizeof(PaintObj::DrawRequest) == 0x50);
