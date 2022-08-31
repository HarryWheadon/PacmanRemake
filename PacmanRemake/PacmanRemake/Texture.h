#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include "commons.h"
using namespace std;

class Texture
{
public:
	Texture(SDL_Renderer* renderer);
	~Texture();

	bool LoadTexFromFile(std::string path);
	void RemoveTexture();
	void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0);
	void Render(SDL_Rect src_rect, SDL_Rect src_dest, SDL_RendererFlip flip, double angle = 0.0);

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }

private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;

	int m_width;
	int m_height;
};

