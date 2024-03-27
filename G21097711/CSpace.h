#pragma once
#include <string>
#include <memory>

using namespace std;

class CSpace
{
protected:
    int mType;
    string mName;

public:
    CSpace(int type, const string name); 
    void setType(int type);
    void setName(const string name);
    int getType() const;
    string getName() const;
};

// Define an alias for the shared pointer
using CSpacePtr = shared_ptr<CSpace>;
