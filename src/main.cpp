#include "raylib.h"
#include "rocket.h"

const int screenWidth = 1600;
const int screenHeight = 800;
Rocket rocket(screenWidth / 2, screenHeight / 2, 0);

int main()
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "Food Collector Game");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        rocket.move();

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        rocket.show();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}
