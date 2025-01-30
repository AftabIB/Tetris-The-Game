#pragma once
#include "grid.h"
#include "blocks.cpp"
#include<vector>

using namespace std;


class Game
{
    public:
        Game();
        Block GetRandomBlock();
        vector<Block> GetAllBlocks();
        void Draw();

        // control the movement of the block using the keyboard
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

        // class should create and hold the grid
        Grid grid;
        bool gameOver;


    private:

        // check whether the block is outside of game window using isCellOutside method
        bool IsBlockOutside();

        //rotate the block 
        void RotateBlock();

        // block the block at the end of grid
        void LockBlock();

        // random block
        vector<Block> blocks;
        
        // attribute to hold the current and next block which is visible on screen
        Block currentBlock;
        Block nextBlock;

        // check every cell of block, if it is on the top of the empty cell or not
        bool BlockFits();

        void Reset();

};