#pragma once

#include <basis/seadTypes.h>

#include "Library/Execute/ExecutorListBase.h"

namespace al {
class ExecutorActorExecuteBase;
class LiveActor;

class ExecutorListActorExecuteBase : public ExecutorListBase {
public:
    ExecutorListActorExecuteBase(const char* name, s32 size);

    ~ExecutorListActorExecuteBase() override;

    /**
     * Calls the executor function of each ExecutorActorExecuteBase in the list.
     * This is the function that handles dispatching virtual functions (movement, calcAnim...)
     */
    void executeList() const override;

    bool isActive() const override { return mCount > 0; }

    virtual ExecutorActorExecuteBase* createExecutor(const char* name) const = 0;

    void createList();

    /**
     * Registers an actor to the executor by updating the Updater list in the actor's execute info.
     * this->createExecutor is called if it doesn't exist yet for the actor.
     * @param actor The actor to register
     */
    void registerActor(LiveActor* actor);

private:
    s32 mMaxSize = 0;
    s32 mCount = 0;
    ExecutorActorExecuteBase** mActorExecutors = nullptr;
};

static_assert(sizeof(ExecutorListActorExecuteBase) == 0x20);

static_assert(sizeof(ExecutorListActorExecuteBase) == 0x20);

}  // namespace al
