#include "CSpace.h"

using namespace std;

/**
 * @brief Constructor for the CSpace class.
 *
 * This constructor initializes a CSpace object with the given type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 *
 * @return None
 */
CSpace::CSpace(int type, const string name) : mType(type), mName(name) {}   // Constructer initializes name and type the space


/**
 * @brief Sets the type of the space.
 *
 * This function sets the type of the space.
 *
 * @param type The type of the space.
 *
 * @return None
 */
void CSpace::setType(int type) {
    mType = type;
}


/**
 * @brief Sets the name of the space.
 *
 * This function sets the name of the space.
 *
 * @param name The name of the space.
 *
 * @return None
 */
void CSpace::setName(const string name) {
    mName = name;
}

/**
 * @brief Gets the type of the space.
 *
 * This function retrieves the type of the space.
 *
 * @param None
 *
 * @return The type of the space.
 */
int CSpace::getType() const {
    return mType;
}

/**
 * @brief Gets the name of the space.
 *
 * This function retrieves the name of the space.
 *
 * @param None
 *
 * @return The name of the space.
 */
string CSpace::getName() const {
    return mName;
}

/**
 * @brief Outputs the name of the space landed on by player.
 *
 * This function is virtual and is overridden by derived classes.
 * It outputs the name of the space landed on by player.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CSpace::outputMessage(CPlayer*) {}

/**
 * @brief Virtual function to be overridden by derived classes to perform changes to player's attributes when landing on this space.
 *
 * This function is intended to be overridden by derived classes to perform changes
 * to player's attributes when landing on this space.
 *
 * @param player Pointer to the player object.
 *
 * @return None
 */
void CSpace::perform(CPlayer*) {}


