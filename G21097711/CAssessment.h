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
    bool receivedHelp;

public:
    CAssessment(int type, const string& name, int motivation, int success, int year); // overloading is done implicitly
    void setMotivation(int motivation);
    void setSuccess(int success);
    void setYear(int year);
    int getMotivation();
    int getSuccess();
    int getYear();
    void outputMessage(CPlayer*);
    void perform(CPlayer*);
    bool getReceivedHelp();
};