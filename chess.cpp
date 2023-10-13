/**********************************************************************
 * CHESS
 * Where the main game logic happens. Here we intialize the game object,
 * and call upon the necessary elements of the project to simulate a
 * chess game.
 * Authors:
 *    Mason Schenk & Andre Regino
 **********************************************************************/

#include "uiInteract.h"   // for INTERFACE
#include "test.h"         // for TESTRUNNER
#include "board.h"        // for BOARD
#include "move.h"         // for MOVE
#include <set>            // for STD::SET
using namespace std;

/*********************************************************************
 * CHESS CALLBACK
 * Where the main game logic is housed per frame draw
 * Note: Main design structure pulled from James Helfrich Pseudocode
 *********************************************************************/
void callBack(Interface *pUI, void *p)
{
   Board *board = (Board *)p;
   Move move;
   set <Move> moves;
   
   // clicked on a piece that has not moved yet
   if(Position(pUI->getPreviousPosition()).isInvalid() && Position(pUI->getSelectPosition()).isValid())
   {
      // clicked on space
      if(board->getPiece(pUI->getSelectPosition())->getLetter() == SPACE)
         pUI->clearSelectPosition();
      // not our turn
      else if (board->getPiece(pUI->getSelectPosition())->isWhite() != board->whiteTurn())
         pUI->clearSelectPosition();
   }
   
   // get possible moves for selected position
   board->getPiece(pUI->getSelectPosition())->getMoves(moves, *board);
   
   // check if proposed move is valid
   if(Position(pUI->getPreviousPosition()).isValid() && Position(pUI->getSelectPosition()).isValid())
   {
      // intialize a possible move
      move.setSrc(pUI->getPreviousPosition());
      move.setDes(pUI->getSelectPosition());
      
      // makes sure the possible moves stay correct
      board->getPiece(pUI->getPreviousPosition())->getMoves(moves, *board);
      
      // moves the piece if the move is found from possible moves
      auto it = moves.find(move);
      if(it != moves.end())
         board->move(*it);
      
      // reset for the next move
      pUI->clearSelectPosition();
      pUI->clearPreviousPosition();
      moves.clear();
   }
   
   // displays the board based on the current state
   board->display(*pUI, moves);
}

/*********************************************************************
 * CHESS MAIN
 * Where the Game and Interface classes are intialized and everything is
 * put into action. This is also where we run the test cases from.
 *********************************************************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // intialize the interface window
   Interface ui("Chess");

   // initialize the board class
   Board board(false);
   
   // run test cases
   testRunner();
   
   // set everything into action
   ui.run(callBack, &board);
   
   return 0;
}
