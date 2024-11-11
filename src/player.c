#include "player.h"
#include "raymath.h"
#include <stdio.h>

Vector3 targetPos = { 0 };
Vector3 direction = { 0 };
static bool targetDraw = false;
static bool isAligned = false;
static bool isMoving = false;

Player player;
Camera3D camera;

// Private declarations
void CreateRayTarget(Camera3D camera);
bool RotateTowards(Vector3* rotation, Vector3 currentPos, Vector3 targetPos, float rotationSpeed, float angleThreshold);
void MoveTowards(Vector3* position, Vector3 targetPos, float speed);

void InitPlayer(void)
{
    camera.position = (Vector3){ player.transform.position.x + 10.f, 20.0f, player.transform.position.z + 10.0f };
    camera.target = player.transform.position;
    // camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    player.playerModel = LoadModel("resources/models/NewRobot.glb");
    player.playerTexture = LoadTexture("resources/textures/RBase.png");
    player.transform.position = (Vector3){ 0.0f, 0.0f, 0.0f };
    player.transform.scale = 1.0f;
    player.moveSpeed = 3.0f;
    player.rotationSpeed = player.moveSpeed;
}

void CreateRayTarget(Camera camera)
{
    Ray ray = GetMouseRay(GetMousePosition(), camera);
    if (ray.direction.y != 0)
    {
        float distance = -ray.position.y / ray.direction.y;
        targetPos = (Vector3){ ray.position.x + ray.direction.x * distance, 0.0f, ray.position.z + ray.direction.z * distance };
    }
}

bool RotateTowards(Vector3* rotation, Vector3 currentPos, Vector3 targetPos, float rotationSpeed, float angleThreshold)
{
    // calculate rotation-Y angle
    Vector3 direction = Vector3Subtract(targetPos, currentPos);
    float y_angle = -(atan2(direction.z, direction.x) - PI / 2.0f);
    Vector3 newRotation = (Vector3){ 0.0f, y_angle, 0.0f };

    // slerp current rotation angle to new rotation angle
    // a.k.a in-between in animation world
    const Quaternion start = QuaternionFromEuler(player.transform.rotation.z, player.transform.rotation.y, player.transform.rotation.x);
    const Quaternion end = QuaternionFromEuler(newRotation.z, newRotation.y, newRotation.x);
    const Quaternion slerp = QuaternionSlerp(start, end, rotationSpeed * GetFrameTime());

    player.playerModel.transform = QuaternionToMatrix(slerp);
    *rotation = newRotation;

    // Check if within the angle threshold
    float angleDifference = fabs(rotation->y - y_angle);
    return angleDifference < angleThreshold;

    // update rotation and rotation matrix
    // player.playerModel.transform = QuaternionToMatrix(slerp);
    // player.transform.rotation = newRotation;
}

void MoveTowards(Vector3* position, Vector3 targetPos, float speed)
{
    Vector3 direction = Vector3Subtract(targetPos, *position);
    float distance = Vector3Length(direction);

    if (distance > 0.1f)
    {
        direction = Vector3Normalize(direction);

        float dt = GetFrameTime();
        position->x += direction.x * speed * dt;
        position->z += direction.z * speed * dt;
    }
}

void UpdatePlayer(void)
{
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        CreateRayTarget(camera);
        targetDraw = true;
        isMoving = true;
    }

    // isAligned = RotateTowards(&player.transform.rotation, player.transform.position, targetPos, player.rotationSpeed, 0.005f);
    RotateTowards(&player.transform.rotation, player.transform.position, targetPos, player.rotationSpeed, 0.01f);
    if (isMoving)
    {
        MoveTowards(&player.transform.position, targetPos, player.moveSpeed);

        if (Vector3Distance(player.transform.position, targetPos) < 0.1f)
        {
            isMoving = false; // Stop moving when close to the target
        }
    }

    camera.target = player.transform.position;
    camera.position = (Vector3){ player.transform.position.x + 10.f, 20.0f, player.transform.position.z + 10.0f };
}

void DrawPlayer(void)
{
    if (targetDraw)
        DrawCylinder((Vector3){ targetPos.x, targetPos.y - 0.1f, targetPos.z }, 0.5f, 0.5f, 0.1f, 16, RED);
    DrawModel(player.playerModel, player.transform.position, player.transform.scale, WHITE);
}

void UnloadPlayer(void)
{
    UnloadModel(player.playerModel);
    UnloadTexture(player.playerTexture);
}
