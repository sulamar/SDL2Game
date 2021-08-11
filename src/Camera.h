#pragma once
#include "Math.h"
struct Camera
{
	Camera(Vector2 _pos, Vector2 _size);
	Camera();

	Vector2 pos;
	Vector2 size;
};
