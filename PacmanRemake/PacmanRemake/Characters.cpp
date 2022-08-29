#include "Characters.h"
#include "Texture2D.h"
#include "constants.h"

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
}

Character::~Character()
{
}

void Character::Render()
{
}

void Character::Update(float deltaTime, SDL_Event e)
{
}

void Character::SetAlive(bool isAlive)
{
}
