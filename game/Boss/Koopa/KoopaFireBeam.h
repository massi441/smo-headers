#pragma once

#include "Library/LiveActor/LiveActor.h"

class KoopaFireBeam : public al::LiveActor {
public:
    KoopaFireBeam(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void calcAnim() override;

    void appearSign();
    void startAppear();
    void disappear();

    void exeWait();
    void exeAppear();
    void exeAppearSign();
    void exeDisappear();

private:
    unsigned char mPadding[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KoopaFireBeam) == 0x110);
