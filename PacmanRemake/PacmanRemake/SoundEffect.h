#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;

class SoundEffect
{
public:
	SoundEffect(string path);
	~SoundEffect();
	void Play();
	void LoadMusic(string path);
private:

	Mix_Music* m_music;
};

