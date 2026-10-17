#pragma once

#include "Library/LiveActor/LiveActor.h"

class BossRaid : public al::LiveActor {
public:
    BossRaid(const char* name);
    
private:
    char name[0x1a8 - sizeof(al::LiveActor)];
};