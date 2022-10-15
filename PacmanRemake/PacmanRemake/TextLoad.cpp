#include "TextLoad.h"

TextLoad::TextLoad(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
bool TextLoad::LoadText(const char* text, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont("Joystix.tff", 25);
	SDL_Color colour = color;

	SDL_Surface* surface = TTF_RenderText_Solid(font, text, colour);

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	return true;
}

void TextLoad::Render(SDL_Rect dstrect)
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, &dstrect);
	SDL_RenderPresent(m_renderer);
}

void TextLoad::RemoveText()
{
	SDL_DestroyTexture(m_texture);
}

TextLoad::~TextLoad()
{
	RemoveText();
	m_renderer = nullptr;
}