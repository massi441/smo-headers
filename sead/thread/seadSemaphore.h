#pragma once

#ifdef NNSDK
#include <nn/os.h>
#endif

#include "basis/seadRawPrint.h"
#include "heap/seadDisposer.h"

namespace sead
{
class Heap;

class Semaphore : public IDisposer
{
public:
    Semaphore() = default;

    explicit Semaphore(s32 initial_count) : Semaphore()
    {
        initialize(initial_count);
    }

    explicit Semaphore(s32 initial_count, s32 max_count) : Semaphore()
    {
        initialize(initial_count, max_count);
    }

    explicit Semaphore(Heap* heap) : Semaphore(heap, HeapNullOption::UseSpecifiedOrContainHeap) {}

    explicit Semaphore(Heap* heap, s32 initial_count) : Semaphore(heap)
    {
        initialize(initial_count);
    }

    explicit Semaphore(Heap* heap, s32 initial_count, s32 max_count) : Semaphore(heap)
    {
        initialize(initial_count, max_count);
    }

    explicit Semaphore(Heap* heap, HeapNullOption heap_null_option)
        : IDisposer(heap, heap_null_option)
    {
    }

    explicit Semaphore(Heap* heap, HeapNullOption heap_null_option, s32 initial_count)
        : Semaphore(heap, heap_null_option)
    {
        initialize(initial_count);
    }

    explicit Semaphore(Heap* heap, HeapNullOption heap_null_option, s32 initial_count, s32 max_count)
        : Semaphore(heap, heap_null_option)
    {
        initialize(initial_count, max_count);
    }

    ~Semaphore() override
    {
        nn::os::FinalizeSemaphore(&mSemaphoreInner);
        setInitialized(false);
    }

    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;

    void initialize(s32 initial_count) { initialize(initial_count, initial_count); }

    void initialize(s32 initial_count, s32 max_count)
    {
#ifdef SEAD_DEBUG
        SEAD_ASSERT_MSG(!mInitialized, "Semaphore is already initialized.");
#endif
        nn::os::InitializeSemaphore(&mSemaphoreInner, initial_count, max_count);
        setInitialized(true);
    }

    void lock()
    {
#ifdef SEAD_DEBUG
        SEAD_ASSERT_MSG(mInitialized, "Semaphore is not initialized.");
#endif
        nn::os::AcquireSemaphore(&mSemaphoreInner);
    }

    bool tryLock()
    {
#ifdef SEAD_DEBUG
        SEAD_ASSERT_MSG(mInitialized, "Semaphore is not initialized.");
#endif
        return nn::os::TryAcquireSemaphore(&mSemaphoreInner);
    }

    void unlock()
    {
#ifdef SEAD_DEBUG
        SEAD_ASSERT_MSG(mInitialized, "Semaphore is not initialized.");
#endif
        nn::os::ReleaseSemaphore(&mSemaphoreInner);
    }

    bool try_lock() { return tryLock(); }

public:
    void setInitialized([[maybe_unused]] bool initialized)
    {
#ifdef SEAD_DEBUG
        mInitialized = initialized;
#endif
    }

#ifdef NNSDK
    nn::os::SemaphoreType mSemaphoreInner;
#else
#error "Unknown platform"
#endif

#ifdef SEAD_DEBUG
    bool mInitialized = false;
#endif
};
}  // namespace sead
