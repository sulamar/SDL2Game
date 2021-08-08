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

	static bool GetRunning();
	static void SetRunning(bool r);

	SDL_Renderer* GetRenderer() const;
	SDL_Texture* LoadTexture(const char* _filepath);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	static bool run;

	const char* title;
	int width;
	int height;
};

