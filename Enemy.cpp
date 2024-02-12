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
    BaseCharacter::tick(dT);
}