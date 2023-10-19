/***********************************************************************
 * Source File:
 *    TEST BOARD : Testing the Board class
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    The unit tests for Board
 ************************************************************************/

#include "testBoard.h" // for TESTBOARD
#include <cassert>     // for ASSERT

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
    assert(board.getPiece(pos1)->getLetter() == ROOK);
    assert(board.getPiece(pos2)->getLetter() == KING);


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
   Board board(false);
   
   Move move("a2a3");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(1,0)->getLetter());
   assert(PAWN == board(2,0)->getLetter());
}  // TEARDOWN

void TestBoard::move_pawnCapture() const
{  // SETUP
   Board board(false);
   
   Pawn p1;
   p1.position = Position(2,2);
   p1.fWhite = false;
   board(2,1) = &p1;
   
   Move move("a2b3p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(1,0)->getLetter());
   assert(PAWN == board(2,1)->getLetter());
}  // TEARDOWN

void TestBoard::move_pawnDouble() const
{  // SETUP
   Board board(false);
   
   Move move("a2a4");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(1,0)->getLetter());
   assert(PAWN == board(3,0)->getLetter());
}  // TEARDOWN

void TestBoard::move_pawnEnpassant() const
{  // SETUP
   Board board(false);
   
   Pawn *p1 = new Pawn;
   p1->position = Position(4,1);
   p1->fWhite = true;
   board(4,1) = p1;
   
   Pawn *p2 = new Pawn;
   p2->position = Position(4,0);
   p2->fWhite = false;
   p2->nMoves = 1;
   board(4,0) = p2;
   
   Move move("b5a6E");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(4,1)->getLetter());
   assert(SPACE == board(4,0)->getLetter());
}  // TEARDOWN

void TestBoard::move_pawnPromotion() const
{  // SETUP
   Board board(false);
   
   Pawn *p1 = new Pawn;
   p1->position = Position(6,2);
   p1->fWhite = true;
   board(6,2) = p1;
   
   Position pos1(7,1);
   board[pos1]->fWhite = true;
   
   Position pos2(7,2);
   board -= pos2;
   
   Position pos3(7,3);
   board[pos3]->fWhite = true;
   
   Move move("c7c8Q");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(6,2)->getLetter());
   assert(QUEEN == board(7,2)->getLetter());
}  // TEARDOWN

/*************************************
 * MOVE : ROOK
 **************************************/
void TestBoard::move_rookSlide() const
{  // SETUP
   Board board(false);
   
   Pawn *p1 = new Pawn;
   p1->position = Position(2,0);
   p1->fWhite = true;
   board(2,0) = p1;
   
   Position pos(1,0);
   board -= pos;
   
   Move move("a1a2");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(ROOK == board(1,0)->getLetter());
   assert(SPACE == board(0,0)->getLetter());
}  // TEARDOWN

void TestBoard::move_rookAttack() const
{  // SETUP
   Board board(false);
   
   Position pos(1,0);
   board -= pos;
   
   Pawn *p1 = new Pawn;
   p1->position = Position(1,0);
   p1->fWhite = false;
   board(1,0) = p1;
   
   Move move("a1a2p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(ROOK == board(1,0)->getLetter());
   assert(SPACE == board(0,0)->getLetter());
}  // TEARDOWN

/*************************************
 * MOVE : BISHOP
 **************************************/
void TestBoard::move_bishopSlide() const
{  // SETUP
   Board board(false);
   
   Position pos(1,1);
   board -= pos;
   
   Move move("c1b2");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(BISHOP == board(1,1)->getLetter());
   assert(SPACE == board(0,2)->getLetter());
}  // TEARDOWN

void TestBoard::move_bishopAttack() const
{  // SETUP
   Board board(false);
   
   Pawn *p1 = new Pawn;
   p1->position = Position(1,1);
   p1->fWhite = false;
   board(1,1) = p1;
   
   Move move("c1b2p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(BISHOP == board(1,1)->getLetter());
   assert(SPACE == board(0,2)->getLetter());
}  // TEARDOWN

/*************************************
 * MOVE : KNIGHT
 **************************************/
void TestBoard::move_knightMove() const
{  // SETUP
   Board board(false);
   
   Move move("b1c3");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(0,1)->getLetter());
   assert(KNIGHT == board(2,2)->getLetter());
}  // TEARDOWN

void TestBoard::move_knightAttack() const
{  // SETUP
   Board board(false);
   
   Pawn *p2 = new Pawn;
   p2->position = Position(2,2);
   p2->fWhite = false;
   board(2,2) = p2;
   
   Move move("b1c3p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(0,1)->getLetter());
   assert(KNIGHT == board(2,2)->getLetter());
}  // TEARDOWN

/*************************************
 * MOVE : QUEEN
 **************************************/
void TestBoard::move_queenSlide() const
{  // SETUP
   Board board(false);
   
   board -= Position(1, 2);
   
   Move move("d1a4");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(0,3)->getLetter());
   assert(SPACE == board(1,2)->getLetter());
   assert(SPACE == board(2,1)->getLetter());
   assert(QUEEN == board(3,0)->getLetter());
}  // TEARDOWN

void TestBoard::move_queenAttack() const
{  // SETUP
   Board board(false);
   
   board(1,3)->fWhite = false;
   Move move("d1d2p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == board(0,3)->getLetter());
   assert(QUEEN == board(1,3)->getLetter());
}  // TEARDOWN

/*************************************
 * MOVE : KING
 **************************************/
void TestBoard::move_kingMove() const
{  // SETUP
   Board board(false);
   
   board -= Position(1,4);
   Move move("e1e2");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == (board(0,4)->getLetter()));
   assert(KING == (board(1,4)->getLetter()));
}  // TEARDOWN

void TestBoard::move_kingAttack() const
{  // SETUP
   Board board(false);
   
   board(1,4)->fWhite = false;
   Move move("e1e2p");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == (board(0,4)->getLetter()));
   assert(KING == (board(1,4)->getLetter()));
}  // TEARDOWN

void TestBoard::move_kingShortCastle() const
{  // SETUP
   Board board(false);
   
   board -= Position(0,5);
   board -= Position(0,6);
   Move move("e1g1c");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == (board(0,4)->getLetter()));
   assert(ROOK == (board(0,5)->getLetter()));
   assert(KING == (board(0,6)->getLetter()));
   assert(SPACE == (board(0,7)->getLetter()));
}  // TEARDOWN

void TestBoard::move_kingLongCastle() const
{  // SETUP
   Board board(false);
   
   board -= Position(0,1);
   board -= Position(0,2);
   board -= Position(0,3);
   Move move("e1b1C");
   // EXERCISE
   board.move(move);
   // VERIFY
   assert(SPACE == (board(0,0)->getLetter()));
   assert(KING == (board(0,1)->getLetter()));
   assert(ROOK == (board(0,2)->getLetter()));
   assert(SPACE == (board(0,3)->getLetter()));
   assert(SPACE == (board(0,4)->getLetter()));
}  // TEARDOWN
