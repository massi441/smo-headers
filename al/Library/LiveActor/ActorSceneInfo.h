#pragma once

namespace al {
class AreaObjDirector;
class CameraDirector;
class ClippingDirector;
class CollisionDirector;
class DemoDirector;
class GameDataHolderBase;
class GamePadSystem;
class GraphicsSystemInfo;
class GravityHolder;
class ItemDirectorBase;
struct ModelDrawBufferCounter;
class ModelGroup;
class NatureDirector;
class PadRumbleDirector;
class PlayerHolder;
class SceneMsgCtrl;
class ScreenCoverCtrl;
class SceneObjHolder;
class SceneStopCtrl;
class ShadowDirector;

struct ActorSceneInfo {
    ActorSceneInfo();

    AreaObjDirector* mAreaObjDirector = nullptr;
    CameraDirector* mCameraDirector = nullptr;
    ClippingDirector* mClippingDirector = nullptr;
    CollisionDirector* mCollisionDirector = nullptr;
    DemoDirector* mDemoDirector = nullptr;
    GameDataHolderBase* mGameDataHolder = nullptr;
    GravityHolder* mGravityHolder = nullptr;
    ItemDirectorBase* mItemDirector = nullptr;
    NatureDirector* mNatureDirector = nullptr;
    const GamePadSystem* mGamePadSystem = nullptr;
    PadRumbleDirector* mPadRumbleDirector = nullptr;
    PlayerHolder* mPlayerHolder = nullptr;
    SceneObjHolder* mSceneObjHolder = nullptr;
    SceneStopCtrl* mSceneStopCtrl = nullptr;
    SceneMsgCtrl* mSceneMsgCtrl = nullptr;
    ScreenCoverCtrl* mScreenCoverCtrl = nullptr;
    ShadowDirector* mShadowDirector = nullptr;
    ModelGroup* mModelGroup = nullptr;
    GraphicsSystemInfo* mGraphicsSystemInfo = nullptr;
    ModelDrawBufferCounter* mModelDrawBufferCounter = nullptr;
};
}  // namespace al

static_assert(sizeof(al::ActorSceneInfo) == 0xa0);
