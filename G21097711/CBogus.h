#pragma once
#include "CBonusBogusManager.h"
class CBogus :
    public CBonusBogusManager
{
public:
    CBogus( int type, const string& name ); // overloading is done implicitly
    void PerformTask( CPlayer*, int spin ) override;
    void GetOutputMessage( CPlayer* player, const string& message ) override;
};


