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
    Character::screenWidth = screenWidth;
    Character::screenHeight = screenHeight;
}

Vector2 Character::getScreenPosition()
{
    return {(screenWidth / 2.f) - (spriteScale * (texture.width / spriteMaxFrames) / 2.f),
           (screenHeight / 2.f) - (spriteScale * (texture.height) / 2.f)};
}

void Character::tick(float dT)
{
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    
    BaseCharacter::tick(dT);
}