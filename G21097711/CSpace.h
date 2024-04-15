#pragma once
#include <string>
#include <memory>
#include "CPlayer.h"

using namespace std;

class CSpace
{
protected:
    int mType = 0;
    string mName = "";

public:
    CSpace( int type,    const string );
    ~CSpace() = default; // Virtual destructor
    void SetType( int );
    void SetName( const string );
    virtual int GetType() const;
    virtual string GetName() const;
    virtual void GetOutputMessage( CPlayer* player );
    virtual void PerformTask( CPlayer* player );
};

// Define an alias for the shared pointer of type CSpace. All spaces will be creted using this shared pointer
using pCSpacePtr = shared_ptr<CSpace>;
