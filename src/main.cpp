#include "GameManager.h"
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

int main(int argc, char* args[])
{
	GameManager game("Game", SCREEN_WIDTH, SCREEN_HEIGHT);
	game.Init();
	game.Run();

	return 0;
}