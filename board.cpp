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
   return new Space;
}

/*********************************************************************
 * BOARD MOVE
 * Move's the piece on the board
 *********************************************************************/
void Board::move(Move move)
{
   
}

/*********************************************************************
 * BOARD WHITE TURN
 * Check's to see if it is white's turn.
 *********************************************************************/
bool Board::whiteTurn()
{
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
void Board::swap(Position pos1, Position pos2)
{
   
}

/*********************************************************************
 * BOARD ASSIGNMENT OPERATOR
 * Assigns a piece to a given place on the board.
 *********************************************************************/
void Board::operator=(Piece piece)
{
   
}

/*********************************************************************
 * BOARD ASSERT BOARD
 * Makes sure the board looks correct.
 *********************************************************************/
void Board::assertBoard()
{
   
}
