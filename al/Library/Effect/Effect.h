#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

#include "EffectInfo.h"

namespace sead {
    class Color4f;
}

namespace al {

class EffectSystemInfo;
class EffectEmitter;
class EffectSystem;
class EffectCameraHolder;
struct EffectInfo;

struct JointMtxPtr {
    void* mMtxPtr;
    bool mIsMtx43;
};

class Effect {
public:
    Effect(EffectSystemInfo* systemInfo, EffectInfo* effectInfo, sead::Vector3f* param3, sead::Vector3f* param4, sead::Matrix34f* matrix, unsigned long param6);

    void update();
    void tryKillEmitterAndParticleAll();
    void forceSetStopCalcAndDraw(bool);
    void setEmitterVolumeScale(const sead::Vector3f&);
    void deleteAndClearEmitter();
    void setParticleLifeScale(float);
    void setStopCalcAndDraw(bool);
    void setEmitterAllScale(const sead::Vector3f&);
    void tryUpdateMaterial(char const*, bool const (&) [3]);
    bool tryDeleteEmitters();
    void setParticleScale(const sead::Vector3f&);
    void setParticleScale(float);
    void setParticleColor(const sead::Color4f&);
    void setParticleAlpha(float alpha);
    int tryEmitEmitters(const sead::Vector3f*, bool);
    bool tryEmitEmitter(al::EffectEmitter*, const sead::Vector3f*);
    void setEmitRatio(float);
    void setActorClip(bool);
    void emitEmitters(const sead::Vector3f*, bool);
    void emitEmitter(al::EffectEmitter*, const sead::Vector3f*);

    void setMtxPtr(sead::Matrix34f* mtx);
    void setPosPtr(sead::Vector3f* pos);
    void setCameraHolder(al::EffectCameraHolder*);
    void setFarClip(bool);

    void* getViewMtxPtr() const; // 0x48
    bool isOneTimeFade() const;
    bool isEmitterActive() const;
    bool isLoopOrInfinity() const;

    // NOTE: custom functions, not part of base game

    const char* getName() const { return mName; }
    void setScale(float scale) const { mEffectInfo->mScale = scale; }
    const EffectInfo* getEffectInfo() const { return mEffectInfo; }
    void setPosOffset(const sead::Vector3f& offset) const { mEffectInfo->mPosOffset = offset; }

    private:
        const char* mName;
        EffectEmitter** mEmitters;
        int mEmittersCount;
        EffectSystemInfo* mEffectSystemInfo;
        EffectInfo* mEffectInfo;
        sead::Vector3f* mPosPtr;
        sead::Vector3f* mRotPtr;
        JointMtxPtr mJointMtxPtr;
        unsigned char mPadding[200 - 0x48];
    };
}

static_assert(sizeof(al::Effect) == 200);