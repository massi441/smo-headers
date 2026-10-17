#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
    class HitSensor;
    class SensorMsg;
    class ActorInitInfo;
}

namespace sead {
    template<typename T>
    class Vector3;
}

class Tank : public al::LiveActor {
public:
    Tank(const char* name);

    void init(const al::ActorInitInfo& info);
    void initAfterPlacement() override;
    void appear() override;
    void appearAndDemoWait();
    void appearCtrl();
    void control() override;
    void calcAnim();
    void kill() override;
    void die();
    
    void attackSensor(al::HitSensor* attacker, al::HitSensor* target) override;
    bool receiveMsg(const al::SensorMsg* msg, al::HitSensor* source, al::HitSensor* target) override;
    bool isMyBullet(al::HitSensor* sensor);
    
    void turn();
    
    void exeWait();
    void exeMove();
    void exeShoot();
    void exeAttackSign();
    void exeAttackHit();
    void exeHack();
    void exeSwoon();
    void exeDamageCapture();
    void exeAppear();
    void exeDemoWait();
    void endDemoWait();
    void exeBlowDown();
    void exePressDown();
    void exePressReaction();
    void exeReset();
    void exeReviveInsideScreen();
    void exeReviveInsideScreenNoAutoRevive();
    
    void enableShoot();
    void disableShoot();
    bool isEnableShoot();
    
    void shootByPlayer(const sead::Vector3f& direction, float param1, int param2);
    void startShootByMofumofu();
    
    void startRevive();
    void startRevivePrepare();
    void startBlowDownByMofumofu(al::HitSensor* sensor);
    
    void preInitHandleByMofumofu();
    void forceEndHackByMofumofu();
    
    bool isExistAndNearRail();
    
    void setSubjectiveCameraLimitDegree(float param1, float param2);
    void setSubjectiveCameraAimFollowRateV(float rate);
    
private:
    char size[0x1b0 - sizeof(al::LiveActor)];
};