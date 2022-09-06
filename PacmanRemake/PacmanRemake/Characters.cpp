#include "Characters.h"
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

void Characters::MoveUp(float deltaTime)
{
	m_facing_direction = FACING_UP;
	m_position.y -= deltaTime * MOVEMENTSPEED;
}

void Characters::MoveDown(float deltaTime)
{
	m_facing_direction = FACING_DOWN;
	m_position.y += deltaTime * MOVEMENTSPEED;
}

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
	m_moving_up = false;
	m_moving_down = false;
}

Characters::~Characters()
{
	m_renderer = nullptr;
}

void Characters::Render()
{
	m_single_sprite_w = m_texture->GetWidth() / 4;
	m_single_sprite_h = m_texture->GetHeight();

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
	if (m_moving_up)
	{
		MoveUp(deltaTime);
	}
	if (m_moving_down)
	{
		MoveDown(deltaTime);
	}


	m_frame_delay -= deltaTime;

	if (m_current_frame == 0)
	{
		if (m_frame_delay <= 0.0f)
		{
			//reset frame delay count
			m_frame_delay = ANIMATION_DELAY;

			//move the frame over
			m_current_frame++;

			//loop frame around if it goes beyond the number of frames
			if (m_current_frame > 1)
				m_current_frame = 0;
		}
	}

	if (m_current_frame == 2)
	{
		if (m_frame_delay <= 0.0f)
		{
			//reset frame delay count
			m_frame_delay = ANIMATION_DELAY;

			//move the frame over
			m_current_frame++;

			//loop frame around if it goes beyond the number of frames
			if (m_current_frame > 3)
				m_current_frame = 2;
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



CharacterPacman::CharacterPacman(SDL_Renderer* renderer, string imagePath, Vector2D startposition, LevelMap* map) : Characters(renderer, imagePath, startposition, map)
{
}

void CharacterPacman::PacmanUpdate(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = true;
			m_current_frame = 0;
			break;
		case SDLK_d:
			m_moving_right = true;
			m_current_frame = 0;
			break;
		case SDLK_w:
			m_moving_up = true;
			m_current_frame = 2;
			break;
		case SDLK_s:
			m_moving_down = true;
			m_current_frame = 2;
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = false;
			break;
		case SDLK_d:
			m_moving_right = false;
			break;
		case SDLK_w:
			m_moving_up = false;
			break;
		case SDLK_s:
			m_moving_down = false;
			break;
		}
		break;
	}
	Characters::Update(deltaTime, e);
}



