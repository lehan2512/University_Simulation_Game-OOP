#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CAssessment :
    public CSpace
{
private:
    int mMotivation();
    int mSuccess();
    int mYear();

public:
    CAssessment(int motivation, string outputMessage, int success, int year);
    void setMotivation(int motivation);
    void setSuccess(int success);
    void setYear(int year);
    int getMotivation();
    int getSuccess();
    int getYear();
    void outputMessage(CPlayer*);
    void effect(CPlayer*);
};

// Define an alias for the shared pointer
using CAssessmentPtr = shared_ptr<CAssessment>;