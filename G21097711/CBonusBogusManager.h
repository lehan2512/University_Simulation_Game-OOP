#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CBonusBogusManager :
    public CSpace
{
public: 
    CBonusBogusManager(int type, const string& name); // overloading is done implicitly
    virtual void perform(CPlayer*, int spin);
    virtual void outputMessage(CPlayer* player, const string& message);
};

