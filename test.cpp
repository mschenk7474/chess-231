
#include "test.h"
#include "testMove.h"
#include "testPosition.h"
#include "testPiece.h"
#include "testBoard.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    MoveTest().run();
    PositionTest().run();
    PieceTest().run();
    TestBoard().run();
}

