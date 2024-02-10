#include "raylib.h"

int main()
{
    const int screenWidth = 384;
    const int screenHeight = 384;

    InitWindow(screenWidth, screenHeight, "Classy Clash");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("nature_tileset/World Map.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw your game here
        Vector2 mapPosition = {0.0f, 0.0f};
        DrawTextureEx(background, mapPosition, 0, 4, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}