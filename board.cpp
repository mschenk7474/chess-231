/***********************************************************************
 * Source File:
 *    BOARD : Keeps track of all elements of chess game, which is on the board
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    Everything we need to know about the game, which is to know the board
 ************************************************************************/

#include "board.h"       // for BOARD
#include "move.h"        // for MOVE
#include <cassert>       // for ASSERT
#include "uiInteract.h"  // for INTERFACE

/*********************************************************************
 * BOARD GET PIECE
 * Gets the piece according the position passed
 *********************************************************************/
Piece* Board::getPiece(const Position & pos) const
{
   return (*this)[pos];
}

/*********************************************************************
 * BOARD DISPLAY
 * Display the board at its current state
 *********************************************************************/
void Board::display(const Interface & ui, const std::set <Move> & possible)
{
   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   for (auto it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(it->getDes().getLocation());
   
   // draw the pieces
   for(int r = 0; r < 8; r++)
      for(int c = 0; c < 8; c++)
         (*this)(r,c)->display(gout);
   
}

/*********************************************************************
 * BOARD MOVE
 * Moves the piece on the board
 *********************************************************************/
void Board::move(const Move &move)
{
   int positionFrom = move.getSrc().getLocation();
   int positionTo = move.getDes().getLocation();
   
   // do not move if not indicated
   if (positionFrom == -1 || positionTo == -1)
      return;
   assert(positionFrom >= 0 && positionFrom < 64);
   assert(positionTo >= 0 && positionTo < 64);
   
   // handle castle for both sides
   // king side first
   if (move.getCastleK())
      (*this).swap(Position(move.getDes().getRow(), 7), Position(move.getDes().getRow(), 5));
      
   // queen side
   if(move.getCastleQ())
      (*this).swap(Position(move.getDes().getRow(), 0), Position(move.getDes().getRow(), 2));
      
   // check for enpassant
   if(move.getEnPassant())
   {
      // white enpassant
      if((*this).getPiece(positionFrom)->isWhite())
         *this -= Position(move.getDes().getRow() - 1, move.getDes().getCol());
      
      // black enpassant
      else
         *this -= Position(move.getDes().getRow() + 1, move.getDes().getCol());
   }
   
   // normal move
   (*this).swap(move.getSrc(), move.getDes());
   
   // want to check for capture
   if (move.getCapture() != SPACE)
      // if there was a capture, need to remove captured piece
      *this -= move.getSrc();
   
   // update the variables to keep track of who's turn it is
   this->getPiece(positionTo)->setLastMove(positionTo);
   this->getPiece(positionTo)->incrementNMoves();
   this->incrementCurrentMove();
   this->setLastMove(positionTo);
   
   
   // check for promote
   if(move.getPromotion() != SPACE)
   {
      *this -= Position(move.getDes());
      (*this)(move.getDes().getRow(),move.getDes().getCol()) = new Queen(move.getDes().getRow(), move.getDes().getCol(), move.getWhiteMove());
   }
}

/*********************************************************************
 * BOARD RESET
 * Resets the board to the start of a normal game.
 *********************************************************************/
void Board::reset(bool fFree)
{
   // free up memory if allocated
   if(fFree)
      free();
   
   // set up middle of board
   for (int r = 2; r < 6; r++)
      for (int c = 0; c < 8; c++)
         board[r][c] = builder(SPACE, r, c, true);
   
   // set up pawns
   for (int c = 0; c < 8; c++)
   {
      board[1][c] = builder(PAWN, 1, c, true);
      board[6][c] = builder(PAWN, 6, c, false);
   }
   
   // white pieces
   board[0][0] = builder(ROOK, 0, 0, true);
   board[0][1] = builder(KNIGHT, 0, 1, true);
   board[0][2] = builder(BISHOP, 0, 2, true);
   board[0][3] = builder(QUEEN, 0, 3, true);
   board[0][4] = builder(KING, 0, 4, true);
   board[0][5] = builder(BISHOP, 0, 5, true);
   board[0][6] = builder(KNIGHT, 0, 6, true);
   board[0][7] = builder(ROOK, 0, 7, true);
   
   // black pieces
   board[7][0] = builder(ROOK, 7, 0, false);
   board[7][1] = builder(KNIGHT, 7, 1, false);
   board[7][2] = builder(BISHOP, 7, 2, false);
   board[7][3] = builder(QUEEN, 7, 3, false);
   board[7][4] = builder(KING, 7, 4, false);
   board[7][5] = builder(BISHOP, 7, 5, false);
   board[7][6] = builder(KNIGHT, 7, 6, false);
   board[7][7] = builder(ROOK, 7, 7, false);
   
   // reset the moves
   resetMoves();
   
   // make sure the board is correct
   assertBoard();
}

/*********************************************************************
 * BOARD FREE
 * Frees the memory of the board, aka the deconstructor
 *********************************************************************/
void Board::free()
{
   
}

/*********************************************************************
 * BOARD SWAP
 * Gives two positions and the two position's pieces swap attributes.
 *********************************************************************/
void Board::swap(const Position &pos1, const Position &pos2)
{
   Piece* p1 = board[pos1.getRow()][pos1.getCol()];
   Piece* p2 = board[pos2.getRow()][pos2.getCol()];
   
   board[pos1.getRow()][pos1.getCol()] = p2;

   board[pos2.getRow()][pos2.getCol()] = p1;

   p1->setPosition(pos2);
   p2->setPosition(pos1);
    
}

/*********************************************************************
 * BOARD ASSIGNMENT OPERATOR
 * Assigns a piece's type to another piece.
 *********************************************************************/
void Board::operator=(Piece* piece)
{
   (*this)(piece->getPosition().getRow(),piece->getPosition().getCol()) = piece;
}

/*********************************************************************
 * BOARD ASSERT BOARD
 * Makes sure the board looks correct.
 *********************************************************************/
void Board::assertBoard()
{
   
}
