#pragma once
#include <SDL.h>
#include "SDL_ttf.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "GameScreen.h"
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
private:
	SDL_Renderer* m_renderer;
	GameScreen* m_current_screen;
};

