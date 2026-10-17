#pragma once

#include "Library/Camera/ICameraInput.h"

namespace al {
    class LiveActor;
}

class ProjectCameraInput : public al::ICameraInput {
public:
    ProjectCameraInput(const al::LiveActor*);

    void calcInputStick(sead::Vector2f* inputStick) const override;
    bool isTriggerReset() const override;
    bool isHoldZoom() const override;
    bool tryCalcSnapShotMoveStick(sead::Vector2f* moveStick) const override;
    bool isHoldSnapShotZoomIn() const override;
    bool isHoldSnapShotZoomOut() const override;
    bool isHoldSnapShotRollLeft() const override;
    bool isHoldSnapShotRollRight() const override;
    void calcGyroPose(sead::Vector3f* dir1, sead::Vector3f* dir2, sead::Vector3f* dir3) const override;

    const al::LiveActor* getActor() const { return mLiveActor; }

private:
    const al::LiveActor* mLiveActor;
};
