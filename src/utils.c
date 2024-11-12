#include "utils.h"

Vector2 Utils_GetScreenCenter(void)
{
	const Vector2 center = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	return center;
}

BoundingBox Utils_MakeBoundingBox(const Vector3 position, const Vector3 size)
{
	BoundingBox bb = (BoundingBox){
		(Vector3){ position.x - size.x / 2, position.y, position.z - size.z / 2 },
		(Vector3){ position.x + size.x / 2, position.y + size.y / 2, position.z + size.z / 2 }
	};
	return bb;
}

