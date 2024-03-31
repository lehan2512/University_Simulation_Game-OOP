#include "CAssessment.h"
#include "CTask.h"
#include <iostream>

// Constructor for CAssessment
CAssessment::CAssessment(int type, const string& name, int motivationalCost, int successAchieved, int year)
    : CTask (type, name, motivationalCost, successAchieved), mYear(year) {}

int CAssessment::getYear() {
    return mYear;
}

// Overrriding player output when completing an assignment
void CAssessment::playerOutput(CPlayer* player)
{
    cout << player->getName() << " completes  " << mName << " for " << getMotivationalCost() << " and achieves " << getSuccessAchieved() << endl;

    if (getYear() == 1)
    {
        player->setYearOneTasks(player->getYearOneTasks() + 1);
    }
    else if (getYear() == 2)
    {
        player->setYearTwoTasks(player->getYearTwoTasks() + 1);
    }
    else
    {
        player->setYearThreeTasks(player->getYearThreeTasks() + 1);
    }
}

// Overriding changes to friend and output message for friend when helped with Assessment
void CAssessment::affectFriendForHelping(CPlayer* player, CPlayer* helper)
{
    // Friend receiving success for helping
    helper->setSuccess(helper->getSuccess() + getSuccessAchieved());
    cout << helper->getName() << " helps and achieves " << getSuccessAchieved() << endl;
}

