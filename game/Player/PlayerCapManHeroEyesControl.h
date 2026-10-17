#pragma once

#include "Library/Nerve/NerveExecutor.h"

namespace al {
class LiveActor;
}

class PlayerCapManHeroEyesControl : public al::NerveExecutor {
public:
    PlayerCapManHeroEyesControl(const char* name, al::LiveActor* capEye, al::LiveActor* capEye2D);

    void startPuppet();
    void requestWaitAnimChange(const char* actionName);
    void end();
    void kill();
    void start();
    void fastStart();
    void update();
    void endPuppet();

    al::LiveActor* getPuppetEye() const;
    bool isAppear() const;
    bool isDisappear() const;
    bool isDemo() const;
    bool isDeadCap() const;

    void setEyesActor(al::LiveActor* actor) {
        mPlayerEyesActor = actor;
    }

    void exeAppear();
    void exeDisappear();
    void exeDead();
    void exeDemo();
    void exeWait();

private:
    al::LiveActor* mPlayerEyesActor; // 0x10
    al::LiveActor* mPlayer2DEyesActor; // 0x18
};

static_assert(sizeof(PlayerCapManHeroEyesControl) == 0x20);
