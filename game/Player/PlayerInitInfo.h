#pragma once

#include "math/seadMatrix.h"

// floats: 0x34 0x38 0x3c 0x40 0x28 0x2c 0x30
// 0x18 initPlayerModelName
// 0x44 isNeedCreateNodeNeedle
// 0x45 : isCloset

// WARNING layout not fully reconstructed
struct PlayerInitInfo {
    const char* unk0x0;
    sead::Matrix34f* viewMtx;
    int portNo;
    const char* bodyCostume;
    const char* capCostume;
    float float1;
    float float2;
    float float3;
    float float4;
    float float5;
    float float6;
    float float7;
    bool isNeedCreateNeedle;
    bool isCloset;
};
