#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

class GolemClimbThrustPoint;
class GolemClimbWeakPoint;
class IUseDemoSkip;

namespace al {
class CameraTicket;
}

class GolemClimb : public al::LiveActor {
public:
    GolemClimb(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;

    virtual void updateLookAt();
    virtual al::LiveActor* getActor();
    virtual al::LiveActor* getSkeleton();
    virtual void getShoutPos(sead::Vector3f* outPos) const;
    virtual const sead::Matrix34f* getFootRootL() const;
    virtual const sead::Matrix34f* getFootRootR() const;
    virtual GolemClimbThrustPoint* getThrustPointL() const;
    virtual GolemClimbThrustPoint* getThrustPointR() const;
    virtual GolemClimbWeakPoint* getWeakPoint(s32 index) const;
    virtual bool isPrepareShout() const;
    virtual IUseDemoSkip* getDemoSkip();
    virtual void stampFoot(const sead::Vector3f& trans, const sead::Quatf& quat);
    virtual void showDamageArea();
    virtual void hideDamageArea();
    virtual void setDamageAreaPose(const sead::Matrix34f& pose);
    virtual bool isInFootL();
    virtual bool isInFootR();
    virtual bool isMoon();
    virtual void throwSearchBomb();
    virtual void throwReflectBomb();
    virtual void throwTsukkun();
    virtual void startDemo();
    virtual void endDemo();
    virtual void startShout();
    virtual void endShout();
    virtual void replaceDemoPlayer();
    virtual bool isFirstDemo() const;
    virtual bool isEnableSkipDemo() const;
    virtual void skipDemo();
    virtual void updateOnlyDemoGrapics();
    virtual void updatePushSensor();
    virtual void endPushSensor();
    virtual bool tryNextPushSensor() const;

    al::CameraTicket* getTowerCameraTicket() const { return mTowerCameraTicket; }
    al::CameraTicket* getFollowLimitCameraTicket() const { return mFollowLimitCameraTicket; }
    al::CameraTicket* getEntranceCameraTicket() const { return mEntranceCameraTicket; }

private:
    u8 _padding[0x208 - 0x108];
    al::CameraTicket* mTowerCameraTicket;
    al::CameraTicket* mFollowLimitCameraTicket;
    al::CameraTicket* mEntranceCameraTicket;
    u8 _padding2[0x430 - 0x220];
};

static_assert(sizeof(GolemClimb) == 0x430);
