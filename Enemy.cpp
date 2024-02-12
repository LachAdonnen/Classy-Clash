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
    moveSpeed = 3.5f;
}

Vector2 Enemy::getScreenPosition()
{
    return Vector2Subtract(worldPosition, target->getWorldPosition());
}

void Enemy::tick(float dT)
{
    if (!isAlive())
        return;

    velocity = Vector2Subtract(target->getScreenPosition(), getScreenPosition());
    if (Vector2Length(velocity) < radius)
        velocity = {};

    BaseCharacter::tick(dT);

    if (CheckCollisionRecs(GetCollisionRec(), target->GetCollisionRec()))
        target->takeDamage(damgePerSecond * dT);
}

void Enemy::setTarget(Character* target)
{
    Enemy::target = target;
}