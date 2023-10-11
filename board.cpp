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
 * Move's the piece on the board
 *********************************************************************/
void Board::move(Move move)
{
   int positionFrom = move.getSrc().getLocation();
   int positionTo = move.getDes().getLocation();
   std::set<Move> moves;
   
   // do not move if not indicated
   if (positionFrom == -1 || positionTo == -1)
      return;
   assert(positionFrom >= 0 && positionFrom < 64);
   assert(positionTo >= 0 && positionTo < 64);
   
   // finding possible moves from current location
   this->getPiece(positionFrom)->getMoves(moves, *this);
   
   // only move there if the suggested move is on the set of possible moves
   if(moves.find(move) != moves.end())
   {
      // handle castle for both sides
      // king side first
      if (move.getCastleK())
         this->swap(Position(move.getDes().getRow(), 7), Position(move.getDes().getRow(), 5));
      
      // queen side
      if(move.getCastleQ())
         this->swap(Position(move.getDes().getRow(), 0), Position(move.getDes().getRow(), 2));
      
      // check for enpassant
      if(move.getEnPassant())
      {
        if(this->getPiece(positionFrom)->isWhite())
           *this -= Position(move.getDes().getRow() - 1, move.getDes().getCol());
         
         else
            *this -= Position(move.getDes().getRow() + 1, move.getDes().getCol());
      }
      
      // moves the piece
      board[move.getDes().getRow()][move.getDes().getCol()] = board[move.getSrc().getRow()][move.getSrc().getCol()];
      
      // makes the previous piece a space
      *this -= Position(move.getSrc());
      
      // check for promote
      if(move.getPromotion())
      {
         *this -= Position(move.getDes());
         board[move.getDes().getRow()][move.getDes().getCol()] = new Queen(move.getDes());
      }
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
      board[6][c] = builder(PAWN, 6, c, true);
      board[1][c] = builder(PAWN, 1, c, false);
   }
   
   // white pieces
   board[7][0] = builder(ROOK, 7, 0, true);
   board[7][1] = builder(KNIGHT, 7, 1, true);
   board[7][2] = builder(BISHOP, 7, 2, true);
   board[7][3] = builder(QUEEN, 7, 3, true);
   board[7][4] = builder(KING, 7, 4, true);
   board[7][5] = builder(BISHOP, 7, 5, true);
   board[7][6] = builder(KNIGHT, 7, 6, true);
   board[7][7] = builder(ROOK, 7, 7, true);
   
   // black pieces
   board[0][0] = builder(ROOK, 0, 0, false);
   board[0][1] = builder(KNIGHT, 0, 1, false);
   board[0][2] = builder(BISHOP, 0, 2, false);
   board[0][3] = builder(QUEEN, 0, 3, false);
   board[0][4] = builder(KING, 0, 4, false);
   board[0][5] = builder(BISHOP, 0, 5, false);
   board[0][6] = builder(KNIGHT, 0, 6, false);
   board[0][7] = builder(ROOK, 0, 7, false);
   
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
void Board::swap(Position pos1, Position pos2)
{
   Piece* lhsTemp = board[pos1.getRow()][pos1.getCol()];
   Piece* lhs = board[pos1.getRow()][pos1.getCol()];
   Piece* rhs = board[pos2.getRow()][pos2.getCol()];
   
   // need to swap type, position, fwhite, nmoves, and lastMove
   lhs = nullptr;
   lhs = *new Piece*(rhs);
   board[pos1.getRow()][pos1.getCol()] = lhs;
   
   rhs = nullptr;
   rhs = *new Piece*(lhsTemp);
   board[pos2.getRow()][pos2.getCol()] = rhs;
   
   lhsTemp = nullptr;
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
