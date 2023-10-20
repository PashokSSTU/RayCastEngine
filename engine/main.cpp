extern "C"
{
#include "raylib.h"
}

#include <cmath>
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
            squareColor = (data[i][j]) ? GRAY : BLACK;
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
    Vector2 playerPos = {screenDelimBorderX / 2, screenDelimBorderX / 2};
    float speed = 5.0f;
    float playerAngle = PI / 2;
    float rotationSpeedDeg = 10.0f;
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Simple raycast");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            playerPos.x += speed * cos(playerAngle);
            playerPos.y -= speed * sin(playerAngle);
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            playerPos.x -= speed * cos(playerAngle);
            playerPos.y += speed * sin(playerAngle);
        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            playerAngle = (playerAngle <= 0.0f)
                              ? 2 * PI
                              : playerAngle - rotationSpeedDeg * PI / 180;
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            playerAngle = (playerAngle >= 2 * PI)
                              ? 0.0f
                              : playerAngle + rotationSpeedDeg * PI / 180;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLANK);
        DrawingMap(mapData, squareWidth);

        DrawLineEx(playerPos,
                   {playerPos.x + 20 * cos(playerAngle),
                    playerPos.y - 20 * sin(playerAngle)},
                   3, GREEN);
        DrawCircleV(playerPos, 10, YELLOW);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}