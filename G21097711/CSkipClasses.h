#pragma once
#include "CSpace.h"
class CSkipClasses :
    public CSpace
{
public:
    CSkipClasses( int type, const string& name );
    void GetOutputMessage( CPlayer* player ) override;
    void PerformTask( CPlayer* player ) override;
};

