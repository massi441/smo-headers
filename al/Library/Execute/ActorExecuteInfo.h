#pragma once

namespace al {
class ExecuteRequestKeeper;
class ExecutorActorExecuteBase;
class ModelDrawerBase;

class ActorExecuteInfo {
public:
    ActorExecuteInfo(ExecuteRequestKeeper* keeper);
    void addUpdater(ExecutorActorExecuteBase* updater);
    void addDrawer(ModelDrawerBase* drawer);

    ExecuteRequestKeeper* getRequestKeeper() const { return mRequestKeeper; }

    int getUpdaterCount() const { return mUpdaterCount; }

    ExecutorActorExecuteBase* getUpdater(int idx) const { return mUpdaters[idx]; }

    int getDrawerCount() const { return mDrawerCount; }

    ModelDrawerBase* getDrawer(int idx) const { return mDrawers[idx]; }

private:
    ExecuteRequestKeeper* mRequestKeeper = nullptr;
    int mUpdaterCount = 0;
    ExecutorActorExecuteBase* mUpdaters[4] = {};
    int mDrawerCount = 0;
    ModelDrawerBase* mDrawers[11] = {};
};

static_assert(sizeof(ActorExecuteInfo) == 0x90);

}  // namespace al
