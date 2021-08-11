#include "GameManager.h"
#include "TextureManager.h"
#include "Collision.h"
GameManager::GameManager(const char* _title, int _width, int _height)
	: title(_title), width(_width), height(_height), playerTex(nullptr), groundTex(nullptr)
{
}

void GameManager::Init()
{
	window = RenderWindow(title, width, height);
	window.Init();

	soundManager.Init();

	playerTex = TextureManager::LoadTexture("assets/square.png");
	groundTex = TextureManager::LoadTexture("assets/ground.png");

	player = Player(playerTex, 100, Vector2(128, 128), Vector2f(100.0f, 372.0f), cam);

	int groundCount = 20;

	for (float i = 0; i < groundCount; i++)
	{
		grounds.push_back(Ground(groundTex, Vector2(128, 128), Vector2f(128.0f * i, 500.0f)));
	}

	soundManager.PlayMusic("assets/music/music.wav");
}

void GameManager::Run()
{
	SDL_Event e;
	while (window.running)
	{
		while (SDL_PollEvent(&e))
		{
			player.CheckInput(e);
			switch (e.type)
			{
			case SDL_QUIT:
				window.running = false;
				soundManager.CleanUp();
				window.CleanUp();
				SDL_Quit();
				Mix_Quit();
			}
		}

		window.Clear();
		Update();
		for (auto g : grounds)
		{
			g.Render(cam);
		}

		player.Render();
		window.Display();
	}
	window.CleanUp();
}

void GameManager::Update()
{
	player.Update();
	player.UpdateCamera(cam);
	for (auto g : grounds)
	{
		g.Update();
		if (collision.CheckCollision(player, g))
		{
			std::cout << "COLLISION" << std::endl;
		}
	}
}
