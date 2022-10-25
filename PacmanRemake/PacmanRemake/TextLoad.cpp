#include "TextLoad.h"

TextLoad::TextLoad(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
TextLoad::~TextLoad()
{
	m_renderer = nullptr;
}

void TextLoad::TextRender(int x, int y)
{
	text_rect.x = x;
	text_rect.y = y;

	SDL_RenderCopy(m_renderer, m_texture, nullptr, &text_rect);
}

bool TextLoad::LoadFont(const char* text, int font_size, string path, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont(path.c_str(), font_size);
	SDL_Surface* surface = TTF_RenderText_Solid(font, text,color);

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	TTF_CloseFont(font);
	SDL_FreeSurface(surface);

	SDL_QueryTexture(m_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);
	return m_texture;
}
