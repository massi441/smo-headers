#pragma once

#include "Library/LiveActor/LiveActor.h"

class PackunFireFireBall : public al::LiveActor {
public:
    PackunFireFireBall(al::LiveActor* parent);

    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;

    // internally sets the speed towards the direction of the quat (8.2f)
    void setParam(const sead::Vector3f& trans, const sead::Quatf& quat, bool isPlayer);
    void killBySwitch();

    void exeYoshiTongueEatBind();
    void exeMove();

private:
    unsigned char mPadding[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PackunFireFireBall) == 0x120);
