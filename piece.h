/***********************************************************************
 * Header File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once
#include "pieceType.h"
#include "position.h"

class PieceTest;

class Piece
{
   friend class PieceTest;
public:
   Piece() {};
   Piece(int row, int col, bool isWhite) : position(row, col), fWhite(isWhite), nMoves(0), lastMove(0) {};
   virtual char getLetter() const;
   
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
};

class Space : Piece
{
   friend class PieceTest;
public:
   Space() : Piece() {};
   Space(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
};

class Pawn : Piece
{
   friend class PieceTest;
public:
   Pawn() : Piece() {};
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};

class Rook : Piece
{
   friend class PieceTest;
public:
   Rook() : Piece() {};
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};

class Knight : Piece
{
   friend class PieceTest;
public:
   Knight() : Piece() {};
   Knight(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};

class Bishop : Piece
{
   friend class PieceTest;
public:
   Bishop() : Piece() {};
   Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};

class Queen : Piece
{
   friend class PieceTest;
public:
   Queen() : Piece() {};
   Queen(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};

class King : Piece
{
   friend class PieceTest;
public:
   King() : Piece() {};
   King(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
};
