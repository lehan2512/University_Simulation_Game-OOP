#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CPlagiarismHearing :
    public CSpace
{
public:
    CPlagiarismHearing(int type, const string& name);
    void outputMessage(CPlayer*) override;
    void perform(CPlayer*) override;
};

