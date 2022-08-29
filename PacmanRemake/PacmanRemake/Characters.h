#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"
using namespace std;

class Texture2D;
class Character
{
protected:
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

public:
	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Character();

private:
	LevelMap* m_current_level_map;
}
