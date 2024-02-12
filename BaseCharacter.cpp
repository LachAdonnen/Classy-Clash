#include "BaseCharacter.h"

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

void BaseCharacter::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return {
        screenPosition.x,
        screenPosition.y,
        spriteWidth * spriteScale,
        spriteHeight * spriteScale};
}