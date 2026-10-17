#pragma once

#include <math/seadVectorFwd.h>

namespace al {
    class LiveActor;
}

class YoshiTongueJointControlStretch;

class YoshiTongueJointControlKeeper {
public:
    YoshiTongueJointControlKeeper(const al::LiveActor*, const al::LiveActor*);

    void update(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);

    const al::LiveActor* getTongue() const { return mTongueActor; }
    const al::LiveActor* getYoshiModel() const { return mYoshiModelActor; }

private:
    al::LiveActor* mTongueActor = nullptr;
    al::LiveActor* mYoshiModelActor = nullptr;
    YoshiTongueJointControlStretch* mTongueController = nullptr;
};

static_assert(sizeof(YoshiTongueJointControlKeeper) == 0x18);
