#pragma once

#include "nn/g3d/ResSkeleton.h"

namespace nn::g3d {

// TODO
class SkeletonObj {
public:
    SkeletonObj();

    const ResSkeleton* GetRes() const { return m_Res; }

    u16 getJointCount() const { return mJointCount; }

private:
    const ResSkeleton* m_Res;
    char padToCount[0x48];
    u16 mJointCount;
    // TODO: the rest of the members
};

// 0x50: BoneCount

}  // namespace nn::g3d
