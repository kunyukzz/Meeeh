#include "animator.h"

Animator_Data InitAnimator(const char* fileName)
{
    Animator_Data animator = { 0 };

    animator.animCount = 0;
    animator.animIndex = 0;
    animator.animCurrentFrame = 0;
    animator.modelAnim = LoadModelAnimations(fileName, &animator.animCount);

    return animator;
}

void SetAnimation(Animator_Data* animator, Animation_ID animID)
{
    // Change animation only if it's different from the current one
    if (animator->animIndex != animID)
    {
        animator->animIndex = animID;
        animator->animCurrentFrame = 0;  // Reset frame for new animation
    }
}

//void SetAnimation(Animator_Data* animator, Animation_ID animID);
void UpdateAnimator(Animator_Data* animator, Model* model, bool isMoving)
{
    //if(isMoving) animator->animIndex = (animator->animIndex + 1)%animator->animCount;
    //else if (!isMoving) animator->animIndex = (animator->animIndex + animator->animCount - 1)%animator->animCount;

    if (isMoving)
    {
        SetAnimation(animator, PLAYER_WALK); // Assuming ANIM_WALK is defined as an enum value
    }
    else
    {
        SetAnimation(animator, PLAYER_IDLE); // Assuming ANIM_IDLE is another enum value
    }

    ModelAnimation animate = animator->modelAnim[animator->animIndex];
    animator->animCurrentFrame = (animator->animCurrentFrame + 1)%animate.frameCount;
    UpdateModelAnimation(*model, animate, animator->animCurrentFrame);
}

//void UnloadAnimator(Animator_Data* animator);

