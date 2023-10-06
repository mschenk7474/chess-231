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
      else if (lastMove % 2 == 0)
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
      else if (lastMove % 2 == 1)
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
      if(lastMove % 2 == 1)
         return true;
      
      // otherwise return false
      else
         return false;
   }
   
   // black piece coverage
   else
   {
      // check if black just moved aka last move is even
      if(lastMove % 2 == 0)
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
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// forward two blank
       }
      possibleRow = currentRow - 1;
      if(possibleRow >= 0 && board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// forward one blank
       }
      possibleCol = currentCol - 1;
      if(board(possibleRow,possibleCol)->isWhite() == true)
      {
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// attack left
       }
      possibleCol = currentCol + 1;
      if (board(possibleRow,possibleCol)->isWhite() == true)
      {
          char letter = board(possibleRow,possibleCol)->getLetter();
         insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// attack right
      }
      // handle en-passant and pawn promotion
   }
   
   // covers white pawns
   else
   {
      possibleCol = currentCol;
      possibleRow = currentRow + 2;
      
      if(currentRow == 1 && board(possibleRow,possibleCol)->getLetter() == SPACE)
      {
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// forward two blank
       }
      possibleRow = currentRow + 1;
      if(possibleRow < 8 && board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// forward one blank
       }
      possibleCol = currentCol - 1;
       if(board(possibleRow,possibleCol)->isWhite() == false)
       {
           // add a call to canEnpassant and if true setEnpassant in move
           // add a call to CanPromote and if true setPromote in move
          char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// attack left
       }
      possibleCol = currentCol + 1;
       if(board(possibleRow,possibleCol)->isWhite() == false)
       {
           // add a call to canEnpassant and if true setEnpassant in move
           // add a call to CanPromote and if true setPromote in move
           char letter = board(possibleRow,possibleCol)->getLetter();
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);// attack right
       }
      // handle en-passant and pawn promotion
      
   }
}
/*********************************************************************
 * Pawn CAN ENPASSANT
 * Returns true ot false depending on if the conditions for enpassant have been met
 *********************************************************************/
bool Pawn::canEnPassant(const Board &board, Position opposingPosition)
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
   
   // first need to check the position passed in and see if it is a pawn
   if(board[opposingPosition]->getLetter() != PAWN)
      return false;
   
   // set opposing pawn to make things easier
   auto opposingPawn = board[opposingPosition];
   
   // for reference, this refers to the pawn that wants to do the enpassant
   
   // need to check if the opposing pawn has only moved once and if it moved two spaces from where it was
   if(opposingPawn)
   
   
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
//                }
//            }
//            else if(previous.isWhite == false)
//            {
//                if (previous.to / 8 == previous.from / 8 + 2)
//                {
//                    return true
//                }
//            }
    if (board.getCurrentMove() % board(row,col)->getNMoves() == 0 )
    {

    }

    
    return true;
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
        if (this->fWhite == false && board(possibleRow,possibleCol)->isWhite() == true)
        {
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
        }
        if (this->fWhite == true && board(possibleRow,possibleCol)->isWhite() == false)
        {
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
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
        if (this->fWhite == false && board(possibleRow,possibleCol)->isWhite() == true)
        {
           // add a call to canCastle and if true set CastleK or CastleQ on move
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
        }
        if (this->fWhite == true && board(possibleRow,possibleCol)->isWhite() == false)
        {
           char letter = board(possibleRow,possibleCol)->getLetter();
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, letter);
        }
    }
       
}

/*********************************************************************
 * KING CAN CASTLE
 * Checks conditions in the board and returns true or false
 *********************************************************************/
bool King::canCastle(const Board &board)
{
    //** The following is the pseudocode for this method **//
//    bool canCastle(Board board)
//        {
//            if(hasMoved || inCheck )
//            {
//                return false
//            }
//
//            int x = position.getX();
//            int y = position.getY();
//            bool kingside = false;
//
//            // Check to the right
//            for (int i = 1; i <= 2; ++i)
//            {
//                if (board[(x + i) * 8 + y] != ' ')
//                {
//                    kingside = false;
//                    i = 3
//                }
//
//                kingside = true;
//            }
//
//            if (!kingside)
//            {
//                // Check to the left
//                for (int i = 1; i <= 3; ++i)
//                {
//                    if (board[(x - i) * 8 + y] != ' ')
//                    {
//                        return false;
//                    }
//                }
//
//                if (board[(x - 4) * 8 + y].getHasMoved == false)
//                    return true
//                else
//                    return false
//            }
//            else
//            {
//                if (board[(x + 3) * 8 + y].getHasMoved == false)
//                    return true
//                else
//                    return false
//            }
//        
//        }
    
    // Can't castle if the king has moved
    if (this->getNMoves() != 0)
        return false;
    
    int row = this->position.getRow();
    int col = this->position.getCol();
    bool kingside = false;
    
    // Check if the rook to the right has not moved
    if (board(row + 3, col)->getLetter() != ROOK || board(row + 3, col)->getNMoves() != 0)
    {
        
    }
    
    // Check to the right
    for (int i = 1; i <= 2; ++i)
    {
        if (board(row = i, col)->getLetter() != SPACE)
        {
            kingside = false;
            i = 3;
        }
        kingside = true;
    }
    
    if (!kingside)
    {
        // Check to the left
        for (int i = 1; i <= 3; i++)
        {
            if (board(row - i, col)->getLetter() != SPACE)
            {
                return false;
            }
        }
        
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
