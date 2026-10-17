#pragma once

#include "Player/PlayerActorBase.h"

template <typename T>
PlayerActorBase* createPlayerFunction(const char* name) {
    return new T(name);
}