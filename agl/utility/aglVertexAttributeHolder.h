#pragma once

namespace sead {
    class Heap;
}

namespace agl::utl {
    class aglVertexAttributeHolder {
    public:
        aglVertexAttributeHolder();
        ~aglVertexAttributeHolder();

        void initialize(sead::Heap*);

        static aglVertexAttributeHolder* instance() { return sInstance; }

    private:
        unsigned char mPadding[0x16a8];
        static aglVertexAttributeHolder* sInstance;
    };
}

static_assert(sizeof(agl::utl::aglVertexAttributeHolder) == 0x16a8);