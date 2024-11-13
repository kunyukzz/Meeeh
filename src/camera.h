#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "raylib.h"

typedef enum
{
    CAMERA_GAME = 0,
    CAMERA_MENU = 1,
} Camera_ID;

typedef struct GameCam_Data
{
    Vector3 position;
    Vector3 target;
} GameCam_Data;

extern Camera3D myCam;

void InitCustomCam(float posX, float posY, float posZ, Vector3 target);
void UpdateCustomCam(float posX, float posY, float posZ, Vector3 target);

#endif // !_CAMERA_H_
