#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CAssessment :
    public CSpace
{
private:
    int mMotivationalCost;
    int mSuccess;
    int mYear;
    bool vyvyanCompleted;
    bool rickCompleted;

public:
    CAssessment(int type, const string& name, int motivation, int success, int year); // overloading is done implicitly
    void setMotivation(int motivation);
    void setSuccess(int success);
    void setYear(int year);
    int getMotivation();
    int getSuccess();
    int getYear();
    void outputMessage(CPlayer*);
    bool effect(CPlayer*);
    bool getVyvyanCompleted();
    void setVyvyanCompleted(bool completed);
    bool getRickCompleted();
    void setRickCompleted(bool completed);
};

// Define an alias for the shared pointer
using CAssessmentPtr = shared_ptr<CAssessment>;