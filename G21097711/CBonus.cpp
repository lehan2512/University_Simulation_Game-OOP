#include "CBonus.h"
#include <iostream>

/**
 * @brief Constructor for CBonus.
 *
 * This constructor initializes a CBonus object with the given attributes, including
 * the type and name.
 *
 * @param type The type of the space.
 * @param name The name of the space.
 *
 * @return None
 */
CBonus::CBonus( int type, const string& name ) : CBonusBogusManager( type, name ) {}

/**
 * @brief Perform the action associated with the Bonus space.
 *
 * This function performs the action associated with landing on the Bonus space,
 * based on the spin result. It updates the player's motivation accordingly and
 * outputs a message describing the action and the motivation gained.
 *
 * @param player Pointer to the player object.
 * @param spin The value obtained from spinning.
 *
 * @return None
 */
void CBonus::PerformTask( CPlayer* player, int spin )
{
    cout << player->GetName() << " lands on Bonus" << endl;
    cout << player->GetName() << " spins " << spin << endl;

    // Take action based on the spin result according to the provided table
    switch (spin) 
    {
    case 1:
        player->SetMotivation( player->GetMotivation() + 20 );
        GetOutputMessage( player, "Receive some useful feedback. Gain motivation of 20." );
        break;
    case 2:
        player->SetMotivation( player->GetMotivation() + 50 );
        GetOutputMessage( player, "Win a hackathon. Gain motivation of 50." );
        break;
    case 3:
        player->SetMotivation( player->GetMotivation() + 80 );
        GetOutputMessage( player, "Get a free coffee with full loyalty card. Gain motivation of 80." );
        break;
    case 4:
        player->SetMotivation( player->GetMotivation() + 100 );
        GetOutputMessage( player, "Impress your lecturer in class. Gain motivation of 100." );
        break;
    case 5:
        player->SetMotivation( player->GetMotivation() + 5 );
        GetOutputMessage( player, "Motivational talk from course leader. Gain motivation of 5." );
        break;
    case 6:
        player->SetMotivation( player->GetMotivation() + 150 );
        GetOutputMessage( player, "Secure an industry placement. Gain motivation of 150." );
        break;
    case 7:
        player->SetMotivation( player->GetMotivation() + 200 );
        GetOutputMessage( player, "Attend an inspiring C++ lecture. Gain motivation of 200." );
        break;
    case 8:
        player->SetMotivation( player->GetMotivation() + 300 );
        GetOutputMessage( player, "Get your best ever assignment mark. Gain motivation of 300." );
        break;
    case 9:
        player->SetMotivation( player->GetMotivation() + 150 );
        GetOutputMessage( player, "Make a new romantic friend. Gain motivation of 150." );
        break;
    case 10:
        player->SetMotivation( player->GetMotivation() + 10 );
        GetOutputMessage( player, "Get elected School President. Gain motivation of 10." );
        break;
    }
}

/**
 * @brief Output a message and the player's motivation after landing on the Bonus space.
 *
 * This function outputs the provided message and the player's current motivation after
 * landing on the Bonus space.
 *
 * @param player Pointer to the player object.
 * @param message The message to be displayed.
 *
 * @return None
 */
void CBonus::GetOutputMessage( CPlayer* player, const string& message )
{
    cout << message << endl;
    cout << player->GetName() << " has " << player->GetMotivation() << endl;
}



