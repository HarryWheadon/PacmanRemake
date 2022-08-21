#pragma once
#include <SDL.h>
#include "Commons.h"
class ScreenManager
{
public:
	ScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~ScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS new_screen);
	int GetScreen() { return screen; }
private:
	SDL_Renderer* m_renderer;
	SCREEN* screen;
};

