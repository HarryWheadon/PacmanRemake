#include "TextLoad.h"

TextLoad::TextLoad(SDL_Renderer* renderer)
{
	m_renderer;
}

TextLoad::~TextLoad()
{
	RemoveText();
	m_renderer = nullptr;
}
bool TextLoad::LoadText(const char* text, const char* font_type, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont(font_type, 25);

	SDL_Color color = color;
	SDL_Surface* surface = TTF_RenderText_Solid(font,
		text, color);

   m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
}

void TextLoad::RemoveText()
{
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}