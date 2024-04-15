#pragma once
#include <string>
#include <memory>
#include <vector>

class CPlayer
{
private:
    std::string mName = "";
    int mMotivation = 1000;
    int mSuccess = 0;
    int mYear = 0;
    int mPosition = 0;
    int mYearOneTasks = 0;
    int mYearTwoTasks = 0;
    int mYearThreeTasks = 0;

public:
    CPlayer( std::string name );
    void SetMotivation( int motivation );
    void SetSuccess( unsigned int success );
    void SetYear( int year );
    void SetPosition( int position );
    std::string GetName();
    int GetMotivation();
    int GetSuccess();
    int GetYear();
    int GetPosition();
    void SetYearOneTasksCompleted( int addTask );
    void SetYearTwoTasksCompleted( int addTask );
    void SetYearThreeTasksCompleted( int addTask );
    int GetYearOneTasksCompleted();
    int GetYearTwoTasksCompleted();
    int GetYearThreeTasksCompleted();
};

// Defined an alias for the shared pointer
using pCPlayerPtr = std::shared_ptr<CPlayer>;
