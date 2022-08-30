#include "Characters.h"

void Character::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}

void Character::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map)
{
	m_current_level_map = map;
	m_renderer = renderer;
	m_position = startPosition;
	m_alive = true;

	m_texture = new Texture(m_renderer);
	if (!m_texture->LoadTexFromFile(imagePath))
	{
		std::cout << "Failed to load Character texture!" << std::endl;
	}

	m_moving_left = false;
	m_moving_right = false;
}

Character::~Character()
{
	m_renderer = nullptr;
}

void Character::Render()
{

}

void Character::Update(float deltaTime, SDL_Event e)
{

	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
	if (GetHitWall() == true)
	{
		if (m_position.x < 0)
		{
			m_position.x += 1;
		}
		else if (m_position.x > 495)
		{
			m_position.x -= 1;
		}
	}
}

void Character::SetAlive(bool isAlive)
{
	m_alive = isAlive;
}

void Character::HitWall(bool Hitwall)
{
	hitwall = Hitwall;
}

