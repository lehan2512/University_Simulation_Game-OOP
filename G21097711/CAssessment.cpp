#include "CAssessment.h"
#include "CTask.h"
#include <iostream>

/**
 * @brief Constructor for CAssessment.
 *
 * This constructor initializes a CAssessment object with the given attributes, including
 * the type, name, motivational cost, success achieved, and year.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 * @param motivationalCost The motivational cost associated with the task.
 * @param successAchieved The success achieved upon completing the task.
 * @param year The year associated with the assessment.
 *
 * @return None
 */
CAssessment::CAssessment( int type, const string& name, int motivationalCost, int successAchieved, int year )
    : CTask ( type, name, motivationalCost, successAchieved ), mYear( year ) {}

/**
 * @brief Gets the year associated with the assessment.
 *
 * This function retrieves the year associated with the assessment.
 *
 * @param None
 *
 * @return The year associated with the assessment.
 */
int CAssessment::GetYear() 
{
    return mYear;
}

/**
 * @brief Overrides player output when completing an assessment.
 *
 * This function customizes player output when completing an assessment, including
 * displaying the completion message and updating the player's task completion count
 * for the respective year.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CAssessment::GetPlayerOutput( CPlayer* player )
{
    cout << player-> GetName() << " completes  " << mName << " for " << GetMotivationalCost() << " and achieves " << GetSuccessAchieved() << endl;

    if ( GetYear() == 1 )
    {
        player->SetYearOneTasksCompleted(player->GetYearOneTasksCompleted() + 1);
    }
    else if ( GetYear() == 2 )
    {
        player->SetYearTwoTasksCompleted( player->GetYearTwoTasksCompleted() + 1 );
    }
    else
    {
        player->SetYearThreeTasksCompleted( player->GetYearThreeTasksCompleted() + 1 );
    }
}

/**
 * @brief Overrides changes to friend's attributes and output message for friend when helped with assessment.
 *
 * This function customizes changes to the friend's attributes and output message for the friend when helped with assessment.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CAssessment::AffectFriendForHelping( CPlayer* player )
{
    // Friend receiving success for helping
    mWhoCompleted[0]->SetSuccess(mWhoCompleted[0]->GetSuccess() + GetSuccessAchieved());
    cout << mWhoCompleted[0]->GetName() << " helps and achieves " << GetSuccessAchieved() << endl;
}

