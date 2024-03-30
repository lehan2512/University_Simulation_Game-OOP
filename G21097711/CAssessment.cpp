#include "CAssessment.h"
#include "CSpace.h"
#include <iostream>

// Constructor for CAssessment
CAssessment::CAssessment(int type, const string& name, int motivation, int success, int year)
    : CSpace(type, name), mMotivationalCost(motivation), mSuccess(success), mYear(year), vyvyanCompleted(false), rickCompleted(false) {
}






void CAssessment::setYear(int year) {
    mYear = year;
}

void CAssessment::setVyvyanCompleted(bool completed) {
    vyvyanCompleted = completed;
}

void CAssessment::setRickCompleted(bool completed) {
    rickCompleted = completed;
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

bool CAssessment::getVyvyanCompleted() {
    return vyvyanCompleted;
}

bool CAssessment::getRickCompleted() {
    return rickCompleted;
}

/*
// Method to output message
void CAssessment::outputMessage(CPlayer* player) {
    std::cout << "Output message: " << getMessage() << std::endl; // Assuming getMessage() is a method in CSpace class
}
*/

// Method to apply effects of assessment on player
bool CAssessment::effect(CPlayer* player) {
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
        return false;

    }
    else if ((playerIndex == 0 && !vyvyanCompleted) || (playerIndex == 1 && !rickCompleted))
    {
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
        cout << player->getName() << " completes  " << mName << " for " << mMotivationalCost / 2 << " and achieves " << mSuccess / 2 << endl;
        return true;
    }
    else 
    {
        return false;
    }
}

