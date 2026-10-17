#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
}

class PlayerModelChangerHakoniwa;
class HackCap;
class PlayerEffect;

// TODO: Find setter workaround with power up mod

class PlayerStainControl {
public:
    PlayerStainControl(const al::LiveActor* player,
                      al::LiveActor* playerModel,
                      const PlayerModelChangerHakoniwa* modelChanger,
                      const HackCap* hackCap,
                      PlayerEffect* effect);
    void update();

    void setPlayerModel(al::LiveActor* player) { mPlayerActor = player; }
    void setHackCap(HackCap* hackCap) { mHackCap = hackCap; }

private:
    al::LiveActor* mPlayerActor;                        // 0x0
    al::LiveActor* mPlayerModelActor;                   // 0x8
    PlayerModelChangerHakoniwa* mModelChanger;          // 0x10
    HackCap* mHackCap;                                  // 0x18
    u8 _padding[0x68];                                  // 0x20 to 0x88
};

static_assert(sizeof(PlayerStainControl) == 0x88);