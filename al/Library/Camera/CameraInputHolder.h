#pragma once

#include <basis/seadTypes.h>

namespace al {
class ICameraInput;

class CameraInputHolder {
public:
    CameraInputHolder(s32 size);
    void initAfterPlacement();
    ICameraInput* getInput(s32 index) const;

private:
    ICameraInput* mDefaultInput = nullptr;
    ICameraInput** mInputs;
    s32 mInputsSize;

    friend class ml::MultiplayerCameraHolder;
};

}

static_assert(sizeof(al::CameraInputHolder) == 0x18);
