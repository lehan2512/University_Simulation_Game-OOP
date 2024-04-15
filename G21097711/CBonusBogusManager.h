#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CBonusBogusManager :
    public CSpace
{
public: 
    CBonusBogusManager( int type, const string& name ); // overloading is done implicitly
    virtual void PerformTask( CPlayer*, int spin );
    virtual void GetOutputMessage( CPlayer* player, const string& message );
};

