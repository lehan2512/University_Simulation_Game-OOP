#pragma once
#include "CTask.h"
#include "CPlayer.h"

class CAssessment :
    public CTask
{
private:
    int mYear;

public:
    CAssessment(int type, const string& name, int motivation, int success, int year); // overloading is done implicitly
    int getYear();
    void playerOutput(CPlayer* player) override;
    void playerOutputIfHelped(CPlayer* player) override;
    void affectFriendForHelping(CPlayer* player, CPlayer* helper) override;
};