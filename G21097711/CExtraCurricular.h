#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CExtraCurricular :
    public CTask
{
public:
    CExtraCurricular(int type, const string& name, int motivationalCost, int successAchieved); // overloading is done implicitly
    void playerOutput(CPlayer* player) override;
    void affectFriendForHelping(CPlayer* player, CPlayer* helper) override;
};

