#pragma once
#include "Characters.h"
#include "Level1.h"

class LevelMap;
class CharacterCoin : public Characters
{
public:
	CharacterCoin(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map);
	~CharacterCoin();

	virtual void Render();
	virtual void update(float deltaTime, SDL_Event e);
};
