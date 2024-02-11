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
    const float mapScale{4.f};

    Character player{};
    player.setScreenPosition(screenWidth, screenHeight);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw your game here
        mapPosition = Vector2Scale(player.getWorldPosition(), -1.f);
        DrawTextureEx(background, mapPosition, 0, mapScale, WHITE);

        player.tick(GetFrameTime());

        if (player.getWorldPosition().x < 0.f ||
            player.getWorldPosition().x > ((background.width * mapScale) - screenWidth) ||
            player.getWorldPosition().y < 0.f ||
            player.getWorldPosition().y > ((background.height * mapScale) - screenHeight))
        {
            player.undoMovement();
        }

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}