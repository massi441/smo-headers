#pragma once

#include <math/seadMatrix.h>

#include "Library/Execute/IUseExecutor.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class AreaObjDirector;
class CameraAngleVerticalRequester;
class CameraInputHolder;
class CameraInSwitchOnAreaDirector;
class CameraParamTransfer;
class CameraPoser;
class CameraPoserFactory;
class CameraPoseUpdater;
class CameraRailHolder;
class CameraResourceHolder;
class CameraStartParamCtrl;
class CameraStopJudge;
class CameraTargetCollideInfoHolder;
class CameraTargetHolder;
class CameraTicket;
class CameraTicketHolder;
class ICameraInput;
class IUseAudioKeeper;
class NameToCameraParamTransferFunc;
class PauseCameraCtrl;
class PlacementId;
class PlayerHolder;
class SceneCameraCtrl;
class SceneCameraInfo;
class SpecialCameraHolder;
struct CameraFlagCtrl;
struct CameraPoserSceneInfo;

class CameraDirector : public HioNode, public IUseExecutor {
public:
    CameraDirector(s32 maxCameras);
    virtual ~CameraDirector();

    void init(CameraPoserSceneInfo*, const CameraPoserFactory*);
    void initAreaCameraSwitcherMultiForPrototype(AreaObjDirector*);
    void initAreaCameraSwitcherSingle();
    void initResourceHolder(const CameraResourceHolder* resourceHolder);
    void initSceneFovyDegree(f32 fov);
    void initSettingCloudSea(f32);
    void initSnapShotCameraAudioKeeper(IUseAudioKeeper* audioKeeper);
    PauseCameraCtrl* initAndCreatePauseCameraCtrl(f32);

    void execute() override;
    void update();
    void endInit(const PlayerHolder*);

    CameraPoseUpdater* getPoseUpdater(s32 index) const;
    CameraTicket* createCameraFromFactory(const char*, const PlacementId*, const char*, s32, const sead::Matrix34f&);
    CameraTicket* createCamera(CameraPoser*, const PlacementId*, const char*, s32, const sead::Matrix34f&, bool registerInHolder);
    CameraTicket* createObjectCamera(const PlacementId*, const char*, const char*, s32, const sead::Matrix34f&);
    CameraTicket* createObjectEntranceCamera(const PlacementId*, const char*, const sead::Matrix34f&);
    CameraTicket* createMirrorObjectCamera(const PlacementId*, const char*, s32, const sead::Matrix34f&);

    ICameraInput* getCameraInput(int index) const;
    CameraTargetHolder* getCameraTargetHolder() const { return mTargetHolder; }
    CameraInputHolder* getCameraInputHolder() const { return mInputHolder; }
    CameraTicketHolder* getTicketHolder() const { return mTicketHolder; }

    void setCameraInput(const ICameraInput* input);
    void setViewCameraInput(const ICameraInput* input, s32);
    void registerCameraRailHolder(CameraRailHolder* railHolder);
    void setCameraParamTransferFuncTable(const NameToCameraParamTransferFunc*, s32);
    f32 getSceneFovyDegree() const;
    void validateCameraArea2D();
    void invalidateCameraArea2D();
    void stopByDeathPlayer();
    void restartByDeathPlayer();
    void startInvalidStopJudgeByDemo();
    void endInvalidStopJudgeByDemo();
    void startSnapShotMode(bool);
    void endSnapShotMode();

    SceneCameraInfo* getSceneCameraInfo() const { return mSceneCameraInfo; }

    SceneCameraCtrl* getSceneCameraCtrl() const { return mSceneCameraCtrl; }

    const CameraFlagCtrl* getFlagCtrl() const { return mFlagCtrl; }

    int getCameraPoseUpdatersCount() const { return mCameraPoseUpdatersCount;}

private:
    s32 mCameraPoseUpdatersCount;
    SceneCameraInfo* mSceneCameraInfo;
    SceneCameraCtrl* mSceneCameraCtrl;
    CameraPoseUpdater** mPoseUpdaters;
    CameraPoserFactory* mPoserFactory;
    CameraPoserSceneInfo* mPoserSceneInfo;
    CameraTicketHolder* mTicketHolder;
    SpecialCameraHolder* mSpecialCameraHolder;
    CameraTargetCollideInfoHolder* mTargetCollideInfoHolder;
    CameraTargetHolder* mTargetHolder;
    CameraInputHolder* mInputHolder;
    CameraAngleVerticalRequester* mAngleVerticalRequester;
    CameraStartParamCtrl* mStartParamCtrl;
    CameraStopJudge* mStopJudge;
    CameraParamTransfer* mParamTransfer;
    const CameraResourceHolder* mCameraResourceHolder;
    CameraFlagCtrl* mFlagCtrl;
    void* unk;
    CameraInSwitchOnAreaDirector* mInSwitchOnAreaDirector;
    void* unk2;
};

static_assert(sizeof(CameraDirector) == 0xA8);

}  // namespace al
