#include "CSkipClasses.h"
#include "CSpace.h"
#include <iostream>

CSkipClasses::CSkipClasses(int type, const string& name) : CSpace(type, name) {}

void CSkipClasses::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Skip Classes and hangs out with their dodgy mates" << endl;
}

void CSkipClasses::perform(CPlayer* player)
{
	outputMessage(player);
}
