#include "Elephant.h"
#include <iostream>

Elephant::Elephant()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
Elephant::Elephant(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::Elephant;
}

Elephant::~Elephant()
{
}

tuple<int, int> Elephant::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 movements can be vertical up or vertical down based on interuption by another piece (self team or opponent)
 movements can be horizontal right or horizontal left based on interuption by another piece (self team or opponent)
*/
/*
 ASSUMPTIONS - 
 Also this method is for an empty board, so assuming there is no opponent and also no self team kukris.
*/
vector<tuple<int, int>> Elephant::getMovePositionsFromCurrent(int x_pos, int y_pos)
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


   return _pieceMoveList;
}


// to get positions based on the board's occupancy on where the piece can move
vector<tuple<int, int>> Elephant::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color Elephant::getPieceColor()
{
    return this->_color;    
}

PieceType Elephant::getPieceType()
{
    return this->_type;
}

int Elephant::TestCases()
{
    int retERR = 0;
    
    int x_pos = 0;
    int y_pos = 0;

    // check incorrect row / column number
    x_pos = 9;
    y_pos = 10;
    vector<tuple<int, int>> moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() > 0)
    {
        cout << "Incorrect row/column from board missed" << endl;
        retERR = -1;
        return retERR;
    }
    
    // check no right movements
    x_pos = 8;
    y_pos = 3;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    for (size_t ctr = 0; ctr < moveList.size(); ctr++)
    {
        if (get<0>(moveList[ctr]) > 8)
        {
            cout << "no right Condition missed - 2" << endl;
            retERR = -1;
            return retERR;
        }
    }

    // check no bottom movements
    x_pos = 6;
    y_pos = 1;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    for (size_t ctr = 0; ctr < moveList.size(); ctr++)
    {
        if (get<1>(moveList[ctr]) < y_pos)
        {
            cout << "No Bottom Movements Condition missed - 2" << endl;
            retERR = -1;
            return retERR;
        }
    }

    return retERR;
}
