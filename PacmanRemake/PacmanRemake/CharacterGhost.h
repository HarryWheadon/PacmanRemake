#pragma once
#include "Characters.h"
#include "Level1.h"

class CharacterGhost : public Characters
{
public:
	CharacterGhost(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
	~CharacterGhost();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

private:
	float m_single_sprite_w;
	float m_single_sprite_h;
};

