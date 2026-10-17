#pragma once

#include "Enemy/Bros.h"

class FireBrosFireBall : public BrosWeaponBase {
public:
    FireBrosFireBall(const char* name, const al::LiveActor* parent);

    void init(const al::ActorInitInfo& info);

    void shoot(const sead::Vector3f& shootPos, const sead::Quatf& quat, const sead::Vector3f& vel, bool isPlayer, int p5, bool isPlayerShot) override;
    void killCollide(al::HitSensor* sensor, const sead::Vector3f& trans, bool isHack) override;
    void killEnemy() override;
private:
    char padding[0x140 - sizeof(BrosWeaponBase)];
};
