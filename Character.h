#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int screenWidth, int screenHeight);
    virtual void tick(float dT) override;
    virtual Vector2 getScreenPosition() override;
private:
    int screenWidth{};
    int screenHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
};

#endif // !CHARACTER_H