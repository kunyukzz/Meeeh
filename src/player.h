#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "raylib.h"

typedef struct Player_Transform
{
	Vector3 position;
	Vector3 rotation;
	Vector3 size;
	float scale;
	BoundingBox boundingBox;
	bool canCollide;
} Player_Transform;

typedef struct Player {
    Player_Transform transform;
    //Vector3 playerPosition;
    //Vector3 playerRotation;
    Model playerModel;
    float rotationSpeed;
    //Rectangle playerBounds;
    Texture2D playerTexture;
    Color playerColor;

    // Animation variables
    Rectangle frameRec;
    int currentFrame;
    int currentSeq;

    int numLifes;
    bool dead;
} Player;

extern Player player;
extern Camera3D camera;

void InitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void UnloadPlayer(void);

#endif // !_PLAYER_H_
