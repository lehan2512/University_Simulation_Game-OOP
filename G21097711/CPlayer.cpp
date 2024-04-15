#include "CPlayer.h"

using namespace std;

CPlayer::CPlayer( string name ) : mName( name ), mMotivation( 1000 ), mSuccess( 0 ), mYear( 1 ), mPosition( 0 ), mYearOneTasks( 0 ), mYearTwoTasks( 0 ), mYearThreeTasks( 0 ) {}

void CPlayer::SetMotivation( int motivation ) 
{
    mMotivation = motivation;
}

void CPlayer::SetSuccess( unsigned int success ) 
{
    mSuccess = success;
}

void CPlayer::SetYear( int year ) 
{
    mYear = year;
}

void CPlayer::SetPosition( int position )
{
    mPosition = position;
}

string CPlayer::GetName() 
{
    return mName;
}

int CPlayer::GetMotivation() 
{
    return mMotivation;
}

int CPlayer::GetSuccess() 
{
    return mSuccess;
}

int CPlayer::GetYear() 
{
    return mYear;
}

int CPlayer::GetPosition() 
{
    return mPosition;
}

void CPlayer::SetYearOneTasksCompleted( int addTask )
{
    mYearOneTasks = addTask;
}

void CPlayer::SetYearTwoTasksCompleted( int addTask )
{
    mYearTwoTasks = addTask;
}

void CPlayer::SetYearThreeTasksCompleted( int addTask )
{
    mYearThreeTasks = addTask;
}

int CPlayer::GetYearOneTasksCompleted()
{
    return mYearOneTasks;
}

int CPlayer::GetYearTwoTasksCompleted()
{
    return mYearTwoTasks;
}

int CPlayer::GetYearThreeTasksCompleted()
{
    return mYearThreeTasks;
}
