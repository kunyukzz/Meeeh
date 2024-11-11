#include "animator.h"
#include <stdio.h>

Animator_Data InitAnimator(const char* fileName)
{
    Animator_Data animator = { 0 };

    animator.animCount = 0;
    animator.animIndex = PLAYER_IDLE2;
    animator.animCurrentFrame = 0;
    animator.modelAnim = LoadModelAnimations(fileName, &animator.animCount);

    printf("Loaded %d animations\n", animator.animCount);
    return animator;
}

void SetAnimation(Animator_Data* animator, Animation_ID animID)
{
    // Change animation only if it's different from the current one
    if (animator->animIndex != animID)
    {
        animator->animIndex = animID;
        animator->animCurrentFrame = 0;  // Reset frame for new animation
        printf("Switching to animation: %d\n", animID);
    }
}

void UpdateAnimator(Animator_Data* animator, Model* model, bool isMoving)
{
    if (isMoving)
    {
        SetAnimation(animator, PLAYER_WALK); // Assuming ANIM_WALK is defined as an enum value
    }
    else
    {
        SetAnimation(animator, PLAYER_IDLE2); // Assuming ANIM_IDLE is another enum value
    }

    ModelAnimation animate = animator->modelAnim[animator->animIndex];
    animator->animCurrentFrame = (animator->animCurrentFrame + 1)%animate.frameCount;
    UpdateModelAnimation(*model, animate, animator->animCurrentFrame);
}
