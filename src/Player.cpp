#include "Player.h"
#include "SoundManager.h"
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

Player::~Player()
{

}

int Player::GetHealth() const
{
	return health;
}

void Player::Render()
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = size.x;
	src.h = size.y;
	SDL_Rect dst;
	dst.x = pos.x;
	dst.y = pos.y;
	dst.w = size.x;
	dst.h = size.y;

	SDL_RenderCopy(RenderWindow::renderer, GetTexture(), &src, &dst);
}

void Player::CheckInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			cam.pos.y -= velocity.y;
			SoundManager::PlaySound("assets/sounds/sound.wav", 10);
			break;
		case SDLK_DOWN:
			cam.pos.y += velocity.y;
			SoundManager::PlaySound("assets/sounds/sound.wav", 10);
			break;
		case SDLK_LEFT:
			cam.pos.x -= velocity.x;
			SoundManager::PlaySound("assets/sounds/sound.wav", 10);
			break;
		case SDLK_RIGHT:
			cam.pos.x += velocity.x;
			SoundManager::PlaySound("assets/sounds/sound.wav", 10);
			break;
		}
	}
}

void Player::UpdateCamera(Camera& _cam)
{
	collider.x = pos.x;
	collider.y = pos.y;
	collider.w = size.x;
	collider.h = size.y;

	_cam = cam;
}





