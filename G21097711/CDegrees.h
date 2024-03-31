#pragma once

#include <vector>
#include <memory>
#include "CSpace.h"
#include "CPlayer.h"

// Degrees game mamager class
class CDegrees {
public:
    CDegrees();
    ~CDegrees();
    void playGame();

private:
    std::vector<std::shared_ptr<CSpace>> spaceVector;
    std::vector<std::shared_ptr<CPlayer>> playerVector;

    void gameInitialization();
    void gameplay();
    int Random();
    int spin();
};


