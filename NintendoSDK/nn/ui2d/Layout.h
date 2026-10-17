/**
 * @file Layout.h
 * @brief UI Layout implementation.
 */

#pragma once

#include <nn/types.h>

namespace nn::ui2d {

class AnimTransform;
class Pane;

class Layout {
public:
    Layout();

    virtual ~Layout();

    virtual void DeleteAnimTransform(AnimTransform*);
    virtual void BindAnimation(AnimTransform*);
    virtual void UnbindAnimation(AnimTransform*);
    virtual void UnbindAnimation(Pane*);
    virtual void UnbindAllAnimation();

    virtual void Animate();
    virtual void UpdateAnimFrame(f32 frame);
    virtual void AnimateAndUpdateAnimFrame(f32 frame);

    Pane* GetRootPane() const { return mPane; }

    static void SetAllocator(void* (*)(size_t, size_t, void*), void (*)(void*, void*), void*);
    static void AllocateMemory(size_t, size_t);
    static void AllocateMemory(size_t);
    static void FreeMemory(void* src);

    Pane* GetPane() const { return mPane; }

private:
    Layout* mPrev; // 0x08
    Layout* mNext; // 0x10
    Pane* mPane; // 0x18
    u64 _20;
    f32 _28;
    f32 _2c;
    u64 _30;

    u64 _40;
    Layout* mPrev2; // 0x48
    Layout* mNext2; // 0x50
    u64 _58;
    u64 _60;

    static void* g_pAllocateFunction;
    static void* g_pFreeFunction;
};

}  // namespace nn
