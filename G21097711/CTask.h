#pragma once
#include "CSpace.h"
#include "CPlayer.h"

// This class holds the common methods and atributes of CAssessment and CExtraCurricular as both classes function similarly
// The differences are done by overriding the virtual functions present here 
class CTask :
    public CSpace
{
private:
    int mMotivationalCost;
    int mSuccessAchieved;
    bool receivedHelp; // Bool to check if player received help when performing a task

protected: // Left these two bools as protected so that they can be accessed by the derived classes directly and not create seperate getters and setters to access them
    bool vyvyanCompleted;   // Bool to check if Vyvyan has already completed the task
    bool rickCompleted; // Bool to check if Rick has already completed the task

public:
    CTask(int type, const string& name, int motivationalCost, int successAchieved); // overloading is done implicitly
    void setMotivationalCost(int motivationalCost);
    void setSuccessAchieved(int successAchieved);
    int getMotivationalCost();
    int getSuccessAchieved();
    bool getReceivedHelp();
    void setReceivedHelp(bool);
    void outputMessage(CPlayer*);   // Output message for landing on the space
    virtual void perform(CPlayer*, CPlayer*);   // Perform changes to player attribute when landed on space
    virtual void playerOutput(CPlayer* player); // Player output after completing the task
    virtual void affectFriendForHelping(CPlayer*, CPlayer*);    // Perform changes to friend's attributes for helping
};

