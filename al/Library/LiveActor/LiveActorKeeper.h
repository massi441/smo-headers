#pragma once

#include <basis/seadTypes.h>

namespace al {
struct ActorInitInfo;
class LiveActor;
struct SubActorInfo;

class SubActorKeeper {
public:
    SubActorKeeper(LiveActor* rootActor);
    void registerSubActor(LiveActor* subActor, u32 syncType);
    void init(const ActorInitInfo& initInfo, const char* suffix, s32 maxSubActors);

    static SubActorKeeper* create(LiveActor* rootActor);
    static SubActorKeeper* tryCreate(LiveActor* rootActor, const char* suffix, s32 maxSubActors);

    s32 getCurActorCount() const { return mCurActorCount; }

    const SubActorInfo* getActorInfo(s32 index) const { return mSubActorInfos[index]; }

public:
    friend class alSubActorFunction;

private:
    LiveActor* mParentActor;
    s32 mMaxActorCount = 0;
    s32 mCurActorCount = 0;
    SubActorInfo** mSubActorInfos = nullptr;
};

}  // namespace al

static_assert(sizeof(al::SubActorKeeper) == 0x18);
