#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
    struct ActorInitInfo;
}

class Frog : public al::LiveActor {
public:
    Frog(const char* name) : al::LiveActor(name) {};
    void init(const al::ActorInitInfo& info) override;

private:
    char size[0x1e0 - sizeof(al::LiveActor)];
};
