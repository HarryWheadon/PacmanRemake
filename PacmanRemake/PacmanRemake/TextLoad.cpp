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

bool TextLoad::LoadFont(int font_size, string text, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont("fonts/Joystix.TTF", font_size);
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (surface != nullptr)
	{
		m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		if (m_texture == nullptr)
		{
			cout << "unable to create texture from surface. Error: " << SDL_GetError();
		}
	}

	TTF_CloseFont(font);
	SDL_FreeSurface(surface);

	SDL_QueryTexture(m_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);
	return m_texture;
}
