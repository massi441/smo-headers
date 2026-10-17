#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "Player/PlayerCeilingCheck.h"
#include "Player/IUsePlayerCollision.h"
#include "Player/PlayerCollider.h"
#include "Player/CollisionShapeKeeper.h"

class PlayerColliderHakoniwa : public IUsePlayerCollision {
public:
    void init();

    void changeCollisionMini();
    void changeCollisionNormal();

public:
    uint8_t _0x0[0x20];              // padding up to 0x20
    al::LiveActor* mActor;           // 0x20
    PlayerConst* mPlayerConst;       // 0x28
    PlayerCollider* mCollider;       // 0x30
    PlayerCeilingCheck* mCeiling;    // 0x38
    uint8_t _0x40[0x30];             // padding
    CollisionShapeKeeper* mKeeper1;  // 0x78
    CollisionShapeKeeper* mKeeper2;  // 0x80
    CollisionShapeKeeper* mKeeper3;  // 0x88
    CollisionShapeKeeper* mKeeper4;  // 0x90
    CollisionShapeKeeper* mKeeper5;  // 0x98
    CollisionShapeKeeper* mKeeper6;  // 0xA0
    CollisionShapeKeeper* mKeeper7; // 0xA8
    CollisionShapeKeeper* mKeeper8; // 0xB0
    void* mFilter2D;                 // 0xB8
    uint8_t _0xC0[0x0];                // 0xB8
};