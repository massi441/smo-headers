#pragma once

#include "Library/LiveActor/LiveActor.h"

class HackCapJointControlKeeper {
public:
    HackCapJointControlKeeper();

    void initCapJointControl(al::LiveActor* hackCap);
    void initDisplayCapJointControl(al::LiveActor* equipmentHat);
    void updateRotateThrowZ(float, float);
    void updateRotateStayZ(float);
    void updateRotateY(float);

    const sead::Vector3f& getRot() const { return mJointRot; }
    float getSkew() const { return mSkew; }

private:
    sead::Vector3f mJointRot = sead::Vector3f();
    float mSkew = 0;
};

static_assert(sizeof(HackCapJointControlKeeper) == 0x10);
