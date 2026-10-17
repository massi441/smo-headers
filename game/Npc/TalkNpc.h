#pragma once

#include "Library/LiveActor/LiveActor.h"

namespace al {
    class EventFlowEventData;
}

class TalkNpc : public al::LiveActor {
public:
    TalkNpc(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void movement() override;
    void updateCollider() override;
    void endClipped() override;
    void kill() override;
    void calcAnim() override;

    bool receiveEvent(const al::EventFlowEventData* eventData);
    void startDemoKoopa(const sead::Vector3f&);
    void endDemoKoopa();
    void onFukankunCameraNearClipSetting();
    void offFukankunCameraNearClipSetting();

    void exeDemoKoopa();
    void exeHackEvent();
    void exeKinopioBrigadeFirstEvent();
    void exeEvent();

private:
    unsigned char mPadding[0x238 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TalkNpc) == 0x238);
