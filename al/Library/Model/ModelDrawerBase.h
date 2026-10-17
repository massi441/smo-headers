#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/HioNode.h"

namespace agl {
class DrawContext;
}

namespace al {
class GraphicsSystemInfo;
struct ModelDrawBufferCounter;
class ModelKeeper;
class ModelDrawDisplayList;
class ModelCtrl;
class MeshDrawerTable;

class ModelDrawerBase : public HioNode {
public:
    ModelDrawerBase(const char* name);
    virtual ~ModelDrawerBase();
    virtual void createTable() = 0;
    virtual void draw() const = 0;
    virtual void registerModel(ModelCtrl* model);
    virtual void addModel(ModelCtrl* model);
    virtual void removeModel(ModelCtrl* model);
    virtual void updateModel(ModelCtrl* model);

    void setDrawInfo(agl::DrawContext* drawCtx, const GraphicsSystemInfo* gfxInfo, const ModelDrawBufferCounter* bufferCounter, const ModelKeeper* modelKeeper);
    void addModelToTable(ModelCtrl* model);
    void getDrawBufferIndex();
    void createModelDrawDisplayList(s32);
    bool isDraw() const;

    const char* getName() const { return mName; }

public:
    const char* mName; // 0x8 (after vptr)
    agl::DrawContext* mDrawCtx; // 0x10
    const ModelKeeper* mModelKeeper; // 0x18
    const GraphicsSystemInfo* mGraphicsSystemInfo; // 0x20
    const ModelDrawBufferCounter* mModelDrawBufferCounter; // 0x28
    ModelDrawDisplayList* mDrawDisplayList; // 0x30
    s32 mModelMaxNum; // 0x38
    s32 mModelNum; // 0x3c
    ModelCtrl** mModels; // 0x40
    MeshDrawerTable* mMeshDrawerTable; // 0x48
};

static_assert(sizeof(ModelDrawerBase) == 0x50);

}  // namespace al
