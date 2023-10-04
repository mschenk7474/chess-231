//
//  testBoard.hpp
//  Lab01
//
//  Created by Andre Regino Paniagua on 28/09/23.
//

#pragma once
#include <iostream>

#include "piece.h"
#include "position.h"
#include "board.h"
#include "move.h"


class TestBoard
{
public:
    void run()
    {
        // Reset
        testReset();
        
//        // SWAP
//        testSwapKingRook();
//        testSwapPawnSpace();
//        testSwapBlackPieceWhitePiece();
//
//        // -=
//        testDeletePieceWhite();
//        testDeletePieceBlack();
//
//        // GET PIECE
//        testGetPieceWhite();
//        testGetPieceBlack();
//
//        // TURN
//        testWhiteTurnTrue();
//        testWhiteTurnFalse();
//
//        // CURRENT MOVE
//        testGetCurrentMove();

       std::cout << "Passed Board Test Cases With Flying Colors!" << std::endl;
    }
private:

    // SWAP
    void testSwapKingRook() const;
    void testSwapPawnSpace() const;
    void testSwapBlackPieceWhitePiece() const;

    // RESET
    void testReset() const;

    // -=
    void testDeletePieceWhite() const;
    void testDeletePieceBlack() const;

    // GET PIECE
    void testGetPieceWhite() const;
    void testGetPieceBlack() const;

    // TURN
    void testWhiteTurnTrue() const;
    void testWhiteTurnFalse() const;

    // CURRENT MOVE
    void testGetCurrentMove() const;


};
