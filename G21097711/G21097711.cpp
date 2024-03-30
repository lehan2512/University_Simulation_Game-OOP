#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <cctype>
#include <cstdlib>
#include "CSpace.h"
#include "CPlayer.h"
#include "CAssessment.h"
#include "CPlagiarismHearing.h"

using namespace std;

// STRUCTURE TO STORE INFO EXTRACTED FROM degrees.txt
struct SpaceInfo {
    int type;
    string name;
    int motivation;
    int success;
    int year;
};

// FUNCTION TO EXTRACT SPACE TYPE AND SPACE NAME AND SPACE DETAILS IF ANY
// Method I used is to store the extracted data in a structure and returning the structure
SpaceInfo extractSpaceInfo(const string& line) {
    stringstream ss(line);
    SpaceInfo info;
    info.motivation = 0;
    info.success = 0;
    info.year = 0;
    ss >> info.type >> ws; // Extract type and skip leading whitespace

    string word;
    // Extract name
    while (ss >> word) {
        if (isdigit(word[0])) break; // If word starts with a digit, break
        if (!info.name.empty()) info.name += " "; // Add space if name is not empty
        info.name += word;
    }

    // If type is 1, extract motivational cost, success score, and year
    if (info.type == 1) {
        // Extract motivational cost
        info.motivation = stoi(word);

        // Extract success score
        ss >> info.success;

        // Extract year
        ss >> info.year;
    }


    return info;
}



// GAME INITIALIZATION
//Extracts information from degrees.txt file, creates spaces, creates players
void gameInitialization(vector<CSpacePtr>& spaceVector, vector<CPlayerPtr>& playerVector)
{

    ifstream file("degrees.txt");
    if (!file)
    {
        cerr << "Error: Unable to open the file degrees.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        SpaceInfo info = extractSpaceInfo(line);

        int type = info.type;
        string name = info.name;

        // Check if type is 1, create CAssessment object
        if (type == 1) {
            spaceVector.push_back(make_shared<CAssessment>(type, name, info.motivation, info.success, info.year));
        }
        else if (type == 6)
        {
            spaceVector.push_back(make_shared<CPlagiarismHearing>(type, name));
        }
        else {
            spaceVector.push_back(make_shared<CSpace>(type, name));
        }
    }

    //creating first two players
    CPlayerPtr vyvyan = make_shared<CPlayer>("Vyvyan");
    CPlayerPtr rick = make_shared<CPlayer>("Rick");

    // Add players to the PlayerVector
    playerVector.push_back(vyvyan);
    playerVector.push_back(rick);

    cout << "Welcome to Scumbag College" << endl << endl;

    playerVector[0]->setPosition(0);
    playerVector[1]->setPosition(0);
}

// FUNCTION TO GENERATE A RANDOM INTEGER
// notice that I am using casting to convert one data type to another
int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1);
}

// FIRST GAMEPLAY
void gameplay(vector<shared_ptr<CSpace>>& spaceVector, vector<CPlayerPtr>& playerVector)
{
    srand(48);

    for (int i = 0; i < 20; i++)
    {
        cout << "ROUND " << i + 1 << endl;
        cout << "=========" << endl;

        for (int j = 0; j < 2; j++)
        {
            string playerName = playerVector[j]->getName();
            int currentPosition = playerVector[j]->getPosition();
            int currentYear = playerVector[j]->getYear();
            int currentMotivation = playerVector[j]->getMotivation();
            int currentSuccess = playerVector[j]->getSuccess();

            int spin = Random();

            cout << playerName << " spins " << spin << endl;

            currentPosition = currentPosition + spin;

            // if completed a year
            if (currentPosition > 35)
            {
                currentPosition -= 35;
                currentYear += 1;
                currentMotivation += 250;

                playerVector[j]->setYear(currentYear);
                playerVector[j]->setMotivation(currentMotivation);
                playerVector[j]->setYear(currentYear);

                cout << playerName << " attends Welcome Week and starts year " << currentYear << " more motivated" << endl;
            }

            playerVector[j]->setPosition(currentPosition);

            // Getting the details of the space
            int spaceType = spaceVector[currentPosition]->getType();
            string spaceName = spaceVector[currentPosition]->getName();

            if (spaceType == 1) 
            {
                shared_ptr<CAssessment> assessmentSpace = dynamic_pointer_cast<CAssessment>(spaceVector[currentPosition]);
                if (assessmentSpace) {
                    CPlayer* playerInSpace = playerVector[j].get();
                    CPlayer* helper;
                    if (j == 0)
                    {
                        helper = playerVector[1].get();
                    }
                    else
                    {
                        helper = playerVector[0].get();
                    }

                    assessmentSpace->perform(playerInSpace, helper);
                }
            }
            else if (spaceType == 6)
            {
                shared_ptr<CPlagiarismHearing> plagiarismHearingSpace = dynamic_pointer_cast<CPlagiarismHearing>(spaceVector[currentPosition]);
                if (plagiarismHearingSpace)
                {
                    plagiarismHearingSpace->perform(playerVector[j].get());
                }
            }
            else
            {
                // Output landed space
                cout << playerName << " lands on " << spaceName << endl;
            }

            // Output the player's motivation and success after each turn
            currentMotivation = playerVector[j]->getMotivation();
            currentSuccess = playerVector[j]->getSuccess();
            cout << playerName << "'s motivation is " << currentMotivation << " and success is " << currentSuccess << endl << endl;
        }
    }

    cout << "Game Over" << endl;
    cout << "=========" << endl;

    // Output scores
    string nameOfVyvyan = playerVector[0]->getName();
    int successOfVyvyan = playerVector[0]->getSuccess();

    string nameOfRick = playerVector[1]->getName();
    int successOfRick = playerVector[1]->getSuccess();

    cout << nameOfVyvyan << " has achieved " << successOfVyvyan << endl;
    cout << nameOfRick << " has achieved " << successOfRick << endl;

    // Output winner
    string winner;
    if (successOfVyvyan > successOfRick)
    {
        winner = nameOfVyvyan;
    }
    else
    {
        winner = nameOfRick;
    }
    cout << winner << " wins." << endl;
}

int main()
{
    vector<shared_ptr<CSpace>> spaceVector;  // Vector for spaces on board
    vector<CPlayerPtr> playerVector;    // Vector for players

    gameInitialization(spaceVector, playerVector);
    gameplay(spaceVector, playerVector);

    return 0;
}
