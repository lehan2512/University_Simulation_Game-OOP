#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "CDegrees.h"

int main()
{
    CDegrees degreesGame; // Creating an instance of CDegrees class
    degreesGame.PlayGame(); // Calling playGame function to start the game
    _CrtDumpMemoryLeaks();  // Detecting memory leaks if any

    return 0;
}
