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
        // class should create and hold the grid

        Grid grid;

        // attribute to hold the current block which is visible on screen

    private:
        // random block
        vector<Block> blocks;

};