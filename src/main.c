#include "raylib.h"

int main(void)
{
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Meeeh");
    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
