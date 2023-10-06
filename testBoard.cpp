#include "testBoard.h"
#include <cassert>

using namespace std;


/*************************************
 * RESET
 **************************************/
void TestBoard:: testReset() const
{
   // SETUP
   Board board(false);
   board.currentMove = 5;

   Pawn p1;
   p1.position = Position(5, 4);
   p1.fWhite = true;
   board(5, 4) = &p1;


   Rook r1;
   r1.position = Position(3, 6);
   r1.fWhite = false;
   board(3, 6) = &r1;


    // EXCERSICE
    board.reset(false);


    // VERIFY
   assert(board.getPiece(Position(5, 4))->getLetter() != PAWN);
    assert(board.getPiece(Position(5, 4))->getLetter() == SPACE);
    assert(board.getPiece(Position(3, 6))->getLetter() != ROOK);
    assert(board.getPiece(Position(3, 6))->getLetter() == SPACE);
    assert(board.getCurrentMove() == 0);


    // TEARDOWN
}


/*************************************
 * SWAP
 **************************************/
void TestBoard:: testSwapKingRook() const
{
    // SETUP
    Board board(false);
    Position pos1(0,4);
    Position pos2(0,0);


    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPiece(pos1)->getLetter() == KING);
    assert(board.getPiece(pos2)->getLetter() == ROOK);


    // TEARDOWN
}


void TestBoard:: testSwapPawnSpace() const
{
    // SETUP
    Board board(false);
    Position pos1(1,2);
    Position pos2(2,2);


    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPiece(pos2)->getLetter() == PAWN);
    assert(board.getPiece(pos1)->getLetter() == SPACE);

    // TEARDOWN

}

void TestBoard:: testSwapBlackPieceWhitePiece() const
{
    // SETUP
    Board board(false);
    Position pos1(1,2);
    Position pos2(6,2);



    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPiece(pos2)->getLetter() == PAWN);
    assert(board.getPiece(pos1)->getLetter() == PAWN);
    assert(board.getPiece(pos2)->isWhite() == true);
    assert(board.getPiece(pos1)->isWhite() == false);

    
    // TEARDOWN
}

/*************************************
 * -=
 **************************************/
void TestBoard:: testDeletePieceWhite() const
{
    // SETUP
    Board board(false);
    Position pos(1,5);

    // EXCERSICE
    board -= pos;

    // VERIFY
    assert(board.getPiece(pos) != NULL);
    assert(board.getPiece(pos)->getLetter() != PAWN);
    assert(board.getPiece(pos)->getLetter() == SPACE);


    // TEARDOWN
}

void TestBoard:: testDeletePieceBlack() const
{
    // SETUP
    Board board(false);
    Position pos(6,4);

    // EXCERSICE
    board -= pos;

    // VERIFY
    assert(board.getPiece(pos) != NULL);
    assert(board.getPiece(pos)->getLetter() != PAWN);
    assert(board.getPiece(pos)->getLetter() == SPACE);


    // TEARDOWN
}


/*************************************
 * GET PIECE
 **************************************/

void TestBoard:: testGetPieceWhite() const
{
    // SETUP
    Board board(false);
    Position pos(1,3);

    // EXCERSICE
    Piece* testPiece = board.getPiece(pos);

    //VERIFY
    assert(testPiece != NULL);
    assert(testPiece->position == pos);
    assert(testPiece->fWhite == true);


    // TEARDOWN
}

void TestBoard:: testGetPieceBlack() const
{
    // SETUP
    Board board(false);
    Position pos(6,5);

    // EXCERSICE
    Piece* testPiece = board.getPiece(pos);

    //VERIFY
    assert(testPiece != NULL);
    assert(testPiece->position == pos);
    assert(testPiece->fWhite == false);


    // TEARDOWN
}

/*************************************
 * TURN
 **************************************/
void TestBoard:: testWhiteTurnTrue() const
{
    // SETUP
    Board board(false);
    board.currentMove = 4;

    // EXCERSICE
    bool turn = board.whiteTurn();

    // VERIFY
    assert(board.getCurrentMove() % 2 == 0);
    assert(turn == true);


    // TEARDOWN
}

void TestBoard:: testWhiteTurnFalse() const
{
    // SETUP
    Board board(false);
    board.currentMove = 7;

    // EXCERSICE
    bool turn = board.whiteTurn();

    // VERIFY
    assert(board.getCurrentMove() % 2 != 0);
    assert(turn == false);


    // TEARDOWN
}


/*************************************
 * CURRENT MOVE
 **************************************/
void TestBoard:: testGetCurrentMove() const
{
    // SETUP
    Board board(false);
    board.currentMove = 6;

    // EXCERSICE

    int move = board.getCurrentMove();

    // VERIFY
    assert(board.getCurrentMove() > 0);
    assert(move == 6);

    // TEARDOWN
}

/*************************************
 * MOVE : PAWN
 **************************************/
void TestBoard::move_pawnSimple() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_pawnCapture() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_pawnDouble() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_pawnEnpassant() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_pawnPromotion() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

/*************************************
 * MOVE : ROOK
 **************************************/
void TestBoard::move_rookSlide() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_rookAttack() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

/*************************************
 * MOVE : BISHOP
 **************************************/
void TestBoard::move_bishopSlide() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_bishopAttack() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

/*************************************
 * MOVE : KNIGHT
 **************************************/
void TestBoard::move_knightMove() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_knightAttack() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

/*************************************
 * MOVE : QUEEN
 **************************************/
void TestBoard::move_queenSlide() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_queenAttack() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

/*************************************
 * MOVE : KING
 **************************************/
void TestBoard::move_kingMove() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_kingAttack() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_kingShortCastle() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN

void TestBoard::move_kingLongCastle() const
{  // SETUP
   // EXERCISE
   // VERIFY
}  // TEARDOWN
