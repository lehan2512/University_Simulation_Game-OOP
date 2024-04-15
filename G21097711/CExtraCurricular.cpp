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
CExtraCurricular::CExtraCurricular( int type, const string& name, int motivationalCost, int successAchieved )
    : CTask( type, name, motivationalCost, successAchieved ) {}

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
void CExtraCurricular::GetPlayerOutput( CPlayer* player )
{
    cout << player->GetName() << " undertakes " << GetName() << " for " << GetMotivationalCost() << " and achieves " << GetSuccessAchieved() << endl;
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
void CExtraCurricular::AffectFriendForHelping( CPlayer* player )
{
    // Friend receiving success for helping
    mWhoCompleted[0]->SetMotivation( mWhoCompleted[0]->GetMotivation() - GetMotivationalCost() );
    mWhoCompleted[0]->SetSuccess( mWhoCompleted[0]->GetSuccess() + GetSuccessAchieved() );
    cout << mWhoCompleted[0]->GetName() << " motivates " << player->GetName() << " by joining their activity" << endl;
}
