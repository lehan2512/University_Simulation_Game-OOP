#pragma once
#include "CBonusBogusManager.h"
class CBogus :
    public CBonusBogusManager
{
public:
    CBogus(int type, const string& name); // overloading is done implicitly
    void perform(CPlayer*, int spin) override;
    void outputMessage(CPlayer* player, const string& message) override;
};


