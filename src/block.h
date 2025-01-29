#pragma once
#include<vector>
#include<map>
#include "position.h"
#include "colors.h"

using namespace std;
// need to detrmine the information what they need to store and distinguish between each block, as each block is different shape and rotating style
class Block 
{
    public:
        Block();
        void Draw();
        void Move(int rows, int columns);
        vector<Position> GetCellPositions();
        int id;
        map<int, vector<Position>> cells;

        // Move the blocks to particular cell using the offset position -> row_offset and column_offset 


    private:
        int cellSize;
        int rotationState;
        vector<Color> colors;
        int rowOffset;
        int colOffset;
};