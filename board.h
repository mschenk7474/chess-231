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
   
   // constructors
   Board(bool rReset) : currentMove(0) { reset(rReset); }
   ~Board()                            { free();        }
   
   // getter
   int getCurrentMove() const { return currentMove;                                              }
   bool whiteTurn()           { return (currentMove % 2 == 0 || currentMove == 0) ? true : false; }
   Piece* getPiece(Position pos); // come back and do
   
   // special methods
   void reset(bool fFree);
   void free();  // come back and do
   void display(Position posHover, Position posSel); // come back and do
   void move(Move move); // come back and do
   void resetMoves() {currentMove = 0;}
   
   // operator overrides
   Piece*& operator()(int row, int col) { Position temp = Position(row, col); return board[temp.getRow()][temp.getCol()]; }
   Piece* const& operator()(int row, int col) const { Position temp = Position(row, col); return board[temp.getRow()][temp.getCol()]; }
   Piece* const operator[](Position pos) const  { return board[pos.getRow()][pos.getCol()]; }
   void operator-=(Position pos)
   {
      board[pos.getRow()][pos.getCol()] = nullptr;
      board[pos.getRow()][pos.getCol()] = new Space(pos);
   }
   // sets the piece passing in to the piece calling this assignment operator
   void operator=(Piece* piece); // come back and do
   
   
private:
   Piece* board[8][8];
   int currentMove;
   ogstream gout;
   
   
   void swap(Position pos1, Position pos2);
   void assertBoard();
   
};
