#include <iostream>

#include <fstream>
#include <sstream>

#include <vector>
#include <memory>

#include "CSpace.h"
#include "CPlayer.h"
#include "CAssessment.h"
#include "CExtraCurricular.h"
#include "CBonus.h"
#include "CBogus.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"
#include "CSkipClasses.h"

using namespace std;

// STRUCTURE TO STORE INFO EXTRACTED FROM degrees.txt
struct SpaceInfo {
    int type;
    string name;
    int motivationalCost;
    int successAchieved;
    int year;
};

// FUNCTION TO EXTRACT SPACE TYPE AND SPACE NAME AND SPACE DETAILS(IF ANY)
// Method I used: store the extracted data in a structure and returning the structure
SpaceInfo extractSpaceInfo(const string& line) {
    stringstream ss(line);
    SpaceInfo info;
    info.motivationalCost = 0;
    info.successAchieved = 0;
    info.year = 0;
    ss >> info.type >> ws; // Extract type and skip leading whitespace

    string word;
    // Extract name
    while (ss >> word) {
        if (isdigit(word[0])) break; // If word starts with a digit, break
        if (!info.name.empty()) info.name += " "; // Add space if name is not empty
        info.name += word;
    }

    // If space type is 1(Assessment), extract motivational motivational cost, success achieved and year
    if (info.type == 1) {
        // Extract motivational cost
        info.motivationalCost = stoi(word);

        // Extract success score
        ss >> info.successAchieved;

        // Extract year
        ss >> info.year;
    }
    // If type is 3(Extra-Curricular Activity), extract motivational cost
    else if (info.type == 3)
    {
        // Extract motivational cost
        info.motivationalCost = stoi(word);
    }
    else{}

    return info; // return the structure
}



// GAME INITIALIZATION
//Extracts information from degrees.txt file, creates spaces, creates players, set position of players to first space and output welcome message
void gameInitialization(vector<CSpacePtr>& spaceVector, vector<CPlayerPtr>& playerVector)
{
    const int SUCCESS_ACHIEVED_FROM_EXTRA_CURRICULAR = 20;
    const int MOTIVATIONAL_COST_OF_ACCUSED_OF_PLAGIARISM = 50;

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
            spaceVector.push_back(make_shared<CAssessment>(type, name, info.motivationalCost, info.successAchieved, info.year));
        }
        // Check if type is 3, create CExtraCurricular object
        else if (type == 3)
        {
            spaceVector.push_back(make_shared<CExtraCurricular>(type, name, info.motivationalCost, SUCCESS_ACHIEVED_FROM_EXTRA_CURRICULAR));
        }
        // Check if type is 4, create CBonus object
        else if (type == 4)
        {
            spaceVector.push_back(make_shared<CBonus>(type, name));
        }
        // Check if type is 5, create CBogus object
        else if (type == 5)
        {
            spaceVector.push_back(make_shared<CBogus>(type, name));
        }
        // Check if type is 6, create CPlagiarismHearing object 
        else if (type == 6)
        {
            spaceVector.push_back(make_shared<CPlagiarismHearing>(type, name));
        }
        // Check if type is 7, create CAccusedOfPlagiarism object
        else if (type == 7)
        {
            spaceVector.push_back(make_shared<CAccusedOfPlagiarism>(type, name, MOTIVATIONAL_COST_OF_ACCUSED_OF_PLAGIARISM));
        }
        // Check if type is 8, create CSkipClasses object
        else if (type == 8)
        {
            spaceVector.push_back(make_shared<CSkipClasses>(type, name));
        }
        // Create a CSpace object for other spaces
        else {
            spaceVector.push_back(make_shared<CSpace>(type, name));
        }
    }

    // Creating first two players and adding to the PlayerVector
    playerVector.push_back(make_shared<CPlayer>("Vyvyan"));
    playerVector.push_back(make_shared<CPlayer>("Rick"));

    cout << "Welcome to Scumbag College" << endl << endl;

    // Set player position to first space(welcome week)
    playerVector[0]->setPosition(0);
    playerVector[1]->setPosition(0);
}

// FUNCTION TO GENERATE A RANDOM INTEGER
// notice that I am using casting to convert one data type to another
int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1);
}

//FUNCTION FOR SPINNER
static int spin()
{
    return Random();
}

// FIRST GAMEPLAY
void gameplay(vector<shared_ptr<CSpace>>& spaceVector, vector<CPlayerPtr>& playerVector)
{
    //seed
    srand(48);

    // Play 20 rounds in iteration
    for (int i = 0; i < 20; i++)
    {
        cout << "ROUND " << i + 1 << endl;
        cout << "=========" << endl;

        // iterate two players in each round
        for (int j = 0; j < 2; j++)
        {
            string playerName = playerVector[j]->getName();
            int currentPosition = playerVector[j]->getPosition();
            int currentYear = playerVector[j]->getYear();
            int currentMotivation = playerVector[j]->getMotivation();
            int currentSuccess = playerVector[j]->getSuccess();

            int spinnedNumber = spin();
            cout << playerName << " spins " << spinnedNumber
                << endl;
            currentPosition = currentPosition + spinnedNumber;

            // Effect if completed a year in current round
            if (currentPosition > 35)
            {
                currentPosition -= 36;
                currentYear += 1;
                currentMotivation += 250;

                playerVector[j]->setYear(currentYear);
                playerVector[j]->setMotivation(currentMotivation);
                playerVector[j]->setYear(currentYear);

                cout << playerName << " attends Welcome Week and starts year " << currentYear << " more motivated" << endl;
            }

            playerVector[j]->setPosition(currentPosition);

            // Getting details of the space
            int spaceType = spaceVector[currentPosition]->getType();
            string spaceName = spaceVector[currentPosition]->getName();

            // Effect if player lands on an Assessment space
            if (spaceType == 1) 
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CAssessment. 
                // AssessmentSpace point to that element
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
            // Effect if player lands on an Extra-Curricular Activity space
            else if (spaceType == 3)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CExtraCurricular 
                // extraCurricularSpace point to that element
                shared_ptr<CExtraCurricular> extraCurricularSpace = dynamic_pointer_cast<CExtraCurricular>(spaceVector[currentPosition]);
                if (extraCurricularSpace) {
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

                    extraCurricularSpace->perform(playerInSpace, helper);
                }
            }
            // Effect if player lands on an Bonus space
            else if (spaceType == 4)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CBonus 
                // bonusSpace point to that element
                shared_ptr<CBonus> bonusSpace = dynamic_pointer_cast<CBonus>(spaceVector[currentPosition]);
                if (bonusSpace) {

                    //spin again
                    int spinnedAgain = spin();
                    bonusSpace->perform(playerVector[j].get(), spinnedAgain);
                }
            }
            // Effect if player lands on an Bogus space
            else if (spaceType == 5)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CBogus 
                // bogusSpace point to that element
                shared_ptr<CBogus> bogusSpace = dynamic_pointer_cast<CBogus>(spaceVector[currentPosition]);
                if (bogusSpace) {
                    //spin again
                    int spinnedAgain = spin();
                    bogusSpace->perform(playerVector[j].get(), spinnedAgain);
                }
            }
            // Effect if player lands on an Plagiarism Hearing space
            else if (spaceType == 6)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CPlagiarismHearing 
                // plagiarismHearingSpace point to that element
                shared_ptr<CPlagiarismHearing> plagiarismHearingSpace = dynamic_pointer_cast<CPlagiarismHearing>(spaceVector[currentPosition]);
                if (plagiarismHearingSpace)
                {
                    plagiarismHearingSpace->perform(playerVector[j].get());
                }
            }
            // Effect if player lands on an Accused of Plagiarism space
            else if (spaceType == 7)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CAccusedOfPlagiarism 
                // accusedOfPlagiarismSpace point to that element
                shared_ptr<CAccusedOfPlagiarism> accusedOfPlagiarismSpace = dynamic_pointer_cast<CAccusedOfPlagiarism>(spaceVector[currentPosition]);
                if (accusedOfPlagiarismSpace)
                {
                    const int INDEX_OF_PLAGIARISM_HEARING_SPACE_ON_BOARD = 32;
                    accusedOfPlagiarismSpace->perform(playerVector[j].get(), INDEX_OF_PLAGIARISM_HEARING_SPACE_ON_BOARD);
                }
            }
            // Effect if player lands on an Skip Classes space
            else if (spaceType == 8)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CSkipClasses 
                // skipClassesSpace point to that element
                shared_ptr<CSkipClasses> skipClassesSpace = dynamic_pointer_cast<CSkipClasses>(spaceVector[currentPosition]);
                if (skipClassesSpace)
                {
                    skipClassesSpace->perform(playerVector[j].get());
                }
            }
            // Effect if player lands on an other spaces
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
    cout << endl << winner << " wins!" << endl;
}

int main()
{
    vector<shared_ptr<CSpace>> spaceVector;  // Vector for spaces on board
    vector<CPlayerPtr> playerVector;    // Vector for players

    gameInitialization(spaceVector, playerVector);
    gameplay(spaceVector, playerVector);

    return 0;
}
