#pragma once

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "raylib.h"
#include "player.h"

typedef struct Debug_Text
{
    char *text;
    Vector2 position;
} Debug_Text;

extern Font myFont;

void InitDebugFont(void);
void UnloadDebugFont(void);
void DrawDebugText(Font font, const char *text, Vector2 *textpos);
void DebugInfo(void);

#endif // !_DEBUG_H_
