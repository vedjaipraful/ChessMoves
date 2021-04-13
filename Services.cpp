#include "Services.h"

int Services::WRONG_POSITION = 'X';

int Services::ConvertCharToNumber(char character)
{
   switch (character)
   {
      case 'A' :
      case 'a' :
         return 1;
         break;
      case 'B':
      case 'b':
         return 2;
         break;
      case 'C':
      case 'c':
         return 3;
         break;
      case 'D':
      case 'd':
         return 4;
         break;
      case 'E':
      case 'e':
         return 5;
         break;
      case 'F':
      case 'f':
         return 6;
         break;
      case 'G':
      case 'g':
         return 7;
         break;
      case 'H':
      case 'h':
         return 8;
         break;
      default:
         return WRONG_POSITION;
   }
}

char Services::ConvertNumberToChar(int number)
{
   switch (number)
   {
      case 1:
         return 'A';
         break;
      case 2:
         return 'B';
         break;
      case 3:
         return 'C';
         break;
      case 4:
         return 'D';
         break;
      case 5:
         return 'E';
         break;
      case 6:
         return 'F';
         break;
      case 7:
         return 'G';
         break;
      case 8:
         return 'H';
         break;
      default:
         return WRONG_POSITION;
   }
}
