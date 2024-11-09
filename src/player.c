#include "player.h"
#include "raymath.h"

Vector3 targetPos = {0};
static bool targetDraw = false;

Player player;
Camera3D camera;

void InitPlayer(void)
{
    camera.position = (Vector3){10.0f, 20.0f, 10.0f};
    //camera.target = player.playerPosition;
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    player.playerModel = LoadModel("resources/models/Robot.glb");
    player.playerTexture = LoadTexture("resources/textures/RBase.png");
    player.transform.position = (Vector3){ 0.0f, 0.0f, 0.0f };
    player.transform.scale = 1.0f;
    player.rotationSpeed = 0.01f;
}

void UpdatePlayer(void)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        Ray ray = GetMouseRay(GetMousePosition(), camera);
        if (ray.direction.y != 0)
        {
            float distance = -ray.position.y / ray.direction.y;
            targetPos = (Vector3){ ray.position.x + ray.direction.x * distance, 0.0f, ray.position.z + ray.direction.z * distance };
        }

        targetDraw = true;
    }

    Vector3 direction = Vector3Subtract(targetPos, player.transform.position);
    float distance = Vector3Length(direction);

    if (distance > 0.1f) // Only move if far enough from the target
    {
        direction = Vector3Normalize(direction);
        
        // calculate rotation-Y angle
        float y_angle = -(atan2(direction.z, direction.x) - PI / 2.0f);
        Vector3 newRotation = (Vector3){0.0f, y_angle, 0.0f};

        // slerp current rotation angle to new rotation angle
        // a.k.a in-between in animation world
        const Quaternion start = QuaternionFromEuler(player.transform.rotation.z, player.transform.rotation.y, player.transform.rotation.x);
	    const Quaternion end   = QuaternionFromEuler(newRotation.z, newRotation.y, newRotation.x);
	    const Quaternion slerp = QuaternionSlerp(start, end, player.rotationSpeed);

        // update rotation and rotation matrix
        player.playerModel.transform = QuaternionToMatrix(slerp);
        player.transform.rotation = newRotation;

        // move player towards target position
        float dt = GetFrameTime();
        float moveSpeed = 5.0f;
        player.transform.position.x += direction.x * moveSpeed * dt;
        player.transform.position.z += direction.z * moveSpeed * dt;
    }
}

void DrawPlayer(void)
{
    if (targetDraw) DrawCylinder((Vector3){targetPos.x, targetPos.y - 0.1f, targetPos.z}, 0.5f, 0.5f, 0.1f, 16, RED);
    DrawModel(player.playerModel, player.transform.position, player.transform.scale, WHITE);
}

void UnloadPlayer(void)
{
    UnloadModel(player.playerModel);
    UnloadTexture(player.playerTexture);
}
