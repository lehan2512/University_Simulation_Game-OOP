#include "CAssessment.h"
#include "CSpace.h"
#include <iostream>

// Constructor for CAssessment
CAssessment::CAssessment(int type, const string& name, int motivation, int success, int year)
    : CSpace(type, name), mMotivationalCost(motivation), mSuccess(success), mYear(year), vyvyanCompleted(false), rickCompleted(false), receivedHelp(false) {
}

void CAssessment::setYear(int year) {
    mYear = year;
}

void CAssessment::setReceivedHelp(bool isFalse)
{
    receivedHelp = isFalse;
}

// Getter methods
int CAssessment::getMotivation() {
    return mMotivationalCost;
}

int CAssessment::getSuccess() {
    return mSuccess;
}

int CAssessment::getYear() {
    return mYear;
}

bool CAssessment::getReceivedHelp()
{
    return receivedHelp;
}

void CAssessment::outputMessage(CPlayer* player) 
{
    cout << player->getName() << " lands on " << mName << endl;
}


// Method to apply effects of assessment on player
void CAssessment::perform(CPlayer* player, CPlayer* helper) {
    int playerIndex = -1; // Index of the player who landed on the assessment

    // Determine the player's index (0 for Vyvyan, 1 for Rick)
    if (player->getName() == "Vyvyan") {
        playerIndex = 0;
    }
    else if (player->getName() == "Rick") {
        playerIndex = 1;
    }

    // If assessment has not been completed by anyone
    if (!vyvyanCompleted && !rickCompleted)
    {
        if (player->getMotivation() >= mMotivationalCost)
        {
            outputMessage(player);

            // If player has enough motivation to complete the assessment
            player->setMotivation(player->getMotivation() - mMotivationalCost);
            player->setSuccess(player->getSuccess() + mSuccess);

            // Mark the assessment as completed by the player
            if (playerIndex == 0)
            {
                vyvyanCompleted = true;
            }
            else
            {
                rickCompleted = true;
            }
            cout << player->getName() << " completes  " << mName << " for " << mMotivationalCost << " and achieves " << mSuccess << endl;
        }

    }
    else if ((playerIndex == 0 && !vyvyanCompleted) || (playerIndex == 1 && !rickCompleted))
    {
        if (player->getMotivation() >= mMotivationalCost)
        {
            outputMessage(player);

            // If assessment has not been completed by the player who landed on it
            int landedPlayerMotivation = player->getMotivation(); // Halve the motivation cost
            player->setMotivation(landedPlayerMotivation - mMotivationalCost / 2);
            player->setSuccess(player->getSuccess() + mSuccess / 2);

            if (playerIndex == 0)
            {
                vyvyanCompleted = true;
            }
            else
            {
                rickCompleted = true;
            }
            receivedHelp = true;
            cout << player->getName() << " completes  " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccess / 2 << endl;

            // Friend receiving success for helping
            helper->setSuccess(helper->getSuccess() + (mSuccess / 2));
            cout << helper->getName() << " helps and achieves " << mSuccess / 2 << endl;
        } 
    }
    else 
    {
        outputMessage(player);  // If player has already completed the task or does not have enough motivation to do the task, outputs space landed on
    }
}

