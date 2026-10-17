#pragma once
#include "Library/LiveActor/LiveActor.h"

class TankBullet : public al::LiveActor {
public:
    TankBullet(const char* name);
    
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;

    void shoot(const sead::Vector3f& trans, const sead::Vector3f& vel, int lifeSpan, bool b1, bool b2);
    void shootByPlayer(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, float, int);
    
    void appear() override;
    void disappear();
    void explode();
    
    void exeStart();
    void exeMove();
    void exeMovePlayer();
    void exeYoshiEat();
    void exeExplode();

private:
    char size[0x140 - sizeof(al::LiveActor)];
};