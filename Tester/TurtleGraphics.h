// Assignment 6 Solution: TurtleGraphics.h
// Declaration of class TurtleGraphics.
// Member functions are defined in TurtleGraphics.cpp.
// Author: Bob Langelaan
// Date: Feb 28, 2016

#pragma once

// Define some enum types that will be used in solution.

enum Commands { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum Directions { NORTH, EAST, SOUTH, WEST };

class TurtleGraphics
{
private:
    
    const static int NROWS = 22;  // number of rows in floor
    const static int NCOLS = 70;  // number of colums in floor
    
    const static int STARTING_ROW = 0;    // row that turtle will start in
    const static int STARTING_COL = 0;    // column that turtle will start in
    
    const static Directions STARTING_DIRECTION = SOUTH; // direction that turtle
    // will be facing at the start
    
    const static bool STARTING_PEN_POSITION = false; // Pen will be up when
    // program starts
    // false means pen up, true means pen down
    
    void displayFloor() const;  // will display floor on the screen
    
    bool m_Floor [NROWS][NCOLS];   // floor on which turtle will draw
    
public:
    TurtleGraphics(void); //ctor will init. floor to all "false" values,
    //     as well as initialization of other data members
    void processTurtleMoves( const int commands[]);  // will process
    // the commands contained in array "commands"
};


