#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/HioNode.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
class LiveActor;

class LiveActorGroup : public HioNode {
public:
    LiveActorGroup(const char* groupName, s32 maxActors);

    virtual s32 registerActor(LiveActor* pActor);

    void removeActor(const LiveActor* pActor);
    void removeActorAll();
    bool isExistActor(const LiveActor* pActor) const;
    bool isFull() const;
    s32 calcAliveActorNum() const;
    LiveActor* getDeadActor() const;
    LiveActor* tryFindDeadActor() const;
    void appearAll();
    void killAll();
    void makeActorAliveAll();
    void makeActorDeadAll();

    s32 getMaxActorCount() const { return mMaxActorCount; }

    s32 getActorCount() const { return mActorCount; }

    LiveActor* getActor(s32 idx) const { return mActors[idx]; }

    bool hasDeadActor() const { return this->getDeadActor(); }

    bool isEmpty() const { return mActorCount == 0; }

    al::LiveActor** begin() { return mActors; }
    al::LiveActor** end() { return mActors + mActorCount; }

    al::LiveActor* const* begin() const { return mActors; }
    al::LiveActor* const* end() const { return mActors + mActorCount;}

private:
    const char* mGroupName;
    s32 mMaxActorCount;
    s32 mActorCount;
    LiveActor** mActors;
};

template <class T>
class DeriveActorGroup : public LiveActorGroup {
public:
    DeriveActorGroup(const char* groupName, s32 groupCount)
        : LiveActorGroup(groupName, groupCount) {}

    T* getDeriveActor(s32 idx) const { return static_cast<T*>(LiveActorGroup::getActor(idx)); }

    T* getDeadDeriveActor() const { return static_cast<T*>(LiveActorGroup::getDeadActor()); }

    T* tryFindDeadDeriveActor() const { return static_cast<T*>(LiveActorGroup::tryFindDeadActor()); }

    using LiveActorGroup::begin;
    using LiveActorGroup::end;

    T** begin() { return reinterpret_cast<T**>(LiveActorGroup::begin()); }
    T** end() { return reinterpret_cast<T**>(LiveActorGroup::end()); }

    T* const* begin() const { return reinterpret_cast<T* const*>(LiveActorGroup::begin()); }
    T* const* end() const { return reinterpret_cast<T* const*>(LiveActorGroup::end()); }
};
}  // namespace al
