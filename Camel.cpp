#include "Camel.h"
#include <iostream>

Camel::Camel()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
Camel::Camel(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::Camel;
}

Camel::~Camel()
{
}

tuple<int, int> Camel::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 movements can be diagonal right up or diagonal left up based on interuption by another piece (self team or opponent)
 movements can be diagonal right down or diagonal left down based on interuption by another piece (self team or opponent)
*/
/*
 ASSUMPTIONS - 
 Also this method is for an empty board, so assuming there is no opponent and also no self team kukris.
*/
vector<tuple<int, int>> Camel::getMovePositionsFromCurrent(int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   //if the check missed from the caller. If one of the row/column information is correct, dont perform the operation of computing the moves
   if(x_pos < 1 || x_pos > 8 || y_pos < 1 || y_pos > 8)
      return _pieceMoveList;

   // will walk through the board as there is no opponent

   int moveCnt = 1;

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
vector<tuple<int, int>> Camel::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color Camel::getPieceColor()
{
    return this->_color;    
}

PieceType Camel::getPieceType()
{
    return this->_type;
}

int Camel::TestCases()
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
    
    // check no top right movements
    // 5th row 8th column
    x_pos = 5;
    y_pos = 8;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() != 7)
    {
        cout << "Top right Condition missed - 1" << endl;
        retERR = -1;
        return retERR;
    }
    for (size_t ctr = 0; ctr < moveList.size(); ctr++)
    {
        if (get<1>(moveList[ctr]) > 8)
        {
            cout << "Top right Condition missed - 2" << endl;
            retERR = -1;
            return retERR;
        }
    }

    // check no bottom movements
    // 1st row 1st column
    x_pos = 1;
    y_pos = 1;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() != 7)
    {
        cout << "No Bottom Movements Condition missed - 1" << endl;
        retERR = -1;
        return retERR;
    }
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
