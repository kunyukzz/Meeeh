#pragma once

#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "raylib.h"

typedef enum 
{
    ANIM_IDLE = 0,
    ANIM_WALK = 1,
} Animation_ID;

typedef struct Animator_Data
{
    ModelAnimation* animation;
    unsigned int animCount;
    int currentAnim;
    int currentFrame;
    float currentTime;
    float frameSpeed;
} Animator_Data;

Animator_Data InitAnimator(const char* fileName);
void SetAnimation(Animator_Data* animator, Animation_ID animType);
void UpdateAnimator(Animator_Data* animator, Model* model);
void UnloadAnimator(Animator_Data* animator);

#endif // !_ANIMATOR_H_
