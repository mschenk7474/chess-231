/***********************************************************************
 * Header File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "pieceType.h"
#include "position.h"

#include <set>

class PieceTest;
class Board;
class Move;

class Piece
{
   friend class PieceTest;
public:
   Piece() : position(1, 1), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(Position pos) : position(pos), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col) : position(row,col), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col, bool isWhite) : position(row, col), fWhite(isWhite), nMoves(0), lastMove(0) {}
   Piece& operator=(Position pos);
   Piece& operator=(Piece* piece);
   bool isWhite(){ return true;} // come back and change, only need to compile
   virtual char getLetter() const = 0;
   virtual void getMoves(std::set<Move> &moves, const Board &board) const = 0;
   
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
};

class Space : public Piece
{
   friend class PieceTest;
public:
   Space() : Piece() {}
   Space(Position pos) : Piece(pos) {}
   Space(int row, int col) : Piece(row, col) {}
   Space(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override  { return SPACE;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class Pawn : public Piece
{
   friend class PieceTest;
public:
   Pawn() : Piece() {}
   Pawn(Position pos) : Piece(pos) {}
   Pawn(int row, int col) : Piece(row, col) {}
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override { return PAWN;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class Rook : public Piece
{
   friend class PieceTest;
public:
   Rook() : Piece() {}
   Rook(Position pos) : Piece(pos) {}
   Rook(int row, int col) : Piece(row, col) {}
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override { return ROOK;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class Knight : public Piece
{
   friend class PieceTest;
public:
   Knight() : Piece() {}
   Knight(Position pos) : Piece(pos) {}
   Knight(int row, int col) : Piece(row, col) {}
   Knight(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override { return KNIGHT;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class Bishop : public Piece
{
   friend class PieceTest;
public:
   Bishop() : Piece() {}
   Bishop(Position pos) : Piece(pos) {}
   Bishop(int row, int col) : Piece(row, col) {}
   Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override { return BISHOP;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class Queen : public Piece
{
   friend class PieceTest;
public:
   Queen() : Piece() {}
   Queen(Position pos) : Piece(pos) {}
   Queen(int row, int col) : Piece(row, col) {}
   Queen(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override { return QUEEN;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};

class King : public Piece
{
   friend class PieceTest;
public:
   King() : Piece() {}
   King(Position pos) : Piece(pos) {}
   King(int row, int col) : Piece(row, col) {}
   King(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override{ return KING;}
   void getMoves(std::set<Move> &moves, const Board &board) const override;
};
