#include "CExtraCurricular.h"
#include "CTask.h"
#include <iostream>

/**
 * @brief Constructor for CExtraCurricular.
 *
 * This constructor initializes a CExtraCurricular object with the given attributes, including
 * the type, name, motivational cost, and success achieved.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 * @param motivationalCost The motivational cost associated with the extra-curricular activity.
 * @param successAchieved The success achieved upon completing the extra-curricular activity.
 *
 * @return None
 */
CExtraCurricular::CExtraCurricular(int type, const string& name, int motivationalCost, int successAchieved)
    : CTask(type, name, motivationalCost, successAchieved) {}

/**
 * @brief Overrides player output when completing an extra-curricular activity.
 *
 * This function customizes player output when completing an extra-curricular activity, including
 * displaying the completion message.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CExtraCurricular::playerOutput(CPlayer* player)
{
    cout << player->getName() << " undertakes " << getName() << " for " << getMotivationalCost() << " and achieves " << getSuccessAchieved() << endl;
}


/**
 * @brief Overrides changes to friend's attributes and output message for friend when helped with extra-curricular activity.
 *
 * This function customizes changes to the friend's attributes and output message for the friend when helped with extra-curricular activity.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CExtraCurricular::affectFriendForHelping(CPlayer* player)
{
    // Friend receiving success for helping
    mWhoCompleted[0]->setMotivation(mWhoCompleted[0]->getMotivation() - getMotivationalCost());
    mWhoCompleted[0]->setSuccess(mWhoCompleted[0]->getSuccess() + getSuccessAchieved());
    cout << mWhoCompleted[0]->getName() << " motivates " << player->getName() << " by joining their activity" << endl;
}
