#include "Prop.h"
#include "raylib.h"
#include "raymath.h"

Prop::Prop(Vector2 worldPosition, Texture2D sourceTexture) : 
    worldPosition(worldPosition), 
    texture(sourceTexture)
{

}

void Prop::Render(Vector2 playerPosition)
{
    screenPosition = Vector2Subtract(worldPosition, playerPosition);
    DrawTextureEx(texture, screenPosition, 0, scale, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 playerPosition)
{
    return {
        screenPosition.x,
        screenPosition.y,
        static_cast<float>(texture.width) * scale,
        static_cast<float>(texture.height) * scale
    };
}