#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CExtraCurricular :
    public CTask
{
public:
    CExtraCurricular(int type, const string& name, int motivation, int success); // overloading is done implicitly
    void playerOutput(CPlayer* player) override;
    void affectFriendForHelping(CPlayer* player, CPlayer* helper) override;
};

