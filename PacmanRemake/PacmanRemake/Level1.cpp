#include "Level1.h"



void Level1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
									   { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}

	//set the new one
	m_level_map = new LevelMap(map);
}

bool Level1::SetUpLevel()
{
	/*SetLevelMap();*/

	m_background_yPos = 0.0f;

	Pacman_Character = new CharacterPacman(m_renderer, "Images/PacmanAnimation.png", Vector2D(64, 330), m_level_map);
	//load texture

	m_background_texture = new Texture(m_renderer);

	if (!m_background_texture->LoadTexFromFile("Images/PacmanBackgroundNew.png"))
	{
		std::cout << " Failed to load background texture!" << std::endl;
		return false;
	}
	return true;
}

Level1::Level1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();
	m_level_map = nullptr;
}

void Level1::Render()
{

	//draw the background
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE, 0.0);
	Pacman_Character->Render();
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	Pacman_Character->PacmanUpdate(deltaTime, e);
}

Level1::~Level1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
}
