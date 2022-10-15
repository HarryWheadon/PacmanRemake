#pragma once
#include "Entity.h"
#include "GameScreen.h"
#include "Level1.h"

class EntityGhost : public Entity
{
public:
	EntityGhost(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
	~EntityGhost();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

private:

	void GhostCollision(float deltaTime,SDL_Event e);
};