#include "debug.h"
#include "animator.h"
#include "player.h"

Debug_Text debugText;
Font myFont;

void InitDebugFont(void)
{
    myFont = LoadFont("resources/JetBrainsMonoNLNerdFont-Regular.ttf");
}

void UnloadDebugFont(void)
{
    UnloadFont(myFont);
}

void DrawDebugText(Font font, const char *text, Vector2 *textpos)
{
    DrawTextEx(font, text, *textpos, 18.0f, 1.0f, WHITE);
}

void DebugInfo(void)
{
    Vector2 debugTargetPos = { 10, 10 };
    Vector2 debugPlayerPos = { 10, 30 };
    Vector2 debugPlayerRot = { 10, 50 };
    Vector2 debugAnimID = { 350, 10 };
    DrawDebugText(myFont, TextFormat("Target Pos : [%.2f, %.2f]", targetPos.x, targetPos.z), &debugTargetPos);
    DrawDebugText(myFont, TextFormat("Player Pos : [%.2f, %.2f]", player.transform.position.x, player.transform.position.z), &debugPlayerPos);
    DrawDebugText(myFont, TextFormat("Player Rot Y-Axis : [%.2f]", player.transform.rotation.y), &debugPlayerRot);
    DrawDebugText(myFont, TextFormat("Animation Index : [%d]", player.animator.animIndex), &debugAnimID);
}
