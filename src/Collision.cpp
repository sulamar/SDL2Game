#include "Collision.h"

bool Collision::CheckCollision(GameObject& a, GameObject& b)
{
	if(a.collider.x + a.collider.w >= b.collider.x &&
		a.collider.x <= b.collider.x + b.collider.w &&
		a.collider.y + a.collider.h >= b.collider.y &&
		a.collider.y <= b.collider.y + b.collider.h
		)
	{
		return true;
	}
	return false;
}
