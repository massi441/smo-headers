#pragma once

#include "gfx/seadColor.h"
#include "math/seadVector.h"

namespace al {
    class EffectResourceInfo;
    class ActionEffectData;

    struct EffectInfo {
        EffectInfo();

        char* mEffectName;
        int mResourceCount;
        int pad_0C;
        EffectResourceInfo* mResourceList;
        int mDrawCategoryIndex;
        int pad_1C;
        char* mJointName;
        sead::Vector3f mPosOffset;
        sead::Vector3f mRotate;
        float mScale; // 0x40
        float mParticleScale;
        float mEmitRatio;
        float mFarClipDistance;
        int mForceCalcFrame;
        int mHandleNum;
        sead::Color4f mColor;
        bool mIsEmitBillboard;
        bool mIsEmitYBillboard;
        bool mIsEmitCamera;
        bool mIsDeleteAtClipping;
        bool mIsOneTimeFade;
        bool mIsEmitIgnoreRotate;
        bool mIsEmitIgnoreScale;
        bool mIsFollowPos;
        bool mIsFollowMtx;
        bool mIsEmitTrans;
        bool mIsEmitRotate;
        bool mIsEmitScale;
        bool mIsFollowTrans;
        bool mIsFollowRotate;
        bool mIsFollowScale;
        bool mIsNeedProgramInfo;
        bool mPad_78;
        bool mPad_79;
        bool mIsDirectPos;
        bool mIsHasPosOffset;
        bool mIsHasRotate;
        bool mIsHasColor;
        bool mIsBindWorldAxisX;
        bool mIsBindWorldAxisY;
        bool mIsBindWorldAxisZ;
        bool mIsNoEmitAtNoCollide;
        bool mIsFollowScaleByFovy;
        bool mPad_83;
        int mPad_84;
        int mActionCount;
        int mPad_8C;
        ActionEffectData* mActionList;
        int mHitReactionCount;
        int mPad_9C;
    };
}

static_assert(sizeof(al::EffectInfo) == 0xa0);
