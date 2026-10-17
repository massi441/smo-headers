#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Player/IUsePlayerCollision.h"

class TRexFootIK;
class PlayerCollider;

class TRex : public al::LiveActor, public IUsePlayerCollision {
public:
    TRex(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* msg, al::HitSensor* self, al::HitSensor* other) override;
    void appear() override;
    void movement() override;
    void control() override;
    void updateCollider() override;
    void calcAnim() override;
    void kill() override;

    void endSleep();
    void resetAllJointController();
    const char* getHeadColliderShapeName();

    float getHoldJumpMoveAccel();
    float getHoldJumpStartUpSpeed();
    float getMaxSinkGroundHeight();
    float getPatrolGravityAccel();
    float getPatrolGroundFriction();
    // float getMaxPatrolFallSpeedOnGround(); // not sure about return type yet

    bool isEnableBreakPartsForceScroll() const;
    TRexFootIK* getLeftFootIK() const; // 0x118
    TRexFootIK* getRightFootIK() const; // (*0x118) + 8
    PlayerCollider* getPlayerCollider() const override; // 0x1c0

    void exeHackStart();
    void exeHackWait();
    void exeHackMove();
    void exeHackMoveGround();
    void exeHackMoveAfter();
    void exeHackMoveEnd();
    void exeHackTurn();
    void exeHackTurnEnd();
    void exeHackJump();
    void exeHackJumpStart();
    void exeHackFall();
    void exeHackLand();
    void endHackLand();
    void exeHackHoldJump();
    void exeHackMoveJump();
    void exeHackAttackWait();
    void endHackAttackWait();

    void exePatrolWalkStart();
    void exePatrolWalk();
    void exePatrolWalkGround();
    void exePatrolWalkAfter();
    void exePatrolWalkEndL();
    void exePatrolDash();
    void exePatrolFall();
    void exePatrolLand();
    void exePatrolHoldJump();
    void exePatrolReset();
    void exePatrolTurnBack();
    void exePatrolTurnMario();
    void exePatrolWaitSniff();
    void exePatrolNoticeSniff();
    void exePatrolSwoon();
    void exePatrolSwoonStart();
    void exePatrolSwoonEnd();

    void exeForceScrollRunStart();
    void exeForceScrollRun();
    void exeForceScrollAttackSign();
    void exeForceScrollAttack();
    void exeForceScrollAttackEnd();
    void endForceScrollAttack();
    void exeForceScrollStartFall();
    void exeForceScrollEndFall();
    void exeForceScrollStartLand();

    void exeSwoonStart();
    void exeSwoonStartLand();

    void exeFall();
    void exeForceScrollEndFallStart();
    void exeLand();
    void exePatrolSwoonStartDashClash();
    void exeReset();
    void exeSwoon();
    void exeSleep();

private:
    unsigned char mPadding[0x360 - sizeof(al::LiveActor) - sizeof(IUsePlayerCollision)];
};

static_assert(sizeof(TRex) == 0x360);
