#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
}

class PlayerModelHolder;
class HackCap;

class PlayerRippleGenerator {
public:
    PlayerRippleGenerator(const al::LiveActor* player,
                         const al::LiveActor* hackCap,
                         const PlayerModelHolder* modelHolder);

public:
    al::LiveActor* mPlayer;              // 0x0
    HackCap* mHackCap;                   // 0x8
    PlayerModelHolder* mModelHolder;     // 0x10
    u8 _padding[0x40];                   // 0x18 to 0x58
};

static_assert(sizeof(PlayerRippleGenerator) == 0x58);