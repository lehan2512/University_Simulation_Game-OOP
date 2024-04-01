#pragma once

#include <vector>
#include <memory>
#include "CSpace.h"
#include "CPlayer.h"

// Degrees game mamager class
class CDegrees {
private:
    std::vector<std::shared_ptr<CSpace>> spaceVector;
    std::vector<std::shared_ptr<CPlayer>> playerVector;
    void gameInitialization();
    void gameplay();
    int Random();
    int spin();

public:
    CDegrees();
    ~CDegrees();
    void playGame();
};


