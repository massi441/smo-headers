#pragma once

#include <basis/seadTypes.h>

class HackCap;
class PlayerConst;
class PlayerTrigger;
class PlayerInput;
class PlayerCounterAfterCapCatch;
class PlayerJudgePreInputCapThrow;

class PlayerSpinCapAttack {
public:
    PlayerSpinCapAttack(HackCap* hackCap,
                       const PlayerConst* playerConst,
                       const PlayerTrigger* trigger,
                       const PlayerInput* input,
                       const PlayerCounterAfterCapCatch* counterCapCatch,
                       const PlayerJudgePreInputCapThrow* judgePreInputCapThrow);

public:
    HackCap* mHackCap;                                      // 0x0
    const PlayerConst* mPlayerConst;                        // 0x8
    const PlayerTrigger* mTrigger;                          // 0x10
    const PlayerInput* mInput;                              // 0x18
    const PlayerCounterAfterCapCatch* mCounterCapCatch;     // 0x20
    const PlayerJudgePreInputCapThrow* mJudgePreInputCapThrow; // 0x28
    u8 _padding[0xE0];                                      // 0x30 to 0x110
};

static_assert(sizeof(PlayerSpinCapAttack) == 0x110);