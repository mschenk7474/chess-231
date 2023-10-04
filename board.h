/***********************************************************************
 * Header File:
 *    Board : hanldes everything to do with the board
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "piece.h"

class PieceTest;
class TestBoard;

class Board
{
   friend class PieceTest;
   friend class TestBoard;
public:
   Board() {}
   Piece*& operator()(int row, int col) { return board[row][col]; }
   
   Piece* const operator[](Position pos) const  { return board[pos.getRow()][pos.getCol()]; }
   
   void operator-=(Position pos) 
   { 
      board[pos.getRow()][pos.getCol()] = nullptr;
      board[pos.getRow()][pos.getCol()] = new Space(pos);
   }
   
   // getter
   int getCurrentMove() const { return currentMove; }
   Piece getPiece(Position pos);
   
   // special methods
   void reset();
   void swap(Position pos1, Position pos2);
   
private:
   Piece* board[8][8];
   int currentMove;
   
};
