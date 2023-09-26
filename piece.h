/***********************************************************************
 * Header File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once
#include "pieceType.h"
#include "position.h"
#include "move.h"
#include "board.h"

#include <set>

class PieceTest;

class Piece
{
   friend class PieceTest;
public:
   Piece() {};
   Piece(int row, int col, bool isWhite) : position(row, col), fWhite(isWhite), nMoves(0), lastMove(0) {};
   Piece& operator=(Position pos);
   Piece& operator=(Piece piece);
   virtual char getLetter() const;
   virtual void getMoves(std::set<Move> &moves, Board board) const;
   
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
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Pawn : Piece
{
   friend class PieceTest;
public:
   Pawn() : Piece() {};
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Rook : Piece
{
   friend class PieceTest;
public:
   Rook() : Piece() {};
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Knight : Piece
{
   friend class PieceTest;
public:
   Knight() : Piece() {};
   Knight(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Bishop : Piece
{
   friend class PieceTest;
public:
   Bishop() : Piece() {};
   Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Queen : Piece
{
   friend class PieceTest;
public:
   Queen() : Piece() {};
   Queen(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class King : Piece
{
   friend class PieceTest;
public:
   King() : Piece() {};
   King(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};
