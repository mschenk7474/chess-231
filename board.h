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
   
   Piece& operator[](int row, int col) { return board[row][col];}
   
   
private:
   Piece board[8][8];
   
};
