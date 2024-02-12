#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 worldPosition, Texture2D idleTexture , Texture2D runTexture);
    Vector2 getWorldPosition() { return worldPosition; }
    void tick(float dT);
    void undoMovement();
    Rectangle GetCollisionRec();
private:
    Vector2 worldPosition{};
    Texture2D textureIdle;
    Texture2D textureRun;
    Texture2D texture;
    int spriteMaxFrames{6};
    float spriteWidth{};
    float spriteHeight{};
    float spriteScale{4.f};

    Vector2 screenPosition{};
    Vector2 worldPositionLastFrame{};
    float moveSpeed{4.f};

    float rightLeft{1.f};
    int spriteCurrentFrame{0};
    float spriteRunningTime{0.f};
    float spriteUpdateTime{1.f / 12.f};
};