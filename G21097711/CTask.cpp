#include "CTask.h"
#include "CSpace.h"
#include <iostream>

/**
 * @brief Constructor for CTask.
 *
 * This constructor initializes a CTask object with the given attributes, including
 * the type, name, motivational cost, and success achieved.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 * @param motivationalCost The motivational cost associated with the task.
 * @param successAchieved The success achieved upon completing the task.
 *
 * @return None
 */
CTask::CTask(int type, const string& name, int motivationalCost, int successAchieved)
	: CSpace(type, name), mMotivationalCost(motivationalCost), mSuccessAchieved(successAchieved), vyvyanCompleted(false), rickCompleted(false), mReceivedHelp(false) {}

/**
 * @brief Sets whether the player received help for the task.
 *
 * This function sets whether the player received help for the task.
 *
 * @param isFalse Flag indicating whether the player received help (true) or not (false).
 *
 * @return None
 */
void CTask::setReceivedHelp(bool isFalse)
{
    mReceivedHelp = isFalse;
}

/**
 * @brief Gets the motivational cost associated with the task.
 *
 * This function retrieves the motivational cost associated with the task.
 *
 * @param None
 *
 * @return The motivational cost associated with the task.
 */
int CTask::getMotivationalCost() {
    return mMotivationalCost;
}

/**
 * @brief Gets the success achieved upon completing the task.
 *
 * This function retrieves the success achieved upon completing the task.
 *
 * @param None
 *
 * @return The success achieved upon completing the task.
 */
int CTask::getSuccessAchieved() {
    return mSuccessAchieved;
}

/**
 * @brief Checks whether the player received help for the task.
 *
 * This function checks whether the player received help for the task.
 *
 * @param None
 *
 * @return True if the player received help, false otherwise.
 */
bool CTask::getReceivedHelp()
{
    return mReceivedHelp;
}

/**
  * @brief Outputs a message related to the task space.
  *
  * This function outputs a message indicating that a player has landed on the task space.
  *
  * @param player Pointer to the player object.
  *
  * @return None
  */
void CTask::outputMessage(CPlayer* player)
{
    cout << player->getName() << " lands on " << mName << endl;
}


/**
  * @brief Overridden function to Performs the task associated with the derived spaces.
  *
  * checking if the player has enough motivationto complete the task, updating player attributes accordingly,
  * and keeping track of which player has completed the task.
  *
  * @param player Pointer to the player object.
  *
  * @return None
  */
void CTask::perform(CPlayer* player) {
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
            mWhoCompleted.push_back(player);
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
            mReceivedHelp = true;

            playerOutput(player);

            //Friend's attributes are affected as he helped
            affectFriendForHelping(player);
        }
    }
    else
    {
        outputMessage(player);  // If player has already completed the task or does not have enough motivation to do the task, simply outputs space landed on
    }
}

/**
 * @brief Outputs player information after completing the task.
 *
 * This function is virtual and overridden by derived classes to customize player output
 * after completing the task.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CTask::playerOutput(CPlayer* player) {} // As mentioned in header file this function is to be overrridden in derived classes

/**
 * @brief Performs changes to the friend's attributes for helping.
 *
 * This function is virtual and intended to be overridden by derived classes to customize
 * changes to the friend's attributes for helping.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CTask::affectFriendForHelping(CPlayer*) {} // As mentioned in header file this function is to be overrridden in derived classes

