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
	for (unsigned int row = 0; row < NROWS; ++row)
	{
		for (unsigned int column = 0; column < NCOLS; ++column)
		{
			//m_Floor[row][column] = 0;
			if (row == 0 || row == NROWS - 1 || column == 0 || column == NCOLS - 1 )//create border 
			{
				m_Floor[row][column] = 1;
			}
			else
			{
				m_Floor[row][column] = 0;
			}
		}
	}
}

void TurtleGraphics::setPenIsUp(unsigned int theCommand)
{
	
	if (theCommand == 1)//pen is up
	{
		penIsUp = true;
	}
	else
	{
		penIsUp = false;
	}
}

bool TurtleGraphics::getPenIsUp() const
{
	return penIsUp;
}

void TurtleGraphics::processTurtleMoves(const int commands[])
{
	Commands command = PEN_UP; //determine first command enum
	Directions direction = STARTING_DIRECTION;//south
	unsigned int currentCommand = 0;//using this for the first element of the array
	unsigned int currentRow = STARTING_ROW;
	unsigned int currentColumn = STARTING_COL;

	while (commands[currentCommand] != 9)//Accept all commands until command value is 9
	{	
		/*cout << "Command #" << currentCommand + 1 << endl;
		cout << "current row: " << currentRow << ", current column: " << currentColumn << endl;*/
		unsigned int tempRowCounter = currentRow;
		unsigned int tempColumnCounter = currentColumn;

		switch (commands[currentCommand]) 
		{
		case 1:
			command = PEN_UP;
			setPenIsUp(command);
			break;
		case 2:
			command = PEN_DWN;
			setPenIsUp(command);
			break;
		case 3:
			command = TURN_RIGHT;
			if (direction == NORTH)
			{
				direction = EAST;
			}
			else if (direction == EAST)
			{
				direction = SOUTH;
			}
			else if (direction == SOUTH)
			{
				direction = WEST;
			}
			else if (direction == WEST)
			{
				direction = NORTH;
			}
			break;
		case 4:
			command = TURN_LEFT;
			if (direction == NORTH)
			{
				direction = WEST;
			}
			else if (direction == EAST)
			{
				direction = NORTH;
			}
			else if (direction == SOUTH)
			{
				direction = EAST;
			}
			else if (direction == WEST)
			{
				direction = SOUTH;
			}
			break;
		case 5:
			command = MOVE;
			switch (direction)//move as dictated by direction and the array's subscript + 1 number of steps
			{
				case 0://moving north, so go up (subtract row element)
					if (currentRow - commands[currentCommand + 1] >= 0)//ensure it does not go past max # of rows
					{
						currentRow -= commands[currentCommand + 1];
					}
					else
					{
						currentRow = NROWS;
					}

					while (tempRowCounter > currentRow)//assign boolean value for the correct cell
					{
						if (!getPenIsUp())
						{
							m_Floor[tempRowCounter][currentColumn] = 1;
						}
						tempRowCounter--;
					}
					break;
				case 1: //moving east, so go right (add column element)
					if (currentColumn + commands[currentCommand + 1] <= NCOLS)//ensure steps do not go past # of columns
					{
						currentColumn += commands[currentCommand + 1];
					}
					else
					{
						currentColumn = NCOLS;
					}
					
					while (tempColumnCounter < currentColumn)//assign boolean value for the correct cell
					{
						if (!penIsUp)
						{
							m_Floor[currentRow][tempColumnCounter] = 1;
						}
						tempColumnCounter++;
					}
					break;
				case 2://moving south, so go down (add row element)
					if (currentRow + commands[currentCommand + 1] <= NROWS)//ensure it does not go past max # of rows
					{
						currentRow += commands[currentCommand + 1];
					}
					else
					{
						currentRow = NROWS;
					}

					while (tempRowCounter < currentRow)//assign boolean value for the correct cell
					{
						if (!getPenIsUp())
						{
							m_Floor[tempRowCounter][currentColumn] = 1;
						}
						tempRowCounter++;
					}
					break;
				case 3://moving west, so go left (subtract column element)
					if (currentColumn - commands[currentCommand + 1] >= 0)//ensure steps do not go past # of columns
					{
						currentColumn -= commands[currentCommand + 1];
					}
					else
					{
						currentColumn = 0;
					}

					while (tempColumnCounter > currentColumn)//assign boolean value for the correct cell
					{
						if (!getPenIsUp())
						{
							m_Floor[currentRow][tempColumnCounter] = 1;
						}
						tempColumnCounter--;
					}
					break;
				default:
					cout << "Bad direction for: " << direction << endl;
					return;
			}//end of case 5 switch

			currentCommand++;//must increment so we don't end up in the subscript for number of steps
			break;//end of case 5
		case 6:
			command = DISPLAY;
			break;
		case 9:
			command = END_OF_DATA;//probably won't ever get entered due to while loop
			break;
		default:
			cout << "Bad command for: " << currentCommand << ", " << commands[currentCommand] << endl;
			return;
		}//end of commands switch
		currentCommand++;//increment for the next subscript of commands array
	}//end of while loop

	for (unsigned int row = 0; row < NROWS; ++row)//print the drawing board
	{
		for (unsigned int column = 0; column < NCOLS; ++column)
		{
			if (m_Floor[row][column])//print `*` for each bool value that returns true
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;//print to next line for each row
	}

	cout << '\n' << endl;//extra space for system pause


}//end of processTurtleMoves function

 //use the endl for each row
 //if greater than 2, print *