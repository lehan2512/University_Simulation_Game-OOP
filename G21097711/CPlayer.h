#pragma once
#include <string>
#include <memory>


using namespace std;

class CPlayer
{
private:
	string mName;
	int mMotivation;
	int mSuccess;
	int mYear;
	int mPosition;

public:
	CPlayer(string name);
	void setName(string name);
	void setMotivation(int motivation);
	void setSuccess(unsigned int success);
	void setYear(int year);
	void setPosition(int position);
	string getName();
	int getMotivation();
	int getSuccess();
	int getYear();
	int getPosition();
};

// Define an alias for the shared pointer
using CPlayerPtr = shared_ptr<CPlayer>;
