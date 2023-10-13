/***********************************************************************
 * Source File:
 *    Piece : hanldes all the types of pieces
 * Author:
 *    Mason Schenk & Andre Regino
 * Summary:
 *    Handles all of the different types of pieces and how to create them.
 ************************************************************************/
#include "piece.h"   // for PIECE
#include "board.h"   // for BOARD
#include "move.h"    // for MOVE

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
 * PAWN GET MOVES
 * Gets the possible moves for a Pawn at a given space
 *********************************************************************/
void Pawn::getMoves(std::set<Move> &moves, const Board &board) const
{
   
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
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward two blank
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
         insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());// forward two blank
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
bool Pawn::canPromote(const Board &board, const Position &possiblePosition) const
{
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
bool Pawn::canEnPassant(const Board &board, const Position &opposingPosition) const
{
   
   // check to see if position passed is a pawn
   if(board[opposingPosition]->getLetter() != PAWN)
      return false;
   
   // set opposing pawn to make things easier
   auto opposingPawn = board[opposingPosition];
   
   /*
      the following conditional statement checks the following things in this order:
         1. confirms the opposing pawn has only moved once
         2. if the piece is black, then it has moved 2 spaces
         3. if the piece is white, then it has moved 2 spaces
         4. if the last move on the board was the opposing opawn
    */
   if(opposingPawn->getNMoves() == 1 && ((opposingPawn->getPosition().getRow() == 4 && opposingPawn->isWhite() == false) || (opposingPawn->getPosition().getRow() == 3 && opposingPawn->isWhite() == true)) && board.getLastMove() == opposingPawn->getLastMove())
      return true;
   
   // otherwise return false
   return false;
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
   
   // possible piece-particular positions
   RC possiblePositions[4] = {{-1, 1}, {1,1}, {-1, -1}, {1,-1}};
   
   // go through each of the possible positions
   for (int i = 0; i < 4; i++)
   {
      // set possible row and col based on position
      possibleRow = currentRow + possiblePositions[i].row;
      possibleCol = currentCol + possiblePositions[i].col;
      
      // check to see if move to be inserted is valid
      while(possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
            board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
         
         // updates the possible row and col to new position
         possibleRow += possiblePositions[i].row;
         possibleCol += possiblePositions[i].col;
      }
      
      // checks to capture
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
    
   // possible piece-particular positions
    RC moveRules[8] =
    {
             {-1,  2}, { 1,  2},
    {-2,  1},                    { 2,  1},
    {-2, -1},                    { 2, -1},
             {-1, -2}, { 1, -2}
    };
   
    // go through each of the possible positions
    for (int i = 0; i < 8; i++)
    {
       // set possible row and col based on position
       possibleRow = currentRow + moveRules[i].row;
       possibleCol = currentCol + moveRules[i].col;
       
       // black piece capture or normal move
       if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
       
       // white piece capture or normal move
       if (this->fWhite == true && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
          insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
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
   
   // possible piece-particular positions
   RC possiblePositions[4] =
   {
               {0, 1},
      {-1, 0},          {1, 0},
               {0, -1}
   };
   
   // go through each of the possible positions
   for (int i = 0; i < 4; i++)
   {
      // set possible row and col based on position
      possibleRow = currentRow + possiblePositions[i].row;
      possibleCol = currentCol + possiblePositions[i].col;
      
      // check to see if move to be inserted is valid
      while(possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
            board(possibleRow, possibleCol)->getLetter() == SPACE)
      {
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
         
         // updates the possible row and col to new position
         possibleRow += possiblePositions[i].row;
         possibleCol += possiblePositions[i].col;
      }
      
      // black piece capture or normal move
      if(board[this->position]->isWhite() == false && board(possibleRow, possibleCol)->isWhite() == true)
         insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
      
      // white piece capture or normal move
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
    
   // possible piece-particular positions
    RC moveRules[8] =
    {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
    };
   
   // go through each of the possible positions
    for (int i = 0; i < 8; i++)
    {
       
        // set possible row and col based on position
        possibleRow = currentRow + moveRules[i].row;
        possibleCol = currentCol + moveRules[i].col;
       
        // check to see if move to be inserted is valid
        while (possibleRow >= 0 && possibleRow < 8 && possibleCol >= 0 && possibleCol < 8 &&
               board(possibleRow, possibleCol)->getLetter() == SPACE)
        {
            insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
            
            // updates the possible row and col to new position
            possibleRow += moveRules[i].row;
            possibleCol += moveRules[i].col;
        }
       
       // white piece capture or normal move
        if ( this->fWhite && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
           insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
       
       // black piece capture or normal move
        if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
            insertMove(moves, move, Position(possibleRow, possibleCol), this->position, board(possibleRow,possibleCol)->getLetter());
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
    
   // possible piece-particular positions
    RC moveRules[8] =
    {
       {-1,  1}, {0,  1}, {1,  1},
       {-1,  0},          {1,  0},
       {-1, -1}, {0, -1}, {1, -1}
    };
   
   // go through each of the possible positions
    for (int i = 0; i < 8; i++)
    {
       
       // set possible row and col based on position
       possibleRow = currentRow + moveRules[i].row;
       possibleCol = currentCol + moveRules[i].col;
       
        // black piece capture or normal move
        if (this->fWhite == false && (board(possibleRow,possibleCol)->isWhite() == true || board(possibleRow,possibleCol)->getLetter() == SPACE))
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
       
        // white piece capture or normal move
        if (this->fWhite == true && (board(possibleRow,possibleCol)->isWhite() == false || board(possibleRow,possibleCol)->getLetter() == SPACE))
           insertMove(moves, move, Position(possibleRow, possibleCol) , this->position, board(possibleRow,possibleCol)->getLetter());
    }
    
    // check castling
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
   
   // sets caputre based on letter passed
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
   
   // sets the source and dest
   move.setSrc(currentPosition);
   move.setDes(possiblePos);
   
   // sets capture
   if(captured != SPACE)
       move.setCapture(captured);
   
   moves.insert(move);
}

/*********************************************************************
 * BUILDER
 * Builds a piece given a type, position, and color
 * Note: Design pulled James Helfrich
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
