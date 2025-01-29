// Header file

#pragma once    // only included once to avoid duplication
#include <vector>
#include <raylib.h>

using namespace std;

class Grid {
    public:
    // constructor
    Grid();

    // initialize the grid with zeros
    void Intitialize();

    // to print the grid
    void print();

    void Draw();

    // Need to know the rows and cols in grid
    int grid[20][10];

    private: 

    int numRows;
    int numCols;
    int cellSize;     // size of cell inside the grid 
    vector<Color> colors;   

};

