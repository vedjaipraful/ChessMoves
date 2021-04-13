/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Soldier.h"
#include "Horse.h"
#include "Camel.h"
#include "Elephant.h"
#include "Services.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "Lets understand some chess moves !" << endl;
    
    string pieceName, cellName;
    char exiting = 'N';
    cout << "Do You Want To EXIT ?" << endl;
    cin >> exiting;
    
    bool errorCase = false;

    while(exiting == 'N')
    {
        errorCase = false;
        cout << "===================================================" << endl;
        cout << "Name the piece ?" << endl;
        cin >> pieceName;
        
        // based on input piece name, create the "Piece" and call the method to find possible moves
        Piece* currentPiece = NULL;
        if (pieceName == "King")
        {
            currentPiece = new King();
            //if(currentPiece != NULL)
            //    cout << "King Created" << endl;
            //else 
            //    cout << "Dead Duck !!" << endl;
        }
        else if(pieceName == "Queen")
        {
            currentPiece = new Queen();
        }
        else if(pieceName == "Horse")
        {
            currentPiece = new Horse();
        }
        else if(pieceName == "Elephant")
        {
            currentPiece = new Elephant();
            //Elephant test;
            //int testresult = test.TestCases();
            //cout << "testresult = " << testresult << endl;
        }
        else if(pieceName == "Camel")
        {
            currentPiece = new Camel();
        }
        else if(pieceName == "Soldier")
        {
            currentPiece = new Soldier();
        }
        else
        {
            cout << "Incorrect Piece Name" << endl;
            errorCase = true;
            continue;
        }

        cout << "Name the position : Row<A-H>Column<1-8> Format?" << endl;
        cin >> cellName;

        //cout << "Input is " << pieceName + " " + cellName << endl;
        int x_pos = Services::ConvertCharToNumber(cellName[0]);
        int y_pos = stoi(&cellName[1]);
        //cout << "x_pos = " << x_pos << "   y_pos = " << y_pos << endl;
        if( (x_pos < 1) || (x_pos > 8) || (y_pos < 1) || (y_pos > 8) )
        {
            cout << "Incorrect Cell Input" << endl;
            errorCase = true;
            continue;
        }
        
        vector<tuple<int, int>> currentPieceMoveList = currentPiece->getMovePositionsFromCurrent(x_pos, y_pos);

        cout << endl << "Possible Moves for " << pieceName << " at " << cellName << " - " << endl;
        size_t sizeOfList = currentPieceMoveList.size();
        for (size_t ctr = 0; ctr < sizeOfList; ctr++)
        {
            //cout << get<0>(currentPieceMoveList[ctr]) << get<1>(currentPieceMoveList[ctr]) << " " ;
            cout << Services::ConvertNumberToChar(get<0>(currentPieceMoveList[ctr])) << get<1>(currentPieceMoveList[ctr]) << " " ;
            if(ctr+1 < sizeOfList)
                cout << ", ";
        }
        cout << endl;
        cout << "Do You Want To EXIT ?" << endl;
        cin >> exiting;
    
    }


    return 0;
}
