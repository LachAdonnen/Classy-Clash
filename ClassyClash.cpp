#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

int main()
{
    const int screenWidth = 384;
    const int screenHeight = 384;

    InitWindow(screenWidth, screenHeight, "Classy Clash");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("nature_tileset/World Map.png");
    Vector2 mapPosition = {0.0f, 0.0f};
    const float mapScale{4.f};

    Character player{screenWidth, screenHeight};

    Enemy goblin {
        {400.f, 400.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };
    goblin.setTarget(&player);

    Prop props[2] {
        Prop{{600.f, 200.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
    };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw your game here
        mapPosition = Vector2Scale(player.getWorldPosition(), -1.f);
        DrawTextureEx(background, mapPosition, 0, mapScale, WHITE);

        player.tick(GetFrameTime());

        if (player.getWorldPosition().x < 0.f ||
            player.getWorldPosition().x > ((background.width * mapScale) - screenWidth) ||
            player.getWorldPosition().y < 0.f ||
            player.getWorldPosition().y > ((background.height * mapScale) - screenHeight))
        {
            player.undoMovement();
        }

        for (auto prop : props)
        {
            if (CheckCollisionRecs(player.GetCollisionRec(), prop.getCollisionRec(player.getWorldPosition())))
            {
                player.undoMovement();
            
            }
            prop.Render(player.getWorldPosition());
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && 
            CheckCollisionRecs(player.GetWeaponCollisionRec(), goblin.GetCollisionRec()))
        {
            goblin.setAlive(false);
        }

        if (!player.isAlive())
        {
            DrawText("Game Over", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else
        {
            std::string health = "Health: ";
            health.append(std::to_string(player.getHealth()), 0, 5);
            DrawText(health.c_str(), 55.f, 45.f, 40, RED);
        }
        
        goblin.tick(GetFrameTime());

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    return 0;
}