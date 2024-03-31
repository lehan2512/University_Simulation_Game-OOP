#pragma once
#include "CSpace.h"
class CSkipClasses :
    public CSpace
{
public:
    CSkipClasses(int type, const string& name);
    void outputMessage(CPlayer*) override;
    void perform(CPlayer*) override;
};

