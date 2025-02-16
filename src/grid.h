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

    // checking whether the block is outside the grid 
    bool IsCellOutside(int row, int column);

    // Need to know the rows and cols in grid
    int grid[20][10];

    // check whether the cell is empty or not
    bool isCellEmpty(int row, int column);

    // clear the original row which is fully filled
    int ClearFullRows();

private: 

    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;     // size of cell inside the grid 
    vector<Color> colors;   

};

