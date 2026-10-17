#pragma once

#include "exl/types.h"
#include "nvn/nvn.h"

namespace sead {
    class Heap;
}

namespace agl {
    class DrawContext;
    class ShaderLocation;
    struct GPUMemVoidAddr;

    class UniformBlock {
    public:
        // TODO: Validate
        enum class Type : u32 {
            Float = 0,
            Vec2 = 4,
            Vec3 = 5,
            Vec4 = 6,
        };

        UniformBlock();

        virtual ~UniformBlock();
        virtual void invalidateGPUCache(agl::DrawContext*, int) const;
        virtual void* getStrideArray_(uchar) const;
        virtual ulong getBlockAlignment_() const; // returns 0x100
        virtual uint getBlockSizeMax_() const; // returns 0x10000
        virtual uint verifyStructSize_(uint) const; // returns param? weird
        virtual void bindBufferNVN_(NVNcommandBuffer*, NVNshaderStage, int, ulong, ulong) const;

        void writeMemory(uint*, uint*, int, int, int, const void*);
        void createDirect(GPUMemVoidAddr, ulong);
        void startDeclare(int, sead::Heap*);
        void createWithBuffer(GPUMemVoidAddr, int, int);
        void createWithoutBuffer();
        void fill(uint, int);
        void create(sead::Heap*, int, int);
        void declare(const UniformBlock&);
        void destroy();
        void declare_(Type, int, ulong, ulong);
        void setBuffer(GPUMemVoidAddr, int, int);

        void* setUniform(agl::DrawContext*, const ulong&, const agl::ShaderLocation&, uint, ulong blockSize) const;
        void copyPartialTo(agl::UniformBlock*, int, int, int, int, int, int) const;
        void setDataStruct_(void*, int, void const*, int, int, uint) const;
        long calcRequiredBufferSize(int, int) const;
        void dcbz(int) const;
        void dcbz(uint, int) const;
        void setData_(void* mBuffer, int uniformIdx, void const* data, int unk1, int amount) const; //unk = 0
        void copyAllTo(agl::UniformBlock*, int, int) const;

    public:
        u8 mPadToBuffer[0x08];   // 0x08
        void* mBuffer;           // 0x10
        u32 mBlockSize;          // 0x18
        u32 mBufferAlignment;    // 0x1c
        u8 _20[0x1d];            // 0x20
        u8 mSomeIdx;             // 0x3d
        u8 _3e;                  // 0x3e
        u8 _3f;                  // 0x3f
        u8 _40;                  // 0x40
        u8 mBufferIndex;         // 0x41
        u8 _42;                  // 0x42
        u8 _43;                  // 0x43
        u16 mBufferStride;       // 0x44
        u8 _46[0x02];            // 0x46
        NVNbuffer mNvnBuffer;    // 0x48
    };
}

static_assert(sizeof(agl::UniformBlock) == 0x78);
