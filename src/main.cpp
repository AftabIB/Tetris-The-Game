#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

using namespace std;

double lastUpdateTime = 0;

// check that some interval has passed like for 2 or 3 seconds then mve the block downwards automatically 
bool EventTriggered(double interval)    // time in seconds
{
    // get the current time in seconds (build in function in raylib)
    double currentTime = GetTime();
    
    // difference 
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

int main() 
{
    // STEP 1 : Game Loop

    // Creating the game window : black canvas
    InitWindow(600, 650, "Raylib tetris");
    
    // how fast the game should run
    SetTargetFPS(60);
    
    // Loading the font
    Font font = LoadFontEx("../Font/monogram.ttf", 64, 0, 0);

    // STEP 2: Creating the Grid 
    // Grid grid = Grid();
    // grid.print();
 
    // STEP 3: Creating the blocks
    // IBlock block = IBlock();
    // block.Move(4, 3);

    Game game = Game();

    // STEP 4: Move the blocks

    // inside while loop check for any events
    while(WindowShouldClose() == false)     // checks esc key is pressed or close icon is pressed and returns true if it is clicked exit
    {
        // Play the music
        UpdateMusicStream(game.music);

        // Handle the movement of the blocks (left, right down)
        game.HandleInput();

        // STEP 6: Moving the blocks downwards after interval pass the difference between the current time and last updated time which is currently 0
        if(EventTriggered(0.4))
        {
            game.MoveBlockDown();
        }

        // to begin drwaing canvas
        BeginDrawing();

        // background
        ClearBackground(darkBlue);

        // Draw the text
        DrawTextEx(font, "Score", {410, 35}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {420, 200}, 38, 2, WHITE);

        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {375, 530}, 38, 2, WHITE);
        }

        DrawRectangleRounded({348, 80, 230, 100}, 0.3, 6, lightBlue);

        // convert it from int into the char array
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        // show thw score
        DrawTextEx(font, scoreText, {344 + (230 - textSize.x)/2, 110}, 38, 2, WHITE);

        // show nwxt block
        DrawRectangleRounded({348, 245, 230, 200}, 0.3, 6, lightBlue);

        game.Draw();

        // 

        // to end drwaing canvas
        EndDrawing();
    }
    CloseWindow();
}