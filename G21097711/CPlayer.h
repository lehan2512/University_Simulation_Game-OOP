#pragma once
#include <string>
#include <memory>
#include <vector>

class CPlayer
{
private:
    std::string mName;
    int mMotivation;
    int mSuccess;
    int mYear;
    int mPosition;
    int mYearOneTasks;
    int mYearTwoTasks;
    int mYearThreeTasks;

public:
    CPlayer(std::string name);
    void setMotivation(int motivation);
    void setSuccess(unsigned int success);
    void setYear(int year);
    void setPosition(int position);
    std::string getName();
    int getMotivation();
    int getSuccess();
    int getYear();
    int getPosition();
    void setYearOneTasks(int addTask);
    void setYearTwoTasks(int addTask);
    void setYearThreeTasks(int addTask);
    int getYearOneTasks();
    int getYearTwoTasks();
    int getYearThreeTasks();
};

// Defined an alias for the shared pointer
using CPlayerPtr = std::shared_ptr<CPlayer>;
