#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
}

class IUsePlayerCollision;
class HackCap;
class PlayerInput;

class HackCapJudgePreInputHoveringJump {
public:
    HackCapJudgePreInputHoveringJump(const al::LiveActor* player,
                                    const IUsePlayerCollision* collision,
                                    const HackCap* hackCap,
                                    const PlayerInput* input);

public:
    u8 _padding_00[0x8];                                // 0x0 to 0x8
    al::LiveActor* mPlayer;                             // 0x8
    IUsePlayerCollision* mCollision;                    // 0x10
    HackCap* mHackCap;                                  // 0x18
    PlayerInput* mInput;                                // 0x20
    u8 _padding[0x8];                                   // 0x28 to 0x30
};

static_assert(sizeof(HackCapJudgePreInputHoveringJump) == 0x30);