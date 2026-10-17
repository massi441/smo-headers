#pragma once

#include "Library/LiveActor/LiveActor.h"

struct BossForestBeamParam {
    int mSearchTime = 90; // 0x0
    int mLockOnDuration = 90; // 0x4
    int mAttackDuration = 48; // 0x8
    int mBurnDuration = 300; // 0xc
};

class BossForestBeam : public al::LiveActor {
public:
    BossForestBeam(const al::LiveActor* parentActor);
    
    void init(const al::ActorInitInfo& info) override;
    void setup(const BossForestBeamParam& param);

    void startAttack();
    void startLockOn();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;

    void appear() override;
    void makeActorDead() override;

    void exeAttackSign();
    void exeAttackWait();
    void exeAttack();
    void exeLockOn();

    int getSearchTime() const;
    bool isStateDamage() const;
    bool isStateLockOn() const;

    // WARNING: Custom functions, not part of original game, including protected ones
    // TODO: Make "BossForestBeamFunction" friend class to keep header equal to original

    void setParentActor(al::LiveActor* parentActor) { mParentActor = parentActor; }
    int getAttackDuration() const { return mParams->mAttackDuration; }
    int getShootDelay() const { return mParams->mBurnDuration; }
    int getLockOnDuration() const { return mParams->mLockOnDuration; }

    al::LiveActor* getLaserActor() const { return mLaserActor; }
    al::LiveActor* getParentActor() const { return mParentActor; }
    BossForestBeamParam* getParams() const { return mParams; }

protected:
    al::LiveActor* mParentActor = nullptr; // 0x108
    al::LiveActor* mLaserActor = nullptr; // 0x110
    BossForestBeamParam* mParams = nullptr; // 0x118
};

// static_assert(sizeof(BossForestBeam) == 0x120);
