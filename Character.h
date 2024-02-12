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
    Rectangle GetWeaponCollisionRec() { return weaponCollisionRec; };
    float getHealth() const { return heatlh; };
    void takeDamage(float damage);
private:
    int screenWidth{};
    int screenHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float heatlh{100.f};
};

#endif // !CHARACTER_H