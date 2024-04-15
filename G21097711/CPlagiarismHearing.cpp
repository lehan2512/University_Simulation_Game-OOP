#include "CPlagiarismHearing.h"
#include "CSpace.h"
#include <iostream>

/**
 * @brief Constructor for CPlagiarismHearing.
 *
 * This constructor initializes a CPlagiarismHearing object with the given attributes, including
 * the type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 *
 * @return None
 */
CPlagiarismHearing::CPlagiarismHearing( int type, const string& name ): 
	CSpace(type, name) {}


/**
 * @brief Overrides output message for landing on Plagiarism Hearing.
 *
 * This function customizes the output message when a player lands on the Plagiarism Hearing space.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CPlagiarismHearing::GetOutputMessage( CPlayer* player )
{
	cout << player->GetName() << " lands on Plagiarism Hearing and supports their friend" << endl;
}


/**
 * @brief Performs the action associated with the Plagiarism Hearing space.
 *
 * This function performs the action associated with the Plagiarism Hearing space, which
 * in this case is simply outputting a message indicating that the player has landed on
 * the Plagiarism Hearing space and is supporting their friend.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CPlagiarismHearing::PerformTask( CPlayer* player )
{
	GetOutputMessage(player);
}

