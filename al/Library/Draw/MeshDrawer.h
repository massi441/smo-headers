#pragma once
#include "basis/seadTypes.h"
#include "g3d/ResFile.h"

namespace agl {
    class DisplayList;
}
namespace nn::g3d {
    class MaterialObj;
    class ShapeObj;
    class ModelObj;
}

namespace al {
    class ModelCtrl;
    class MeshDrawerInitArg;
    class ModelShader;
    class ModelShaderAssign;

    // custom
    struct MeshDrawerEntry {
        nn::g3d::ModelObj* mModelObj;
        nn::g3d::ShapeObj* mShapeObj;
        nn::g3d::MaterialObj* mMaterialObj;
        ModelCtrl* mModelCtrl;
        agl::DisplayList* mDisplayList;
    };

    class MeshDrawer {
    public:
        MeshDrawer(const MeshDrawerInitArg&);
        ~MeshDrawer();

        bool addMesh(nn::g3d::ModelObj const*, nn::g3d::ShapeObj const*, al::ModelCtrl*);

    public:
        u8 _00[0x28];                              // 0x00
        nn::g3d::ShapeObj* mShapeObj;              // 0x28
        nn::g3d::MaterialObj* mMaterialObj;        // 0x30
        ModelShaderAssign* mShaderAssign;          // 0x38
        ModelShader* mModelShader;                 // 0x40
        s32 mShapeIndex;                           // 0x48
        u32 _4c;                                   // 0x4c
        s32 mSomeInt;                              // 0x50
        u8 _54[0x14];                              // 0x54
        s32 mEntryCount;                           // 0x68
        u8 _6c[0x4];                               // 0x6c
        MeshDrawerEntry** mEntries;                // 0x70
        u8 _78[0x20];                              // 0x78
    };
}

static_assert(sizeof(al::MeshDrawer) == 0x98);
