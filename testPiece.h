/***********************************************************************
 * Header File:
 *    TEST Piece : test the Piece and related Derived Classes
 * Author:
 *    Mason Schenk & Andre Regino
 ************************************************************************/

#pragma once

#include "piece.h"
#include "position.h"
#include "board.h"
#include "move.h"

/***************************************************
 * PIECE TEST
 * Test the Piece & Derived classes
 ***************************************************/
class PieceTest
{
public:
   // run method goes here
   void run() const
   {
   
      // Constructor
      constructor_piece(); // talk to andre about this, maybe making it just make a space?
      constructor_space();
      constructor_pawn();
      constructor_rook();
      constructor_bishop();
      constructor_knight();
      constructor_queen();
      constructor_king();
      
      // Assign
      assign_piece_position();
      assign_piece_to_piece();
      
      // Get Letter
      getLetter_space();
      getLetter_pawn();
      getLetter_rook();
      getLetter_bishop();
      getLetter_knight();
      getLetter_queen();
      getLetter_king();
      
      // Get Moves
      getMoves_pawn_blocked();
      getMoves_pawn_simple();
      getMoves_pawn_intial();
      getMoves_pawn_capture();
      getMoves_pawn_enpassant();
      getMoves_pawn_promotion();
      
      getMoves_rook_blocked();
      getMoves_rook_free();
      getMoves_rook_capture();
      
      getMoves_bishop_blocked();
      getMoves_bishop_free();
      getMoves_bishop_capture();
      
      getMoves_knight_blocked();
      getMoves_knight_free();
      getMoves_knight_capture();
      
      getMoves_queen_blocked();
      getMoves_queen_free();
      getMoves_queen_capture();
      
      getMoves_king_free();
      getMoves_king_blocked();
      getMoves_king_capture();
      getMoves_king_castle_king_moved();
      getMoves_king_castle_rooks_moved();
      getMoves_king_castle_blocked();
      getMoves_king_castle();
   }
   
private:
   
   void constructor_piece() const;
   void constructor_space() const;
   void constructor_pawn() const;
   void constructor_rook() const;
   void constructor_bishop() const;
   void constructor_knight() const;
   void constructor_queen() const;
   void constructor_king() const;
   
   void assign_piece_position() const;
   void assign_piece_to_piece() const;
   
   void getLetter_space() const;
   void getLetter_pawn() const;
   void getLetter_rook() const;
   void getLetter_bishop() const;
   void getLetter_knight() const;
   void getLetter_queen() const;
   void getLetter_king() const;
   
   void getMoves_pawn_blocked() const;
   void getMoves_pawn_simple() const;
   void getMoves_pawn_intial() const;
   void getMoves_pawn_capture() const;
   void getMoves_pawn_enpassant() const;
   void getMoves_pawn_promotion() const;
   void getMoves_rook_blocked() const;
   void getMoves_rook_free() const;
   void getMoves_rook_capture() const;
   void getMoves_bishop_blocked() const;
   void getMoves_bishop_free() const;
   void getMoves_bishop_capture() const;
   void getMoves_knight_blocked() const;
   void getMoves_knight_free() const;
   void getMoves_knight_capture() const;
   void getMoves_queen_blocked() const;
   void getMoves_queen_free() const;
   void getMoves_queen_capture() const;
   void getMoves_king_free() const;
   void getMoves_king_blocked() const;
   void getMoves_king_capture() const;
   void getMoves_king_castle_king_moved() const;
   void getMoves_king_castle_rooks_moved() const;
   void getMoves_king_castle_blocked() const;
   void getMoves_king_castle() const;
};
