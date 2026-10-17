#pragma once

namespace al {
class ExecuteDirector;
class PlacementId;
class StageSwitchAccesser;
class StageSwitchDirector;
class StageSwitchListener;
class PlacementInfo;
class IUseStageSwitch;
class FunctorBase;
class IUseName;

struct StageSwitchAccesserList {
    StageSwitchAccesserList();
    StageSwitchAccesserList(const StageSwitchAccesser* accessers);

    const StageSwitchAccesser* accessers = nullptr;
    int accesserSize = 0;
    int accesserCapacity = 0;
};

class StageSwitchKeeper {
public:
    StageSwitchKeeper();
    void init(StageSwitchDirector* director, const PlacementInfo& placementInfo);
    StageSwitchAccesser* tryGetStageSwitchAccesser(const char* linkName) const;

    void setUseName(IUseName* useName) { mUseName = useName; }

    // custom funcs

    IUseName* getUseName() const { return mUseName; }
    int getAccessersCount() const { return mAccesserCount; }
    StageSwitchAccesser* getAccessers() const { return mAccessers;}

private:
    StageSwitchAccesser* mAccessers = nullptr;
    int mAccesserCount = 0;
    IUseName* mUseName = nullptr;
};

}  // namespace al
