extern "C"
{
#include "raylib.h"
}

#include <iostream>
#include <vector>

const int screenWidth = 1920;
const int screenHeight = 1020;

const int screenDelimBorderX = screenHeight;

const int squareWidth = 102;

// clang-format off
std::vector<std::vector<unsigned int>> mapData = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
// clang-format on

void DrawingMap(const std::vector<std::vector<unsigned int>>& data,
                const unsigned int squareSideLength)
{
    for (int i = 0; i < data.size(); i++)
        for (int j = 0; j < data[i].size(); j++)
        {
            Color squareColor;
            squareColor = (data[i][j]) ? BLUE : SKYBLUE;
            DrawRectangle(j * squareSideLength, i * squareSideLength,
                          squareSideLength, squareSideLength, squareColor);
        }

    for (int i = 0; i < screenHeight / squareSideLength; i++)
    {
        DrawLine(0, (i + 1) * squareSideLength, screenDelimBorderX,
                 (i + 1) * squareSideLength, BLACK);

        DrawLine((i + 1) * squareSideLength, 0, (i + 1) * squareSideLength,
                 screenHeight, BLACK);
    }

    DrawRectangle(screenDelimBorderX, 0, screenWidth, screenHeight, BLACK);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Simple raycast");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLANK);
        DrawingMap(mapData, squareWidth);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}