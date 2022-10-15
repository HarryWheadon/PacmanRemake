#include "Level1.h"



void Level1::SetLevelMap()
{
	//create the map using a 2d array
	int map[MAP_HEIGHT][MAP_WIDTH] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		                               {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
									   {1,2,0,0,2,0,2,1,2,0,2,0,0,2,1},
									   {1,0,1,1,0,1,0,1,0,1,0,1,1,0,1},
									   {1,0,1,1,2,0,2,3,2,0,2,1,1,0,1},
									   {1,2,0,0,2,1,1,1,1,1,2,0,0,2,1},
									   {1,0,1,1,2,0,2,1,2,0,2,1,1,0,1},
									   {1,2,0,0,2,1,0,1,0,1,2,0,0,2,1},
									   {1,1,1,1,2,0,2,3,2,0,2,1,1,1,1},
									   {0,0,0,0,3,1,1,1,1,1,3,0,0,0,0},
									   {1,1,1,1,3,1,1,1,1,1,3,1,1,1,1},
									   {1,2,0,0,2,0,2,3,2,0,2,0,0,2,1},
									   {1,0,1,1,0,1,1,1,1,1,0,1,1,0,1},
		                               {1,0,1,2,2,2,1,1,1,2,2,2,1,0,1},
		                               {1,2,0,2,1,2,2,1,2,2,1,2,0,2,1},
		                               {1,0,1,1,1,1,0,1,0,1,1,1,1,0,1},
		                               {1,2,0,0,0,0,2,3,2,0,0,0,0,2,1},
									   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}
	//set the new map
	m_level_map = new LevelMap(map);
}

bool Level1::SetUpLevel()
{
	SetLevelMap();

	//load textures
	Pacman_Entity = new EntityPacman(m_renderer, "Images/PacmanAnimation2.png", Vector2D(288, 224), m_level_map);
	m_background_sound = new SoundEffect("Audio/Intro.mp3");
	m_pop = new SoundEffect("Audio/pop.wav");

	//Create individual ghosts using different starting positions
	CreateGhost("Images/GhostAnimation1.png", Vector2D(32, 512));
	CreateGhost("Images/GhostAnimation2.png", Vector2D(416, 512));
	CreateGhost("Images/GhostAnimation3.png", Vector2D(32, 64));
	CreateGhost("Images/GhostAnimation4.png", Vector2D(416, 64));

    //loops through map
	//any tile thaat isnt a wall loads in pellet
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (!m_level_map->GetTileAt((y), (x)) || m_level_map->GetTileAt((y), (x)) == 2 || m_level_map->GetTileAt((y), (x)) == 3)
			{
				CreatePellet(Vector2D((x * TILE_WIDTH), (y * TILE_HEIGHT)));
			}
		}
	}
    
	m_background_yPos = 0.0f;
	m_background_texture = new Texture(m_renderer);


	//loads in background texture
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
	Pacman_Entity->Render();
	for (int i = 0; i < m_pellets.size(); i++)
	{
		m_pellets[i]->Render();
	}

	for (int i = 0; i < m_ghost.size(); i++)
	{
		m_ghost[i]->Render();
	}
}

void Level1::Update(float deltaTime, SDL_Event e)
{
	if (!m_ghost.empty())
	{
		for (unsigned int i = 0; i < m_ghost.size(); i++)
		{
			m_ghost[i]->Update(deltaTime, e);
			m_ghost[i]->HitWall(true);
		}
	}
	Pacman_Entity->PacmanUpdate(deltaTime, e);
	Pacman_Entity->HitWall(true);
	UpdatePellet(deltaTime, e);
	UpdateGhost(deltaTime, e);

	if (!m_pellets.size())
	{
	}
}

Level1::~Level1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
}

void Level1::CreatePellet(Vector2D position)
{
	Pellet_Entity = new EntityPellet(m_renderer, "Images/Coin.png", position, m_level_map);
	m_pellets.push_back(Pellet_Entity);
}

void Level1::CreateGhost(string file, Vector2D position)
{
	Ghost_Entity = new EntityGhost(m_renderer, file, m_level_map, position, FACING_RIGHT, MOVEMENTSPEED);
	m_ghost.push_back(Ghost_Entity);
}

void Level1::UpdatePellet(float deltaTime, SDL_Event e)
{
	if (!m_pellets.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_pellets.size(); i++)
		{
			//check to see if player collides with a pellet
			if (Collisions::Instance()->Circle(m_pellets[i], Pacman_Entity))
			{ 
			    //the pellet is deleted and a sound effect is played
				m_pellets[i]->SetAlive(false);
				m_pop->Play();
			}
			if (!m_pellets[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
		}
		if (enemyIndexToDelete != -1)
		{
			m_pellets.erase(m_pellets.begin() + enemyIndexToDelete);
		}
	}
}

void Level1::UpdateGhost(float deltaTime, SDL_Event e)
{
	//check to see if player collides with a Ghost
	for (unsigned int i = 0; i < m_ghost.size(); i++)
	{
		if (Collisions::Instance()->Circle(m_ghost[i], Pacman_Entity))
		{
            //pacman dies and the game ends
			cout << "dead" << endl;
		}
	}
}
