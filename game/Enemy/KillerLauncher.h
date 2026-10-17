#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Library/LiveActor/LiveActorGroup.h"

class Killer;
class KillerLauncher : public al::LiveActor {
public:
    KillerLauncher(const char* name);

    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void control() override;
    void killAllAndThis();
    void killAll();

    void startLaunch();

    Killer* getCurrentKiller() const { return mCurrentKiller; }

    void exeWait();
    void exeDelay();
    void exeStandBy();
    void exeLaunch();
    void endLaunch();

private:
    al::DeriveActorGroup<Killer>* mKillers = nullptr;
    Killer* mCurrentKiller = nullptr;
    char mPadding[0x120 - sizeof(al::LiveActor)];
    // 0x12d --> bool mIsMagnumLauncher
};

static_assert(sizeof(KillerLauncher) == 0x130);
