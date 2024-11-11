#pragma once

#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include "raylib.h"

typedef enum 
{
    PLAYER_IDLE = 0,
    PLAYER_WALK = 1,
    //PLAYER_ATTACK,
    //PLAYER_DEATH
} Animation_ID;

typedef struct Animator_Animation
{
	ModelAnimation animation;
	int id;
} Animator_Animation;

typedef struct Animator_Data
{
	Animator_Animation *animations;
	unsigned int animationsCount;
	Animator_Animation currentAnimation;
	int animationFrame;
	float nextFrame;
} Animator_Data;

#endif // !_ANIMATOR_H_
