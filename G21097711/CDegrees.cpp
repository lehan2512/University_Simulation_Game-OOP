#include "CDegrees.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib> // For srand and rand
#include <ctime>   // For time

#include "CAssessment.h"
#include "CExtraCurricular.h"
#include "CBonus.h"
#include "CBogus.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"
#include "CSkipClasses.h"

using namespace std;

// Typedef for vector of shared pointers to spaces
typedef vector<shared_ptr<CSpace>> SpaceVector;

// Typedef for vector of shared pointers to players
typedef vector<shared_ptr<CPlayer>> PlayerVector;


/**
 * @brief Default constructor for the CDegrees class.
 *
 * This constructor initializes a CDegrees object.
 *
 * @param None
 *
 * @return None
 */
CDegrees::CDegrees() {}


/**
 * @brief Default destructor for the CDegrees class.
 *
 * This destructor cleans up resources associated with a CDegrees object.
 *
 * @param None
 *
 * @return None
 */
CDegrees::~CDegrees() {}


/**
 * @brief Executes the entire game.
 *
 * This function executes the entire game by first initializing the game using the gameInitialization()
 * function and then simulating the gameplay using the gameplay() function.
 *
 * @param None
 *
 * @return None
 */
void CDegrees::PlayGame() {
    GameInitialization();
    Gameplay();
}


/**
 * @brief Initializes the game by reading data from a file and creating game spaces and players.
 *
 * This function reads data from a file "degrees.txt" to initialize the game spaces. Each line of the
 * file represents a different space in the game. The function parses each line to determine the type
 * of space and its characteristics, such as name, motivational cost, success achieved, and year (if applicable).
 * It then creates the corresponding space objects and adds them to the game space vector.
 * Additionally, it creates two player objects and adds them to the player vector.
 *
 * @param[in] None
 *
 * @return None
 */
void CDegrees::GameInitialization() {
const int SUCCESS_ACHIEVED_FROM_EXTRA_CURRICULAR = 20;
    const int MOTIVATIONAL_COST_OF_ACCUSED_OF_PLAGIARISM = 50;

    // Open degrees file
    ifstream file("degrees.txt");
    if (!file)
    {
        cerr << "Error: Unable to open the file degrees.txt" << endl;
        return;
    }

    //Take line by line from the text file
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);

        int spaceType;
        string spaceName;
        int motivationalCost;
        int successAchieved;
        int year;

        ss >> spaceType >> ws; // Extract type and skip leading whitespace

        string word;
        // Extract name
        while (ss >> word) {
            if (isdigit(word[0])) break; // If word starts with a digit, break
            if (!spaceName.empty()) spaceName += " "; // Add space if name is not empty
            spaceName += word;
        }

        // If space type is 1(Assessment), extract motivational motivational cost, success achieved and year
        if (spaceType == 1) {
            // Extract motivational cost
            motivationalCost = stoi(word);

            // Extract success score
            ss >> successAchieved;

            // Extract year
            ss >> year;
        }
        // If type is 3(Extra-Curricular Activity), extract motivational cost
        else if (spaceType == 3)
        {
            // Extract motivational cost
            motivationalCost = stoi(word);
        }
        else {}


        // Check if type is 1, create CAssessment object
        if (spaceType == 1) {
            spaceVector.push_back(make_shared<CAssessment>(spaceType, spaceName, motivationalCost, successAchieved, year));
        }
        // Check if type is 3, create CExtraCurricular object
        else if (spaceType == 3)
        {
            spaceVector.push_back(make_shared<CExtraCurricular>(spaceType, spaceName, motivationalCost, SUCCESS_ACHIEVED_FROM_EXTRA_CURRICULAR));
        }
        // Check if type is 4, create CBonus object
        else if (spaceType == 4)
        {
            spaceVector.push_back(make_shared<CBonus>(spaceType, spaceName));
        }
        // Check if type is 5, create CBogus object
        else if (spaceType == 5)
        {
            spaceVector.push_back(make_shared<CBogus>(spaceType, spaceName));
        }
        // Check if type is 6, create CPlagiarismHearing object 
        else if (spaceType == 6)
        {
            spaceVector.push_back(make_shared<CPlagiarismHearing>(spaceType, spaceName));
        }
        // Check if type is 7, create CAccusedOfPlagiarism object
        else if (spaceType == 7)
        {
            spaceVector.push_back(make_shared<CAccusedOfPlagiarism>(spaceType, spaceName, MOTIVATIONAL_COST_OF_ACCUSED_OF_PLAGIARISM));
        }
        // Check if type is 8, create CSkipClasses object
        else if (spaceType == 8)
        {
            spaceVector.push_back(make_shared<CSkipClasses>(spaceType, spaceName));
        }
        // Create a CSpace object for other spaces
        else {
            spaceVector.push_back(make_shared<CSpace>(spaceType, spaceName));
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


/**
 * @brief Simulates the gameplay for the degrees game.
 *
 * This function simulates the gameplay for the degrees game. It executes 20 rounds, each consisting of
 * turns for two players. It simulates the movement of players on the game board, handles effects of
 * landing on different types of spaces, and updates player attributes accordingly. At the end of the
 * simulation, it outputs the final scores and declares the winner.
 *
 * @param None
 *
 * @return None
 */
void CDegrees::Gameplay() {
    mGameWon = false;
    //seed
    srand(48);

    int round = 0;

    // Play in iteration till game is won
    while (!mGameWon)
    {
        round += 1;
        cout << "ROUND " << round << endl;
        cout << "=========" << endl;

        // iterate two players in each round
        for (int j = 0; j < 2; j++)
        {
            string playerName = playerVector[j]->getName();
            int currentPosition = playerVector[j]->getPosition();
            int currentYear = playerVector[j]->getYear();
            int currentMotivation = playerVector[j]->getMotivation();
            int currentSuccess = playerVector[j]->getSuccess();
            int yearOneTasksCompleted = playerVector[j]->getYearOneTasks();
            int yearTwoTasksCompleted = playerVector[j]->getYearTwoTasks();
            int yearThreeTasksCompleted = playerVector[j]->getYearThreeTasks();

            int spinnedNumber = Spin();
            cout << playerName << " spins " << spinnedNumber << endl;
            currentPosition = currentPosition + spinnedNumber;

            // Effect if completed a year in current round
            if (currentPosition > 35)
            {
                currentPosition -= 36;

                if ((currentYear == 1 && yearOneTasksCompleted == 3) || (currentYear == 2 && yearTwoTasksCompleted == 3))
                {
                    currentYear += 1;
                    currentMotivation += 250;

                    playerVector[j]->setYear(currentYear);
                    playerVector[j]->setMotivation(currentMotivation);
                    playerVector[j]->setYear(currentYear);

                    cout << playerName << " attends Welcome Week and starts year " << currentYear << " more motivated" << endl;
                }
                else if ((currentYear == 3 && yearThreeTasksCompleted == 3))
                {
                    cout << playerName << " has successfully completed Year 3" << endl;
                    cout << "Congratulations to " << playerName << " on their Graduation Day!" << endl;
                    cout << "Game Over" << endl;
                    cout << "=========" << endl << endl;
                    cout << playerName << " wins!";

                    mGameWon = true;
                    break;
                }
                else
                {
                    currentMotivation += 250;
                    playerVector[j]->setMotivation(currentMotivation);

                    cout << playerName << " attends Welcome Week and starts " << currentYear << " again" << endl;
                }
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
                    CPlayer* pPlayerInSpace = playerVector[j].get();
                    assessmentSpace->perform(pPlayerInSpace);
                }
            }
            // Effect if player lands on an Extra-Curricular Activity space
            else if (spaceType == 3)
            {
                // Cast the object at the currentPosition index of the spaceVector into a shared_ptr of type CExtraCurricular 
                // extraCurricularSpace point to that element
                shared_ptr<CExtraCurricular> extraCurricularSpace = dynamic_pointer_cast<CExtraCurricular>(spaceVector[currentPosition]);
                if (extraCurricularSpace) {
                    CPlayer* pPlayerInSpace = playerVector[j].get();
                    extraCurricularSpace->perform(pPlayerInSpace);
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
                    int spinnedAgain = Spin();
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
                    int spinnedAgain = Spin();
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
                    accusedOfPlagiarismSpace->perform(playerVector[j].get());
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
}

/**
 * @brief Generates a random integer between 1 and 10.
 *
 * This function generates a random integer between 1 and 10 using the rand() function.
 *
 * @param None
 *
 * @return Random integer between 1 and 10
 */
int CDegrees::Random() {
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}

/**
 * @brief Simulates spinning a wheel.
 *
 * This function simulates spinning a wheel by calling the Random() function
 * to generate a random integer between 1 and 10.
 *
 * @param None
 *
 * @return Random integer between 1 and 10
 */
int CDegrees::Spin() {
    return Random();
}
