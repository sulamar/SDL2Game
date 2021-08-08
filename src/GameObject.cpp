#include "GameObject.h"
#include "GameManager.h"
#include "Player.h"
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

void GameObject::Render(SDL_Renderer* renderer, Camera& cam)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = GetH();
	src.h = GetW();
	SDL_Rect dst;
	dst.x = int(GetX()) * 4 - cam.pos.x;
	dst.y = int(GetY()) * 4 - cam.pos.y;
	dst.w = int(GetW()) * 4;
	dst.h = int(GetH()) * 4;

	SDL_RenderCopy(renderer, GetTexture(), &src, &dst);
}

int GameObject::GetW() const
{
	return size.x;
}

int GameObject::GetH() const
{
	return size.y;
}

float GameObject::GetX() const
{
	return pos.x;
}
float GameObject::GetY() const
{
	return pos.y;
}
void GameObject::SetX(float _x)
{
	pos.x = _x;
}
void GameObject::SetY(float _y)
{
	pos.y = _y;
}





	



