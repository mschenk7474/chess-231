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
        
        // SWAP
        testSwapKingRook();
        testSwapPawnSpace();
        testSwapBlackPieceWhitePiece();

        // -=
        testDeletePieceWhite();
        testDeletePieceBlack();

        // GET PIECE
        testGetPieceWhite();
        testGetPieceBlack();

        // TURN
        testWhiteTurnTrue();
        testWhiteTurnFalse();

        // CURRENT MOVE
        testGetCurrentMove();
       
       // MOVE
        move_pawnSimple() ;
        move_pawnCapture() ;
        move_pawnDouble() ;
        move_pawnEnpassant() ;
        move_pawnPromotion() ;
        move_rookSlide() ;
        move_rookAttack() ;
        move_bishopSlide() ;
        move_bishopAttack() ;
        move_knightMove() ;
        move_knightAttack() ;
        move_queenSlide() ;
        move_queenAttack() ;
        move_kingMove() ;
        move_kingAttack() ;
        move_kingShortCastle() ;
        move_kingLongCastle() ;

       std::cout << "Passed Board Test Cases With Flying Colors!" << std::endl;
    }
private:
   
   // CONSTRUCTOR
   void construct_default() const;

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
   
   // MOVE
   void move_pawnSimple() const;
   void move_pawnCapture() const;
   void move_pawnDouble() const;
   void move_pawnEnpassant() const;
   void move_pawnPromotion() const;
   void move_rookSlide() const;
   void move_rookAttack() const;
   void move_bishopSlide() const;
   void move_bishopAttack() const;
   void move_knightMove() const;
   void move_knightAttack() const;
   void move_queenSlide() const;
   void move_queenAttack() const;
   void move_kingMove() const;
   void move_kingAttack() const;
   void move_kingShortCastle() const;
   void move_kingLongCastle() const;


};
