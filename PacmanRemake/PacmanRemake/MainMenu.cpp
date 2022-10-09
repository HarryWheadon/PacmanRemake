#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	m_background_texture = new Texture(m_renderer);

	if (!m_background_texture->LoadTexFromFile("Images/PacmanMenu.png"))
	{
		std::cout << " Failed to load background texture!" << std::endl;
	}
}

MainMenu::~MainMenu()
{
}

void MainMenu::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(0, 0), SDL_FLIP_NONE, 0.0);

	if(changeScreen)
	screen_manager->Render();

}

void MainMenu::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_RETURN: {
			screen_manager = new ScreenManager(m_renderer, SCREEN_LEVEL1);
			changeScreen = true;
			break; }
		}
	}
	if (changeScreen)
		screen_manager->Update(deltaTime, e);
}
