//
//  piece.cpp
//  Lab01
//
//  Created by Mason Schenk on 10/3/23.
//

#include "piece.h"
#include "board.h"
#include "move.h"

// this is to tell who's turn it is. if the last move is odd, then it is black's turn, and vice versa for white
// need to tell what color
bool Piece::isMove()
{
   // need to check if back or white
   
   // white piece coverage
   if(fWhite == true)
   {
      // intial check to see if anyone has moved yet
      if (lastMove == 0)
         return true;
      
      // if the last move is even, that means black just moved, so it is white's turn now
      else if (lastMove % 2 == 0)
         return true;
      
      // if the last move is odd and someone has moved, return false because it's not white's turn
      else
         return false;
   }
   
   // black piece coverage
   else
   {
      // if no moves, return false as white always goes first
      if(lastMove == 0)
         return false;
      
      // if last move is odd, then white just went and it is black's turn
      else if (lastMove % 2 == 1)
         return true;
      
      // if there has been a move and the last move is even, return false as it is not black's turn
      else
         return false;
   }
}

void Pawn::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

void Bishop::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

void Knight::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

void Rook::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

void Queen::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

void King::getMoves(std::set<Move> &moves, const Board &board) const
{
   
}

Piece * builder(PieceType type, int r, int c, bool isWhite)
{
   // intialize object
   Piece *p;
   
   // set type of piece
   switch (type) {
      case KING:
         p = new King;
         break;
      case QUEEN:
         p = new Queen;
         break;
      case ROOK:
         p = new Rook;
         break;
      case BISHOP:
         p = new Bishop;
         break;
      case KNIGHT:
         p = new Knight;
         break;
      case PAWN:
         p = new Pawn;
         break;
      default:
         p = new Space;
   }
   
   // set position
   p->setPosition(r,c);
   
   // set the color
   if (isWhite)
      p->setWhite();
   else
      p->setBlack();
   
   return p;
}
