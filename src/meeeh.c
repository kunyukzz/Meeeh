#include "raylib.h"
#include "player.h"
#include "debug.h"

static const int scrWidth = 800;
static const int scrHeight = 600;

static void Update(void);
static void Draw(void);
static void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(scrWidth, scrHeight, "Meeeh");
    InitPlayer();
    InitDebugFont();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    UnloadPlayer();
    UnloadDebugFont();

    CloseWindow();
    return 0;
}

void Update(void)
{
    UpdatePlayer();
}

void Draw(void)
{
    BeginDrawing();
    ClearBackground(BLACK);

        BeginMode3D(camera);
        DrawPlayer();
        DrawGrid(20, 1.0f);
        //DrawPlane((Vector3){0.0f, -1.0f, 0.0f},(Vector2){20.0f, 20.0f}, WHITE);
        EndMode3D();

    DebugInfo();
    EndDrawing();
}

void UpdateDrawFrame(void)
{
    Update();
    Draw();
}

