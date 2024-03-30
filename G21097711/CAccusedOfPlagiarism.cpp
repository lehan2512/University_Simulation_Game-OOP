#include "CAccusedOfPlagiarism.h"
#include "CSpace.h"
#include <iostream>

CAccusedOfPlagiarism::CAccusedOfPlagiarism(int type, const string& name) : CSpace(type, name) {}

void CAccusedOfPlagiarism::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Accused of Plagiarism and goes to hearing" << endl;
	cout << player->getName() << " loses motivation" << endl;
}

void CAccusedOfPlagiarism::perform(CPlayer* player, int indexOfPlagiarismHearing)
{
	// Set player position to Plagerism Hearing
	player->setPosition(indexOfPlagiarismHearing);
	player->setMotivation(player->getMotivation() - 50);
	outputMessage(player);
}
