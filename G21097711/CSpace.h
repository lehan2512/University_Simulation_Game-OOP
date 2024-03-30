#pragma once
#include <string>
#include <memory>
#include "CPlayer.h"

using namespace std;

class CSpace
{
protected:
    int mType;
    string mName;

public:
    CSpace(int type, const string name);
    virtual ~CSpace() = default; // Virtual destructor
    void setType(int type);
    void setName(const string name);
    virtual int getType() const;
    virtual string getName() const;
    virtual void outputMessage(CPlayer*);
    virtual void perform(CPlayer*);
};

// Define an alias for the shared pointer
using CSpacePtr = shared_ptr<CSpace>;
