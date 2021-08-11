#pragma once
#include "SDL_mixer.h"
class SoundManager
{
public:
	static bool Init();
	static void PlayMusic(const char* path);
	static void PlaySound(const char* path, int volume);
	static void CleanUp();
private:
	static Mix_Music* music;
	static Mix_Chunk* sound;
};


