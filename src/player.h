#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "raylib.h"
#include "animator.h"

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
    Model playerModel;
    float rotationSpeed;
    float moveSpeed;
    //Rectangle playerBounds;
    Texture2D playerTexture;
    Color playerColor;
    Animator_Data animator;

    // Animation variables
    Rectangle frameRec;
    int currentFrame;
    int currentSeq;

    int numLifes;
    bool dead;
} Player;

extern Player player;
extern Camera3D camera;
extern Vector3 targetPos;

void InitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void UnloadPlayer(void);

#endif // !_PLAYER_H_
