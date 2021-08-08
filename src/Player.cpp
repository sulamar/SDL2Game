#include "Player.h"

Player::Player(SDL_Texture* tex, int _health, Vector2 _size, Vector2f _pos, Camera& _cam)
{
	texture = tex;
	health = _health;
	size.x = _size.x;
	size.y = _size.y;
	pos.x = _pos.x;
	pos.y = _pos.y;
	cam = _cam;
}

Player::Player()
{
}

int Player::GetHealth() const
{
	return health;
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = GetH();
	src.h = GetW();
	SDL_Rect dst;
	dst.x = int(GetX()) * 4;
	dst.y = int(GetY()) * 4;
	dst.w = int(GetW()) * 4;
	dst.h = int(GetH()) * 4;

	SDL_RenderCopy(renderer, GetTexture(), &src, &dst);
}

void Player::CheckInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			cam.pos.y -= Player::vel;
			break;
		case SDLK_DOWN:
			cam.pos.y += Player::vel;
			break;
		case SDLK_LEFT:
			cam.pos.x -= Player::vel;
			break;
		case SDLK_RIGHT:
			cam.pos.x += Player::vel;
			break;
		}
	}
}

void Player::UpdateCamera(Camera& _cam)
{
	_cam = cam;
}



