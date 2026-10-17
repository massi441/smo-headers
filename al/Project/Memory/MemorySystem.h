#pragma once

#include <container/seadStrTreeMap.h>
#include <heap/seadExpHeap.h>
#include <heap/seadFrameHeap.h>
#include <heap/seadHeapMgr.h>

namespace al {
class AudioResourceDirector;

class MemorySystem {
public:
    MemorySystem(sead::Heap* heap);

    void allocFailedCallbackFunc(const sead::HeapMgr::AllocFailedCallbackArg* arg);
    void createSequenceHeap();
    void freeAllSequenceHeap();
    void printSequenceHeap();
    bool createSceneHeap(const char* stageName, bool backwards);
    void createSceneResourceHeap(const char* stageName, bool backwards);
    void destroySceneHeap();
    void destroySceneResourceHeap();
    void createCourseSelectHeap();
    void destroyCourseSelectHeap();
    void createWorldResourceHeap();
    void destroyWorldResourceHeap();
    void freeAllPlayerHeap();
    sead::Heap* tryFindNamedHeap(const char* heapName) const;
    sead::Heap* findNamedHeap(const char* heapName) const;
    void addNamedHeap(sead::Heap* heap, const char* heapName);
    void removeNamedHeap(const char* heapName);

    sead::ExpHeap* getStationedHeap() const { return mStationedHeap; }

    sead::ExpHeap* getSequenceHeap() const { return mSequenceHeap; }

    sead::FrameHeap* getSceneResourceHeap() const { return mSceneResourceHeap; }

    sead::FrameHeap* getSceneHeap() const { return mSceneHeap; }

    sead::ExpHeap* getPlayerResourceHeap() const { return mPlayerResourceHeap; }

    sead::FrameHeap* getCourseSelectResourceHeap() const { return mCourseSelectResourceHeap; }

    sead::FrameHeap* getCourseSelectHeap() const { return mCourseSelectHeap; }

    sead::ExpHeap* getWorldResourceHeap() const { return mWorldResourceHeap; }

    AudioResourceDirector* getAudioResourceDirector() const { return mAudioResourceDirector; }

    void setAudioResourceDirector(AudioResourceDirector* audioResourceDirector) {
        mAudioResourceDirector = audioResourceDirector;
    }

private:
    sead::ExpHeap* mStationedHeap = nullptr;
    sead::ExpHeap* mSequenceHeap = nullptr;
    sead::FrameHeap* mSceneResourceHeap = nullptr;
    sead::FrameHeap* mSceneHeap = nullptr;
    sead::ExpHeap* mPlayerResourceHeap = nullptr;
    sead::FrameHeap* mCourseSelectResourceHeap = nullptr;
    sead::FrameHeap* mCourseSelectHeap = nullptr;
    sead::ExpHeap* mWorldResourceHeap = nullptr;
    sead::StrTreeMap<32, sead::Heap*> mHeapList;
    AudioResourceDirector* mAudioResourceDirector = nullptr;
    bool mIsExistFileResource = false;
    sead::Delegate1<MemorySystem, const sead::HeapMgr::AllocFailedCallbackArg*> mDelegate;
};

static_assert(sizeof(MemorySystem) == 0x90);
}  // namespace al
