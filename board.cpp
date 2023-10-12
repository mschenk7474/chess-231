//
//  board.cpp
//  Lab01
//
//  Created by Mason Schenk on 10/4/23.
//

#include "board.h" // for BOARD
#include "move.h"  // for MOVE
#include <cassert> // for assertBoard

/*********************************************************************
 * BOARD GET PIECE
 * Get's the piece according the position passed
 *********************************************************************/
Piece* Board::getPiece(Position pos)
{
   return (*this)[pos];
}

/*********************************************************************
 * BOARD MOVE
 * Moves the piece on the board
 *********************************************************************/
bool Board::move(const Move &move) // pass by reference
{
   int positionFrom = move.getSrc().getLocation();
   int positionTo = move.getDes().getLocation();
   
   // do not move if not indicated
   if (positionFrom == -1 || positionTo == -1)
      return false;
   assert(positionFrom >= 0 && positionFrom < 64);
   assert(positionTo >= 0 && positionTo < 64);
   
   // need to check who's turn it is
   if((this->whiteTurn() && this->getPiece(positionFrom)->isWhite() == false) || (!this->whiteTurn() && this->getPiece(positionFrom)->isWhite() == true))
      return false;
   
   // handle castle for both sides
   // king side first
   if (move.getCastleK())
   {
      (*this).swap(Position(move.getDes().getRow(), 7), Position(move.getDes().getRow(), 5));
      return true;
   }
      
   // queen side
   if(move.getCastleQ())
   {
      (*this).swap(Position(move.getDes().getRow(), 0), Position(move.getDes().getRow(), 2));
      return true;
   }
      
   // check for enpassant
   if(move.getEnPassant())
   {
      if((*this).getPiece(positionFrom)->isWhite())
      {
         *this -= Position(move.getDes().getRow() - 1, move.getDes().getCol());
         return true;
      }
        
      else
      {
         *this -= Position(move.getDes().getRow() + 1, move.getDes().getCol());
         return true;
      }
   }
   
   // normal move
   (*this).swap(move.getSrc(), move.getDes());
   
   // want to check for capture
   if (move.getCapture() != SPACE)
      // if there was a capture that went down, need to remove instead
      *this -= move.getSrc();
   // update the variables to keep track of who's turn it is
   this->getPiece(positionFrom)->setLastMove(positionFrom);
   this->getPiece(positionFrom)->incrementNMoves();
   this->incrementCurrentMove();
   
   
   // check for promote
   if(move.getPromotion())
   {
      *this -= Position(move.getDes());
      board[move.getDes().getRow()][move.getDes().getCol()] = new Queen(move.getDes());
   }

 return true;
   
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
void Board::swap(const Position &pos1, const Position &pos2)// pass by reference
{
   Piece* p1 = board[pos1.getRow()][pos1.getCol()];
   Piece* p2 = board[pos2.getRow()][pos2.getCol()];
   
   board[pos1.getRow()][pos1.getCol()] = p2;

   board[pos2.getRow()][pos2.getCol()] = p1;
// p1

    
//   tell the pieces where they are bu calling p1->set`position\
//    or board[][]->set`posiiton(
   p1->setPosition(pos2);
   p2->setPosition(pos1);
    

   // need to swap type, positoon, fwhite, nmoves, and lastMove

}

/*********************************************************************
 * BOARD ASSIGNMENT OPERATOR
 * Assigns a piece's type to another piece.
 *********************************************************************/
void Board::operator=(Piece* piece)
{
   (*this)(piece->getPosition().getRow(),piece->getPosition().getCol()) = piece;
    
//    int r = piece->getPosition().getRow();
//    int c = piece->getPosition().getCol();
//       
//       delete board[r][c];
//       board[r][c] = piece;
   
}

/*********************************************************************
 * BOARD ASSERT BOARD
 * Makes sure the board looks correct.
 *********************************************************************/
void Board::assertBoard()
{
   
}
