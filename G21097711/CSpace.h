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
    CSpace(int, const string);
    virtual ~CSpace() = default; // Virtual destructor
    void setType(int);
    void setName(const string);
    virtual int getType() const;
    virtual string getName() const;
    virtual void outputMessage(CPlayer*);
    virtual void perform(CPlayer*);
};

// Define an alias for the shared pointer of type CSpace. All spaces will be creted using this shared pointer
using CSpacePtr = shared_ptr<CSpace>;
