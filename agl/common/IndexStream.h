#pragma once

namespace agl {
    class GPUMemAddrBase;

    class IndexStream {
    public:
        IndexStream();

    private:
        //NVNbuffer somwhere
        // 0x10 GPUMemAddrBase
        const char mPadding[0x60];
    };
}

static_assert(sizeof(agl::IndexStream) == 0x60);
