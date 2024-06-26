#pragma once
#include "CBonusBogusManager.h"
#include "CPlayer.h"

class CBonus :
    public CBonusBogusManager
{
public:
    CBonus( int type, const string& name ); // overloading is done implicitly
    void PerformTask( CPlayer*, int spin ) override;
    void GetOutputMessage( CPlayer* player, const string& message ) override;
};

