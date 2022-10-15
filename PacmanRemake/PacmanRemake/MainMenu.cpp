#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	//loads in the background texture
	m_background_texture = new Texture(m_renderer);

	if (!m_background_texture->LoadTexFromFile("Images/PacmanMenu.png"))
	{
		std::cout << " Failed to load background texture!" << std::endl;
	}
	//m_score = new TextLoad(m_renderer);
	//if (!m_score->LoadText("0", { 255, 255, 255 }))
	//{
	//	std::cout << " Failed to load text" << std::endl;
	//}
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
	//m_score->Render({ 0,0,0,0 });
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
