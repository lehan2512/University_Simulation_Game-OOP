#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "CDegrees.h"

int main()
{
    CDegrees degreesGame; // Create an instance of the CDegrees class
    degreesGame.playGame(); // Call the playGame function to start the game
    
    return 0;
    _CrtDumpMemoryLeaks();
}
