#include "CAccusedOfPlagiarism.h"
#include "CSpace.h"
#include <iostream>

CAccusedOfPlagiarism::CAccusedOfPlagiarism(int type, const string& name, int motivationalCost) 
	: CSpace(type, name), mMotivationalCost(motivationalCost) {}

void CAccusedOfPlagiarism::outputMessage(CPlayer* player)
{
	cout << player->getName() << " lands on Accused of Plagiarism and goes to hearing" << endl;
	cout << player->getName() << " loses motivation" << endl;
}

// Overridden Function to perform changes to player attributes in this space
void CAccusedOfPlagiarism::perform(CPlayer* player)
{
	const int positionOfPlagiarismHearing = 32;
	// Set player position to Plagerism Hearing and reduction motivation
	player->setPosition(positionOfPlagiarismHearing);
	player->setMotivation(player->getMotivation() - mMotivationalCost);
	outputMessage(player);
}
