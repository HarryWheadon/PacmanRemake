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

	void TextRender(int x, int y);
	bool LoadFont(const char* text,int font_size, string path, SDL_Color color);

private:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	mutable SDL_Rect text_rect;
	TTF_Font* font;
};
