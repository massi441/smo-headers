#pragma once

#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

class Killer : public al::LiveActor {
public:
    Killer(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;

    void appearInit();
    void appearBy2D(const sead::Vector3f& trans, const sead::Vector3f& front, const sead::Quatf& quat, s32 aliveCount);
    void standByAppear(const sead::Vector3f& trans, const sead::Quatf& quat);
    void launch(s32 aliveCount);
    void explode();
    void forceExplode();
    void applyVelocityDamp();
    void resetAliveCountAndAnim();

    void exeAppear();
    void exeStandBy();
    void exeLaunch();
    void exeFly();
    void exeFallDown();
    void exeDamageCap();
    void exeHack();
    void exeAfterHack();
    void exeExplode();

private:
    char mPadding[0x140 - sizeof(al::LiveActor)];
    // 0x136 bool mIsMagnumKiller
};

static_assert(sizeof(Killer) == 0x140);
