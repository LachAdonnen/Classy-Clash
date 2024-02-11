#include "raylib.h"

class Prop {
public:
    // Public members and functions
    Prop(Vector2 worldPosition, Texture2D sourceTexture);
private:
    // Private members and functions
    Vector2 worldPosition;
    Texture2D texture;
    Vector2 screenPosition;
    float scale{4.f};
};