#pragma once

#include "Library/LiveActor/LiveActor.h"

class GhostPlayer : public al::LiveActor {
public:
    GhostPlayer(char const*, int, int);

private:
    char mPadding[0x230 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GhostPlayer) == 0x230);
