#include "CExtraCurricular.h"
#include "CSpace.h"
#include "CTask.h"
#include <iostream>

// Constructor for CExtraCurricular
CExtraCurricular::CExtraCurricular(int type, const string& name, int motivation, int success)
    : CTask(type, name, motivation, 20) {}

void CExtraCurricular::playerOutput(CPlayer* player)
{
    cout << player->getName() << " undertakes " << getName() << " for " << getMotivation() << " and achieves " << getSuccess() << endl;
}

void CExtraCurricular::playerOutputIfHelped(CPlayer* player)
{
    cout << player->getName() << " undertakes " << getName() << " for " << getMotivation() / 2 << " and achieves " << getSuccess() / 2 << endl;
}

void CExtraCurricular::affectFriendForHelping(CPlayer* player, CPlayer* helper)
{
    // Friend receiving success for helping
    helper->setMotivation(helper->getMotivation() - (getMotivation() / 2));
    helper->setSuccess(helper->getSuccess() + (getSuccess() / 2));
    cout << helper->getName() << " motivates " << player->getName() << " by joining their activity" << endl;
}
