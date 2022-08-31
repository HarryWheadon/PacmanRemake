#include "Texture.h"
using namespace std;

Texture::Texture(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

void Texture::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//set where to render the texture
	SDL_Rect renderLocation = { new_position.x, new_position.y,m_width, m_height };

	//Render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, 0, nullptr, flip);
}

void Texture::Render(SDL_Rect src_rect, SDL_Rect src_dest, SDL_RendererFlip flip, double angle)
{
	SDL_RenderCopyEx(m_renderer, m_texture, &src_rect, &src_dest, angle, nullptr, flip);
}

void Texture::RemoveTexture()
{
	//check is texture exists before removing it
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;

		m_width = 0;
		m_height = 0;
	}
}


Texture::~Texture()
{
	RemoveTexture();

	m_renderer = nullptr;
}


bool Texture::LoadTexFromFile(std::string path)
{
//Free up some memory
    RemoveTexture();


	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());

	if (p_surface != nullptr)
	{
		//colour key the image to be transparent
		SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0XFF, 0XFF));

		//create the texture from pixels on the surface
		m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);

		if (m_texture == nullptr)
		{
			cout << "unable to create texture from surface. Error: " << SDL_GetError();
		}
		else
		{
			m_width = p_surface->w;
			m_height = p_surface->h;
		}
		//remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "unable to create texture from surface. Error: " << IMG_GetError();
	}

	//Return whether the process was successful
	return m_texture != nullptr;
}

