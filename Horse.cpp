#include "Horse.h"

Horse::Horse()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
Horse::Horse(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::Horse;
}

Horse::~Horse()
{
}

tuple<int, int> Horse::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 movements can be 
   2 right and 1 up
   2 left and 1 up
   1 right and 2 up
   1 left and 2 up
   2 right and 1 down
   2 left and 1 down
   1 right and 2 down
   1 left and 2 down
 movements can done if no interuption by another piece at the above locations (self team or opponent)
*/
/*
 ASSUMPTIONS - 
 Also this method is for an empty board, so assuming there is no opponent and also no self team kukris.
*/
vector<tuple<int, int>> Horse::getMovePositionsFromCurrent(int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   //if the check missed from the caller. If one of the row/column information is correct, dont perform the operation of computing the moves
   if(x_pos < 1 || x_pos > 8 || y_pos < 1 || y_pos > 8)
      return _pieceMoveList;

   // will walk through the board as there is no opponent

   // 2 right and 1 up
   if( (x_pos >= 1) && (x_pos + 2 <= 8) && (y_pos >= 1) && (y_pos + 1 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 2, y_pos + 1));
   }

   // 2 left and 1 up
   if( (x_pos - 2 >= 1) && (x_pos <= 8) && (y_pos >= 1) && (y_pos + 1 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 2, y_pos + 1));
   }

   // 1 right and 2 up
   if( (x_pos >= 1) && (x_pos + 1 <= 8) && (y_pos >= 1) && (y_pos + 2 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 1, y_pos + 2));
   }

   // 1 left and 2 up
   if( (x_pos - 1 >= 1) && (x_pos <= 8) && (y_pos >= 1) && (y_pos + 2 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 1, y_pos + 2));
   }

   // 2 right and 1 down
   if( (x_pos >= 1) && (x_pos + 2 <= 8) && (y_pos - 1 >= 1) && (y_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 2, y_pos - 1));
   }

   // 2 left and 1 down
   if( (x_pos - 2 >= 1) && (x_pos <= 8) && (y_pos - 1 >= 1) && (y_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 2, y_pos - 1));
   }

   // 1 right and 2 down
   if( (x_pos >= 1) && (x_pos + 1 <= 8) && (y_pos - 2 >= 1) && (y_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 1, y_pos - 2));
   }

   // 1 left and 2 down
   if( (x_pos - 1 >= 1) && (x_pos <= 8) && (y_pos - 2 >= 1) && (y_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 1, y_pos - 2));
   }

   return _pieceMoveList;
}


// to get positions based on the board's occupancy on where the piece can move
vector<tuple<int, int>> Horse::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color Horse::getPieceColor()
{
    return this->_color;    
}

PieceType Horse::getPieceType()
{
    return this->_type;
}

