#pragma once

#include "Library/MapObj/BreakMapPartsBase.h"

class BlockHard : public al::BreakMapPartsBase {
public:
    BlockHard(const char* name);

    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void movement() override;
    void calcAnim() override;
    void kill() override;

    void validateIncludeShineChip();
    void startBreak(const al::SensorMsg*, al::HitSensor* other, al::HitSensor* self);

private:
    unsigned char mPadding[0x158 - sizeof(al::BreakMapPartsBase)];
};

static_assert(sizeof(BlockHard) == 0x158);
