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
	if (new_screen == SCREEN_MENU)
	{

	}
	else if (new_screen == SCREEN_LEVEL1)
	{
	     Level1* tempScreen;
		tempScreen = new Level1(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
	}
	else if (new_screen == SCREEN_LEVEL2)
	{

	}
	else if (new_screen == SCREEN_LEVEL3)
	{

	}
	//clear up the old Screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
}
