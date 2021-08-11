#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_timer.h>
#include <vector>
class RenderWindow
{
public:
	RenderWindow(const char* _title, int _width, int _height);
	RenderWindow();
	void CleanUp();
	void Init();
	void Clear();
	void Display();

	bool running;

	static SDL_Renderer* renderer;
private:
	SDL_Window* window;

	const char* title;
	int width;
	int height;
};

