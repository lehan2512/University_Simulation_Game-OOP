#include "CSpace.h"

using namespace std;

CSpace::CSpace(int type, const string name) : mType(type), mName(name) {}

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
