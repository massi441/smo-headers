#pragma once

#include "Library/LiveActor/LiveActor.h"

class KickStone : public al::LiveActor {
public:
    KickStone(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;

    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;

    void movement() override;
    void control() override;
    void kill() override;
    void updateCollider() override;

    void exeEatPrepare();
    void exeRestartPrepare();
    void endWait();
    void exeFall();
    void exeHold();
    void exeRoll();
    void exeWait();
    void exeWater();
    void exeEatBy();

private:
    unsigned char mPadding[0x1e0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KickStone) == 0x1e0);
