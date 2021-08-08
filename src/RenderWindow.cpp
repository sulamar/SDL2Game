#include "RenderWindow.h"
bool RenderWindow::run = false;

RenderWindow::RenderWindow(const char* _title, int _width, int _height)
	: title(_title), width(_width), height(_height), window(nullptr), renderer(nullptr)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) > 0)		
	{ 
		std::cout << "SDL could not init everything: " << SDL_Error << std::endl;
		return;
	}
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "SDL could not init everything: " << SDL_Error << std::endl;
		return;
	}

}

RenderWindow::RenderWindow()
{
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::Init()
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, NULL);
	if (window == nullptr)
		std::cout << "Window could not be created: " << SDL_Error << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
		std::cout << "Renderer could not be created: " << SDL_Error << std::endl;

	run = true;
}

bool RenderWindow::GetRunning()
{
	return run;
}

void RenderWindow::SetRunning(bool r)
{
	run = r;
}


SDL_Texture* RenderWindow::LoadTexture(const char* _filepath)
{
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(renderer, _filepath);
	if (tex != nullptr)
		return tex;
	else
		std::cout << "Texture could not be loaded: " << IMG_GetError() << std::endl;
}

SDL_Renderer* RenderWindow::GetRenderer() const
{
	return renderer;
}

void RenderWindow::Clear()
{
	SDL_SetRenderDrawColor(renderer, 55, 0, 255, 255);
	SDL_RenderClear(renderer);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}

