#pragma once
#include "Entity.h"
#include "Level1.h"

class LevelMap;
class EntityPellet : public Entity
{
public:
	EntityPellet(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map);
	~EntityPellet();

	virtual void Render();
	virtual void update(float deltaTime, SDL_Event e);
};
