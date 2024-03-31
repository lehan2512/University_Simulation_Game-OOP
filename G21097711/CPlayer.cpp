#include "CPlayer.h"

using namespace std;

CPlayer::CPlayer(string name) : mName(name), mMotivation(1000), mSuccess(0), mYear(1), mPosition(0), mYearOneTasks(0), mYearTwoTasks(0), mYearThreeTasks(0) {}

void CPlayer::setMotivation(int motivation) {
    mMotivation = motivation;
}

void CPlayer::setSuccess(unsigned int success) {
    mSuccess = success;
}

void CPlayer::setYear(int year) {
    mYear = year;
}

void CPlayer::setPosition(int position) {
    mPosition = position;
}

string CPlayer::getName() {
    return mName;
}

int CPlayer::getMotivation() {
    return mMotivation;
}

int CPlayer::getSuccess() {
    return mSuccess;
}

int CPlayer::getYear() {
    return mYear;
}

int CPlayer::getPosition() {
    return mPosition;
}

void CPlayer::setYearOneTasks(int addTask)
{
    mYearOneTasks = addTask;
}

void CPlayer::setYearTwoTasks(int addTask)
{
    mYearTwoTasks = addTask;
}

void CPlayer::setYearThreeTasks(int addTask)
{
    mYearThreeTasks = addTask;
}

int CPlayer::getYearOneTasks()
{
    return mYearOneTasks;
}

int CPlayer::getYearTwoTasks()
{
    return mYearTwoTasks;
}

int CPlayer::getYearThreeTasks()
{
    return mYearThreeTasks;
}
