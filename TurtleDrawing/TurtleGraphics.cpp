//
//  TurtleGraphics.cpp
//  Tester
//
//  Created by simmons on 2017-11-01. 15:24
//  Copyright © 2017 simmonscho. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include "TurtleGraphics.h"

using namespace std;

TurtleGraphics::TurtleGraphics(void)//constructor
{
	//assign values to each subscript of the 2d array
	for (size_t row = 0; row < m_Floor.size(); ++row)
	{
		for (size_t column = 0; column < NCOLS; ++column)
		{
			if (row == 0 || row == NROWS - 1 || column == 0 || column == NCOLS - 1)
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

void TurtleGraphics::setIsPenUp( Cmds theCommand)
{
	
	if (theCommand == Cmds::PEN_UP)//pen is up
	{
		isPenUp = true;
	}
	else if(theCommand == Cmds::PEN_DWN)
	{
		isPenUp = false;
	}
	else//should never reach this if theCommand param is entered correctly
	{
		isPenUp = false;
	}
}

bool TurtleGraphics::getIsPenUp() const
{
	return isPenUp;
}

void TurtleGraphics::processTurtleMoves(const array<int, ARRAY_SIZE> & commands)
{
	Cmds command = Cmds::PEN_UP; //determine first command enum
	Directions direction = STARTING_DIRECTION;//south
	unsigned int currentCommand = 0;//using this for the first element of the array
	unsigned int currentRow = STARTING_ROW;
	unsigned int currentColumn = STARTING_COL;

	while (commands[currentCommand] != 0)//Accept all commands until we run out of commands, which the value of the array will be 0
	{	
		/*cout << "Command #" << currentCommand + 1;
		cout << ". Current row: " << currentRow << ", current column: " << currentColumn << endl;*/
		unsigned int tempRowCounter = currentRow;
		unsigned int tempColumnCounter = currentColumn;

		switch (commands[currentCommand]) 
		{
		case 1:
			command = Cmds::PEN_UP;
			setIsPenUp(command);
			break;
		case 2:
			command = Cmds::PEN_DWN;
			setIsPenUp(command);
			break;
		case 3:
			command = Cmds::TURN_RIGHT;
			if (direction == Directions::NORTH)
			{
				direction = Directions::EAST;
			}
			else if (direction == Directions::EAST)
			{
				direction = Directions::SOUTH;
			}
			else if (direction == Directions::SOUTH)
			{
				direction = Directions::WEST;
			}
			else if (direction == Directions::WEST)
			{
				direction = Directions::NORTH;
			}
			break;
		case 4:
			command = Cmds::TURN_LEFT;
			if (direction == Directions::NORTH)
			{
				direction = Directions::WEST;
			}
			else if (direction == Directions::EAST)
			{
				direction = Directions::NORTH;
			}
			else if (direction == Directions::SOUTH)
			{
				direction = Directions::EAST;
			}
			else if (direction == Directions::WEST)
			{
				direction = Directions::SOUTH;
			}
			break;
		case 5:
			command = Cmds::MOVE;
			switch (int(direction))//move as dictated by direction and the array's subscript + 1 number of steps
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
						if (!getIsPenUp())
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
						if (!getIsPenUp())
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
						if (!getIsPenUp())
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
						if (!getIsPenUp())
						{
							m_Floor[currentRow][tempColumnCounter] = 1;
						}
						tempColumnCounter--;
					}
					break;
				default:
					cout << "Bad direction for: " << int(direction) << endl;
					return;
			}//end of case 5 switch

			currentCommand++;//must increment so we don't end up in the subscript for number of steps
			break;//end of case 5
		case 6:
			command = Cmds::DISPLAY;
			break;
		case 9:
			command = Cmds::END_OF_DATA;//probably won't ever get entered due to while loop
			break;
		default:
			cout << "Bad command for: " << currentCommand << ", " << commands[currentCommand] << endl;
			return;
		}//end of commands switch
		currentCommand++;//increment for the next subscript of commands array
	}//end of while loop
	//cout << currentCommand << endl;
	for (size_t row = 0; row < m_Floor.size(); ++row)
	{
		for (size_t column = 0; column < NCOLS; ++column)
		{
			if (m_Floor[row][column])
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;//move on to next row
	}

	cout << '\n' << endl;//extra space for system pause


}//end of processTurtleMoves function

 //use the endl for each row
 //if greater than 2, print *