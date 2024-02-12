#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
    // Constructor code here
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