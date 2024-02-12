#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int screenWidth, int screenHeight);
    void tick(float dT);
private:
};