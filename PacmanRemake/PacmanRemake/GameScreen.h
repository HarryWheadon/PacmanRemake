#pragma once
#include <SDL.h>
#include "commons.h"

class GameScreen
{
public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreen() { return m_newScreen; };
protected:
	SDL_Renderer* m_renderer;
	SCREENS m_newScreen;
};

