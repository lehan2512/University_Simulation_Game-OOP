#include "CTask.h"
#include "CSpace.h"
#include <iostream>

// Constructor for CTask overloaded by the attributes of constructor in CSpace
CTask::CTask(int type, const string& name, int motivationalCost, int successAchieved)
	: CSpace(type, name), mMotivationalCost(motivationalCost), mSuccessAchieved(successAchieved), vyvyanCompleted(false), rickCompleted(false), receivedHelp(false) {}

// Function to show that player recieved help
void CTask::setReceivedHelp(bool isFalse)
{
    receivedHelp = isFalse;
}

// Getter methods
int CTask::getMotivationalCost() {
    return mMotivationalCost;
}

int CTask::getSuccessAchieved() {
    return mSuccessAchieved;
}

// Function to check if player revieved help
bool CTask::getReceivedHelp()
{
    return receivedHelp;
}

// Function to output message when player lands on a square
void CTask::outputMessage(CPlayer* player)
{
    cout << player->getName() << " lands on " << mName << endl;
}

// Function to perform effects of assessment on player
void CTask::perform(CPlayer* player, CPlayer* helper) {
    int playerIndex = -1; // Index of the player who landed on the assessment

    // Determine the player's index (0 for Vyvyan, 1 for Rick) to keep track of which player is currently on the space
    if (player->getName() == "Vyvyan") {
        playerIndex = 0;
    }
    else if (player->getName() == "Rick") {
        playerIndex = 1;
    }

    // If assessment has not been completed by anyone
    if (!vyvyanCompleted && !rickCompleted)
    {
        if (player->getMotivation() > mMotivationalCost) //Checking if player has enough motivation to do task
        {
            outputMessage(player);

            // Changes to player attributes
            player->setMotivation(player->getMotivation() - mMotivationalCost);
            player->setSuccess(player->getSuccess() + mSuccessAchieved);

            // Mark the assessment as completed by the player
            if (playerIndex == 0)
            {
                vyvyanCompleted = true;
            }
            else
            {
                rickCompleted = true;
            }
            playerOutput(player);
            

            //reduce the motivational cost and success achieved from the task so that when another player comes to this task, they receive half and helper receives half
            mMotivationalCost = mMotivationalCost / 2;
            mSuccessAchieved = mSuccessAchieved / 2;
        }
        else
        {
            cout << player->getName() << " doesn't have the " << mMotivationalCost << " motivation to complete the " << mName << endl;
        }
        
    }
    //If assessment has not been completed by the player who landed on it but completed by another player
    else if ((playerIndex == 0 && !vyvyanCompleted) || (playerIndex == 1 && !rickCompleted))
    {
        if (player->getMotivation() > mMotivationalCost)    // Checking if player has enough motivation to perform task
        {
            outputMessage(player);

            //Note that motivationalCost and successAchieved are now half of actual value since one player has already completed task
            int landedPlayerMotivation = player->getMotivation();
            player->setMotivation(landedPlayerMotivation - mMotivationalCost);
            player->setSuccess(player->getSuccess() + mSuccessAchieved);

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

            //Friend's attributes are affected as he helped
            affectFriendForHelping(player, helper);
        }
    }
    else
    {
        outputMessage(player);  // If player has already completed the task or does not have enough motivation to do the task, simply outputs space landed on
    }
}

void CTask::playerOutput(CPlayer* player) {} // As mentioned in header file this function is to be overrridden in derived classes

void CTask::affectFriendForHelping(CPlayer*, CPlayer*) {} // As mentioned in header file this function is to be overrridden in derived classes

