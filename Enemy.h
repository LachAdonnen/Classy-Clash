#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 worldPosition, Texture2D idleTexture , Texture2D runTexture);
    virtual void tick(float dT) override;
    void setTarget(Character *target);
    virtual Vector2 getScreenPosition() override;
private:
    Character* target;
};