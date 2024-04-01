#include "CBogus.h"
#include <iostream>

/**
 * @brief Constructor for CBogus.
 *
 * This constructor initializes a CBogus object with the given attributes, including
 * the type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 *
 * @return None
 */
CBogus::CBogus(int type, const string& name) : CBonusBogusManager(type, name) {}

/**
 * @brief Perform the action associated with the Bogus space.
 *
 * This function performs the action associated with landing on the Bogus space,
 * based on the spin result. It updates the player's motivation accordingly and
 * outputs a message describing the action and the motivation lost.
 *
 * @param player Pointer to the player object.
 * @param spin The value obtained from spinning.
 *
 * @return None
 */
void CBogus::perform(CPlayer* player, int spin)
{
    cout << player->getName() << " lands on Bogus" << endl;
    cout << player->getName() << " spins " << spin << endl;

    // Take action based on the spin result according to the provided table
    switch (spin) {
    case 1:
        player->setMotivation(player->getMotivation() - 20);
        outputMessage(player, "Fall asleep in a boring lecture. Lost motivation of 20");
        break;
    case 2:
        player->setMotivation(player->getMotivation() - 50);
        outputMessage(player, "Meet with coach about poor attendance. Lost motivation of 50");
        break;
    case 3:
        player->setMotivation(player->getMotivation() - 80);
        outputMessage(player, "Feel really tired after a night out. Lost motivation of 80");
        break;
    case 4:
        player->setMotivation(player->getMotivation() - 100);
        outputMessage(player, "Get kicked out of lab for messing about. Lost motivation of 100");
        break;
    case 5:
        player->setMotivation(player->getMotivation() - 150);
        outputMessage(player, "Get dumped before a big night out. Lost motivation of 150");
        break;
    case 6:
        player->setMotivation(player->getMotivation() - 200);
        outputMessage(player, "Fail an assignment. Lost motivation of 200");
        break;
    case 7:
        player->setMotivation(player->getMotivation() - 50);
        outputMessage(player, "Get caught skipping class. Lost motivation of 50");
        break;
    case 8:
        player->setMotivation(player->getMotivation() - 200);
        outputMessage(player, "Your friend drops out of uni. Lost motivation of 200");
        break;
    case 9:
        player->setMotivation(player->getMotivation() - 300);
        outputMessage(player, "Nobody turns up to teach your class. Lost motivation of 300");
        break;
    case 10:
        player->setMotivation(player->getMotivation() - 20);
        outputMessage(player, "Lecturer changes assignment schedule. Lost motivation of 20");
        break;
    }

}

/**
 * @brief Output a message and the player's motivation after landing on the Bogus space.
 *
 * This function outputs the provided message and the player's current motivation after
 * landing on the Bogus space.
 *
 * @param player Pointer to the player object.
 * @param message The message to be displayed.
 *
 * @return None
 */
void CBogus::outputMessage(CPlayer* player, const string& message)
{
    cout << message << endl;
    cout << player->getName() << " has " << player->getMotivation() << endl;
}


