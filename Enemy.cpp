#include "Enemy.h"
#include "raylib.h"
#include "raymath.h"

Enemy::Enemy(Vector2 i_worldPosition, Texture2D i_textureIdle, Texture2D i_textureRun)
{
    worldPosition = i_worldPosition;
    textureIdle = i_textureIdle;
    textureRun = i_textureRun;
    texture = textureIdle;
    spriteWidth = static_cast<float>(texture.width) / spriteMaxFrames;
    spriteHeight = static_cast<float>(texture.height);
}

void Enemy::tick(float dT)
{
    worldPositionLastFrame = worldPosition;

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
         spriteHeight},
        {screenPosition.x,
         screenPosition.y,
         spriteScale * spriteWidth,
         spriteScale * spriteHeight},
        {0, 0},
        spriteScale,
        WHITE);
}