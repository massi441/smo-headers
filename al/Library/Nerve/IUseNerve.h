#pragma once

namespace al {
class NerveKeeper;

class IUseNerve {
public:
    IUseNerve() {}

    virtual NerveKeeper* getNerveKeeper() const = 0;
};
}  // namespace al
