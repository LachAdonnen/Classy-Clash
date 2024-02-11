#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int screenWidth = 384;
    const int screenHeight = 384;

    InitWindow(screenWidth, screenHeight, "Classy Clash");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("nature_tileset/World Map.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    Character player{};
    player.setScreenPosition(screenWidth, screenHeight);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw your game here
        mapPosition = Vector2Scale(player.getWorldPosition(), -1.f);
        DrawTextureEx(background, mapPosition, 0, 4, WHITE);

        player.tick(GetFrameTime());

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}