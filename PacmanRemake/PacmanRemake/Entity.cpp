#include "Entity.h"

void Entity::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}

void Entity::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}

void Entity::MoveUp(float deltaTime)
{
	m_facing_direction = FACING_UP;
	m_position.y -= deltaTime * MOVEMENTSPEED;
}

void Entity::MoveDown(float deltaTime)
{
	m_facing_direction = FACING_DOWN;
	m_position.y += deltaTime * MOVEMENTSPEED;
}

Entity::Entity(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map)
{
	m_current_level_map = map;
	m_renderer = renderer;
	m_position = startPosition;

	m_alive = true;
	m_moving_left = false;
	m_moving_right = false;
	m_moving_up = false;
	m_moving_down = false;

	//Loads entity texture in from texture class
	m_texture = new Texture(m_renderer);
	if (!m_texture->LoadTexFromFile(imagePath))
	{
		std::cout << "Failed to load Character texture!" << std::endl;
	}
}

Entity::~Entity()
{
	m_renderer = nullptr;
}

void Entity::Render()
{
	//splits the width of the sprite so that it accounts for only one sprite
	m_single_sprite_w = m_texture->GetWidth() / 4;
	m_single_sprite_h = m_texture->GetHeight();

	SDL_Rect portion_of_sprite = { m_single_sprite_w * m_current_frame,0,m_single_sprite_w, m_single_sprite_h };

	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	//sprite direction and renderer is changed depending pacman direction
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else if (m_facing_direction == FACING_LEFT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}

	if (m_facing_direction == FACING_UP)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else if (m_facing_direction == FACING_DOWN)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_VERTICAL);
	}
}

void Entity::Update(float deltaTime, SDL_Event e)
{

	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
	if (m_moving_up)
	{
		MoveUp(deltaTime);
	}
	if (m_moving_down)
	{
		MoveDown(deltaTime);
	}

	//m_frame_delay -= deltaTime;

	//if (m_current_frame < 2)
	//{
	//	if (m_frame_delay <= 0.0f)
	//	{
	//		//reset frame delay count
	//		m_frame_delay = ANIMATION_DELAY;

	//		//move the frame over
	//		m_current_frame++;

	//		//loop frame around if it goes beyond the number of frames
	//		if (m_current_frame > 1)
	//		m_current_frame = 0;
	//}
	//}
	//else
	//{
	//	if (m_frame_delay <= 0.0f)
	//	{
	//		//reset frame delay count
	//		m_frame_delay = ANIMATION_DELAY;

	//		//move the frame over
	//		m_current_frame++;

	//	//loop frame around if it goes beyond the number of frames
	//		if (m_current_frame > 3)
	//			m_current_frame = 2;
	//	}
	//}


	// If entity hits edge, loop to the other side
	if (GetHitWall() == true)
	{
		if (m_position.x < -TILE_HEIGHT)
		{
			m_position.x = 500;
		}
		else if (m_position.x > 500)
		{
			m_position.x = -TILE_HEIGHT;
		}
	}

}

void Entity::UpdateCollision(float deltaTime, SDL_Event e)
{
	//loops through map 2d array to find all tiles equal to 1
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (m_current_level_map->GetTileAt(y, x) == 1)
			{
				//checks collision between the entity and tiles 
				Rect2D TempTile((x * TILE_WIDTH), (y * TILE_HEIGHT), TILE_WIDTH, TILE_HEIGHT);
				if (Collisions::Instance()->Box(GetCollisionBox(), TempTile))
				{
					switch (m_facing_direction)
					{
					case FACING_LEFT:
						m_position.x += 1;
						break;
					case FACING_RIGHT:
						m_position.x -= 1;
						break;
					case FACING_UP:
						m_position.y += 1;
						break;
					case FACING_DOWN:
						m_position.y -= 1;
						break;
					}
				}
			}

		}

	}
	//checks for tiles equal to 2 and 3
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (!m_current_level_map->GetTileAt(y, x) || m_current_level_map->GetTileAt(y, x) == 2 || m_current_level_map->GetTileAt(y, x) == 3)
			{
				//checks if entity is lined up with the centre of the tile
				//if a key has already been pressed it will turn that direction once aligned with a 2 or 3 
				if ((int)m_position.x == (x * TILE_WIDTH) && (int)m_position.y == (y * TILE_HEIGHT) || (int)m_position.x - 3 == (x * TILE_WIDTH) && (int)m_position.y == (y * TILE_HEIGHT)
					|| (int)m_position.x == (x * TILE_WIDTH) && (int)m_position.y - 3 == (y * TILE_HEIGHT) || (int)m_position.x - 3 == (x * TILE_WIDTH) && (int)m_position.y - 3 == (y * TILE_HEIGHT))
				{
					switch (m_turn_direction)
					{
					case(TURN_LEFT):
					{
						m_current_frame = 0;
						m_moving_left = true;
						m_moving_right = false;
						m_moving_up = false;
						m_moving_down = false;
						break;
					}
					case (TURN_RIGHT):
					{
						m_current_frame = 0;
						m_moving_left = false;
						m_moving_right = true;
						m_moving_up = false;
						m_moving_down = false;
						break;
					}
					case(TURN_UP):
					{
						m_current_frame = 2;
						m_moving_left = false;
						m_moving_right = false;
						m_moving_up = true;
						m_moving_down = false;
						break;
					}
					case(TURN_DOWN):
					{
						m_current_frame = 2;
						m_moving_left = false;
						m_moving_right = false;
						m_moving_up = false;
						m_moving_down = true;
						break;
					}
					}
				}
			}
		}
	}
}

void Entity::SetAlive(bool isAlive)
{
	m_alive = isAlive;
}

float Entity::GetCollisionRadius()
{
	return 10.0f;
}

Vector2D Entity::GetPosition()
{
	return m_position;
}

void Entity::HitWall(bool Hitwall)
{
	hitwall = Hitwall;
}

EntityPacman::EntityPacman(SDL_Renderer* renderer, string imagePath, Vector2D startposition, LevelMap* map) : Entity(renderer, imagePath, startposition, map)
{
}

void EntityPacman::PacmanUpdate(float deltaTime, SDL_Event e)
{
	//if a wasd key is pressed the direction bool will be set to that
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_turn_direction = TURN_LEFT;
			break;
		case SDLK_d:
			m_turn_direction = TURN_RIGHT;
			break;
		case SDLK_w:
			m_turn_direction = TURN_UP;
			break;
		case SDLK_s:
			m_turn_direction = TURN_DOWN;
			break;
		}
		break;
	}

	UpdateCollision(deltaTime, e);
	Entity::Update(deltaTime, e);
}
