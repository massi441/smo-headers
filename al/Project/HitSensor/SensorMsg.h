#pragma once

#include <prim/seadRuntimeTypeInfo.h>

namespace al {
class HitSensor;
class ComboCounter;

class SensorMsg {
    SEAD_RTTI_BASE(SensorMsg)

public:
    virtual ~SensorMsg() = default;
};
}  // namespace al
