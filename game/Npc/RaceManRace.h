#pragma once

#include <container/seadPtrArray.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/ISceneObj.h"

class GhostPlayer;

class RaceManRace : public al::LiveActor, public al::IEventFlowEventReceiver, public al::ISceneObj  {
public:
    RaceManRace(const char* name);

    GhostPlayer* getRacer(int index) {
        return mGhostPlayers.at(index);
    }

private:
    sead::PtrArray<GhostPlayer> mGhostPlayers;
    char mPadding[0x1a0 - sizeof(al::LiveActor) - sizeof(sead::PtrArray<GhostPlayer>)];
};

static_assert(sizeof(RaceManRace) == 0x1b0);
