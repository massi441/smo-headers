#pragma once

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

namespace al {
class GraphicsPreset;
class GraphicsSystemInfo;
class Resource;

class GraphicsPresetDirector {
public:
    struct Request {
        bool isRequested;
        sead::FixedSafeString<64> name;
        s32 priority;
        s32 inFrames;
        s32 outFrames;
        sead::Vector3f angle;
    };

    static_assert(sizeof(Request) == 0x78);

    GraphicsPresetDirector(GraphicsSystemInfo* graphicsSystemInfo);

    void initProjectResource();
    void registerPreset(const char* name, const char*, const char*, bool isCreateSky);
    void endInit();
    void clearRequest();
    void requestPreset(const char* name, s32 priority, s32 inFrames, s32 outFrames,
                       const sead::Vector3f& angle);
    void update();
    GraphicsPreset* findPreset(const char* name) const;
    GraphicsPreset* findPreset(s32 index) const;
    s32 findPresetId(const char* name) const;
    s32 calcPresetNum() const;
    GraphicsPreset* findDefaultPreset() const;

    GraphicsSystemInfo* getGraphicsSystemInfo() const { return mGraphicsSystemInfo; }

    GraphicsPreset* getCurrentPreset() const { return mCurrentPreset; }

private:
    GraphicsSystemInfo* mGraphicsSystemInfo;
    Resource* mResource;
    sead::PtrArray<GraphicsPreset> mPresets;
    GraphicsPreset* mCurrentPreset;
    GraphicsPreset* mPreviousPreset;
    sead::PtrArray<Request> mRequests;
    Request mCurrentRequest;
    Request mPreviousRequest;
    s32 mInterpFrames;
};

static_assert(sizeof(GraphicsPresetDirector) == 0x138);

}  // namespace al
