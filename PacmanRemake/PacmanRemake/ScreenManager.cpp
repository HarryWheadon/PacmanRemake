#include "ScreenManager.h"

ScreenManager::ScreenManager(SDL_Renderer* renderer, SCREENS Screen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreen(Screen);
}

ScreenManager::~ScreenManager()
{
	m_renderer = nullptr;

	delete m_current_screen;
	m_current_screen = nullptr;
}

void ScreenManager::Render()
{
	m_current_screen->Render();
}

void ScreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);

	if(m_current_screen->GetScreen() != SCREEN_NULL)
	{ 
	ChangeScreen(m_current_screen->GetScreen());
    }
}

void ScreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old Screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}

	if (new_screen == SCREEN_MENU)
	{
		MainMenu* tempScreen;
		tempScreen = new MainMenu(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
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
		Level2* tempScreen;
		tempScreen = new Level2(m_renderer);
		m_current_screen = (GameScreen*)tempScreen;
		tempScreen = nullptr;
	}
	else if (new_screen == SCREEN_LEVEL3)
	{

	}
}

