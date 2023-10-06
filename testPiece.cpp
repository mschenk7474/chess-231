/***********************************************************************
 * Source File:
 *    TEST Piece : test the Piece and related Derived Classes
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

// include the test header, needed classes for composite attributes, and all of the classes to be tested
#include "testPiece.h"
#include "piece.h"
#include "board.h"
#include "move.h"

#include <cassert> // for asserts
#include <set>     // for set

using namespace std;
/*************************************
 * CONSTRUCTOR
 **************************************/

void PieceTest::constructor_space() const
{  // SETUP
   double row = 6;
   double col = 6;
   bool isWhite = false;
   // EXERCISE
   Space pieceTest(row,col,isWhite);
   // VERIFY
   assert(SPACE == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(false == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_pawn() const
{  // SETUP
   double row = 2;
   double col = 4;
   bool isWhite = true;
   // EXERCISE
   Pawn pieceTest(row,col,isWhite);
   // VERIFY
   assert(PAWN == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(true == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_rook() const
{  // SETUP
   double row = 8;
   double col = 8;
   bool isWhite = false;
   // EXERCISE
   Rook pieceTest(row,col,isWhite);
   // VERIFY
   assert(ROOK == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(false == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_bishop() const
{  // SETUP
   double row = 8;
   double col = 6;
   bool isWhite = false;
   // EXERCISE
   Bishop pieceTest(row,col,isWhite);
   // VERIFY
   assert(BISHOP == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(false == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_knight() const
{  // SETUP
   double row = 8;
   double col = 7;
   bool isWhite = false;
   // EXERCISE
   Knight pieceTest(row,col,isWhite);
   // VERIFY
   assert(KNIGHT == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(false == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_queen() const
{  // SETUP
   double row = 1;
   double col = 4;
   bool isWhite = true;
   // EXERCISE
   Queen pieceTest(row,col,isWhite);
   // VERIFY
   assert(QUEEN == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(true == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

void PieceTest::constructor_king() const
{  // SETUP
   double row = 1;
   double col = 5;
   bool isWhite = true;
   // EXERCISE
   King pieceTest(row,col,isWhite);
   // VERIFY
   assert(KING == pieceTest.getLetter());
   assert(Position(row, col) == pieceTest.position);
   assert(true == pieceTest.fWhite);
   assert(0 == pieceTest.nMoves);
   assert(0 == pieceTest.lastMove);
}  // TEARDOWN

/*************************************
 * ASSIGN
 **************************************/
void PieceTest::assign_piece_position() const
{  // SETUP
   Piece *pieceTest = new Pawn;
   pieceTest->position = Position(4,5);
   pieceTest->fWhite = false;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   
   Position rhs;
   rhs.location = 63;
   // EXERCISE
   pieceTest->position = rhs;
   // VERIFY
   assert(PAWN == pieceTest->getLetter());
   assert('?' == pieceTest->position.location);
   assert(false == pieceTest->fWhite);
   assert(0 == pieceTest->nMoves);
   assert(0 == pieceTest->lastMove);
}  // TEARDOWN

void PieceTest::assign_piece_to_piece() const
{  // SETUP
   Piece *pieceTest = new Pawn;
   pieceTest->position = Position(2,1);
   pieceTest->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   
   Piece *rhs = new Queen;
   rhs->position = Position(2,1);
   rhs->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   pieceTest = rhs;
   // VERIFY
   assert(QUEEN == pieceTest->getLetter());
   assert(true == pieceTest->fWhite);
   assert(0 == pieceTest->nMoves);
   assert(0 == pieceTest->lastMove);
}  // TEARDOWN

/*************************************
 * GET LETTER
 **************************************/
void PieceTest::getLetter_space() const
{  // SETUP
   Piece *pieceTest = new Space;
   pieceTest->position = Position(5,5);
   pieceTest->fWhite = false;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(SPACE == letter);
}  // TEARDOWN

void PieceTest::getLetter_pawn() const
{  // SETUP
   Piece *pieceTest = new Pawn;
   pieceTest->position = Position(2,1);
   pieceTest->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(PAWN == letter);
}  // TEARDOWN

void PieceTest::getLetter_rook() const
{  // SETUP
   Piece *pieceTest = new Rook;
   pieceTest->position = Position(1,1);
   pieceTest->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(ROOK == letter);
}  // TEARDOWN

void PieceTest::getLetter_bishop() const
{  // SETUP
   Piece *pieceTest = new Bishop;
   pieceTest->position = Position(8,6);
   pieceTest->fWhite = false;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(BISHOP == letter);
}  // TEARDOWN

void PieceTest::getLetter_knight() const
{  // SETUP
   Piece *pieceTest = new Knight;
   pieceTest->position = Position(8,7);
   pieceTest->fWhite = false;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(KNIGHT == letter);
}  // TEARDOWN

void PieceTest::getLetter_queen() const
{  // SETUP
   Piece *pieceTest = new Queen;
   pieceTest->position = Position(1,4);
   pieceTest->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(QUEEN == letter);
}  // TEARDOWN

void PieceTest::getLetter_king() const
{  // SETUP
   Piece *pieceTest = new King;
   pieceTest->position = Position(1,5);
   pieceTest->fWhite = true;
   pieceTest->nMoves = 0;
   pieceTest->lastMove = 0;
   // EXERCISE
   char letter = pieceTest->getLetter();
   // VERIFY
   assert(KING == letter);
}  // TEARDOWN

/*************************************
 * GET MOVES
 **************************************/
void PieceTest::getMoves_pawn_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(4,4);
   p1.fWhite = true;
   board(4,4) = &p1;
   
   Pawn p2;
   p2.position = Position(5,4);
   p2.fWhite = false;
   board(5,4) = &p2;
   // EXERCISE
   p1.getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(4,4) == p1.position);
   assert(Position(5,4) == p2.position);
}  // TEARDOWN

void PieceTest::getMoves_pawn_simple() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
      
   Pawn p1;
   p1.position = Position(3,1);
   p1.fWhite = true;
   board(4,2) = &p1;
   
   
   // EXERCISE
   p1.getMoves(moves, board);
   // VERIFY
   assert(moves.find(Move("b4b5")) != moves.end());
   assert(Position(3,1) == p1.position);
}  // TEARDOWN

void PieceTest::getMoves_pawn_intial() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   // EXERCISE
   board(1,1)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"b2b3", "b2b4"} == moves));
   assert(Position(1,1) == board(1,1)->position);
}  // TEARDOWN

void PieceTest::getMoves_pawn_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(5,1);
   p1.fWhite = true;
   board(5,1) = &p1;
   
   // EXERCISE
   p1.getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"b6a7p", "b6c7p"} == moves));
   assert(Position(5,1) == p1.position);
   assert(Position(6,0) == board(6,0)->position);
   assert(Position(6,1) == board(6,1)->position);
   assert(Position(6,2) == board(6,2)->position);
}  // TEARDOWN

void PieceTest::getMoves_pawn_enpassant() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(4,1);
   p1.fWhite = true;
   board(4,1) = &p1;
   
   Pawn p2;
   p2.position = Position(4,0);
   p2.fWhite = false;
   p2.nMoves = 1;
   board(4,0) = &p2;
   
   Pawn p3;
   p3.position = Position(4,2);
   p3.fWhite = false;
   p3.nMoves = 1;
   board(4,2) = &p3;
   
   Pawn p4;
   p4.position = Position(5, 1);
   p4.fWhite = false;
   board(5,1) = & p4;
   // EXERCISE
   p1.getMoves(moves, board);
   // VERIFY
   assert(moves.find(Move("b5a6E")) != moves.end());
   assert(moves.find(Move("b5c6E")) != moves.end());
   assert(Position(4,1) == p1.position);
   assert(Position(4,0) == p2.position);
   assert(Position(4,2) == p3.position);
   assert(Position(5,1) == p4.position);
}  // TEARDOWN

void PieceTest::getMoves_pawn_promotion() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(7,2);
   p1.fWhite = true;
   
   Position pos(8,2);
   board -= pos;
   // EXERCISE
   p1.getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"b7b8Q"} == moves);
   assert(Position(2,2) == p1.position);
   assert(SPACE == board(8,2)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_rook_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   // EXERCISE
   board(1,1)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(1,1) == board(1,1)->position);
}  // TEARDOWN

void PieceTest::getMoves_rook_free() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,1);
   p1.fWhite = true;
   board(3,1) = &p1;
   
   Position pos(2,1);
   board -= pos;
   // EXERCISE
   board(1,1)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"a1a2"} == moves);
   assert(Position(1,1) == board(1,1)->position);
   assert(Position(3,1) == p1.position);
   assert(SPACE == board(2,1)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_rook_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,1);
   p1.fWhite = false;
   board(3,1) = &p1;
   
   Position pos(2,1);
   board -= pos;
   // EXERCISE
   board(1,1)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"a1a2", "a1a3p"} == moves));
   assert(Position(1,1) == board(1,1)->position);
   assert(Position(3,1) == p1.position);
   assert(false == p1.fWhite);
   assert(SPACE == board(2,1)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_bishop_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   // EXERCISE
   board(1,3)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(1,3) == board(1,3)->position);
}  // TEARDOWN

void PieceTest::getMoves_bishop_free() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,2);
   p1.fWhite = true;
   board(3,2) = &p1;
   
   Position pos(2,2);
   board -= pos;
   // EXERCISE
   board(1,3)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"c1b2", "c1a3"} == moves));
   assert(Position(1,3) == board(1,3)->position);
   assert(Position(3,2) == p1.position);
   assert(SPACE == board(2,2)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_bishop_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos(2,2);
   board -= pos;
   
   Pawn p1;
   p1.position = Position(2,2);
   p1.fWhite = false;
   board(2,2) = &p1;
   
   
   // EXERCISE
   board(1,3)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"c1b2p"} == moves);
   assert(Position(1,3) == board(1,3)->position);
   assert(Position(2,2) == p1.position);
   assert(false == p1.fWhite);
}  // TEARDOWN

void PieceTest::getMoves_knight_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,3);
   p1.fWhite = true;
   board(3,3) = &p1;
   
   Pawn p2;
   p2.position = Position(3,1);
   p2.fWhite = true;
   board(3,1) = &p2;
   
   Position pos1(2,3);
   board -= pos1;
   
   Position pos2(2,1);
   board -= pos2;
   
   // EXERCISE
   board(1,2)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(1,2) == board(1,2)->position);
   assert(Position(3,3) == p1.position);
   assert(Position(3,1) == p2.position);
   assert(SPACE == board(2,3)->getLetter());
   assert(SPACE == board(2,1)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_knight_free() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   // EXERCISE
   board(1,2)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"b1c3", "b1a3"} == moves));
   assert(Position(1,2) == board(1,2)->position);
}  // TEARDOWN

void PieceTest::getMoves_knight_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,3);
   p1.fWhite = false;
   board(3,3) = &p1;
   
   Pawn p2;
   p2.position = Position(3,1);
   p2.fWhite = true;
   board(3,1) = &p2;
   // EXERCISE
   board(1,2)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"b1c3p"} == moves);
   assert(Position(3,3) == p1.position);
   assert(Position(3,1) == p2.position);
   assert(Position(1,2) == board(1,2)->position);
}  // TEARDOWN

void PieceTest::getMoves_queen_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   // EXERCISE
   board(1,4)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(1,4) == board(1,4)->position);
}  // TEARDOWN

void PieceTest::getMoves_queen_free() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Pawn p1;
   p1.position = Position(3,3);
   p1.fWhite = true;
   board(3,3) = &p1;
   
   Pawn p2;
   p2.position = Position(3,5);
   p2.fWhite = true;
   board(3,5) = &p2;
   
   Position pos1(2,3);
   board -= pos1;
   
   Position pos2(2,5);
   board -= pos2;
   
   Position pos3(1,3);
   board -= pos3;
   
   // EXERCISE
   board(1,4)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"d1c1", "d1c2", "d1b3", "d1a4", "d1e2", "d1f3", "d1g4", "d1h5"} == moves));
   assert(Position(1,4) == board(1,4)->position);
   assert(Position(3,3) == p1.position);
   assert(Position(3,5) == p2.position);
   assert(SPACE == board(2,3)->getLetter());
   assert(SPACE == board(2,5)->getLetter());
   assert(SPACE == board(1,3)->getLetter());
}  // TEARDOWN

void PieceTest::getMoves_queen_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos1(2,3);
   board -= pos1;
   
   Position pos2(2,5);
   board -= pos2;
   
   Pawn p1;
   p1.position = Position(2,3);
   p1.fWhite = false;
   board(2,3) = &p1;
   
   Pawn p2;
   p2.position = Position(2,5);
   p2.fWhite = false;
   board(2,5) = &p2;
   // EXERCISE
   board(1,4)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"d1c2p", "d1e2p"} == moves));
   assert(Position(1,4) == board(1,4)->position);
   assert(Position(2,3) == p1.position);
   assert(Position(2,5) == p2.position);
}  // TEARDOWN

void PieceTest::getMoves_king_free() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos(2,5);
   board -= pos;
   
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"e1e2"} == moves);
   assert(Position(1,5) == board(1,5)->position);
}  // TEARDOWN

void PieceTest::getMoves_king_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
 
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{} == moves);
   assert(Position(1,5) == board(1,5)->position);
}  // TEARDOWN

void PieceTest::getMoves_king_capture() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos(2,5);
   board -= pos;
   
   Pawn p1;
   p1.position = Position(2,5);
   p1.fWhite = false;
 
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert(set<Move>{"e1e2p"} == moves);
   assert(Position(1,5) == board(1,5)->position);
   assert(Position(2,5) == p1.position);
}  // TEARDOWN

void PieceTest::getMoves_king_castle_king_moved() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   board(1,5)->nMoves = 1;
   
   Position pos1(1,6);
   board -= pos1;
   Position pos2(1,4);
   board -= pos2;
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"e1f1", "e1d1"} == moves));
   assert(Position(1,5) == board(1,5)->position);
   assert(1 == board(1,5)->nMoves);
}  // TEARDOWN

void PieceTest::getMoves_king_castle_rooks_moved() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   board(1,1)->nMoves = 1;
   board(1,8)->nMoves = 1;
   
   Position pos1(1,6);
   board -= pos1;
   Position pos2(1,4);
   board -= pos2;
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"e1f1", "e1d1"} == moves));
   assert(Position(1,5) == board(1,5)->position);
   assert(1 == board(1,5)->nMoves);
}  // TEARDOWN

void PieceTest::getMoves_king_castle_blocked() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos1(1,6);
   board -= pos1;
   Position pos2(1,4);
   board -= pos2;
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"e1f1", "e1d1"} == moves));
   assert(Position(1,5) == board(1,5)->position);
}  // TEARDOWN

void PieceTest::getMoves_king_castle() const
{  // SETUP
   Board board(false);
   
   set<Move> moves;
   
   Position pos1(1,6);
   board -= pos1;
   Position pos2(1,4);
   board -= pos2;
   Position pos3(1,3);
   board -= pos3;
   Position pos4(1,2);
   board -= pos4;
   Position pos5(1,7);
   board -= pos4;
   // EXERCISE
   board(1,5)->getMoves(moves, board);
   // VERIFY
   assert((set<Move>{"e1f1", "e1d1", "e1g1C", "e1c1C"} == moves));
   assert(Position(1,5) == board(1,5)->position);
}  // TEARDOWN



