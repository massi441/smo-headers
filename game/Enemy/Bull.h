#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Player/CapTargetInfo.h"

namespace al {
    struct ActorInitInfo;
    class HitSensor;
    class SensorMsg;
}

class EnemyCap;

class Bull : public al::LiveActor {
public:
    Bull(const char* name) : al::LiveActor(name) {

    }

    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;
    void updateCollider() override;

    void exeNoStart();
    void exeBlowDown();
    void exeTrampled();
    void exeDamageCap();
    void exePressDown();
    void deathAndReset();
    void exeTrampledEnd();
    void exeReviveAppear();
    void exeFall();
    void exeFind();
    void exeHack();
    void exeTurn();
    void exeWait();
    void endChase();
    void exeAngry();
    void exeBrake();
    void exeChase();
    void exeClash();
    void exeReset();
    void exeSwoon();
    void switchOn();
    void exeAttack();
    void exeRevive();

    bool tryReceiveMsgTrample(const al::SensorMsg* message, const al::HitSensor* other, const al::HitSensor* self);
    void getSensorNameSendAttack();
    void startHack(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self);

    EnemyCap* getEnemyCap() const { return mEnemyCap; }

private:
    CapTargetInfo* mCapTargetInfo = nullptr;
    EnemyCap* mEnemyCap = nullptr;
    unsigned char size[0x138 - sizeof(al::LiveActor)] = {};
};

static_assert(sizeof(Bull) == 0x148);
