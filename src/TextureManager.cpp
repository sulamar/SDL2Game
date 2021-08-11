#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* _filepath)
{
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(RenderWindow::renderer, _filepath);
	if (tex != nullptr)
		return tex;
	else
	{
		std::cout << "Texture could not be loaded: " << IMG_GetError() << std::endl;
		return nullptr;
	}
}