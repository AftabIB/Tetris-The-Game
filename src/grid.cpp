// Imlementation file

#include <iostream>
#include "grid.h"
#include "colors.h"

using namespace std;

// grid size
Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    // in pixels
    cellSize = 30;
    Intitialize();
    colors = GetCellColors();
}

// all cells are initialized to zero
void Grid::Intitialize()
{
    for(int row=0; row< numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::print()
{
    // print it all to terminal
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
}

// Draw the each cell of grid

void Grid::Draw()
{
    // draw the grid color with specific color like red -> 1, yellow -> 2, etc
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            // draw the cells (in square)
            DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]); // -> cell values are currently zero hence 0th index color will be returned       
            // plus and minus because to show the margin of 1px


        }
    }
}

// check whether the colored blocks are outside the grid or not
bool Grid::IsCellOutside(int row, int column)
{
    if( row >= 0&& row < numRows && column >=0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

// check whether the row is full, if yes then remove it from down of  grid
int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row>=0; row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if(completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    // check whether the cell in row is empty or not
    for (int column = 0; column < numCols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}


// clear the row if it doesn't contain the any empty cell 
void Grid::ClearRow(int row)
{
    for(int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

// move that number of all the rows which are all filled in total, like 2 are filled and 3 are yet to be then, that 3 rows should be moved 2 down
void Grid::MoveRowDown(int row, int numRows)
{
    for(int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
