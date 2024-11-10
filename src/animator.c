#include "animator.h"
#include <stdlib.h>

Animator_Data InitAnimator(const char* fileName)
{
    Animator_Data animator = { 0 };

    // Load animations from the file
    animator.animation = LoadModelAnimations(fileName, &animator.animCount);
    animator.currentAnim = 0;
    animator.currentFrame = 0;

    return animator;
}

void UpdateAnimator(Animator_Data* animator, Model* model)
{
    if (animator->animCount > 0)
    {
        UpdateModelAnimation(*model, animator->animation[animator->currentAnim], animator->currentFrame);
        animator->currentFrame++;

        // Loop the animation if it reaches the end
        if (animator->currentFrame >= animator->animation[animator->currentAnim].frameCount)
        {
            animator->currentFrame = 0;
        }
    }
}

void UnloadAnimator(Animator_Data* animator)
{
    if (animator->animation != NULL)
    {
        for (unsigned int i = 0; i < animator->animCount; i++)
        {
            UnloadModelAnimation(animator->animation[i]);
        }
        RL_FREE(animator->animation);
        animator->animation = NULL;
        animator->animCount = 0;
    }
}
