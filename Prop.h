#include "raylib.h"

class Prop {
public:
    // Public members and functions
    Prop(Vector2 worldPosition, Texture2D sourceTexture);
    void Render(Vector2 playerPostion);
    Rectangle getCollisionRec(Vector2 playerPosition);
private:
    // Private members and functions
    Vector2 worldPosition;
    Texture2D texture;
    Vector2 screenPosition;
    float scale{4.f};
};