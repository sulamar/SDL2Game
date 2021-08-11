#include "GameObject.h"
GameObject::GameObject(SDL_Texture* tex, Vector2 _size, Vector2f _pos)
{
	texture = tex;
	size.x = _size.x;
	size.y = _size.y;
	pos.x = _pos.x;
	pos.y = _pos.y;
}

GameObject::GameObject()
{
}

SDL_Texture* GameObject::GetTexture()
{
	return texture;
}

void GameObject::Update()
{
	collider.x = pos.x;
	collider.y = pos.y;
	collider.w = size.x;
	collider.h = size.y;
}

void GameObject::Render(Camera& cam)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = size.x;
	src.h = size.y;
	SDL_Rect dst;
	dst.x = pos.x - cam.pos.x;
	dst.y = pos.y - cam.pos.y;
	dst.w = size.x;
	dst.h = size.y;

	SDL_RenderCopy(RenderWindow::renderer, GetTexture(), &src, &dst);
}






	



