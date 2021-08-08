#pragma once
#include "GameObject.h"

class Ground : public GameObject
{
public:
	Ground(SDL_Texture* tex, Vector2 _size, Vector2f _pos);
	Ground();	
};

