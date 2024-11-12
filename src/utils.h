#pragma once

#ifndef _UTILS_H_
#define _UTILS_H_

#include "raylib.h"

Vector2 Utils_GetScreenCenter(void);
BoundingBox Utils_MakeBoundingBox(Vector3 position, Vector3 size);

#endif // !_UTILS_H_
