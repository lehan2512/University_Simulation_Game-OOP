#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CAccusedOfPlagiarism :
    public CSpace
{
private:
    int mMotivationalCost;
public:
    CAccusedOfPlagiarism( int type, const string& name, int motivationalCost );
    void GetOutputMessage( CPlayer* player ) override;
    void PerformTask( CPlayer* player ) override;
};

