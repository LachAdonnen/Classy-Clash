#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 worldPosition, Texture2D idleTexture , Texture2D runTexture);
    void tick(float dT);
private:
};