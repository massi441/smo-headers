#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Player/IUsePlayerCollision.h"

class IUsePlayerPuppet;

class Motorcycle : public al::LiveActor, public IUsePlayerCollision {
public:
    Motorcycle(const char*);

    void init(al::ActorInitInfo const &) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor*, al::HitSensor*) override;
    bool receiveMsg(const al::SensorMsg*, al::HitSensor*, al::HitSensor*) override;
    void kill() override;
    void movement() override;
    void calcAnim() override;
    void updateCollider() override;
    
    PlayerCollider* getPlayerCollider() const override;
    
    void exeWait();
    void exeCreep();
    void exeJump();
    void endJump();
    void exeFall();
    void exeReset();
    void exeReaction();
    void exeRideWait();
    void exeRideWaitJump();
    void endRideWaitJump();
    void exeRideWaitLand();
    void exeRideStart();
    void exeRideStartOn();
    void exeRideParking();
    void exeRideParkingStart();
    void exeRideParkingSnap();
    void exeRideParkingAfter();
    void exeRideRun();
    void exeRideRunStart();
    void exeRideRunJump();
    void endRideRunJump();
    void exeRideRunLand();
    void exeRideRunFall();
    void exeRideRunBound();
    void exeRideRunBoundStart();
    void exeRideRunClash();
    void exeRideRunCollide();
    void exeRideRunWheelie();
    void endRideRunWheelie();

    // Custom section

    IUsePlayerPuppet* getPlayerPuppet() const { return mPlayerPuppet; }
    bool isRidden() const { return mPlayerPuppet; }

private:
    IUsePlayerPuppet* mPlayerPuppet;
    char size[0x250 - 0x118];
};

static_assert(sizeof(Motorcycle) == 0x250);
