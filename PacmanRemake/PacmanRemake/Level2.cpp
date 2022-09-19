#include "Level2.h"


Level2::Level2(SDL_Renderer* renderer) : GameScreen(renderer)
{
}

Level2::~Level2()
{
}

void Level2::Render()
{
}

void Level2::Update(float deltaTime, SDL_Event e)
{
}

bool Level2::SetUpLevel()
{
	//m_background_texture = new Texture(m_renderer);

	//if (!m_background_texture->LoadTexFromFile("Images/PacmanBackground1.png"))
	//{
	//	std::cout << " Failed to load background texture!" << std::endl;
	//	return false;
	//}
	return true;
}
