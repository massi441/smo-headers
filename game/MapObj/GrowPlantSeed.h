#pragma once

#include "Library/LiveActor/LiveActor.h"

// TODO: implement

class GrowPlantSeed : public al::LiveActor {
public:
    GrowPlantSeed(const char* name);

    void appear() override;
    void kill() override;
};
