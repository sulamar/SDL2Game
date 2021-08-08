#pragma once

struct Vector2
{
	Vector2(int _x, int _y)
		: x(_x), y(_y) {}
	Vector2() {};
	int x, y;
};

struct Vector2f
{
	Vector2f(float _x, float _y)
			: x(_x), y(_y) {}
	Vector2f() {};
	float x, y;
};



