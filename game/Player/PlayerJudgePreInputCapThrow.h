#pragma once

#include <basis/seadTypes.h>

class PlayerConst;
class PlayerInput;
class PlayerCarryKeeper;
class HackCap;

class PlayerJudgePreInputCapThrow {
public:
    PlayerJudgePreInputCapThrow(const PlayerConst* playerConst,
                               const PlayerInput* input,
                               const PlayerCarryKeeper* carryKeeper,
                               const HackCap* hackCap);

public:
    u8 _padding_00[0x8];                                // 0x0 to 0x8
    PlayerConst* mPlayerConst;                          // 0x8
    PlayerInput* mInput;                                // 0x10
    PlayerCarryKeeper* mCarryKeeper;                    // 0x18
    HackCap* mHackCap;                                  // 0x20
    u8 _padding[0x38];                                  // 0x28 to 0x60
};

static_assert(sizeof(PlayerJudgePreInputCapThrow) == 0x60);