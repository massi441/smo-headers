#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
    struct SkyRotateInfo {
        float* jointController;
        float rotationSpeed;
    };

    class Sky : public al::LiveActor {
    public:
        Sky(const char* name);
        
        void init(const ActorInitInfo& info);
        void initFromPreset(const ActorInitInfo& info);
        void control();

    public:
        u32 mRotateInfoCount;
        SkyRotateInfo* mRotateInfoArray;
        s32 mTexturePatternId;
        bool mIsOnlyCubeMap;
        u8 _padding3[3];
    };

    // static_assert(sizeof(al::Sky) == 0x120);
}
