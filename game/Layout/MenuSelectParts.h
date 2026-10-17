#pragma once

#include <basis/seadTypes.h>

#include "Library/Nerve/NerveExecutor.h"

namespace al {
class LayoutActor;
class LayoutInitInfo;
class LiveActor;
class KeyRepeatCtrl;
}  // namespace al

class MenuSelectParts : public al::NerveExecutor {
public:
    enum Selection : s32 {
        Continue = 0,
        SeparatePlay = 1,
        NewGame = 2,
        Help = 3,
        Save = 4,
        Setting = 5
    };

    MenuSelectParts(const char* name, al::LayoutActor* layoutActor, al::LiveActor* marioActor,
                    const al::LayoutInitInfo& info, s32 menuItemCount);

    void update();
    void appear(s32 menuItemAmount);
    void startActionPartsIllustSelectIndex();
    void appearWait();
    void setSelectMessage(s32 index, const char16* message);

    bool isDecideContinue() const;
    bool isDecideEnd() const;
    bool isSelectContinue() const;
    bool isDecideSetting() const;
    bool isSelectSetting() const;
    bool isDecideSave() const;
    bool isSelectSave() const;
    bool isDecideSeparatePlay() const;
    bool isSelectSeparatePlay() const;
    bool isDecideHelp() const;
    bool isSelectHelp() const;
    bool isDecideNewGame() const;
    bool isSelectNewGame() const;
    s32 calcPartsIndex(s32 selection) const;

    al::LayoutActor* getFullLayout() const { return mLayoutActor; }
    al::LayoutActor* getLayout(Selection selection) const { return mLayoutArray[selection]; }
    al::LayoutActor* getSelectedLayout() const { return mLayoutArray[this->calcPartsIndex(mCursorItemIndex)]; }

    al::LiveActor* getMarioActor() const { return mMarioActor; }
    al::LiveActor* getCapActor() const { return mCapActor; }

    s32 getSelectedIndex() const { return mCursorItemIndex; }
    s32 getMenuItemCount() const { return mMenuItemAmount; }

    void exeHide();
    void exeAppear();
    void startActionMarioSelectIndex();
    void exeSelect();
    void startActionMario(al::LiveActor* marioActor, const char* actionName);
    void exeDecideParts();
    bool isInvalidSelect() const;
    void exeDecideInterval();
    void exeDecideEnd();

    void setMainMenu(bool isMainMenu) { mIsMainMenu = isMainMenu; }

private:
    al::LayoutActor* mLayoutActor;
    s32 mMenuItemAmount = 0;
    s32 mCursorItemIndex = 0;
    s32 mMax;
    al::LayoutActor** mLayoutArray = nullptr;
    al::LayoutActor* mMenuLayout = nullptr;
    s32 mDefaultIndex = 0;
    al::LiveActor* mMarioActor = nullptr;
    al::LiveActor* mCapActor = nullptr;
    al::KeyRepeatCtrl* mKeyRepeatCtrl = nullptr;
    bool mIsMainMenu = false;
};
