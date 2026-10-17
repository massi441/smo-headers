#pragma once
#include "Library/Nerve/NerveStateBase.h"

class YoshiEgg;
class IUsePlayerCollision;
class PlayerModelChangerYoshi;
class PlayerConst;

namespace al {
    class WaterSurfaceFinder;
    struct ActorInitInfo;
}

class YoshiStateEgg : public al::ActorStateBase {
public:
    explicit YoshiStateEgg(const al::ActorInitInfo&, al::LiveActor*, const IUsePlayerCollision*, const PlayerConst*, const al::WaterSurfaceFinder*, PlayerModelChangerYoshi*);
    ~YoshiStateEgg() override;

    void appear() override;
    void kill() override;

    bool reactionCollidedCollisionCode();

    YoshiEgg* getEgg() const { return mYoshiEgg; }

    void exeWait();
    void exeAppear();

private:
    const IUsePlayerCollision* mCollisionUser;
    const PlayerConst* mPlayerConst;
    const al::WaterSurfaceFinder* mWaterSurfaceFinder;
    YoshiEgg* mYoshiEgg = nullptr;
    PlayerModelChangerYoshi* mModelChanger;
    bool mUnk = true;
};

static_assert(sizeof(YoshiStateEgg) == 0x50);
