#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    // STEP 1 : Game Loop

    // colors
    Color darkBlue = {44, 44, 127, 255};

    // Creating the game window : balck canvas
    InitWindow(300, 600, "Raylib tetris");
    
    // how fast the game should run
    SetTargetFPS(60);
    

    // STEP 2: Creating the Grid 
    Grid grid = Grid();
    grid.print();

    // STEP 3: Creating the blocks
    IBlock block = IBlock();
    // block.Move(4, 3);


    // STEP 4: Move the blocks

    // inside while loop check for any events
    while(WindowShouldClose() == false)     // checks esc key is pressed or close icon is pressed and returns true if it is clicked exit
    {
        // to begin drwaing canvas
        BeginDrawing();

        // background
        ClearBackground(darkBlue);

        // grid with cells
        grid.Draw();

        block.Draw();

        // to end drwaing canvas
        EndDrawing();
    }
    CloseWindow();
}