#pragma once

#include <basis/seadTypes.h>
#include "Library/Nerve/NerveStateBase.h"

namespace al {
    class LiveActor;
}

class PlayerConst;
class IPlayerModelChanger;
class IUseDimension;
class PlayerInput;
class PlayerJumpMessageRequest;
class IJudge;
class PlayerCounterForceRun;
class PlayerJointControlKeeper;
class IUsePlayerCollision;
class PlayerTrigger;
class PlayerContinuousJump;
class PlayerAnimator;
class PlayerActionDiveInWater;
class HackCap;

class PlayerStateJump : public al::ActorStateBase {
public:
    PlayerStateJump(al::LiveActor* player,
                   const PlayerConst* playerConst,
                   const IPlayerModelChanger* modelChanger,
                   const IUseDimension* dimension,
                   const PlayerInput* input,
                   const PlayerJumpMessageRequest* jumpMessageRequest,
                   const IJudge* judgeCapCatch,
                   const PlayerCounterForceRun* counterForceRun,
                   const PlayerJointControlKeeper* jointControlKeeper,
                   const IUsePlayerCollision* collision,
                   PlayerTrigger* trigger,
                   PlayerContinuousJump* continuousJump,
                   PlayerAnimator* animator,
                   PlayerActionDiveInWater* actionDiveInWater,
                   HackCap* hackCap,
                   IJudge* judgeHoldHoveringJump,
                   bool isMoon);

public:
    u8 _padding_00[0x88 - sizeof(ActorStateBase)];      // 0x0 to 0x88
    HackCap* mHackCap;                                  // 0x88
    u8 _padding[0x70];                                  // 0x90 to 0x100
};

static_assert(sizeof(PlayerStateJump) == 0x100);