/***********************************************************************
 * Source File:
 *    TEST : Keeps track of the test cases to be ran
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    Everything we need to know about running our test cases
 ************************************************************************/

#include "test.h"          // for TESTRUNNER
#include "testMove.h"      // for MOVETEST
#include "testPosition.h"  // for POSITIONTEST
#include "testPiece.h"     // FOR PIECETEST
#include "testBoard.h"     // FOR TESTBOARD

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

