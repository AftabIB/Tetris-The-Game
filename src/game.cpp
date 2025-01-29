#include "game.h"
#include<random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();  // vector of blocks: for random selection of blocks
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        // check whether the block is empty or not
        // if yes recreate the block vector
        blocks = GetAllBlocks();
    }
    // cycle to select the blocks
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];

    // remove it from block vector
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

// vector that returns the new vector block
vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), TBlock(), ZBlock()};
}