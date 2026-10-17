#pragma once

#include "Library/HostIO/HioNode.h"
#include "Library/Nerve/IUseNerve.h"

namespace al {

class Nerve;
class NerveKeeper;

class NerveExecutor : public IUseNerve, public HioNode {
public:
    NerveExecutor() = default;
    NerveExecutor(const char* name);

    NerveKeeper* getNerveKeeper() const override { return mKeeper; }

    virtual ~NerveExecutor();

    void initNerve(const Nerve* nerve, int stateCount = 0);
    void updateNerve();

private:
    NerveKeeper* mKeeper = nullptr;
};

}
