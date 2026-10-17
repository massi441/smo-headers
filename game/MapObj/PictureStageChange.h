#pragma once

#include "Library/LiveActor/LiveActor.h"

class IUsePlayerPuppet;
class ChangeStageInfo;

namespace al {
    class RippleCtrl;
}

class PictureStageChange : public al::LiveActor {
public:
    PictureStageChange(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;

    void exeWait();
    void exeBindIn();
    void exeBindOut();

    const ChangeStageInfo* getChangeStageInfo() const { return mChangeStageInfo; }
    IUsePlayerPuppet* getPuppetUser() const { return mPuppetUser; }
    al::CameraTicket* getCameraTicket() const { return mCameraTicket; }

private:
    al::RippleCtrl* mRippleCtrl;
    IUsePlayerPuppet* mPuppetUser;
    void* mPad1[3]; // 0x118, 0x120, 0x128
    ChangeStageInfo* mChangeStageInfo; // 0x130
    void* mPad2;
    al::CameraTicket* mCameraTicket;
    char mPad3[0x160 - sizeof(al::LiveActor)];

    void setupOutCamera();

    bool isPlayerInBounds() const;
    bool isPlayerAtForceBind() const;
};

static_assert(sizeof(PictureStageChange) == 0x1a0);
