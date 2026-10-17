#pragma once

#include "Library/HostIO/HioNode.h"

#include "Player/IPlayerModelChanger.h"

class PlayerModelHolder;

namespace al {
class LiveActor;
}  // namespace al

class PlayerModelChangerYoshi : public al::HioNode, public IPlayerModelChanger {
public:
    PlayerModelChangerYoshi(const al::LiveActor*, PlayerModelHolder*);

    bool isFireFlower() const override { return false; }

    bool isMini() const override { return false; }

    bool isChange() const override { return false; }

    bool is2DModel() const override { return false; }

    bool isHiddenModel() const override;

    bool isHiddenShadowMask() const override { return false; }

    void resetPosition() override;
    void hideModel() override;
    void hideSilhouette() override;

    void hideShadowMask() override {}

    void showModel() override;
    void showSilhouette() override;

    void showShadowMask() override {}

    void appearModel();
    void killModel();
    void syncHost();

    void changeModel(al::LiveActor*);
    void syncModelFlag(al::LiveActor*);

public:
    al::LiveActor* mActor;
    al::LiveActor* mModelActor;
    PlayerModelHolder* mModelHolder;
    bool _20;
    bool _21;
    bool _22;
};

static_assert(sizeof(PlayerModelChangerYoshi) == 0x28);
