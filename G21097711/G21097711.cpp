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

using namespace std;

pair<int, string> parseLine(const string& line);


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
        pair<int, string> data = parseLine(line);
        int type = data.first;
        string name = data.second;
        spaceVector.push_back(make_shared<CSpace>(type, name));

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
}


// FUNCTION TO EXTRACT SPACE TYPE AND SPACE NAME
// The method I used to extract the name is to check the first letter of each word
// If the letter is alphabetical, then store it in the name
pair<int, string> parseLine(const string& line) {
    stringstream ss(line);
    int type;
    string name;
    ss >> type >> ws; // Extract type and skip leading whitespace
    string word;
    while (ss >> word) {
        if (!isalpha(word[0])) break; // Check if the first character is alphabetic
        name += (name.empty() ? "" : " ") + word;
    }
    return { type, name };
}


// FUNCTION TO GENERATE A RANDOM INTEGER
// notice that I am using casting to convert one data type to another
int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 10.0f + 1);
}


// FIRST GAMEPLAY
void gameplay(vector<CSpacePtr>& spaceVector, vector<CPlayerPtr>& playerVector)
{
    srand(48);
    int currentPosition = 0;

    for (int i = 0; i < 20; i++)
    {
        cout << "ROUND " << i + 1 << endl;
        cout << "=========" << endl;

        for (int j = 0; j < 2; j++)
        {
            string playerName = playerVector[j]->getName();
            currentPosition = playerVector[j]->getPosition();
            int currentYear = playerVector[j]->getYear();
            int currentMotivation = playerVector[j]->getMotivation();

            int spin = Random();

            cout << playerName << " spins " << spin << endl;

            currentPosition = currentPosition + spin;
            if (currentPosition > 35)
            {
                currentPosition -= 35;
                playerVector[j]->setYear(currentYear + 1);
                playerVector[j]->setMotivation(currentMotivation + 250);
                cout << playerName << " attends Welcome Week and starts year " << currentYear << " more motivated" << endl;
            }
            playerVector[j]->setPosition(currentPosition);

            cout << playerName << " lands on " << spaceVector[currentPosition]->getName() << endl << endl;

        }       
    }
}


int main()
{
    vector<CSpacePtr> spaceVector;  // Vector for spaces on board
    vector<CPlayerPtr> playerVector;    // Vector for players


    gameInitialization(spaceVector, playerVector);

    gameplay(spaceVector, playerVector);


    cout << "Game Over" << endl;
    cout << "=========" << endl;

    return 0;
}
