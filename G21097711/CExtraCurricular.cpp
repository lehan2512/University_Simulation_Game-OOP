#include "CExtraCurricular.h"
#include "CTask.h"
#include <iostream>

// Constructor for CExtraCurricular
CExtraCurricular::CExtraCurricular(int type, const string& name, int motivationalCost, int successAchieved)
    : CTask(type, name, motivationalCost, successAchieved) {}

// Overrriding player output when completing an Extra-curricular activity
void CExtraCurricular::playerOutput(CPlayer* player)
{
    cout << player->getName() << " undertakes " << getName() << " for " << getMotivationalCost() << " and achieves " << getSuccessAchieved() << endl;
}

// Overriding changes to friend and output message for friend when helped with Extra-curricular activity
void CExtraCurricular::affectFriendForHelping(CPlayer* player, CPlayer* helper)
{
    // Friend receiving success for helping
    helper->setMotivation(helper->getMotivation() - getMotivationalCost());
    helper->setSuccess(helper->getSuccess() + getSuccessAchieved());
    cout << helper->getName() << " motivates " << player->getName() << " by joining their activity" << endl;
}
