#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "raylib.h"

typedef struct Player {
    Vector3 playerPosition;
    Model playerModel;
    Rectangle playerBounds;
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
void ResetPlayer(void);

#endif // !_PLAYER_H_
