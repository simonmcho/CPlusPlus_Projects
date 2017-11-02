//
//  TurtleGraphics.cpp
//  Tester
//
//  Created by simmons on 2017-11-01.
//  Copyright © 2017 simmonscho. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "TurtleGraphics.h"

using namespace std;

TurtleGraphics::TurtleGraphics(void)//constructor
{
    //assign values to each subscript of the 2d array
    for(unsigned int row = 0; row < NROWS; ++row)
    {
        for(unsigned int column = 0; column < NCOLS; ++column)
        {
            m_Floor[row][column] = 0;
        }
    }
}

void TurtleGraphics::processTurtleMoves(const int commands[])
{
    Commands command = PEN_UP; //determine first command enum
    Directions direction = STARTING_DIRECTION;//south
    int currentCommand = 0;//using this for the first element of the array
    int currentRow = STARTING_ROW;
    int currentColumn = STARTING_COL;
    int currentPosition;
    
    m_Floor[STARTING_ROW][STARTING_COL] = '&';
    
    while(commands[currentCommand] != 9)//Accept all commands until command value is 9
    {
        switch(commands[currentCommand])
        {
            case 1:
                command = PEN_UP;
                break;
            case 2:
                command = PEN_DWN;
                break;
            case 3:
                command = TURN_RIGHT;
                break;
            case 4:
                command = TURN_LEFT;
                break;
            case 5:
                command = MOVE;
                
                switch(direction)//move as dictated by direction and the array's subscript + 1 number of steps
                {
                    case 0:
                        m_Floor[currentRow + commands[currentCommand + 1]][currentColumn] = 1;
                        break;
                    case 1:
                        m_Floor[currentRow][currentColumn - commands[currentCommand + 1]] = 1;
                        break;
                    case 2:
                        m_Floor[currentRow - commands[currentCommand + 1]][currentColumn] = 1;
                        break;
                    case 3:
                        m_Floor[currentRow][currentColumn + commands[currentCommand + 1]] = 1;
                        break;
                    default:
                        cout << "Bad direction for: " << direction << endl;
                        return;
                }//end of case 5 switch
                
                currentCommand++;//must increment so we don't end up in the subscript for number of steps
                
                break;
            case 6:
                command = DISPLAY;
                break;
            case 9:
                command = END_OF_DATA;
                break;
            default:
                cout << "Bad command for: " << commands[currentCommand] << endl;
                return;
        }//end of commands switch
        currentCommand++;//increment for the next subscript of commands array
        
    }//end of while loop
}//end of processTurtleMoves function

//use the endl for each row
//if greater than 2, print *
