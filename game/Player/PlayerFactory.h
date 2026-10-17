#pragma once

#include "Library/Factory/Factory.h"

class PlayerActorBase;

using PlayerCreatorFunction = PlayerActorBase* (*)(const char* name);

class PlayerFactory : public al::Factory<PlayerCreatorFunction> {
public:
    PlayerFactory();
};