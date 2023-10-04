
#include "test.h"
#include "testMove.h"
#include "testPosition.h"
#include "testPiece.h"
#include "testBoard"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    TestMove().run();
    TestPosition().run();
    TestPiece().run();
    TestBoard().run();
}

