#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(SDL_Texture* tex, int _health, Vector2 _size, Vector2f _pos, Camera& _cam);
	Player();

	void Render(SDL_Renderer* renderer);

	int GetHealth() const;

	void CheckInput(SDL_Event& e);
	void UpdateCamera(Camera& _cam);

	static const int vel = 5;

private:
	int health;
	Camera cam;
};

