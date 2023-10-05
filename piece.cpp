//
//  piece.cpp
//  Lab01
//
//  Created by Mason Schenk on 10/3/23.
//

#include "piece.h"
#include "board.h"
#include "move.h"

bool Piece::isMove()
{
   // need to check if black or white
   
   // white piece coverage
   if(fWhite == true)
   {
      // intial check to see if anyone has moved yet
      if (nMoves == 0)
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
      if(nMoves == 0)
         return false;
      
      // if last move is odd, then white just went and it is black's turn
      else if (lastMove % 2 == 1)
         return true;
      
      // if there has been a move and the last move is even, return false as it is not black's turn
      else
         return false;
   }
}

bool Piece::justMoved()
{
   // this will need to check if the piece in question just moved
   // will follow same struct as is move
   
   // no matter what, if nMoves is 0, need to return false as no one has moved
   if(nMoves == 0)
      return false;
   
   // white piece coverage
   if(fWhite == true)
   {
      // check if white just moved aka last move is odd
      if(lastMove % 2 == 1)
         return true;
      
      // otherwise return false
      else
         return false;
   }
   
   // black piece coverage
   else
   {
      // check if black just moved aka last move is even
      if(lastMove % 2 == 0)
         return true;
      
      // otherwise return false
      else
         return false;
   }
}

Piece* Piece::operator=(Position pos)
{
   return new Space;
}
Piece* Piece::operator=(Piece* piece)
{
   return new Space;
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
