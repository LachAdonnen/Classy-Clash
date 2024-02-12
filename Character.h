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
private:
};

#endif // !CHARACTER_H