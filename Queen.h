#pragma once
#include "Piece.h"
#include <tuple>
#include <vector>
#include <string>
using namespace std;


class Queen : public Piece
{
   public :
      Queen ();
      ~Queen();
      Queen (Color color);

      // to get simple positions on where the piece can move
      virtual vector<tuple<int, int>> getMovePositionsFromCurrent(int x_pos, int y_pos);

      // to get positions based on the board's occupancy on where the piece can move
      virtual vector<tuple<int, int>> getMovePositionsFromCurrent(Piece* board[8][8], int x_pos, int y_pos);

      virtual tuple<int, int> getCurrentPosition();
      virtual Color getPieceColor();
      virtual PieceType getPieceType();

};
