// Implementation file

#include "block.h"

Block::Block()
{
    // Initialize the cell size
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors(); 
    rowOffset = 0;
    colOffset = 0;
}

// Draw method to draw the methods on screen
void Block::Draw()
{

    // retrives the vector of positions for current rotation state based on current rotationState attribute value
    
    vector<Position> tiles = GetCellPositions();    // updated positions, which included offsets
    
    // position of occupied cells of the block to draw it on the screen -> create the seperate file that contain position for rotations
    for(Position item : tiles)
    {
        // create the rectangle for each cell
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }

}

// Method to move the block by adding the row and column offset
void Block::Move(int rows, int columns)
{
    // change the row and column offset
    rowOffset += rows;
    colOffset += columns;    
}

// method to modify the position of cells in block according to new offsets added 

vector<Position> Block::GetCellPositions()
{
    // get the default cell position for current rotation states
    vector<Position> tiles = cells[rotationState];  
    
    // vector to move the tiles
    vector<Position> moveTiles;

    // look all the tiles and then add the positions
    for(Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + colOffset);

        // push the new offset to movedTiles vector 
        moveTiles.push_back(newPos); 
    }

    return moveTiles;
}