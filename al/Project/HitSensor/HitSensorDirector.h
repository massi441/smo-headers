#pragma once

#include "Library/Execute/IUseExecutor.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class ExecuteDirector;
class HitSensor;
class SensorHitGroup;

class HitSensorDirector : public IUseExecutor, public IUseHioNode {
public:
    HitSensorDirector(ExecuteDirector* parent);

    void execute() override;
    void initGroup(HitSensor* sensor);
    void executeHitCheckInSameGroup(SensorHitGroup* group) const;
    void executeHitCheckGroup(SensorHitGroup* group, SensorHitGroup* group2) const;
    void executeHitCheck(HitSensor* sensor, HitSensor* otherSensor) const;

private:
    SensorHitGroup* mPlayerGroup = nullptr;
    SensorHitGroup* mPlayerEyeGroup = nullptr;
    SensorHitGroup* mRideGroup = nullptr;
    SensorHitGroup* mEyeGroup = nullptr;
    SensorHitGroup* mLookAtGroup = nullptr;
    SensorHitGroup* mSimpleGroup = nullptr;
    SensorHitGroup* mMapObjGroup = nullptr;
    SensorHitGroup* mCharacterGroup = nullptr;
};

static_assert(sizeof(HitSensorDirector) == 0x48);

}  // namespace al
