#include "CSkipClasses.h"
#include "CSpace.h"
#include <iostream>

/**
 * @brief Constructor for CSkipClasses class.
 *
 * This constructor initializes a CSkipClasses object with the specified type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 */
CSkipClasses::CSkipClasses(int type, const string& name) : CSpace(type, name) {}

/**
 * @brief Overriden function that Output a message when a player lands on the Skip Classes space.
 *
 * This function outputs a message indicating that the player has landed on the Skip Classes space
 * and hangs out with their dodgy mates.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CSkipClasses::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

/**
 * @brief Overridden function that Perform actions when a player lands on the Skip Classes space.
 *
 * This function simply outputs a message indicating that the player has landed on the Skip Classes space.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CSkipClasses::perform(CPlayer* player)
{
	outputMessage(player);
}
