#pragma once

#include <nn/types.h>

namespace nn::g3d {

class MaterialObj;
class ResModel;
class ShapeObj;
class SkeletonObj;

// TODO
class ModelObj {
public:
    ModelObj();

    SkeletonObj* GetSkeleton() const { return m_Skeleton; }

    nn::g3d::MaterialObj* FindMaterial(char const* materialName);

    s32 GetNumShapes() const { return m_NumShapes; }

    s32 get_8c() const { return _8c; }

public:
    struct InitializeArgument;

    bool Initialize(const InitializeArgument& arg, void* buffer, size_t bufferSize);

    u32 getMaterialVisFlag(int index) {
        return mMaterialVisFlags[index];
    }

private:
    const ResModel* m_ResModel;
    void* _8;
    u32* mMaterialVisFlags;
    u8 _18;
    u8 _19;
    u16 _1a;
    void* _20;
    void* _28;
    u16 m_NumShapes;
    u16 m_NumMaterials;
    SkeletonObj* m_Skeleton;
    ShapeObj* m_Shapes;
    MaterialObj* m_Materials;
    void* _50;
    void* m_UserData;
    void* _60;
    void* _68;
    void* _70;
    void* _78;
    void* _80;
    bool _88;
    int _8c;
};

}  // namespace nn::g3d
