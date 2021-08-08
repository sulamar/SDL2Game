#pragma once
#include "RenderWindow.h"
#include "Camera.h"

class GameObject
{
public:
	GameObject(SDL_Texture* tex, Vector2 _size, Vector2f _pos);
	GameObject();
	void Render(SDL_Renderer* renderer, Camera& cam);

	SDL_Texture* GetTexture();
	int GetW() const;
	int GetH() const;
	float GetX() const;
	float GetY() const;

	void SetX(float _x);
	void SetY(float _y);

protected:
	SDL_Texture* texture;
	
	Vector2 size;
	Vector2f pos;

};

