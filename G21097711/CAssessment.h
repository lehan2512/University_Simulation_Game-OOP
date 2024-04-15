#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CAssessment :
    public CTask
{
private:
    int mYear = 0;

public:  // Overloading is done implicitly
    CAssessment( int type, const string& name, int motivationalCost, int successAchieved, int year );
    int GetYear();
    void GetPlayerOutput(CPlayer* player) override;
    void AffectFriendForHelping(CPlayer* player) override;
};