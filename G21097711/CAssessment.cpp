#include "CAssessment.h"
#include "CSpace.h"
#include "CTask.h"
#include <iostream>

// Constructor for CAssessment
CAssessment::CAssessment(int type, const string& name, int motivation, int success, int year)
    : CTask (type, name, motivation, success), mYear(year) {}

int CAssessment::getYear() {
    return mYear;
}

void CAssessment::playerOutput(CPlayer* player)
{
    cout << player->getName() << " completes  " << mName << " for " << getMotivation() / 2 << " and achieves " << getSuccess() / 2 << endl;
}

void CAssessment::affectFriendForHelping(CPlayer* player, CPlayer* helper)
{
    // Friend receiving success for helping
    helper->setSuccess(helper->getSuccess() + (getSuccess() / 2));
    cout << helper->getName() << " helps and achieves " << getSuccess() / 2 << endl;
}

