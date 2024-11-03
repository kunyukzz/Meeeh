#include "raylib.h"
#include "player.h"

static const int scrWidth = 800;
static const int scrHeight = 600;

static void Update(void);
static void Draw(void);
static void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(scrWidth, scrHeight, "Meeeh");
    InitPlayer();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    UnloadPlayer();

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
    ClearBackground(GRAY);

        BeginMode3D(camera);
        DrawPlayer();
        DrawGrid(10, 1.0f);
        EndMode3D();

    EndDrawing();
}

void UpdateDrawFrame(void)
{
    Update();
    Draw();
}
