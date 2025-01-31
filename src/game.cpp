#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();  // vector of blocks: for random selection of blocks
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false; 
    score = 0;
    // for sounds
    InitAudioDevice();
    music = LoadMusicStream("../Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("../Sounds/rotate.mp3");
    clearSound = LoadSound("../Sounds/clear.mp3");
}

Game::~Game()
{
    UnloadMusicStream(music);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    CloseAudioDevice();
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
    currentBlock.Draw(25, 25);
    nextBlock.Draw(320, 320);   
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
            UpdateScore(0, 1);
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
        else
        {
            PlaySound(rotateSound);
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
    int rowsCleared = grid.ClearFullRows();
    if(rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
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

// update the score
void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared)
    {
        case 1:
            score += 100;
            break;
        
        case 2:
            score += 300;
            break;
        
        case 3:
            score += 500;
            break;
        
        default:
            break;
    }

    score += moveDownPoints;
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
    score = 0;
}
