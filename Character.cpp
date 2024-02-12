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
    if (!isAlive())
        return;

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    BaseCharacter::tick(dT);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.f)
    {
        origin = {0.f, weapon.height * spriteScale};
        offset = {35.f, 55.f};
        
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
        weaponCollisionRec =
            {
                getScreenPosition().x + offset.x,
                getScreenPosition().y + offset.y - (weapon.height * spriteScale),
                spriteScale * weapon.width,
                spriteScale * weapon.height};
    }
    else
    {
        origin = {weapon.width * spriteScale, weapon.height * spriteScale};
        offset = {25.f, 55.f};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
        weaponCollisionRec =
            {
                getScreenPosition().x + offset.x - (weapon.width * spriteScale),
                getScreenPosition().y + offset.y - (weapon.height * spriteScale),
                spriteScale * weapon.width,
                spriteScale * weapon.height};
    }

    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle destination{getScreenPosition().x + offset.x, getScreenPosition().y + offset.y, spriteScale * weapon.width, spriteScale * weapon.height};
    DrawTexturePro(weapon, source, destination, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        RED);
}

void Character::takeDamage(float damage)
{
    heatlh -= damage;
    if (heatlh <= 0.f)
        setAlive(false);
}