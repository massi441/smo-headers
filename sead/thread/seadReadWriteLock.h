#pragma once

#include "basis/seadRawPrint.h"
#include "prim/seadScopedLock.h"
#include "thread/seadAtomic.h"
#include "thread/seadSemaphore.h"
#include "thread/seadThread.h"

namespace sead
{
class Thread;

class ReadWriteLock
{
public:
    ReadWriteLock() = default;
    ~ReadWriteLock() = default;

    void readLock()
    {
        ScopedLock<SemaphoreLock> lock(&mReadLock);

        if (mNumReaders.increment() == 0)
            mWriteLock.lock();
    }

    void readUnlock()
    {
        if (mNumReaders.decrement() == 1)
            mWriteLock.unlock();
    }

    void writeLock()
    {
        Thread* current_thread = ThreadMgr::instance()->getCurrentThread();
        if (mWriterThread != current_thread)
        {
            if (mNumWriters.increment() == 0)
                mReadLock.lock();

            mWriteLock.lock();
            mWriterThread = current_thread;
        }
        ++mWritingThreadCount;
    }

    void writeUnlock()
    {
        Thread* current_thread = ThreadMgr::instance()->getCurrentThread();
        if (mWriterThread != current_thread)
        {
            SEAD_ASSERT_MSG(false, "This thread[%p] does not have the lock.", current_thread);
            return;
        }

        if (!current_thread || mWritingThreadCount == 0 || int(mWritingThreadCount) < 0)
        {
            SEAD_ASSERT_MSG(
                false,
                "mWritingThreadCount[%d] must not be 0 and current_thread[%p] must not be nullptr",
                mWritingThreadCount, current_thread);
            return;
        }

        --mWritingThreadCount;
        if (mWritingThreadCount == 0)
        {
            mWriterThread = nullptr;
            mWriteLock.unlock();
            if (mNumWriters.decrement() == 1)
                mReadLock.unlock();
        }
    }

private:
    class SemaphoreLock
    {
    public:
        SemaphoreLock() = default;

        void lock()
        {
            if (mLockCount.increment())
                mSemaphore.lock();
        }

        void unlock()
        {
            if (mLockCount.decrement() != 1)
                mSemaphore.unlock();
        }

    public:
        Semaphore mSemaphore{0, 0x7FFF};
        Atomic<u32> mLockCount{0};
    };

    Atomic<u32> mNumReaders{0};
    Atomic<u32> mNumWriters{0};
    SemaphoreLock mReadLock;
    SemaphoreLock mWriteLock;
    Thread* mWriterThread = nullptr;
    u32 mWritingThreadCount{0};
};
}  // namespace sead
