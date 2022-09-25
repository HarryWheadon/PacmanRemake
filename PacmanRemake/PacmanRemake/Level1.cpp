#include "Level1.h"



void Level1::SetLevelMap()
{
<<<<<<< Updated upstream
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									   { 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
									   { 1,0,1,1,0,1,0,1,0,1,0,1,1,0,1},
									   { 1,0,1,1,0,0,0,0,0,0,0,1,1,0,1},
									   { 1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
									   { 1,0,1,1,0,0,0,1,0,0,0,1,1,0,1},
									   { 1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
									   { 1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
									   { 1,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
									   { 1,1,1,1,0,1,1,1,1,1,0,1,1,1,1},
									   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									   { 1,0,1,1,0,1,1,1,1,1,0,1,1,0,1},
		                               { 1,0,1,0,0,0,1,1,1,0,0,0,1,0,1},
		                               { 1,0,0,0,1,0,0,1,0,0,1,0,0,0,1},
		                               { 1,0,1,1,1,1,0,1,0,1,1,1,1,0,1},
		                               { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
=======
	int map[MAP_HEIGHT][MAP_WIDTH] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									   {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
									   {1,0,1,1,0,1,0,1,0,1,0,1,1,0,1},
									   {1,0,1,1,0,0,0,0,0,0,0,1,1,0,1},
									   {1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
									   {1,0,1,1,0,0,0,1,0,0,0,1,1,0,1},
									   {1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
									   {1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
									   {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
									   {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1},
									   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									   {1,0,1,1,0,1,1,1,1,1,0,1,1,0,1},
		                               {1,0,1,0,0,0,1,1,1,0,0,0,1,0,1},
		                               {1,0,0,0,1,0,0,1,0,0,1,0,0,0,1},
		                               {1,0,1,1,1,1,0,1,0,1,1,1,1,0,1},
		                               {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
									   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
>>>>>>> Stashed changes

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
	SetLevelMap();

	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
<<<<<<< Updated upstream
			if (m_level_map->GetTileAt((x * TILE_WIDTH), (y * TILE_HEIGHT) == 0))
=======
			if (!m_level_map->GetTileAt((y), (x)) || m_level_map->GetTileAt((y), (x)) == 2)
>>>>>>> Stashed changes
			{
				CreateCoin(Vector2D((x * TILE_WIDTH), (y * TILE_HEIGHT)));
			}
		}
	}

	m_background_yPos = 0.0f;

<<<<<<< Updated upstream
	Pacman_Character = new CharacterPacman(m_renderer, "Images/PacmanAnimation2.png", Vector2D(64, 330), m_level_map);
	//load texture
=======
	//load textures
	Pacman_Character = new CharacterPacman(m_renderer, "Images/PacmanAnimation2.png", Vector2D(64, 480), m_level_map);

	Ghost_Character = new CharacterGhost(m_renderer, "Images/Ghost.png",m_level_map, Vector2D(64, 320), FACING_RIGHT, MOVEMENTSPEED);
>>>>>>> Stashed changes

	m_background_texture = new Texture(m_renderer);

	if (!m_background_texture->LoadTexFromFile("Images/PacmanBackground.png"))
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

	for (int i = 0; i < m_coins.size(); i++)
	{
		m_coins[i]->Render();
	}
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	Pacman_Character->PacmanUpdate(deltaTime, e);
	Pacman_Character->HitWall(true);
<<<<<<< Updated upstream
	UpdateCoins(deltaTime, e);
=======
	Ghost_Character->Update(deltaTime, e);
	UpdatePellet(deltaTime, e);
	if (!m_pellets.size())
	{
		/*screen_manager->ChangeScreen(SCREEN_LEVEL2);*/
    }

>>>>>>> Stashed changes
}

Level1::~Level1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
}

void Level1::CreateCoin(Vector2D position)
{
	Coin_Character = new CharacterCoin(m_renderer, "Images/Coin.png", position, m_level_map);
	m_coins.push_back(Coin_Character);
}

void Level1::UpdateCoins(float deltaTime, SDL_Event e)
{
	if (!m_coins.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_coins.size(); i++)
		{
			//check to see if player collides with a coin
			if (Collisions::Instance()->Circle(m_coins[i], Pacman_Character))
				m_coins[i]->SetAlive(false);

			if (!m_coins[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
			if (enemyIndexToDelete != -1)
			{
				m_coins.erase(m_coins.begin() + enemyIndexToDelete);
			}
		}
	}
}
