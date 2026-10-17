#pragma once

#include <basis/seadTypes.h>

namespace al {
class LayoutActor;

class LayoutPartsActorKeeper {
public:
    LayoutPartsActorKeeper(s32 maxActors);

    void resisterPartsActor(LayoutActor* actor);
    void appear();
    void kill();
    void update();
    void calcAnim(bool recursive);

    al::LayoutActor* getLayoutActor(int idx) const { return mPartsActors[idx]; }
    s32 getNumActors() const { return mNumActors; }
    s32 getMaxActors() const { return mMaxActors; }

private:
    LayoutActor** mPartsActors = nullptr;
    s32 mNumActors = 0;
    s32 mMaxActors = 0;
};
}  // namespace al
