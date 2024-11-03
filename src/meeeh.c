#include "raylib.h"
#include "player.h"

static const int scrWidth = 800;
static const int scrHeight = 600;

int main(void)
{
    InitWindow(scrWidth, scrHeight, "Meeeh");
    InitPlayer();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
            BeginMode3D(camera);
            //DrawPlayer();
            
            DrawGrid(20, 1.0f);
            EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
