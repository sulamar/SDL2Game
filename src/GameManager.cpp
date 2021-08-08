#include "GameManager.h"

GameManager::GameManager(const char* _title, int _width, int _height)
	: title(_title), width(_width), height(_height), playerTex(nullptr), groundTex(nullptr)
{
}

void GameManager::Init()
{
	window = RenderWindow(title, width, height);
	window.Init();

	playerTex = window.LoadTexture("assets/square.png");
	groundTex = window.LoadTexture("assets/ground.png");

	player = Player(playerTex, 100, Vector2(32, 32), Vector2f(100.0f, 100.0f), cam);

	int groundCount = 20;

	for (float i = 0; i < groundCount; i++)
	{
		if(i == 0)
			grounds.push_back(Ground(groundTex, Vector2(32,32), Vector2f(0.0f, 132.0f)));
		grounds.push_back(Ground(groundTex, Vector2(32, 32), Vector2f(32.0f * i, 132.0f)));
	}

}

void GameManager::Run()
{
	SDL_Event e;
	while (window.GetRunning())
	{
		while (SDL_PollEvent(&e))
		{
			player.CheckInput(e);
			switch (e.type)
			{
			case SDL_QUIT:
				window.SetRunning(false);
				SDL_Quit();
				window.CleanUp();
			}
		}

		window.Clear();
		for (auto g : grounds)
		{
			g.Render(window.GetRenderer(), cam);
		}
		player.UpdateCamera(cam);
		player.Render(window.GetRenderer());
		
		window.Display();
	}
	window.CleanUp();
}