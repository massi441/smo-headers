#pragma once

#include <prim/seadSafeString.h>
#include "Library/LiveActor/LiveActor.h"

class PlayerActorBase;
namespace ml {
    class HackCapKeeper;
}

namespace al {
    class ActorDitherAnimator;
    class WaterSurfaceFinder;
    class PadRumbleKeeper;
}

class PlayerInput;
class PlayerAreaChecker;
class PlayerWallActionHistory;
class PlayerCapActionHistory;
class PlayerEyeSensorHitHolder;
class PlayerSeparateCapFlag;
class IUsePlayerCollision;
class IUsePlayerHeightCheck;
class PlayerWetControl;
class PlayerJointControlKeeper;
class HackCapJudgePreInputSeparateThrow;
class HackCapJudgePreInputSeparateJump;
class CapTargetInfo;
class PlayerColliderHackCap;
class HackCapTrigger;
class HackCapAboveGroundChecker;
class HackCapThrowParam;
class HackCapJointControlKeeper;
class PlayerExternalVelocity;
class PlayerPushReceiver;
class HackCapStateThrowStay;
class HackCapStateHide;

class HackCap : public al::LiveActor {
public:
    enum class SwingHandType { /*TODO: missing values*/ };

    HackCap(const al::LiveActor* liveActor,
        const char* capTypeName,
        const PlayerInput* playerInput,
        const PlayerAreaChecker* areaChecker,
        const PlayerWallActionHistory* wallActionHistory,
        const PlayerCapActionHistory* capActionHistory,
        const PlayerEyeSensorHitHolder* eyeSensorHitHolder,
        const PlayerSeparateCapFlag* separateCapFlag,
        const IUsePlayerCollision* usePlayerCollision,
        const IUsePlayerHeightCheck* usePlayerHeightCheck,
        const PlayerWetControl* wetControl,
        const PlayerJointControlKeeper* jointControlKeeper,
        HackCapJudgePreInputSeparateThrow* judgePreInputSeparateThrow,
        HackCapJudgePreInputSeparateJump* judgePreInputSeparateJump);
    
    void init(const al::ActorInitInfo& info) override;
    void movement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void attackSpin(al::HitSensor*, al::HitSensor*, f32);
    
    void calcReturnTargetPos(sead::Vector3f*) const;
    void hide(bool);
    void forcePutOn();
    void updateCapPose();
    
    void startHack();
    void endHack();
    void forceHack(al::HitSensor*, const CapTargetInfo*);
    void recordHack();
    void noticeHackMarioEnter();
    void noticeHackDemoPuppetableEnd();
    bool sendMsgStartHack(al::HitSensor*);
    void addHackStartDemo();
    void emitHackStartEffect();
    void startHackShineGetDemo();
    void endHackShineGetDemo();
    void syncHackDamageVisibility(bool);
    
    void startCatch(const char*, bool, const sead::Vector3f&);
    void exeCatch();
    
    void startThrow(bool, const sead::Vector3f&, const sead::Vector3f&, f32, const sead::Vector2f&, const sead::Vector2f&, const sead::Vector3f&, bool, const sead::Vector3f&, SwingHandType, bool, f32, s32);
    void exeThrow();
    void exeThrowStart();
    void setupThrowStart();
    void exeThrowStay();
    void exeThrowBrake();
    void exeThrowAppend();
    bool tryAppendAttack();
    void exeThrowSpiral();
    void endThrowSpiral();
    void exeThrowRolling();
    void exeThrowRollingBrake();
    void rollingGround();
    void exeThrowTornado();
    void endHackThrow();
    void endHackThrowAndReturnHack();
    void endHackThrowAndReturnHackOrHide();
    void clearThrowType();
    void updateThrowJoint();
    bool changeThrowParamInWater(s32, bool);
    bool checkEnableThrowStartSpace(sead::Vector3f*, sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&, f32, f32, bool, const sead::Vector3f&);
    void collideThrowStartArrow(al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
    
    void startThrowSeparatePlay(const sead::Vector3f&, const sead::Vector3f&, f32, bool);
    void startThrowSeparatePlayHack(al::HitSensor*, const sead::Vector3f&, const sead::Vector3f&, f32);
    void startThrowSeparatePlayJump(const sead::Vector3f&, const sead::Vector3f&, f32);
    bool tryChangeSeparateThrow();
    void updateSeparateMode(const PlayerSeparateCapFlag*);
    void prepareCooperateThrow();
    void requestForceFollowSeparateHide();
    
    void exeSpinAttack();
    void startSpinAttack(const char*);
    
    void prepareLockOn(al::HitSensor*);
    void setupStartLockOn();
    void exeLockOn();
    void exeTrampleLockOn();
    void resetLockOnParam();
    void prepareTransferLockOn(al::HitSensor*);
    bool receiveRequestTransferHack(al::HitSensor*, al::HitSensor*);
    bool requestLockOnHitReaction(const CapTargetInfo*, const char*);
    bool tryCollideWallLockOn();
    void addLockOnKeepDemo();
    void updateTargetLayout();
    
    void exeRebound();
    void exeTrample();
    void exeBlow();
    
    void exeReturn();
    bool tryReturn(bool, bool*);
    bool requestReturn(bool*);
    void endMove();
    void followTarget();
    void addCurveOffset();
    
    void exeRescue();
    void startRescuePlayer();
    
    void exeHide();
    
    void startPuppet();
    void endPuppet();
    void showPuppetCap();
    void hidePuppetCap();
    void syncPuppetSilhouette();
    void showPuppetCapSilhouette();
    void hidePuppetCapSilhouette();
    void startPuppetCheckpointWarp();
    
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool trySendAttackCollideAndReaction(bool*);
    
    void updateCollider() override;
    bool stayWallHit();
    bool tryCollideWallReaction();
    bool tryCollideWallReactionStay();
    bool tryCollideWallReactionSpiral();
    bool tryCollideWallReactionReflect();
    bool tryCollideWallReactionRollingGround();
    bool tryCollideReflectReaction();
    bool stayRollingOrReflect();
    
    void updateWaterArea();
    void updateLavaSurfaceMove();
    
    bool cancelCapState();
    void updateCapEyeShowHide(bool, s32);
    void startThrowCapEyeThrowAction();
    void updateFrameOutLayout();
    void updateShadowMaskOffset();
    void updateModelAlphaForSnapShot();
    
    void activateInvincibleEffect();
    void syncInvincibleEffect(bool);
    
    void recordCapJump(PlayerWallActionHistory*);
    
    bool isFlying() const;
    bool isThrowTypeSpiral() const;

    bool isNoPutOnHide() const;
    bool isEnableThrow() const;
    bool isEnableSpinAttack() const;
    bool isSpinAttack() const;
    f32 getFlyingSpeedMax() const;
    f32 getThrowSpeed() const;
    void calcHackFollowTrans(sead::Vector3f*, bool) const;
    void makeFollowMtx(sead::Matrix34f*) const;
    bool isEnableRescuePlayer() const;
    bool isRescuePlayer() const;
    bool isEnableHackThrow(bool*) const;
    bool isSeparateHipDropLand() const;
    bool isSeparateHide() const;
    bool isSeparateThrowFlying() const;
    f32 calcSeparateHideSpeedH(const sead::Vector3f&) const;
    s32 getPadRumblePort() const;
    bool isEnableThrowSeparate() const;
    bool isHoldInputKeepLockOn() const;
    bool isRequestableReturn() const;
    bool isLockOnEnableHackTarget() const;
    bool isWaitHackLockOn() const;
    bool isCatched() const;
    bool isHide() const;
    bool isPutOn() const;
    bool isLockOnInterpolate() const;
    bool isEnablePreInput() const;
    bool isForceCapTouchJump() const;
    bool isHackInvalidSeparatePlay() const;
    void exeHack();
    bool isHoldSpinCapStay() const;
    bool isThrowTypeRolling() const;
    f32 getThrowHeight() const;
    f32 getThrowRange() const;
    s32 getThrowBrakeTime() const;
    f32 getThrowBackSpeed() const;
    bool isEnableHackThrowAutoCatch() const;
    s32 getThrowStayTime() const;
    s32 getThrowStayTimeMax() const;
    f32 getThrowSpeedAppend() const;
    f32 getThrowRangeAppend() const;
    bool isEnableCapTouchJumpInput() const;
    CapTargetInfo* getCapTargetInfo() const { return mCapTargetInfo1; }
    bool isSeparateFlying() const { return mIsSeparateFlying; }
    void setIsHide(bool isHide) { mIsHide = isHide; }

    // Custom section

    friend class ml::HackCapKeeper;

    const LiveActor* getPlayerActor() const { return mPlayerActor; }
    const HackCapJointControlKeeper* getJointControlKeeper() const { return mHackCapJointControlKeeper; }

private:
    al::LiveActor* mEquipmentHat;
    al::LiveActor* mEquipmentHatDepthShadow;
    al::LiveActor* mLockOnCapEyes;
    al::LiveActor* mThrowingHatEyes;
    const al::LiveActor* mPlayerActor;
    const IUsePlayerCollision* mPlayerCollision;
    const char* mTypeName;
    const PlayerAreaChecker* mPlayerAreaChecker;
    const PlayerSeparateCapFlag* mPlayerSeparateCapFlag;
    const IUsePlayerHeightCheck* mPlayerHeightCheck;
    const PlayerWetControl* mPlayerWetControl;
    const PlayerJointControlKeeper* mPlayerJointControlKeeper;
    PlayerColliderHackCap* mPlayerColliderHackCap;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    al::PadRumbleKeeper* mPadRumbleKeeper;
    PlayerWetControl* mSelfPlayerWetControl;
    HackCapTrigger* mHackCapTrigger;
    al::ActorDitherAnimator* mActorDitherAnimator;
    HackCapAboveGroundChecker* mHackCapAboveGroundChecker;
    void* _1a0_arr;
    u64 _1a0_capacity;
    s32 _1a0_current;
    void* _1b8_arr;
    u64 _1b8_capacity;
    s32 _1b8_current;
    const al::HitSensor* _1d0;
    al::HitSensor* mAttackSensor;
    sead::Vector3f mSpiralTailPositions[5];
    HackCapThrowParam* mHackCapThrowParam;
    CapTargetInfo* mCapTargetInfo1;
    CapTargetInfo* mCapTargetInfo2;
    void* _238;
    sead::Vector3f _240;
    sead::Vector3f _24c;
    sead::Vector3f _258;
    f32 _264;
    sead::Vector2f _268;
    f32 _270;
    s32 _274;
    s32 _278;
    s32 _27c;
    f32 _280;
    f32 _284;
    f32 _288;
    f32 _28c;
    s32 _290;
    char filler_294[4];
    s32 _298;
    char filler_29c[4];
    char _2a0[4];
    bool mIsSeparateFlying;
    char _2a5[11];
    const PlayerWallActionHistory* mPlayerWallActionHistory;
    const PlayerCapActionHistory* mPlayerCapActionHistory;
    const PlayerInput* mInput;
    PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder;
    PlayerEyeSensorHitHolder* mCapEyeSensorHitHolder;
    f32 _2d8;
    s32 _2dc;
    HackCapJointControlKeeper* mHackCapJointControlKeeper;
    void* _2e8[5];
    sead::FixedSafeString<128> _310;
    sead::FixedSafeString<128> _3a8;
    sead::Matrix34f _440;
    sead::Matrix34f _470;
    sead::Matrix34f _4a0;
    bool _4d0;
    sead::Vector3f _4d4;
    sead::Vector3f _4e0;
    bool _4ec;
    void* _4f0;
    PlayerExternalVelocity* mCapExternalVelocity;
    PlayerPushReceiver* mCapPushReceiver;
    al::HitSensor* mPlayerBodySensor;
    bool _510;
    sead::Vector3f _514;
    HackCapJudgePreInputSeparateThrow* mCapJudgePreInputSeparateThrow;
    HackCapJudgePreInputSeparateJump* mCapJudgePreInputSeparateJump;
    bool _530;
    s32 _534;
    sead::Vector3f mWallPos;
    sead::Vector3f mWallNormal;
    sead::Vector3f mWallVelocity;
    void* _560[4];
    s32 _580;
    s32 mLockOnCounter;
    sead::Matrix34f _588;
    bool mIsHide;
    bool mIsHackDamageVisible;
    bool _5ba;
    bool _5bb;
    s32 _5bc;
    void* _5c0[7];
    bool mIsPuppet;
    bool _5f9;
    bool mIsHidePuppetCapSilhouette;
    HackCapStateThrowStay* mStateThrowStay;
    HackCapStateHide* mStateHide;
};

static_assert(sizeof(HackCap) == 0x610);
