#include "Enemy.h"
#include "raylib.h"
#include "raymath.h"

Enemy::Enemy(Vector2 worldPosition, Texture2D textureIdle, Texture2D textureRun)
{
    Enemy::worldPosition = worldPosition;
    Enemy::textureIdle = textureIdle;
    Enemy::textureRun = textureRun;
    texture = textureIdle;
    spriteWidth = static_cast<float>(texture.width) / spriteMaxFrames;
    spriteHeight = static_cast<float>(texture.height);
}

void Enemy::tick(float dT)
{
    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());
    BaseCharacter::tick(dT);
}

void Enemy::setTarget(Character* target)
{
    Enemy::target = target;
}