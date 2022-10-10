#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "commons.h"
using namespace std;

class TextLoad
{
public:
	TextLoad(SDL_Renderer* renderer);
	~TextLoad();

	bool LoadText(const char* text, const char* font_type, SDL_Color color);
	void RemoveText();
private:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
};
