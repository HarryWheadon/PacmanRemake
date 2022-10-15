#include "SoundEffect.h"

SoundEffect::SoundEffect(string path)
{
LoadMusic(path);
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::Play()
{
		Mix_PlayMusic(m_music, 1);
}

void SoundEffect::LoadMusic(string path)
{
	m_music = Mix_LoadMUS(path.c_str());
	if (m_music == nullptr)
	{
		cout << "Failed to load music. Error: " << Mix_GetError() << endl;
	}
}