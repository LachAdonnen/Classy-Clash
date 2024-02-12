#include "BaseCharacter.h"
#include "raylib.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
    // Constructor code here
}

void BaseCharacter::tick(float dT)
{
    worldPositionLastFrame = worldPosition;

    spriteRunningTime += dT;
    if (spriteRunningTime >= spriteUpdateTime)
    {
        spriteRunningTime = 0.0f;
        spriteCurrentFrame++;
        if (spriteCurrentFrame >= spriteMaxFrames)
            spriteCurrentFrame = 0;
    }

    if (Vector2Length(velocity) != 0)
    {
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), moveSpeed));
        rightLeft = velocity.x >= 0 ? 1.f : -1.f;
        texture = textureRun;
    }
    else
        texture = textureIdle;
    velocity = {};

    DrawTexturePro(
        texture,
        {spriteCurrentFrame * spriteWidth,
         0,
         rightLeft * spriteWidth,
         spriteHeight},
        {getScreenPosition().x,
         getScreenPosition().y,
         spriteScale * spriteWidth,
         spriteScale * spriteHeight},
        {0, 0},
        spriteScale,
        WHITE);
}

void BaseCharacter::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return {
        getScreenPosition().x,
        getScreenPosition().y,
        spriteWidth * spriteScale,
        spriteHeight * spriteScale};
}