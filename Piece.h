#pragma once
#include <tuple>
#include <vector>
#include <string>
using namespace std;


enum class Color {None, White, Black};
enum class PieceType {None, Soldier, Horse, Camel, Elephant, Queen, King};

class Piece
{
   public :
      Piece();
      ~Piece();
      Piece(Color color);
      // to get simple positions on where the piece can move
      virtual vector<tuple<int, int>> getMovePositionsFromCurrent(int x_pos, int y_pos) = 0;

      // to get positions based on the board's occupancy on where the piece can move
      virtual vector<tuple<int, int>> getMovePositionsFromCurrent(Piece* cells[8][8], int x_pos, int y_pos) = 0;

      virtual tuple<int, int> getCurrentPosition();
      virtual Color getPieceColor();
      virtual PieceType getPieceType();

   protected :
      Color _color;
      PieceType _type;
      int _xPos;
      int _yPos;
      vector<tuple<int, int>> _pieceMoveList;
};
