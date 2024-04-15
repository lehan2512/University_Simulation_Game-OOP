#pragma once
#include "CSpace.h"
#include "CPlayer.h"

// This class holds the common methods and atributes of CAssessment and CExtraCurricular
class CTask :
    public CSpace
{
private:
    int mMotivationalCost = 0;
    int mSuccessAchieved = 0;
    bool mReceivedHelp = false; // Bool to check if player received help when performing a task

protected: // Left these two bools as protected so that they can be accessed by the derived classes
           //directly and not create seperate getters and setters to access them
    bool mVyvyanCompletedThisTask = false;   // Bool to check if Vyvyan has already completed the task
    bool mRickCompletedThisTask = false; // Bool to check if Rick has already completed the task
    vector<CPlayer*> mWhoCompleted;

public:
    CTask(int type, const string& name, int motivationalCost, int successAchieved); // overloading is done implicitly
    int GetMotivationalCost();
    int GetSuccessAchieved();
    bool GetReceivedHelp();
    void SetReceivedHelp(bool);
    void GetOutputMessage(CPlayer*) override;   // Output message for landing on the space overridden from CSpace
    void PerformTask(CPlayer*) override;   // Perform changes to player attribute when landed on space
    virtual void GetPlayerOutput(CPlayer* player); // Player output after completing the task
    virtual void AffectFriendForHelping(CPlayer*);    // Perform changes to friend's attributes for helping
};

