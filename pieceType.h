/***********************************************************************
 * Header File:
 *    PIECE TYPE : what type of piece are we working with?
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Just an enumeration of a piece type. Nothing fancy
 ************************************************************************/


#pragma once

enum PieceType { SPACE, KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

inline PieceType charToPieceType(char pieceChar)
{
   switch (pieceChar) {
      case ' ':
         return SPACE;
      case 'K':
         return KING;
      case 'Q':
         return QUEEN;
      case 'R':
         return ROOK;
      case 'B':
         return BISHOP;
      case 'N':
         return KNIGHT;
      case 'P':
         return PAWN;
      default:
         break;
   }
   return SPACE;
}
