#include "Piece.h"

Piece::Piece()
{
   _xPos = 0;
   _yPos = 0;
   _color = Color::None;
   _type = PieceType::None;
   _pieceMoveList.clear();
}

Piece::Piece(Color color)
{
   _xPos = 0;
   _yPos = 0;
   _color = color;
   _type = PieceType::None;
   _pieceMoveList.clear();
}

Piece::~Piece()
{
}

tuple<int, int> Piece::getCurrentPosition()
{
   return make_tuple(_xPos, _yPos);
}

Color Piece::getPieceColor()
{
    return this->_color;    
}

PieceType Piece::getPieceType()
{
    return this->_type;
}

