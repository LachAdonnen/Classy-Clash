#include "Character.h"
#include "raylib.h"
#include "raymath.h"

Character::Character(int screenWidth, int screenHeight)
{
    textureIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    textureRun = LoadTexture("characters/knight_run_spritesheet.png");
    texture = textureIdle;
    spriteWidth = static_cast<float>(texture.width) / spriteMaxFrames;
    spriteHeight = static_cast<float>(texture.height);
    screenPosition =
        {
            (screenWidth / 2.f) - (spriteScale * (texture.width / spriteMaxFrames) / 2.f),
            (screenHeight / 2.f) - (spriteScale * (texture.height) / 2.f)};
}

void Character::tick(float dT)
{
    BaseCharacter::tick(dT);

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
}