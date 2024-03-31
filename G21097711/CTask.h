#pragma once
#include "CSpace.h"
#include "CPlayer.h"

class CTask :
    public CSpace
{
private:
    int mMotivationalCost;
    int mSuccess;
    bool receivedHelp;

protected:
    bool vyvyanCompleted;
    bool rickCompleted;

public:
    CTask(int type, const string& name, int motivation, int success); // overloading is done implicitly
    void setMotivation(int motivation);
    void setSuccess(int success);
    int getMotivation();
    int getSuccess();
    bool getReceivedHelp();
    void setReceivedHelp(bool);
    void outputMessage(CPlayer*);
    virtual void perform(CPlayer*, CPlayer*);
    virtual void playerOutput(CPlayer* player);
    virtual void playerOutputIfHelped(CPlayer* player);
    virtual void affectFriendForHelping(CPlayer*, CPlayer*);
};

