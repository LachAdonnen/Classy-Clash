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

    Texture2D playerTexture = LoadTexture("characters/knight_idle_spritesheet.png");
    const int playerSpriteCount = 6;
    const float playerSpriteWidth = (float)(playerTexture.width / playerSpriteCount);
    float playerSpriteScale = 4.0f;
    Vector2 playerPosition = {
        screenWidth / 2.0f - (playerSpriteScale * 0.5f * playerSpriteWidth),
        screenHeight / 2.0f - (playerSpriteScale * 0.5f * ((float)playerTexture.height))
    };
    float playerRightLeft = 1.0f; // Positive for right, negative for left
    int playerSpriteCurrentFrame = 0;
    float playerSpriteRunningTime = 0.0f;
    const float playerSpriteUpdateTime = 1.0f / 12.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        const float dT = GetFrameTime();

        Vector2 direction = {0.0f, 0.0f};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0) 
        {
            mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), moveSpeed));
            playerRightLeft = direction.x >= 0 ? 1.0f : -1.0f;
        }

        // Draw your game here
        DrawTextureEx(background, mapPosition, 0, 4, WHITE);

        playerSpriteRunningTime += dT;
        if (playerSpriteRunningTime >= playerSpriteUpdateTime)
        {
            playerSpriteRunningTime = 0.0f;
            playerSpriteCurrentFrame++;
            if (playerSpriteCurrentFrame >= playerSpriteCount) playerSpriteCurrentFrame = 0;
        }

        DrawTexturePro(
            playerTexture, 
            {
                playerSpriteCurrentFrame * playerSpriteWidth, 
                0, 
                playerRightLeft * playerSpriteWidth, 
                (float)playerTexture.height
            },
            {
                playerPosition.x, 
                playerPosition.y, 
                playerSpriteScale * playerSpriteWidth, 
                playerSpriteScale * (float)playerTexture.height
            },
            {0, 0}, 
            playerSpriteScale, 
            WHITE
        );

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}