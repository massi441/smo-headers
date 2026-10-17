#pragma once

#include "Library/LiveActor/LiveActor.h"

class Rabbit : public al::LiveActor {
public:
    Rabbit(const char* name);


    void onMoveEnd();

private:

};

// static_assert(sizeof(Rabbit) == 0x)
