#include "CBonusBogusManager.h"

/**
 * @brief Constructor for CBonusBogusManager.
 *
 * This constructor initializes a CBonusBogusManager object with the given attributes, including
 * the type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 *
 * @return None
 */
CBonusBogusManager::CBonusBogusManager( int type, const string& name ) 
	: CSpace( type, name ) {}

/**
 * @brief Virtual function to perform an action associated with the Bonus/Bogus manager space.
 *
 * This function is virtual and intended to be overridden by derived classes to perform an action
 * associated with the Bonus/Bogus manager space, taking into account the spin value.
 *
 * @param player Pointer to the player object.
 * @param spin The value obtained from spinning.
 *
 * @return None
 */
void CBonusBogusManager::PerformTask( CPlayer* player, int spin ) {}

/**
 * @brief Virtual function to output a message associated with the Bonus/Bogus manager space.
 *
 * This function is virtual and intended to be overridden by derived classes to output a message
 * associated with the Bonus/Bogus manager space, customizing the message based on the player and
 * additional information provided.
 *
 * @param player Pointer to the player object.
 * @param message Additional message to be included in the output.
 *
 * @return None
 */
void CBonusBogusManager::GetOutputMessage( CPlayer* player, const string& message ) {}


