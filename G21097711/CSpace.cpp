#include "CSpace.h"

using namespace std;

CSpace::CSpace(int type, const string name) : mType(type), mName(name) {}   // Constructer initializes name and type the space

void CSpace::setType(int type) {
    mType = type;
}

void CSpace::setName(const string name) {
    mName = name;
}

int CSpace::getType() const {
    return mType;
}

string CSpace::getName() const {
    return mName;
}

// Virtual function to be overrriden by derived classes to output player landing on this space
void CSpace::outputMessage(CPlayer*) {}

// Virtual function to be overridden by derived classes to perform changes to player's attributes when landing on this space
void CSpace::perform(CPlayer*) {}


