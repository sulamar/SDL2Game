#include "Ground.h"
Ground::Ground(SDL_Texture* tex, Vector2 _size, Vector2f _pos)
{
	texture = tex;
	size.x = _size.x;
	size.y = _size.y;
	pos.x = _pos.x;
	pos.y = _pos.y;
}

Ground::Ground()
{
}


