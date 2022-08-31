#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture.h"
#include "constants.h"
#include "LevelMap.h"
using namespace std;

class Texture;
class Characters
{
protected:
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture* m_texture;

	bool m_moving_left;
	bool m_moving_right;
	bool m_alive;
	bool hitwall;
public:
	Characters(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Characters();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	bool GetHitWall() { return hitwall; }
	void HitWall(bool hitwall);

	FACING m_facing_direction;
	bool GetAlive() { return m_alive; }
	void SetAlive(bool isAlive);
private:
	LevelMap* m_current_level_map;
};
