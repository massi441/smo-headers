#pragma once

namespace nn::g3d {
    class ResFile;
}

namespace nn::gfx {
    class ResTexture;
    class ResTextureFile;
}

namespace agl::g3d {
    class ResFile {
    public:
        static nn::gfx::ResTexture* GetTexture(const nn::g3d::ResFile* resFile, int idx);
        static nn::gfx::ResTexture* GetTexture(nn::g3d::ResFile* resFile, int idx);
        static nn::gfx::ResTexture* GetTexture(const nn::g3d::ResFile* resFile, const char* textureName);
        static nn::gfx::ResTexture* GetTexture(nn::g3d::ResFile* resFile, const char* textureName);
        static nn::gfx::ResTextureFile* GetResTextureFile(const nn::g3d::ResFile*);
        static nn::gfx::ResTextureFile* GetResTextureFile(nn::g3d::ResFile*);
        static bool BinTexture(nn::g3d::ResFile*, nn::g3d::ResFile*);
        static const char* GetTextureName(const nn::g3d::ResFile* resFile, int idx);
        static int GetTextureCount(const nn::g3d::ResFile* resFile);
        static int GetTextureIndex(const nn::g3d::ResFile* resFile, const char* textureName);
        static void Setup(nn::g3d::ResFile* resFile);
        static void Cleanup(nn::g3d::ResFile* resFile);
    };
}
