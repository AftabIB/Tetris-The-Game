#include "game.h"
#include<random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();  // vector of blocks: for random selection of blocks
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false; 

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
    
    if(gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

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
    if(!gameOver)
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if(!gameOver)
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if(!gameOver)
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false) // also check whether the cells are empty or is there any already block occupied
        {
            currentBlock.Move(-1, 0);

            // lock the blocks at the current state when they reach at the end of grid, so that they cannot be moved left or right
            LockBlock();
        }
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
    if(!gameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
    }
}

// lock the block on grid at the end
void Game::LockBlock()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    
    // store the id of the block in the grid    
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;

    if(BlockFits() == false)
    {
        gameOver = true; 
    }

    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits()
{
    vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        if(grid.isCellEmpty(item.row, item. column) == false)
        {
            return false;
        }
    }
    return true;
}

// resets the grid after game overs
void Game::Reset()
{
    // sets the grid cells to zero
    grid.Intitialize();

    // selecting the new random block and next block
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
