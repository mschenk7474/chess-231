/***********************************************************************
 * Header File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"

#include <set>

class PieceTest;
class TestBoard;
class Board;
class Move;

class Piece
{
   friend class PieceTest;
   friend class TestBoard;
public:
   
   // constructors
   Piece() : position(1, 1), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(Position pos) : position(pos), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col) : position(row,col), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col, bool isWhite) : position(row, col), fWhite(isWhite), nMoves(0), lastMove(0) {}
   virtual ~Piece() {};
   
   // setters
   void setPosition(Position pos)      { position = pos;        }
   void setPosition(int row, int col)  { position.set(row,col); }
   void setWhite()                     { fWhite = true;         }
   void setBlack()                     { fWhite = false;        }
   
   // getters
   bool isMove();
   bool justMoved();
   bool isWhite()               { return fWhite == true;                   }
   int getNMoves() const        { return nMoves;                           }
   Position getPosition() const { return position;                         }
   
   // pure virtual methods
   virtual char getLetter() const = 0;
   virtual void getMoves(std::set<Move> &moves, const Board &board) const = 0;
   virtual void display(ogstream &gout) = 0;
   
   // operator overrides
   void operator=(Position pos) { position.set(pos.getRow(), pos.getCol()); }
   Piece* operator=(Piece* piece); // come back and do
   
   // special methods
   bool canMove() const
   {
      // checks boundaries limits and if the spot in question is a space
      return (this->position.getLocation() < 0 || this->position.getLocation() >= 64 || this->getLetter() == SPACE) ? false : true;
   }
   
   
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
   void getMoves(std::set<Move> &moves, const Board &board) const override {}
   void display(ogstream &gout) override {}
};

class Pawn : public Piece
{
   friend class PieceTest;
public:
   Pawn() : Piece() {}
   Pawn(Position pos) : Piece(pos) {}
   Pawn(int row, int col) : Piece(row, col) {}
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override       { return PAWN;                                   }
   void display(ogstream &gout) override { gout.drawPawn(position.getLocation(), fWhite); }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   bool canEnPassant(const Board &board, Position opposingPosition) const;
   bool canPromote(const Board &board, Position possiblePosition) const;
};

class Rook : public Piece
{
   friend class PieceTest;
public:
   Rook() : Piece() {}
   Rook(Position pos) : Piece(pos) {}
   Rook(int row, int col) : Piece(row, col) {}
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   char getLetter() const override       { return ROOK;                                   }
   void display(ogstream &gout) override { gout.drawRook(position.getLocation(), fWhite); }
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
   char getLetter() const override       { return KNIGHT;                                   }
   void display(ogstream &gout) override { gout.drawKnight(position.getLocation(), fWhite); }
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
   char getLetter() const override       { return BISHOP;                                   }
   void display(ogstream &gout) override { gout.drawBishop(position.getLocation(), fWhite); }
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
   char getLetter() const override       { return QUEEN;                                   }
   void display(ogstream &gout) override { gout.drawQueen(position.getLocation(), fWhite); }
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
   char getLetter() const override        { return KING;                                   }
   void display(ogstream &gout) override  { gout.drawKing(position.getLocation(), fWhite); }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   void addCastle(const Board &board, std::set<Move> &moves, Move &move) const;
};


Piece * builder(PieceType type, int r, int c, bool isWhite);
void insertMove(std::set<Move> &moves, Move &move, Position possiblePos, Position currentPosition, char letter);

struct RC
{
   int row;
   int col;
};
