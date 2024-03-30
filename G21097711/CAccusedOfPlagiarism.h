#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CAccusedOfPlagiarism :
    public CSpace
{
public:
    CAccusedOfPlagiarism(int type, const string& name);
    void outputMessage(CPlayer*);
    void perform(CPlayer*, int);
};

