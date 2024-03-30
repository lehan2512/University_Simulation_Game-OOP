#include "CPlagiarismHearing.h"
#include "CSpace.h"
#include <iostream>

CPlagiarismHearing::CPlagiarismHearing(int type, const string& name): CSpace(type, name) {}

void CPlagiarismHearing::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Plagiarism Hearing and supports their friend" << endl;
}

void CPlagiarismHearing::perform(CPlayer* player)
{
	outputMessage(player);
}

