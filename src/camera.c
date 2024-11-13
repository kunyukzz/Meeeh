#include "camera.h"

#define CAM_OFFSET_XZ 8.0f
#define CAM_OFFSET_Y 15.0f

Camera3D myCam;

void InitCustomCam(float posX, float posY, float posZ, Vector3 target)
{
    myCam.position = (Vector3){ posX + CAM_OFFSET_XZ, posY + CAM_OFFSET_Y, posZ + CAM_OFFSET_XZ };
    myCam.target = target;
    myCam.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    myCam.fovy = 45.0f;
    myCam.projection = 0;
};

void UpdateCustomCam(float posX, float posY, float posZ, Vector3 target)
{
    myCam.position = (Vector3){ posX + CAM_OFFSET_XZ, posY + CAM_OFFSET_Y, posZ + CAM_OFFSET_XZ };
    myCam.target = target;
};
