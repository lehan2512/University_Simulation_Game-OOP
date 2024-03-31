#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CAccusedOfPlagiarism :
    public CSpace
{
private:
    int mMotivationalCost;
public:
    CAccusedOfPlagiarism(int type, const string& name, int motivationalCost);
    void outputMessage(CPlayer*) override;
    void perform(CPlayer*, int);
};

