#pragma once

#include "Library/Camera/CameraPoser.h"

class CameraPoserFollowLimit : public al::CameraPoser {
public:
    CameraPoserFollowLimit(const char* name);

    void init() override;
    void initByPlacementObj(const al::PlacementInfo& info) override;
    void loadParam(const al::ByamlIter& iter) override;
    void start(const al::CameraStartInfo& info) override;
    void update() override;
    void movement() override;
    bool receiveRequestFromObject(const al::CameraObjectRequestInfo& info) override;
    bool requestTurnToDirection(const al::CameraTurnInfo* info) override;
    void startSnapShotMode() override;
    void endSnapShotMode() override;
    void calcCameraPose(sead::LookAtCamera* cam) const override;
    bool isEnableRotateByPad() const override;

    void invalidateAutoResetLowAngleV();
    void updateInputOrSubTargetTurnH();
    void updateRotateSpeedInputH();
    bool trySwitchLimitObj();
    void startTurnBrake(s32);
    bool tryStartWater(bool);

    f32 calcDistance() const;
    f32 calcDistanceRaw() const;
    float getAngleDegreeV() const; // (*0x150) + 0xc0
    bool isInvalidCollider() const;
    bool isUseDistanceCurve() const;

    void exeFollow();
    void exeFollowRailUserCtrl();
    void exeWater();
    void endWater();
    void exeWaterRadicon();
    void exeResetAngle();
    void exeFollowRail();

private:
    unsigned char mPadding[0x2a0 - sizeof(al::CameraPoser)];

    /*
      * bool mIsBlendFollowAndParallel          -> 0x210
      * bool mIsValidCtrlDistance               -> 0x214
      * bool mIsInvalidSearchCollisionParts     -> 0x215
      * bool mIsInvalidDistanceChaser           -> 0x216
      * bool mIsInvalidInWater                  -> 0x217
      * bool mIsInvalidOutWaterResetAngleV      -> 0x218
      * bool mIsInvalidWaterAutoCtrlAngleV      -> 0x219
      * bool mIsInvalidSlopeSnapAngleV          -> 0x21b
      * bool mIsValid2DGalaxy                   -> 0x21c
      * bool mIsSetTargetBackAngleH             -> 0x211
      * bool mIsMultiStartAngleDegreeH          -> 0x212
      * bool mIsSetAngleV                       -> 0x213
      * bool mIsInvalidRequestSetAngleV         -> 0x21a
      * bool mIsApplyStartMovingDirOffset       -> 0x254
      * bool mIsSetClimbPoleAngleV              -> 0x26d
      * bool mIsInvalidSubTargetTurn            -> 0x278
      * f32  mDistanceByUser                    -> 0x228
      * f32  mStartAngleDegreeV                 -> 0x1e0
      * f32  mOutWaterResetAngleV               -> 0x1f0
      * f32  mClimbPoleAngleV                   -> 0x270
      * f32  mMaxMovingDirOffset                -> 0x258
      * f32  mMovingDirOffsetChaseRate          -> 0x25c
    */
};

static_assert(sizeof(CameraPoserFollowLimit) == 0x2a0);
