#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
}

class HackCap;
class PlayerAnimator;
class PlayerModelChangerHakoniwa;
class PlayerExternalVelocity;

class PlayerSeCtrl {
public:
    PlayerSeCtrl(const al::LiveActor* player,
                const PlayerAnimator* animator,
                const HackCap* hackCap,
                const PlayerModelChangerHakoniwa* modelChanger,
                const al::LiveActor* liveActor,
                const PlayerExternalVelocity* externalVelocity);

public:
    al::LiveActor* mPlayer;                             // 0x0
    PlayerAnimator* mAnimator;                          // 0x8
    PlayerExternalVelocity* mExternalVelocity;          // 0x10
    u32 _18;                                            // 0x18
    u8 _padding_1c[0x4];                                // 0x1c
    HackCap* mHackCap;                                  // 0x20
    u8 _padding[0x170];                                 // 0x28 to 0x198
};

static_assert(sizeof(PlayerSeCtrl) == 0x198);