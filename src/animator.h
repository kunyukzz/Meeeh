#pragma once

#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "raylib.h"

typedef enum
{
    PLAYER_IDLE = 0,
    PLAYER_IDLE2 = 1,
    PLAYER_WALK = 2,
    // PLAYER_ATTACK,
    // PLAYER_DEATH
} Animation_ID;

typedef struct Animator_Data
{
    ModelAnimation* modelAnim;
    int animCount;
    unsigned int animIndex;
    int animCurrentFrame;
    int currentAnim;
} Animator_Data;

Animator_Data InitAnimator(const char* fileName);
void SetAnimation(Animator_Data* animator, Animation_ID animID);
void UpdateAnimator(Animator_Data* animator, Model* model, bool isMoving);
void UnloadAnimator(Animator_Data* animator);

//void PlayAnimation(Animator_Data animData, Model model);

#endif // !_ANIMATOR_H_
