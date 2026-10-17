#pragma once
#include "Library/Joint/JointControllerBase.h"

namespace al {
    class HitSensor;
    class LiveActor;
}

class TrexFootIKInfo;

class TRexFootIK : public al::JointControllerBase,
                   public al::IUseCollision,
                   public al::IUseNerve {
public:
    TRexFootIK(const al::LiveActor* parent, al::HitSensor* sensor, const TrexFootIKInfo& footInfo);

    void calcJointCallback(s32, sead::Matrix34f*) override;
    void calcConstraint(const sead::Matrix34f*);
    void updateRoot(const sead::Matrix34f*);
    void updateLast(const sead::Matrix34f*);
    void updateMiddle(const sead::Matrix34f*);
    void update();
    void validate();
    void invalidate();

    al::NerveKeeper* getNerveKeeper() const override;
    al::CollisionDirector* getCollisionDirector() const override;
    const char* getCtrlTypeName() const override;

    const char* tryGetLandingCollisionMaterialCode() const;
    bool isCollidedWall() const;
    bool isCollidedGround() const;
    bool isCollidedGroundJumpCode() const;
    bool isCollidedGroundVelocity() const;
    const sead::Vector3f& getCollidedWallNormal() const; // unsure about return type
    const sead::Vector3f& getCollidedGroundNormal() const;
    void checkEnableJumpOverLowWall() const;
    bool isInvalid() const;

    void exeWait();
    void exeStart();
    void exeInvalid();

private:
    unsigned char mPadding[0x1d0 - sizeof(al::JointControllerBase) - sizeof(al::IUseNerve) - sizeof(al::IUseCollision)]; // starts at 0x28
};

static_assert(sizeof(TRexFootIK) == 0x1d0);
