#pragma once

#include <nn/types.h>
#include <nn/ui2d/Pane.h>

namespace nn::font {
class Font;
class DispStringBuffer;
struct Rectangle;
}

namespace nn::ui2d {

class Material;
class TagProcessor;

class TextBox : public Pane {
public:
    NN_RUNTIME_TYPEINFO(nn::ui2d::Pane);

    TextBox();
    TextBox(bool);

    ~TextBox() override;

    void Initialize();

    // all the number of characters written

    u64 SetString(const char16_t* str, u16 startIdx);
    u64 SetString(const char16_t* str, u16 startIdx, u16 length);
    u64 SetStringUtf8(const char* str, u16 startIdx);
    u64 SetStringUtf8(const char* str, u16 startIdx, u16 length);

    // usable capacity in characters, excluding the null terminator

    u16 GetStringBufferLength() const;
    s32 GetDrawStringBufferLength() const;

    const nn::font::Font* GetFont() const;
    void SetFont(const nn::font::Font*);

    nn::font::Rectangle GetTextDrawRect() const;

    void SetMaterial(Material*);
    void UnsetMaterial();

private:
    char16_t* mStringBuffer;
    u64 _E8;
    u64 _F0;
    const nn::font::Font* mFont;
    f32 mFontSizeX;
    f32 mFontSizeY;
    f32 mLineSpace;
    f32 mCharSpace;
    TagProcessor* mTagProcessor;
    u16 mStringBufferLength;
    u16 mStringLength;
    u8 mFlags;
    u8 _11D;
    u8 mAlignmentFlags;
    bool mIsUtf8;
    u32 _120;
    u32 _124;
    u64 _128;
    u64 _130;
    u64 _138;
    u64 _140;
    u64 _148;
    nn::font::DispStringBuffer* mDispStringBuffer;
    void* mPerCharacterTransform;
};

static_assert(sizeof(TextBox) == 0x160);

}
