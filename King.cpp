#include "King.h"
#include <iostream>

King::King()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
}
King::King(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::King;
}

King::~King()
{
}

tuple<int, int> King::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

// to get simple positions on where the piece can move
/* 
 RULES - 
 King will move 
   only one up or one down or 
   one left or one right or
   one up left diagonal or one up right diagonal or
   one up right diagonal or one up left diagonal
 there is some other rule to swap two kukri, but I will manage this later after reading
*/
/*
 ASSUMPTIONS - 
 Also this method is for an empty board, so assuming there is no opponent.
*/
vector<tuple<int, int>> King::getMovePositionsFromCurrent(int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   //if the check missed from the caller. If one of the row/column information is correct, dont perform the operation of computing the moves
   if(x_pos < 1 || x_pos > 8 || y_pos < 1 || y_pos > 8)
      return _pieceMoveList;

   // one up
   if ( (y_pos >= 1) && (y_pos + 1 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos + 1));
   }

   // one down
   if ( (y_pos - 1 >= 1) && (y_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos, y_pos - 1));
   }

   // one right
   if ( (x_pos >= 1) && (x_pos + 1 <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 1, y_pos));
   }

   // one left
   if ( (x_pos - 1 >= 1) && (x_pos <= 8) )
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 1, y_pos));
   }

   // one up right diagonal
   if ( (x_pos + 1 >= 1) && (x_pos + 1 <= 8) && (y_pos + 1 >= 1) && (y_pos + 1 <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 1, y_pos + 1));
   }

   // one up left diagonal
   if ( (x_pos - 1 >= 1) && (x_pos - 1 <= 8) && (y_pos + 1 >= 1) && (y_pos + 1 <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 1, y_pos + 1));
   }

   // one down right diagonal
   if ( (x_pos + 1 >= 1) && (x_pos + 1 <= 8) && (y_pos - 1 >= 1) && (y_pos - 1 <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos + 1, y_pos - 1));
   }

   // one down left diagonal
   if ( (x_pos - 1 >= 1) && (x_pos - 1 <= 8) && (y_pos - 1 >= 1) && (y_pos - 1 <= 8))
   {
      _pieceMoveList.push_back(tuple<int, int>(x_pos - 1, y_pos - 1));
   }


   return _pieceMoveList;
}


// to get positions based on the board's occupancy on where the piece can move
vector<tuple<int, int>> King::getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos)
{
   // empty the move list if already filled in previous transaction
   _pieceMoveList.clear();

   return _pieceMoveList;
}

Color King::getPieceColor()
{
    return this->_color;    
}

PieceType King::getPieceType()
{
    return this->_type;
}

int King::TestCases()
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
