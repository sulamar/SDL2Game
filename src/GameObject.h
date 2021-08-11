#pragma once
#include "RenderWindow.h"
#include "Math.h"
#include "Camera.h"
class GameObject
{
public:
	GameObject(SDL_Texture* tex, Vector2 _size, Vector2f _pos);
	GameObject();
	void Render(Camera& cam);

	SDL_Texture* GetTexture();

	Vector2 size;
	Vector2f pos;
	
	SDL_Rect collider;

	virtual void Update();
protected:
	SDL_Texture* texture;
};

