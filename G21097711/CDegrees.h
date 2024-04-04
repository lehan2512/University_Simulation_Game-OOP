#pragma once

#include <vector>
#include <memory>
#include "CSpace.h"
#include "CPlayer.h"

// Degrees game mamager class
class CDegrees {
private:
    bool mGameWon;
    std::vector<std::shared_ptr<CSpace>> spaceVector;
    std::vector<std::shared_ptr<CPlayer>> playerVector;
    void GameInitialization();
    void Gameplay();
    int Random();
    int Spin();

public:
    CDegrees();
    ~CDegrees();
    void PlayGame();
};


