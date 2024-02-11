#include "raylib.h"
#include "raymath.h"

class Character
{
public:
    Vector2 getWorldPosition() { return worldPosition; }
    void setScreenPosition(int screenWidth, int screenHeight);
    void tick(float dT);

private:
    Texture2D textureIdle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D textureRun{LoadTexture("characters/knight_run_spritesheet.png")};
    Texture2D texture{textureIdle};
    int spriteMaxFrames{6};
    float spriteWidth{textureIdle.width / (float)spriteMaxFrames};
    float spriteScale{4.f};

    Vector2 screenPosition{};
    Vector2 worldPosition{};
    const float moveSpeed{4.f};

    float rightLeft{1.f};
    int spriteCurrentFrame{0};
    float spriteRunningTime{0.f};
    const float spriteUpdateTime{1.f / 12.f};
};

void Character::setScreenPosition(int screenWidth, int screenHeight)
{
    screenPosition =
        {
            (screenWidth / 2.f) - (spriteScale * (texture.width / spriteMaxFrames) / 2.f),
            (screenHeight / 2.f) - (spriteScale * (texture.height) / 2.f)};
}

void Character::tick(float dT)
{
    Vector2 direction = {0.0f, 0.0f};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0)
    {
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(direction), moveSpeed));
        rightLeft = direction.x >= 0 ? 1.f : -1.f;
        texture = textureRun;
    }
    else
        texture = textureIdle;

    spriteRunningTime += dT;
    if (spriteRunningTime >= spriteUpdateTime)
    {
        spriteRunningTime = 0.0f;
        spriteCurrentFrame++;
        if (spriteCurrentFrame >= spriteMaxFrames)
            spriteCurrentFrame = 0;
    }

    DrawTexturePro(
        texture,
        {spriteCurrentFrame * spriteWidth,
         0,
         rightLeft * spriteWidth,
         (float)texture.height},
        {screenPosition.x,
         screenPosition.y,
         spriteScale * spriteWidth,
         spriteScale * (float)texture.height},
        {0, 0},
        spriteScale,
        WHITE);
}

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