#pragma once

#include "Library/MapObj/MirrorActorBase.h"

class Mirror : public MirrorActorBase {
public:
    Mirror(const char* name);

private:
    // char size[0x1948 - sizeof(MirrorActorBase)];
};