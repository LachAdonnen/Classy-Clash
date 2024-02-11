#include "raylib.h"
#include "raymath.h"

int main()
{
    const int screenWidth = 384;
    const int screenHeight = 384;

    InitWindow(screenWidth, screenHeight, "Classy Clash");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("nature_tileset/World Map.png");
    Vector2 mapPosition = {0.0f, 0.0f};
    float moveSpeed = 4.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction = {0.0f, 0.0f};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0) 
        {
            mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), moveSpeed));
        }

        // Draw your game here
        DrawTextureEx(background, mapPosition, 0, 4, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}