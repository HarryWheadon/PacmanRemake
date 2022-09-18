#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "Texture.h"
#include "constants.h"
#include "Collisions.h"
#include "LevelMap.h"

using namespace std;

class Texture;
class Characters
{
protected:
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void MoveUp(float deltaTime);
	virtual void MoveDown(float deltaTime);
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture* m_texture;

	bool m_moving_left;
	bool m_moving_right;
	bool m_moving_up;
	bool m_moving_down;
	bool m_alive;
	bool hitwall;
	float m_single_sprite_w;
	float m_single_sprite_h;
	float m_current_frame;
	float m_frame_delay;
	LevelMap* m_current_level_map;

public:
	Characters(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Characters();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth() / 4, m_texture->GetHeight()); }

	FACING m_facing_direction;
	bool GetAlive() { return m_alive; }
	void SetAlive(bool isAlive);

	float GetCollisionRadius();
	Vector2D GetPosition();
	bool GetHitWall() { return hitwall; }
	void HitWall(bool hitwall);
private:
};


class CharacterPacman : public Characters
{
public:
	CharacterPacman(SDL_Renderer* renderer, string imagePath, Vector2D startposition, LevelMap* map);
	virtual void PacmanUpdate(float deltaTime, SDL_Event e);
};