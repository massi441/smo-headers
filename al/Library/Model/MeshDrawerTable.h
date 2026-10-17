#pragma once

#include "container/seadPtrArray.h"

namespace al {
    class MeshDrawer;

    class MeshDrawerTable : public sead::PtrArrayImpl {
    public:
        void insert(MeshDrawer* meshDrawer);
    };
}
