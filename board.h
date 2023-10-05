/***********************************************************************
 * Header File:
 *    Board : hanldes everything to do with the board
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "piece.h"
#include "uiDraw.h"

class PieceTest;
class TestBoard;

class Board
{
   friend class PieceTest;
   friend class TestBoard;
public:
   
   // constructor
   Board(ogstream &gout,bool rReset) : currentMove(0), gout(gout) { reset(rReset); }
   
   // getter
   int getCurrentMove() const { return currentMove; }
   Piece* getPiece(Position pos); // come back and do
   bool whiteTurn(); // come back and do
   
   // special methods
   void reset(bool fFree); // come back and do
   void free();  // come back and do
   void display(Position posHover, Position posSel);
   void move(Move move);
   
   // operator overrides
   Piece*& operator()(int row, int col) { return board[row][col]; }
   Piece* const operator[](Position pos) const  { return board[pos.getRow()][pos.getCol()]; }
   void operator-=(Position pos)
   {
      board[pos.getRow()][pos.getCol()] = nullptr;
      board[pos.getRow()][pos.getCol()] = new Space(pos);
   }
   // sets the piece passing in to the piece calling this assignment operator
   void operator=(Piece piece); // come back and do
   
   
private:
   Piece* board[8][8];
   int currentMove;
   ogstream gout;
   
   
   void swap(Position pos1, Position pos2);
   
};
