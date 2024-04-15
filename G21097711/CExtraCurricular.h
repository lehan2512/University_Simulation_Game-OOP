#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CExtraCurricular :
    public CTask
{
public:  // overloading is done implicitly
    CExtraCurricular(int type, const string& name, int motivationalCost, int successAchieved);
    void GetPlayerOutput(CPlayer* player) override;
    void AffectFriendForHelping(CPlayer* player) override;
};

