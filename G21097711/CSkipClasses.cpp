#include "CSkipClasses.h"
#include "CSpace.h"
#include <iostream>

CSkipClasses::CSkipClasses(int type, const string& name) : CSpace(type, name) {}

// Function to output what happens to player
void CSkipClasses::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

void CSkipClasses::perform(CPlayer* player)
{
	outputMessage(player);
}
