#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"
#include "raymath.h"
class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPosition() { return worldPosition; }
    virtual Vector2 getScreenPosition() = 0;
    virtual void tick(float dT);
    void undoMovement();
    Rectangle GetCollisionRec();
    bool isAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
protected:
    Texture2D textureIdle;
    Texture2D textureRun;
    Texture2D texture;
    int spriteMaxFrames{6};
    float spriteWidth{};
    float spriteHeight{};
    float spriteScale{4.f};

    Vector2 worldPosition{};
    Vector2 worldPositionLastFrame{};
    float moveSpeed{4.f};

    float rightLeft{1.f};
    int spriteCurrentFrame{0};
    float spriteRunningTime{0.f};
    float spriteUpdateTime{1.f / 12.f};
    Vector2 velocity{};
private:
    bool alive{true};
};

#endif // !BASE_CHARACTER_H