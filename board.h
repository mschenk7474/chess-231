/***********************************************************************
 * Header File:
 *    Board : hanldes everything to do with the board
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "piece.h"

class PieceTest;

class Board
{
   friend class PieceTest;
public:
   Board() {}
   const Piece* operator()(int row, int col) const { return board[row][col]; }
   Piece*& operator()(int row, int col) { return board[row][col]; }
   
   Piece* const operator()(Position pos) const  { return board[pos.getRow()][pos.getCol()]; }
   
   void operator-=(Position pos) { board[pos.getRow()][pos.getCol()] = nullptr; board[pos.getRow()][pos.getCol()] = new Space(pos);}
   
   
private:
   Piece* board[8][8];
   
};
