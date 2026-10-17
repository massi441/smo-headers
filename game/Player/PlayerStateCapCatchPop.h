#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
}

class PlayerConst;
class IUsePlayerCollision;
class PlayerInput;
class PlayerAnimator;
class HackCap;

class PlayerStateCapCatchPop {
public:
    PlayerStateCapCatchPop(al::LiveActor* player,
                          const PlayerConst* playerConst,
                          const IUsePlayerCollision* collision,
                          const PlayerInput* input,
                          PlayerAnimator* animator,
                          HackCap* hackCap);

public:
    u8 _padding_00[0x40];                               // 0x0 to 0x40
    HackCap* mHackCap;                                  // 0x40
    u8 _padding[0x00];                                  // 0x48 to 0x48
};

static_assert(sizeof(PlayerStateCapCatchPop) == 0x48);