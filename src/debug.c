#include "debug.h"

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
    DrawTextEx(font, text, *textpos, 20.0f, 1.0f, WHITE);
}
