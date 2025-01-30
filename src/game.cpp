#include "game.h"
#include<random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();  // vector of blocks: for random selection of blocks
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();

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

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    // detect the key pressed using GetKeyPressed function
    int keyPressed = GetKeyPressed();
    switch(keyPressed)
    {
        case KEY_LEFT:  // checks whether the key pressed = KEY_LEFT constant (Left arrow)
            MoveBlockLeft();
            break;
        
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        
        case KEY_DOWN:
            MoveBlockDown();
            break;
        
        case KEY_UP:
            RotateBlock();
            break;
    } 
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if(IsBlockOutside())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsBlockOutside())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if (IsBlockOutside())
    {
        currentBlock.Move(-1, 0);
    }
}

bool Game::IsBlockOutside()
{
    // get the full size or list of the blocks
    vector<Position> tiles = currentBlock.GetCellPositions();

    // check any tile is outside the grid 
    for(Position item: tiles)
    {
        if(grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if(IsBlockOutside())
    {
        currentBlock.UndoRotation();
    }
}
