#include "raylib.h"
#include "raymath.h"

class Character
{
public:
    Character(int screenWidth, int screenHeight);
    Vector2 getWorldPosition() { return worldPosition; }
    void tick(float dT);
    void undoMovement();
    Rectangle GetCollisionRec();
private:
    Texture2D textureIdle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D textureRun{LoadTexture("characters/knight_run_spritesheet.png")};
    Texture2D texture{textureIdle};
    int spriteMaxFrames{6};
    float spriteWidth{};
    float spriteHeight{};
    float spriteScale{4.f};

    Vector2 screenPosition{};
    Vector2 worldPosition{};
    Vector2 worldPositionLastFrame{};
    float moveSpeed{4.f};

    float rightLeft{1.f};
    int spriteCurrentFrame{0};
    float spriteRunningTime{0.f};
    float spriteUpdateTime{1.f / 12.f};
};