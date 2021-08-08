#include "App.h"

void App::Run()
{
	GameManager manager("Game", SCREEN_WIDTH, SCREEN_HEIGHT);
	manager.Init();
	manager.Run();
}