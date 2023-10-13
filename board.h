/***********************************************************************
 * Header File:
 *    BOARD : Keeps track of all elements of chess game, which is on the board
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    Everything we need to know about the game, which is to know the board
 ************************************************************************/

#pragma once

#include "piece.h"   // for PIECE
#include "uiDraw.h"  // for OGSTREAM

class PieceTest;
class TestBoard;
class Interface;

class Board
{
   friend class PieceTest;
   friend class TestBoard;
public:
   
   // constructor & deconstructor
   Board(bool rReset) : currentMove(0) { reset(rReset); }
   ~Board()                            { free();        }
   
   // getters
   int getCurrentMove() const { return currentMove;                                               }
   int getLastMove()    const { return lastMove;                                                  }
   bool whiteTurn()           { return (currentMove % 2 == 0 || currentMove == 0) ? true : false; }
   Piece* getPiece(const Position & pos) const;
   
   // special methods
   void reset(bool fFree);
   void free();
   void display(const Interface & ui, const std::set <Move> & possible);
   void move(const Move &move);
   void resetMoves()           { currentMove = 0; }
   void incrementCurrentMove() { currentMove++;   }
   void setLastMove(int pos)   { lastMove = pos;  }
   
   // operator overrides
   Piece*& operator()(int row, int col)              { Position temp = Position(row, col); return board[temp.getRow()][temp.getCol()]; }
   Piece* const& operator()(int row, int col) const  { Position temp = Position(row, col); return board[temp.getRow()][temp.getCol()]; }
   Piece* const operator[](Position pos)      const  { return board[pos.getRow()][pos.getCol()];                                       }
   void operator-=(Position pos)
   {
      board[pos.getRow()][pos.getCol()] = nullptr;
      board[pos.getRow()][pos.getCol()] = new Space(pos);
   }
   void operator=(Piece* piece);
   
   
private:
   Piece* board[8][8];
   int currentMove;
   int lastMove;
   ogstream gout;
   
   // board-specific methods
   void swap(const Position &pos1, const Position &pos2);
   void assertBoard();
   
};
