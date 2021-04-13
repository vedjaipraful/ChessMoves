#include "Soldier.h"
#include <iostream>

Soldier::Soldier()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
Soldier::Soldier(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::Soldier;
}

Soldier::~Soldier()
{
}

tuple<int, int> Soldier::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 if we have white soldier, going up
 if we have black soldier, going down
 soldier will move only one up or one down. 
 only from first position could move 2 steps up or down
 can move one diagonal to kill if there is any opponent
*/
/*
 ASSUMPTIONS - 
 For soldier movement, color needs to be known to decide if the soldier will move up or move down.
 If color is None, then assuming white movement for the time being
 Also this method is for an empty board, so assuming there is no opponent. 
 Hence will assume no slant movements to kill the opponent kukri
*/
vector<tuple<int, int>> Soldier::getMovePositionsFromCurrent(int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   //if the check missed from the caller. If one of the row/column information is correct, dont perform the operation of computing the moves
   if(x_pos < 1 || x_pos > 8 || y_pos < 1 || y_pos > 8)
      return _pieceMoveList;

   // color not part of the input, Assuming white
   if(_color == Color::None || _color == Color::White)
   {
      if (y_pos < 8)
      {
         _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos + 1));
      }
      if(y_pos == 2)
      {
         _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos + 2));
      }
   }
   else // black soldier
   {
      if (y_pos > 1)
      {
         _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos - 1));
      }
      if(y_pos == 7)
      {
         _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos - 2));
      }
   }

   return _pieceMoveList;
}


// to get positions based on the board's occupancy on where the piece can move
vector<tuple<int, int>> Soldier::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color Soldier::getPieceColor()
{
    return _color;
}

PieceType Soldier::getPieceType()
{
    return _type;
}

int Soldier::TestCases()
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
    
    // check no top movements for default white piece
    x_pos = 5;
    y_pos = 8;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() > 0)
    {
        cout << "Top Condition missed" << endl;
        retERR = -1;
        return retERR;
    }

    // check 2 step moves
    x_pos = 3;
    y_pos = 2;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() != 2)
    {
        cout << "2 step movement missed" << endl;
        retERR = -1;
        return retERR;
    }
    
    // check -1 step moves
    x_pos = 8;
    y_pos = 5;
    moveList = getMovePositionsFromCurrent(x_pos, y_pos);
    if(moveList.size() != 1)
    {
        cout << "1 step movement missed" << endl;
        retERR = -1;
        return retERR;
    }

    return retERR;
}