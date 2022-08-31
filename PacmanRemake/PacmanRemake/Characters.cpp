#include "Characters.h"

Characters::Characters(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map)
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

Characters::~Characters()
{
	m_renderer = nullptr;
}

void Characters::Render()
{

}

void Characters::Update(float deltaTime, SDL_Event e)
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

void Characters::SetAlive(bool isAlive)
{
	m_alive = isAlive;
}

void Characters::HitWall(bool Hitwall)
{
	hitwall = Hitwall;
}

void Characters::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}

void Characters::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}

CharacterPacman::CharacterPacman(SDL_Renderer* renderer, string imagePath, Vector2D startposition, LevelMap* map) {}

void CharacterPacman::PacmanUpdate(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_UP:
			m_moving_up = true;
			break;
		case SDLK_DOWN:
			m_moving_down = true;
			break;
		}
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		}
		break;
	}
}



