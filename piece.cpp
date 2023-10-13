//
//  piece.cpp
//  Lab01
//
//  Created by Mason Schenk on 10/3/23.
//

#include "piece.h"
#include "board.h"
#include "move.h"

/*********************************************************************
 * PIECE IS MOVE
 * Checks to see if the piece in question can go or not.
 *********************************************************************/
bool Piece::isMove()
{
   // white piece coverage
   if(fWhite == true)
   {
      // intial check to see if anyone has moved yet
      if (nMoves == 0)
         return true;
      
      // if the last move is even, that means black just moved, so it is white's turn now
      else if (nMoves % 2 == 0)
         return true;
      
      // if the last move is odd and someone has moved, return false because it's not white's turn
      else
         return false;
   }
   
   // black piece coverage
   else
   {
      // if no moves, return false as white always goes first
      if(nMoves == 0)
         return false;
      
      // if last move is odd, then white just went and it is black's turn
      else if (nMoves % 2 == 1)
         return true;
      
      // if there has been a move and the last move is even, return false as it is not black's turn
      else
         return false;
   }
}

/*********************************************************************
 * PIECE JUST MOVED
 * Checks to see if the piece in question just moved.
 *********************************************************************/
bool Piece::justMoved()
{
   // no matter what, if nMoves is 0, need to return false as no one has moved
   if(nMoves == 0)
      return false;
   
   // white piece coverage
   if(fWhite == true)
   {
      // check if white just moved aka last move is odd
      if(nMoves % 2 == 1)
         return true;
      
      // otherwise return false
      else
         return false;
   }
   
   // black piece coverage
   else
   {
      // check if black just moved aka last move is even
      if(nMoves % 2 == 0)
         return true;
      
      // otherwise return false
      else
         return false;
   }
}

/*********************************************************************
 * PIECE ASSIGNMENT OPERATOR (PIECE PASSED)
 * Assigns a piece to the piece object in question
 *********************************************************************/
Piece* Piece::operator=(Piece* piece)
{
   return new Space;
}



/*********************************************************************
 * PAWN GET MOVES
 * Gets the possible moves for a Pawn at a given space
 *********************************************************************/
void Pawn::getMoves(std::set<Move> &moves, const Board &board) const
{
   // *** PUT THIS BEFORE THIS FUNCTION IS CALLED
//   // returns an empty set if no possible move
//   if(!canMove())
//   {
//      moves.clear();
//      return;
//   }
   
   int possibleRow, possibleCol; // row and col we are checking
   int currentRow = this->position.getRow();
   int currentCol = this->position.getCol();
   Move move = Move();
   
   // covers black pawns
   if (this->fWhite == false)
   {
      possibleCol = currentCol;
      possibleRow = currentRow - 2;
      
      if(currentRow == 6 && board(possibleRow,possibleCol)->getLetter() == SPACE)
      {
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward two blank
       }
      possibleRow = currentRow - 1;
      if(possibleRow >= 0 && board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward one blank
       }
      possibleCol = currentCol - 1;
      if(board(possibleRow,possibleCol)->isWhite() == true && board(possibleRow,possibleCol)->getLetter() != SPACE)
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// attack left
       }
      possibleRow = currentRow;
      if(board(possibleRow,possibleCol)->isWhite() == true && this->canEnPassant(board, Position(possibleRow, possibleCol)))
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
         move.setEnPassant();
         insertMove(moves, move, Position(possibleRow - 1, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// enpassant left
      }
      possibleCol = currentCol + 1;
      possibleRow = currentRow - 1;
      if (board(possibleRow,possibleCol)->isWhite() == true && board(possibleRow,possibleCol)->getLetter() != SPACE)
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
         insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// attack right
      }
      possibleRow = currentRow;
      if(board(possibleRow,possibleCol)->isWhite() == true && this->canEnPassant(board, Position(possibleRow, possibleCol)))
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
         move.setEnPassant();
         insertMove(moves, move, Position(possibleRow - 1, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// enpassant right
      }
   }
   
   // covers white pawns
   else
   {
      possibleCol = currentCol;
      possibleRow = currentRow + 2;
      
      if(currentRow == 1 && board(possibleRow,possibleCol)->getLetter() == SPACE)
      {
         insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward two blank
       }
      possibleRow = currentRow + 1;
      if(possibleRow < 8 && board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward one blank
       }
      possibleCol = currentCol - 1;
       if(board(possibleRow,possibleCol)->isWhite() == false && board(possibleRow,possibleCol)->getLetter() != SPACE)
       {
          if(canPromote(board, Position(possibleRow, possibleCol)))
             move.setPromote(QUEEN);
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// attack left
       }
      possibleRow = currentRow;
      if(board(possibleRow,possibleCol)->isWhite() == false && this->canEnPassant(board, Position(possibleRow, possibleCol)))
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
         move.setEnPassant();
         insertMove(moves, move, Position(possibleRow + 1, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// enpassant left
      }
      possibleCol = currentCol + 1;
      possibleRow = currentRow + 1;
       if(board(possibleRow,possibleCol)->isWhite() == false && board(possibleRow,possibleCol)->getLetter() != SPACE)
       {
          if(canPromote(board, Position(possibleRow, possibleCol)))
             move.setPromote(QUEEN);
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// attack right
       }
      possibleRow = currentRow;
      if(board(possibleRow,possibleCol)->isWhite() == false && this->canEnPassant(board, Position(possibleRow, possibleCol)))
      {
         if(canPromote(board, Position(possibleRow, possibleCol)))
            move.setPromote(QUEEN);
         move.setEnPassant();
         insertMove(moves, move, Position(possibleRow + 1, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// enpassant right
      }
      
      
   }
}
/*********************************************************************
 * Pawn CAN PROMOTE
 * Returns true ot false depending on if the conditions for pawn promotion have been met
 *********************************************************************/
bool Pawn::canPromote(const Board &board, Position possiblePosition) const
{
   /*
      conditions for promoting:
         - pawn in question needs to be on either side of board depending on color
         - space in question needs to be space
         - move to see if the dest is correct
    */
   
   // check if the piece moving to is a space
   if(board[possiblePosition]->getLetter() != SPACE)
      return false;
   // check color and side of the board the pawn is moving to, aka possiblePosition
   if((this->fWhite == true && board[possiblePosition]->getPosition().getRow() == 7) || (this->fWhite == false && board[possiblePosition]->getPosition().getRow() == 0))
      return true;
   
   return false;
}

/*********************************************************************
 * Pawn CAN ENPASSANT
 * Returns true ot false depending on if the conditions for enpassant have been met
 *********************************************************************/
bool Pawn::canEnPassant(const Board &board, Position opposingPosition) const
{
   
   /*
      conditions for enpassant:
         - opposing pawn moves two squares forward from its starting position
            - if you do not capture enpassant the very next turn, you loose the chance to do so
         - the pawn that is looking to capture woud move diagonally to where the opposing pawn would
           have been if it had moved only one space instead of two
         - at this point, the pawn looking to capture would be either to the left or right of the opposing pawn
    */
   
   /*
      what this function needs to check:
         - needs to check
      
      what needs to be/already passed in:
         - already: the pawn in a question is the one looking to see if it can enpassant
         - need to: possible position to see what is there and check pawn
         - need to: board to see what is at the position passed
    */
   
   // for reference, this refers to the pawn that wants to do the enpassant
   
   // first need to check the position passed in and see if it is a pawn
   if(board[opposingPosition]->getLetter() != PAWN)
      return false;
   
   // set opposing pawn to make things easier
   auto opposingPawn = board[opposingPosition];
   
//   // need to check if the opposing position is next to the current pawn, either to the left or right
//   if ((opposingPawn->getPosition().getRow() != this->getPosition().getRow()) || (opposingPawn->getPosition().getCol() != ((this->getPosition().getCol() - 1) || (this->getPosition().getCol() + 1))))
//      return false;
      
//   // also need to make sure that the pieces are not the same color
//   if(opposingPawn->isWhite() == this->isWhite())
//      return false;
   
   // need to check if the opposing pawn has only moved once and if it moved two spaces from where it was
   // confirms the opposing pawn has only moved once           makes sure if the piece is black, that it has moved 2 spaces            make sure if the piece is white, then it has moved two spaces
   if(opposingPawn->getNMoves() == 1 && ((opposingPawn->getPosition().getRow() == 4 && opposingPawn->isWhite() == false) || (opposingPawn->getPosition().getRow() == 3 && opposingPawn->isWhite() == true)))
      return true;
   
   // otherwise return false
   return false;
   
   
    // *** this is what the pseudocode for this function has:
    //This includes a struct called PreviousMove passed as a parameter that keeps track of the last move, its destination and source, and its pieceType
//    if (previous.pieceType != PAWN)
//            {
//                return false
//            }
//
//            if(previous.isWhite == true)
//            {
//                if (previous.to / 8 == previous.from / 8 - 2)
//                {
//                    return true
//
//            }
//            else if(previous.isWhite == false)
//            {
//                if (previous.to / 8 == previous.from / 8 + 2)
//                {
//                    return true
//                }
//            }
}

/*********************************************************************
 * BISHOP GET MOVES
 * Gets the possible moves for a Bishop at a given space
 *********************************************************************/
void Bishop::getMoves(std::set<Move> &moves, const Board &board) const
{
    int possibleRow, possibleCol; // row and col we are checking
    int currentRow = this->position.getRow();
    int currentCol = this->position.getCol();
    Move move = Move();
   
   RC possiblePositions[4] = {{-1, 1}, {1,1}, {-1, -1}, {1,-1}};
   
   for (int i = 0; i < 4; i++)
   {
      possibleRow = currentRow + possiblePositions[i].row;
      possibleCol = currentCol + possiblePositions[i].col;
      
      while(possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
            board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
         possibleRow += possiblePositions[i].row;
         possibleCol += possiblePositions[i].col;
      }
      
      if(board[this->position]->isWhite() == false && board(possibleRow, possibleCol)->isWhite() == true)
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
      if(board[this->position]->isWhite() == true && board(possibleRow, possibleCol)->isWhite() == false)
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
   }
   
}

/*********************************************************************
 * KNIGHT GET MOVES
 * Gets the possible moves for a Knight at a given space
 *********************************************************************/
void Knight::getMoves(std::set<Move> &moves, const Board &board) const
{
    int possibleRow, possibleCol; // row and col we are checking
    int currentRow = this->position.getRow();
    int currentCol = this->position.getCol();
    Move move = Move();
    
    RC moveRules[8] =
    {
             {-1,  2}, { 1,  2},
    {-2,  1},                    { 2,  1},
    {-2, -1},                    { 2, -1},
             {-1, -2}, { 1, -2}
    };
    for (int i = 0; i < 8; i++)
    {
       possibleRow = currentRow + moveRules[i].row;
       possibleCol = currentCol + moveRules[i].col;
        if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
        }
        if (this->fWhite == true && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
        }
    }
  
}

/*********************************************************************
 * ROOK GET MOVES
 * Gets the possible moves for a Rook at a given space
 *********************************************************************/
void Rook::getMoves(std::set<Move> &moves, const Board &board) const
{
    int possibleRow, possibleCol; // row and col we are checking
    int currentRow = this->position.getRow();
    int currentCol = this->position.getCol();
    Move move = Move();
   
   // possible positions
   RC possiblePositions[4] =
   {
               {0, 1},
      {-1, 0},          {1, 0},
               {0, -1}
   };
   
   for (int i = 0; i < 4; i++)
   {
      possibleRow = currentRow + possiblePositions[i].row;
      possibleCol = currentCol + possiblePositions[i].col;
      
      while(possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
            board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
         possibleRow += possiblePositions[i].row;
         possibleCol += possiblePositions[i].col;
      }
      
      if(board[this->position]->isWhite() == false && board(possibleRow, possibleCol)->isWhite() == true)
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
      if(board[this->position]->isWhite() == true && board(possibleRow, possibleCol)->isWhite() == false)
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
   }
   
   
   
}

/*********************************************************************
 * QUEEN GET MOVES
 * Gets the possible moves for a Queen at a given space
 *********************************************************************/
void Queen::getMoves(std::set<Move> &moves, const Board &board) const
{
    int possibleRow, possibleCol; // row and col we are checking
    int currentRow = this->position.getRow();
    int currentCol = this->position.getCol();
    Move move = Move();
    char letter;
    
    RC moveRules[8] =
    {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
    };
    for (int i = 0; i < 8; i++)
    {
        possibleRow = currentRow + moveRules[i].row;
        possibleCol = currentCol + moveRules[i].col;
        while (possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
               board(possibleRow, possibleCol)->getLetter() == SPACE)
        {
            letter = board(possibleRow,possibleCol)->getLetter();
            insertMove(moves, move, Position(possibleRow, possibleCol), this->position, letter);
            
            possibleRow += moveRules[i].row;
            possibleCol += moveRules[i].col;
        }
        if ( this->fWhite && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
           letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol), this->position, letter);
        }
        if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
            letter = board(possibleRow,possibleCol)->getLetter();
            insertMove(moves, move, Position(possibleRow, possibleCol), this->position, letter);
        }
    }
   
}

/*********************************************************************
 * KING GET MOVES
 * Gets the possible moves for a Pawn at a given space
 *********************************************************************/
void King::getMoves(std::set<Move> &moves, const Board &board) const
{
    int possibleRow, possibleCol; // row and col we are checking
    int currentRow = this->position.getRow();
    int currentCol = this->position.getCol();
    Move move = Move();
    
    RC moveRules[8] =
    {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
    };
    for (int i = 0; i < 8; i++)
    {
       possibleRow = currentRow + moveRules[i].row;
       possibleCol = currentCol + moveRules[i].col;
        if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
        }
        if (this->fWhite == true && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
        {
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
        }
    }
    
    // Check Castling
    this->addCastle(board, moves, move);
       
}

/*********************************************************************
 * KING CAN CASTLE
 * Checks conditions in the board and returns true or false
 *********************************************************************/
void King::addCastle(const Board &board, std::set<Move> &moves,Move &move) const
{
    // Can't castle if the king has moved
    if (this->getNMoves() != 0)
        return;
    
    int row = this->position.getRow();
    int col = this->position.getCol();
    bool kingside = false;
    
    // Check if the rook to the right has not moved

    // Check to the right
    if (board(row, col + 3)->getLetter() == ROOK || board(row, col +  3)->getNMoves() == 0)
    {
        // Check there are no pieces in between
        for (int i = 1; i <= 2; ++i)
        {
            if (board(row, col + i)->getLetter() != SPACE)
            {
                kingside = false;
                break;
            }
            
            kingside = true;
        }
    }
    
    // Insert a move into the set for castling on King side
    if (kingside)
    {
        move.setCastle(kingside);
       
        insertMove(moves, move, Position(row, col + 2), this->position, board(row,col + 2)->getLetter());
    }
   
   kingside = false;
   Move move2 = Move();
    
    // Check to the left
    if (board(row, col - 4)->getLetter() == ROOK || board(row, col - 4)->getNMoves() <= 0)
    {
        // Check there are no pieces in between
        for (int i = 1; i <= 3; i++)
            if (board(row, col - i)->getLetter() != SPACE)
                return;
        
        // Insert a move into the set for castling on Queen side
        move2.setCastle(kingside);
        insertMove(moves, move2, Position(row, col - 3), this->position, board(row,col - 3)->getLetter());
        return;
    }
}




/*********************************************************************
 * INSERT MOVE
 * Adds a move to the possible moves
 *********************************************************************/
void insertMove(std::set<Move> &moves, Move &move, Position possiblePos, Position currentPosition, char letter)
{
    PieceType captured;
    switch (letter) {
        case PieceType(PAWN):
            captured = PAWN;
            break;
        case PieceType(QUEEN):
            captured = QUEEN;
            break;
        case PieceType(KING):
            captured = KING;
            break;
        case PieceType(BISHOP):
            captured = BISHOP;
            break;
        case PieceType(ROOK):
            captured = ROOK;
            break;
        case PieceType(KNIGHT):
            captured = KNIGHT;
            break;
        default:
            captured = SPACE;
            break;
    }
   move.setSrc(currentPosition);
   move.setDes(possiblePos);
   if(captured != SPACE)
       move.setCapture(captured);
   moves.insert(move);
}

/*********************************************************************
 * BUILDER
 * Builds a piece given a type, position, and color
 *********************************************************************/
Piece * builder(PieceType type, int r, int c, bool isWhite)
{
   // intialize object
   Piece *p;
   
   // set type of piece
   switch (type) {
      case KING:
         p = new King;
         break;
      case QUEEN:
         p = new Queen;
         break;
      case ROOK:
         p = new Rook;
         break;
      case BISHOP:
         p = new Bishop;
         break;
      case KNIGHT:
         p = new Knight;
         break;
      case PAWN:
         p = new Pawn;
         break;
      default:
         p = new Space;
   }
   
   // set position
   p->setPosition(r,c);
   
   // set the color
   if (isWhite)
      p->setWhite();
   else
      p->setBlack();
   
   return p;
}
