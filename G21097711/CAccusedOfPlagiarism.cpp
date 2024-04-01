#include "CAccusedOfPlagiarism.h"
#include "CSpace.h"
#include <iostream>

/**
 * @brief Constructor for CAccusedOfPlagiarism class.
 *
 * This constructor initializes a CAccusedOfPlagiarism object with the specified type, name, and motivational cost.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 * @param motivationalCost The motivational cost associated with landing on this space.
 */
CAccusedOfPlagiarism::CAccusedOfPlagiarism(int type, const string& name, int motivationalCost) 
	: CSpace(type, name), mMotivationalCost(motivationalCost) {}


/**
 * @brief Overriden function that Output a message when a player lands on the Accused of Plagiarism space.
 *
 * This function outputs a message indicating that the player has landed on the Accused of Plagiarism space
 * and their motivation decreases.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CAccusedOfPlagiarism::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Accused of Plagiarism and goes to hearing" << endl;
	cout << player->getName() << " loses motivation" << endl;
}

/**
 * @brief Overrided function that Perform changes to player attributes when landing on the Accused of Plagiarism space.
 *
 * This function sets the player's position to the Plagiarism Hearing space and reduces their motivation.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CAccusedOfPlagiarism::perform(CPlayer* player)
{
	const int positionOfPlagiarismHearing = 32;
	// Set player position to Plagerism Hearing and reduction motivation
	player->setPosition(positionOfPlagiarismHearing);
	player->setMotivation(player->getMotivation() - mMotivationalCost);
	outputMessage(player);
}
