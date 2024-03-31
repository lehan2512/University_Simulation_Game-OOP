#include "CBonus.h"
#include <iostream>

CBonus::CBonus(int type, const string& name) : CBonusBogusManager(type, name) {}

void CBonus::perform(CPlayer* player, int spin)
{
    cout << player->getName() << " lands on Bonus" << endl;
    cout << player->getName() << " spins " << spin << endl;

    // Take action based on the spin result according to the provided table
    switch (spin) {
    case 1:
        player->setMotivation(player->getMotivation() + 20);
        outputMessage(player, "Receive some useful feedback. Gain motivation of 20.");
        break;
    case 2:
        player->setMotivation(player->getMotivation() + 50);
        outputMessage(player, "Win a hackathon. Gain motivation of 50.");
        break;
    case 3:
        player->setMotivation(player->getMotivation() + 80);
        outputMessage(player, "Get a free coffee with full loyalty card. Gain motivation of 80.");
        break;
    case 4:
        player->setMotivation(player->getMotivation() + 100);
        outputMessage(player, "Impress your lecturer in class. Gain motivation of 100.");
        break;
    case 5:
        player->setMotivation(player->getMotivation() + 5);
        outputMessage(player, "Motivational talk from course leader. Gain motivation of 5.");
        break;
    case 6:
        player->setMotivation(player->getMotivation() + 150);
        outputMessage(player, "Secure an industry placement. Gain motivation of 150.");
        break;
    case 7:
        player->setMotivation(player->getMotivation() + 200);
        outputMessage(player, "Attend an inspiring C++ lecture. Gain motivation of 200.");
        break;
    case 8:
        player->setMotivation(player->getMotivation() + 300);
        outputMessage(player, "Get your best ever assignment mark. Gain motivation of 300.");
        break;
    case 9:
        player->setMotivation(player->getMotivation() + 150);
        outputMessage(player, "Make a new romantic friend. Gain motivation of 150.");
        break;
    case 10:
        player->setMotivation(player->getMotivation() + 10);
        outputMessage(player, "Get elected School President. Gain motivation of 10.");
        break;
    }
}

void CBonus::outputMessage(CPlayer* player, const string& message)
{
    cout << message << endl;
    cout << player->getName() << " has " << player->getMotivation() << endl;
}



