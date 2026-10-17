#pragma once

#include "Library/Camera/ActorCameraTarget.h"

class PlayerCameraTarget : public al::ActorCameraTarget {
public:
    PlayerCameraTarget(const al::LiveActor* actor);

    void calcTrans(sead::Vector3f* trans) const override;
    bool isCollideGround() const override;
    bool isInWater() const override;
    bool isInMoonGravity() const override;
    bool isClimbPole() const override;
    bool isGrabCeil() const override;
    bool isWallCatch() const override;
    bool isInvalidMoveByInput() const override;
    bool isEnableEndAfterInterpole() const override;
    void update() override;
    f32 getRequestDistance() const override;

private:
    unsigned char mPadding[0x30 - sizeof(al::ActorCameraTarget)];
};

static_assert(sizeof(PlayerCameraTarget) == 0x30);
