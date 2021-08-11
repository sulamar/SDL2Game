#include "SoundManager.h"
#include <iostream>
Mix_Music* SoundManager::music = nullptr;
Mix_Chunk* SoundManager::sound = nullptr;

bool SoundManager::Init()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Could not init SDL_mixer: Error: " << Mix_GetError() << std::endl;
		return false;
	}
}

void SoundManager::PlayMusic(const char* path)
{
	music = Mix_LoadMUS(path);
	if (music == nullptr)
	{
		std::cout << "Music could not be loaded: Error: " << Mix_GetError() << std::endl;
	}
	else
		Mix_PlayMusic(music, -1);
}

void SoundManager::PlaySound(const char* path, int volume)
{
	sound = Mix_LoadWAV(path);
	Mix_VolumeChunk(sound, volume);
	if (sound == nullptr)
	{
		std::cout << "Sound could not be loaded: Error: " << Mix_GetError() << std::endl;
	}
	else
		Mix_PlayChannel(-1, sound, 0);
}

void SoundManager::CleanUp()
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(sound);
}

