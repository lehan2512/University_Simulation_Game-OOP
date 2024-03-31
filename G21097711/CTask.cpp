#include "CTask.h"
#include "CSpace.h"
#include <iostream>

CTask::CTask(int type, const string& name, int motivation, int success)
	: CSpace(type, name), mMotivationalCost(motivation), mSuccess(success), vyvyanCompleted(false), rickCompleted(false), receivedHelp(false) {}

void CTask::setReceivedHelp(bool isFalse)
{
    receivedHelp = isFalse;
}

// Getter methods
int CTask::getMotivation() {
    return mMotivationalCost;
}

int CTask::getSuccess() {
    return mSuccess;
}

bool CTask::getReceivedHelp()
{
    return receivedHelp;
}

void CTask::outputMessage(CPlayer* player)
{
    cout << player->getName() << " lands on " << mName << endl;
}

// Method to apply effects of assessment on player
void CTask::perform(CPlayer* player, CPlayer* helper) {
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
            playerOutput(player);

            affectFriendForHelping(player, helper);
        }
    }
    else
    {
        outputMessage(player);  // If player has already completed the task or does not have enough motivation to do the task, outputs space landed on
    }
}

void CTask::playerOutput(CPlayer* player) {}

void CTask::affectFriendForHelping(CPlayer*, CPlayer*) {}
