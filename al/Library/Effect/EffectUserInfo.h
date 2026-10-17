#pragma once

namespace al {
    class EffectHitReactionInfo;
    struct EffectInfo;

    class EffectUserInfo {
    public:
        EffectUserInfo();

        EffectInfo* tryFindEffectInfo(const char*) const;
        EffectHitReactionInfo * tryFindHitReactionInfo(const char*) const;

    private:
        void* mUnk1 = nullptr;
        void* mUnk2 = nullptr;
        void* mUnk3 = nullptr;
        void* mUnk4 = nullptr;
        void* mUnk5 = nullptr;
        void* mUnk6 = nullptr;
    };
}

static_assert(sizeof(al::EffectUserInfo) == 0x30);
