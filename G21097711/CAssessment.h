#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CAssessment :
    public CTask
{
private:
    int mYear;

public:
    CAssessment(int type, const string& name, int motivationalCost, int successAchieved, int year); // overloading is done implicitly
    int getYear();
    void playerOutput(CPlayer* player) override;
    void affectFriendForHelping(CPlayer* player) override;
};