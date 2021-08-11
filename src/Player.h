#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(SDL_Texture* tex, int _health, Vector2 _size, Vector2f _pos, Camera& _cam);
	Player();
	~Player();
	void Render();

	int GetHealth() const;

	void CheckInput(SDL_Event& e);

	Vector2 velocity = { 4,5 };

	void UpdateCamera(Camera& _cam);
private:
	Camera cam;
	int health;
};

