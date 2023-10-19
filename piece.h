/***********************************************************************
 * Header File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    Handles all of the different types of pieces and how to create them.
 ************************************************************************/

#pragma once

#include "pieceType.h"  // for PIECETYPE
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for OGSTREAM
#include <set>          // for GETMOVES

class PieceTest;
class TestBoard;
class Board;
class Move;

/***************************************************
 * PIECE
 * An abstract class for the different pieces on the board
 ***************************************************/
class Piece
{
   friend class PieceTest;
   friend class TestBoard;
public:
   
   // constructors & deconstructor
   Piece() : position(1, 1), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(Position pos) : position(pos), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col) : position(row,col), fWhite(false), nMoves(0), lastMove(0) {}
   Piece(int row, int col, bool isWhite) : position(row, col), fWhite(isWhite), nMoves(0), lastMove(0) {}
   virtual ~Piece() = default;
   
   // setters
   void setPosition(Position pos)      { position = pos;        }
   void setPosition(int row, int col)  { position.set(row,col); }
   void setWhite()                     { fWhite = true;         }
   void setBlack()                     { fWhite = false;        }
   void incrementNMoves()              { nMoves++;              }
   void setLastMove(int pos)           { lastMove = pos;        }
   
   // getters
   bool isMove();
   bool justMoved();
   bool isWhite()               { return fWhite == true;                   }
   int getNMoves() const        { return nMoves;                           }
   Position getPosition() const { return position;                         }
   int getLastMove() const      {return lastMove;                          }
   
   // pure virtual methods
   virtual char getLetter() const = 0;
   virtual void getMoves(std::set<Move> &moves, const Board &board) const = 0;
   virtual void display(ogstream &gout) = 0;
   
   // operator overrides
   void operator=(Position pos) { position.set(pos.getRow(), pos.getCol()); }
   
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

/***************************************************
 * SPACE
 * Handles the creation of a Space
 ***************************************************/
class Space : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Space() : Piece() {}
   Space(Position pos) : Piece(pos) {}
   Space(int row, int col) : Piece(row, col) {}
   Space(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override  { return SPACE;}
   void getMoves(std::set<Move> &moves, const Board &board) const override {}
   
   // special methods
   void display(ogstream &gout) override {}
};

/***************************************************
 * PAWN
 * Handles the creation of a Pawn
 ***************************************************/
class Pawn : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Pawn() : Piece() {}
   Pawn(Position pos) : Piece(pos) {}
   Pawn(int row, int col) : Piece(row, col) {}
   Pawn(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
 
   
   // getters
   char getLetter() const override       { return PAWN;                                   }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override { gout.drawPawn(position.getLocation(), !fWhite); }
   bool canEnPassant(const Board &board, const Position &opposingPosition) const;
   bool canPromote(const Board &board, const Position &possiblePosition) const;
};

/***************************************************
 * ROOK
 * Handles the creation of a Rook
 ***************************************************/
class Rook : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Rook() : Piece() {}
   Rook(Position pos) : Piece(pos) {}
   Rook(int row, int col) : Piece(row, col) {}
   Rook(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override       { return ROOK;                                   }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override { gout.drawRook(position.getLocation(), !fWhite); }
};

/***************************************************
 * KNIGHT
 * Handles the creation of a Knight
 ***************************************************/
class Knight : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Knight() : Piece() {}
   Knight(Position pos) : Piece(pos) {}
   Knight(int row, int col) : Piece(row, col) {}
   Knight(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override       { return KNIGHT;                                    }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override { gout.drawKnight(position.getLocation(), !fWhite); }
};

/***************************************************
 * BISHOP
 * Handles the creation of a Bishop
 ***************************************************/
class Bishop : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Bishop() : Piece() {}
   Bishop(Position pos) : Piece(pos) {}
   Bishop(int row, int col) : Piece(row, col) {}
   Bishop(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override       { return BISHOP;                                    }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override { gout.drawBishop(position.getLocation(), !fWhite); }
};

/***************************************************
 * QUEEN
 * Handles the creation of a Queen
 ***************************************************/
class Queen : public Piece
{
   friend class PieceTest;
public:
   // constructors
   Queen() : Piece() {}
   Queen(Position pos) : Piece(pos) {}
   Queen(int row, int col) : Piece(row, col) {}
   Queen(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override       { return QUEEN;                                    }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override { gout.drawQueen(position.getLocation(), !fWhite); }
};

/***************************************************
 * KING
 * Handles the creation of a Knight
 ***************************************************/
class King : public Piece
{
   friend class PieceTest;
public:
   // constructors
   King() : Piece() {}
   King(Position pos) : Piece(pos) {}
   King(int row, int col) : Piece(row, col) {}
   King(int row, int col, bool isWhite) : Piece(row, col, isWhite) {}
   
   // getters
   char getLetter() const override        { return KING;                                    }
   void getMoves(std::set<Move> &moves, const Board &board) const override;
   
   // special methods
   void display(ogstream &gout) override  { gout.drawKing(position.getLocation(), !fWhite); }
   void addCastle(const Board &board, std::set<Move> &moves, Move &move) const;
};

// functions pertaining to the piece classes
Piece * builder(PieceType type, int r, int c, bool isWhite);
void insertMove(std::set<Move> &moves, Move &move, Position possiblePos, Position currentPosition, char letter);

/***************************************************
 * RC
 * A simple structure for piece-specific moves
 ***************************************************/
struct RC
{
   int row;
   int col;
};
