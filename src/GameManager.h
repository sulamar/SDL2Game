#pragma once
#include "Player.h"
#include "Ground.h"
#include "SoundManager.h"
class GameManager
{
public:
	GameManager(const char* _title, int _width, int _height);
	void Init();
	void Run();

	static const int LEVEL_WIDTH = 3200;
	static const int LEVEL_HEIGHT = 800;
private:
	RenderWindow window;
	SoundManager soundManager;

	SDL_Texture* playerTex;
	SDL_Texture* groundTex;

	Player player;
	std::vector<Ground> grounds;

	const char* title;
	int width;
	int height;

	Camera cam = { Vector2(0, 0), Vector2(width, height) };
};

