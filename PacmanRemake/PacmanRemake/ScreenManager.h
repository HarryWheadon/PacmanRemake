#pragma once
#include <SDL.h>
#include "Commons.h"
#include "constants.h"
class ScreenManager
{
public:
	ScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~ScreenManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS new_screen);
	int GetScreen() { return m_current_screen; }
private:
	SDL_Renderer* m_renderer;
	SCREENS m_current_screen;
};

