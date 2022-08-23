#include "ScreenManager.h"

ScreenManager::ScreenManager(SDL_Renderer* renderer, SCREENS Screen)
{
	m_renderer = renderer;
	ChangeScreen(Screen);
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::Render()
{
}

void ScreenManager::Update(float deltaTime, SDL_Event e)
{
}

void ScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old Screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
}
