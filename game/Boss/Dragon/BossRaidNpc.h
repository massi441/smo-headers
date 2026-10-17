#pragma once

#include "Library/LiveActor/LiveActor.h"

class BossRaidNpc : public al::LiveActor {
public:
    BossRaidNpc(const char* name);
    
private:
    char size[0x120 - sizeof(al::LiveActor)];
};