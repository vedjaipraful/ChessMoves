#include "Queen.h"

Queen::Queen()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
Queen::Queen(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::Queen;
}

Queen::~Queen()
{
}

tuple<int, int> Queen::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 movements can be vertical up or vertical down based on interuption by another piece (self team or opponent)
 movements can be horizontal right or horizontal left based on interuption by another piece (self team or opponent)
 movements can be diagonal right up or diagonal left up based on interuption by another piece (self team or opponent)
 movements can be diagonal right down or diagonal left down based on interuption by another piece (self team or opponent)
*/
/*
 ASSUMPTIONS - 
 Also this method is for an empty board, so assuming there is no opponent and also no self team kukris.
*/
vector<tuple<int, int>> Queen::getMovePositionsFromCurrent(int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   //if the check missed from the caller. If one of the row/column information is correct, dont perform the operation of computing the moves
   if(x_pos < 1 || x_pos > 8 || y_pos < 1 || y_pos > 8)
      return _pieceMoveList;

   // will walk through the board as there is no opponent

   // vertical moves up
   int moveCnt = 1;
   while( (y_pos >= 1) && (y_pos + moveCnt <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos + moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // vertical moves down
   while( (y_pos - moveCnt >= 1) && (y_pos <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos - moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // horizontal moves right
   while( (x_pos >= 1) && (x_pos + moveCnt <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + moveCnt, y_pos));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // horizontal moves left
   while( (x_pos - moveCnt >= 1) && (x_pos <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - moveCnt, y_pos));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // diagonal right up
   while( (x_pos >= 1) && (x_pos + moveCnt <= 8) && (y_pos >= 1) && (y_pos + moveCnt <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + moveCnt, y_pos + moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // diagonal left up
   while( (x_pos >= 1) && (x_pos - moveCnt <= 8) && (y_pos >= 1) && (y_pos + moveCnt <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - moveCnt, y_pos + moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // diagonal right down
   while( (x_pos >= 1) && (x_pos + moveCnt <= 8) && (y_pos >= 1) && (y_pos - moveCnt <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + moveCnt, y_pos - moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   // diagonal left down
   while( (x_pos >= 1) && (x_pos - moveCnt <= 8) && (y_pos >= 1) && (y_pos - moveCnt <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - moveCnt, y_pos - moveCnt));
      moveCnt++;
   }

   //reset counter
   moveCnt = 1;

   return _pieceMoveList;
}


// to get positions based on the board's occupancy on where the piece can move
vector<tuple<int, int>> Queen::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color Queen::getPieceColor()
{
    return this->_color;    
}

PieceType Queen::getPieceType()
{
    return this->_type;
}

