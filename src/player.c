#include "player.h"
#include "raymath.h"

Player player;
Camera3D camera;

void InitPlayer(void)
{
    camera.position = (Vector3){0.0f, 0.0f, 0.0f};
    camera.target = player.playerPosition;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 70.0f;
    camera.projection = 0;

    player.playerModel = LoadModel("resources/models/Robot.glb");
    player.playerTexture = LoadTexture("resources/textures/RBase.png");
    player.playerPosition = (Vector3){ 0.0f, 0.0f, 0.0f };
}

void UpdatePlayer(void)
{
    
    Vector3 targetPos;

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        Ray ray = GetMouseRay(GetMousePosition(), camera);
        if (ray.direction.y != 0)
        {
            float distance = -ray.position.y / ray.direction.y;
            targetPos = (Vector3){ ray.position.x + ray.direction.x * distance, 0.0f, ray.position.z + ray.direction.z * distance };
        }
    }

    // Vector3 direction = (Vector3){ targetPos.x - player.position.x, 0.0f, targetPos.z - player.position.z };

    Vector3 direction = Vector3Subtract(targetPos, player.playerPosition);
    float distance = Vector3Length(direction);

    if (distance > 0.1f) // Only move if we are far enough from the target
    {
        float dt = GetFrameTime();
        float moveSpeed = 2.0f;
        direction = Vector3Normalize(direction);
        player.playerPosition.x += direction.x * moveSpeed * dt;
        player.playerPosition.z += direction.z * moveSpeed * dt;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        player.playerPosition = (Vector3){ 0.0f, 0.0f, 0.0f };
        targetPos = player.playerPosition;
    }
}

void DrawPlayer(void)
{
    DrawModel(player.playerModel, player.playerPosition, 1.5f, WHITE);
}

void UnloadPlayer(void)
{
    UnloadModel(player.playerModel);
    UnloadTexture(player.playerTexture);
}
