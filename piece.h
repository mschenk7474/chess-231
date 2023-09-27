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

#include <set>

class PieceTest;
class Board;

class Piece
{
   friend class PieceTest;
public:
   Piece() {};
   Piece(Position pos) : position(pos), fWhite(false), nMoves(0), lastMove(0) {};
   Piece(int row, int col) : position(row,col), fWhite(false), nMoves(0), lastMove(0) {};
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

class Space : public Piece
{
   friend class PieceTest;
public:
   Space() : Piece() {};
   Space(Position pos) : Piece(pos) {};
   Space(int row, int col) : Piece(row, col) {};
   Space(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Pawn : public Piece
{
   friend class PieceTest;
public:
   Pawn() : Piece() {};
   Pawn(Position pos) : Piece(pos) {};
   Pawn(int row, int col) : Piece(row, col) {};
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Rook : public Piece
{
   friend class PieceTest;
public:
   Rook() : Piece() {};
   Rook(Position pos) : Piece(pos) {};
   Rook(int row, int col) : Piece(row, col) {};
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Knight : public Piece
{
   friend class PieceTest;
public:
   Knight() : Piece() {};
   Knight(Position pos) : Piece(pos) {};
   Knight(int row, int col) : Piece(row, col) {};
   Knight(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Bishop : public Piece
{
   friend class PieceTest;
public:
   Bishop() : Piece() {};
   Bishop(Position pos) : Piece(pos) {};
   Bishop(int row, int col) : Piece(row, col) {};
   Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class Queen : public Piece
{
   friend class PieceTest;
public:
   Queen() : Piece() {};
   Queen(Position pos) : Piece(pos) {};
   Queen(int row, int col) : Piece(row, col) {};
   Queen(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};

class King : public Piece
{
   friend class PieceTest;
public:
   King() : Piece() {};
   King(Position pos) : Piece(pos) {};
   King(int row, int col) : Piece(row, col) {};
   King(int row, int col, bool isWhite) : Piece(row, col, isWhite) {};
   virtual char getLetter() const override;
   virtual void getMoves(std::set<Move> &moves, Board board) const override;
};
