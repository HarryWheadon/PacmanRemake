#include "CharacterGhost.h"
#include "Characters.h"
#include "GameScreen.h"


CharacterGhost::CharacterGhost(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) : Characters(renderer, imagePath, start_position, map)
{
	m_facing_direction = start_facing;
	m_position = start_position;

	m_single_sprite_w = m_texture->GetWidth();
	m_single_sprite_h = m_texture->GetHeight();
}


CharacterGhost::~CharacterGhost()
{
}

void CharacterGhost::Render()
{
	SDL_Rect portion_of_sprite = { m_single_sprite_w * m_current_frame,0,m_single_sprite_w, m_single_sprite_h };
	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

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

void CharacterGhost::Update(float deltaTime, SDL_Event e)
{
}
