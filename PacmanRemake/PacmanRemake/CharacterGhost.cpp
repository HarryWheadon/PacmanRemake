#include "CharacterGhost.h"

CharacterGhost::CharacterGhost(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) : Characters(renderer, imagePath, start_position, map)
{
	m_current_level_map = map;
	m_facing_direction = start_facing;
	m_position = start_position;
	m_renderer = renderer;

	m_single_sprite_w = m_texture->GetWidth() / 4;
	m_single_sprite_h = m_texture->GetHeight();

	m_moving_left = false;
	m_moving_right = true;
	m_moving_up = false;
	m_moving_down = false;
}

CharacterGhost::~CharacterGhost()
{
}


void CharacterGhost::Render()
{

	SDL_Rect portion_of_sprite = { m_single_sprite_w * m_current_frame,0,m_single_sprite_w, m_single_sprite_h };

	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
}

void CharacterGhost::Update(float deltaTime, SDL_Event e)
{
	CharacterGhost::GhostCollision(deltaTime, e);
	Characters::Update(deltaTime, e);
}

void CharacterGhost::GhostCollision(float deltaTime, SDL_Event e)
{



	int Direction = (rand() % 4);
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (m_current_level_map->GetTileAt(y, x) == 1 || m_current_level_map->GetTileAt(y, x) == 3)
			{
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

			if (m_current_level_map->GetTileAt(y, x) == 2)
			{
				if ((int)m_position.x == (x * TILE_WIDTH) && (int)m_position.y == (y * TILE_HEIGHT) || (int)m_position.x - 3 == (x * TILE_WIDTH) && (int)m_position.y == (y * TILE_HEIGHT)
					|| (int)m_position.x == (x * TILE_WIDTH) && (int)m_position.y - 3 == (y * TILE_HEIGHT) || (int)m_position.x - 3 == (x * TILE_WIDTH) && (int)m_position.y - 3 == (y * TILE_HEIGHT))
				{
					m_frame_delay -= deltaTime;
					if (m_frame_delay <= 0.0f)
					{
						//reset frame delay count
						m_frame_delay = TURN_DELAY;
						switch (Direction)
						{
						case 0:
							if (m_facing_direction == FACING_LEFT || m_facing_direction == FACING_DOWN || m_facing_direction == FACING_UP)
							{
								m_current_frame = 1;
								m_moving_left = true;
								m_moving_right = false;
								m_moving_up = false;
								m_moving_down = false;
								break;
							}
						case 1:
							if (m_facing_direction == FACING_RIGHT || m_facing_direction == FACING_DOWN || m_facing_direction == FACING_UP)
							{
								m_current_frame = 0;
								m_moving_left = false;
								m_moving_right = true;
								m_moving_up = false;
								m_moving_down = false;
								break;
							}
						case 2:
							if (m_facing_direction == FACING_LEFT || m_facing_direction == FACING_RIGHT || m_facing_direction == FACING_UP)
							{
								m_current_frame = 2;
								m_moving_left = false;
								m_moving_right = false;
								m_moving_up = true;
								m_moving_down = false;
								break;
							}
						case 3:
							if (m_facing_direction == FACING_LEFT || m_facing_direction == FACING_RIGHT || m_facing_direction == FACING_DOWN)
							{
								m_current_frame = 3;
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
}
