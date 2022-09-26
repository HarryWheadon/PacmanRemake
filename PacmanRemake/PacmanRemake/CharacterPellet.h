#pragma once
#include "Characters.h"
#include "Level1.h"

class LevelMap;
class CharacterPellet : public Characters
{
public:
	CharacterPellet(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map);
	~CharacterPellet();

	virtual void Render();
	virtual void update(float deltaTime, SDL_Event e);
};
