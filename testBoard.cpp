#include "testBoard.h"
#include <cassert>

using namespace std;


/*************************************
 * RESET
 **************************************/
void TestBoard:: testReset()
{
    // SETUP
    Board board;
    board.currentMove = 5;

    Pawn p1;
    p1.position = (5, 4);
    p1.fWhite = true;
    board(5, 4) = &p1;


    Rook r1;
    r1.position = (3, 6);
    re.fWhite = false;
    board(3, 6) = &r1


    // EXCERSICE
    board.reset();


    // VERIFY
    assert(board.getPosition(Position(5, 4)).getLetter() != PAWN);
    assert(board.getPosition(Position(5, 4)).getLetter() == SPACE);
    assert(board.getPosition(Position(3, 6)).getLetter() != ROOK);
    assert(board.getPosition(Position(3, 6)).getLetter() == SPACE);
    assert(boart.getCurrentMove() == 0);


    // TEARDOWN
}


/*************************************
 * SWAP
 **************************************/
void TestBoard:: testSwapKingRook()
{
    // SETUP
    Board board;
    Position pos1(0,4);
    Position pos2(0,0);


    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPosition(pos1).getLetter() == KING);
    assert(board.getPosition(pos2).getLetter() == ROOK);


    // TEARDOWN
}


void TestBoard:: testSwapPawnSpace()
{
    // SETUP
    Board board;
    Position pos1(1,2);
    Position pos2(2,2);


    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPosition(pos2).getLetter() == PAWN);
    assert(board.getPosition(pos1).getLetter() == SPACE);

    // TEARDOWN

}

void TestBoard:: testSwapBlackPieceWhitePiece()
{
    // SETUP
    Board board;
    Position pos1(1,2);
    Position pos2(6,2);



    // EXCERSICE
    board.swap(pos1, pos2);


    // VERIFY
    assert(board.getPosition(pos2).getLetter() == PAWN);
    assert(board.getPosition(pos1).getLetter() == PAWN);
    assert(board.getPosition(pos2).iswhite() == true);
    assert(board.getPosition(pos1).iswhite() == false);

    
    // TEARDOWN
}

/*************************************
 * -=
 **************************************/
void TestBoard:: testDeletePieceWhite()
{
    // SETUP
    board board;
    Position pos(1,5)

    // EXCERSICE
    board -= pos;

    // VERIFY
    assert(board.getPosition(pos) != null);
    assert(board.getPosition(pos).getLetter() != PAWN);
    assert(board.getPosition(pos).getLetter() == SPACE);


    // TEARDOWN
}

void TestBoard:: testDeletePieceBlack()
{
    // SETUP
    board board;
    Position pos(6,4)

    // EXCERSICE
    board -= pos;

    // VERIFY
    assert(board.getPosition(pos) != null);
    assert(board.getPosition(pos).getLetter() != PAWN);
    assert(board.getPosition(pos).getLetter() == SPACE);


    // TEARDOWN
}


/*************************************
 * GET PIECE
 **************************************/

void TestBoard:: testGetPieceWhite()
{
    // SETUP
    Board board;
    Position pos(1,3);

    // EXCERSICE
    Piece testPiece = board.getPiece(pos);

    //VERIFY
    assert(board.getPiece(pos).type() == Piece);
    assert(testPiece != null);
    assert(testPiece.getPosition() == pos);
    assert(testPiece.isWhite() == true);


    // TEARDOWN
}

void TestBoard:: testGetPieceBlack()
{
    // SETUP
    Board board;
    Position pos(6,5);

    // EXCERSICE
    Piece testPiece = board.getPiece(pos);

    //VERIFY
    assert(board.getPiece(pos).type() == Piece);
    assert(testPiece != null);
    assert(testPiece.getPosition() == pos);
    assert(testPiece.isWhite() == false);


    // TEARDOWN
}

/*************************************
 * TURN
 **************************************/
void TestBoard:: testWhiteTurnTrue()
{
    // SETUP
    Board board;
    board.getCurrentMove() = 4;

    // EXCERSICE
    bool turn = board.WhiteTurn();

    // VERIFY
    assert(board.whiteTurn().type == bool);
    assert(turn != null);
    assert(board.getCurrentMove() % 2 == 0);
    assert(turn == true);


    // TEARDOWN
}

void TestBoard:: testWhiteTurnFalse()
{
    // SETUP
    Board board;
    board.getCurrentMove() = 7;

    // EXCERSICE
    bool turn = board.WhiteTurn();

    // VERIFY
    assert(board.whiteTurn().type == bool);
    assert(turn != null);
    assert(board.getCurrentMove() % 2 != 0);
    assert(turn == false);


    // TEARDOWN
}


/*************************************
 * CURRENT MOVE
 **************************************/
void TestBoard:: testGetCurrentMove()
{
    // SETUP
    Board board;
    board.currentMove = 6;

    // EXCERSICE

    int move = board.getCurrentMove();

    // VERIFY
    assert(board.getCurrentMove().type == int);
    assert(move != null);
    assert(board.getCurrentMove() > 0);
    assert(move == 6);

    // TEARDOWN
}
