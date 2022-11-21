#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "constants.h"
#include "Collisions.h"
#include "Texture.h"
#include "LevelMap.h"
using namespace std;

class Texture;
class Entity
{
protected:
	virtual void MoveLeft(float deltaTime, int speed);
	virtual void MoveRight(float deltaTime, int speed);
	virtual void MoveUp(float deltaTime, int speed);
	virtual void MoveDown(float deltaTime, int speed);

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture* m_texture;
	LevelMap* m_current_level_map;

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
	int m_speed;

public:
	Entity(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Entity();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void GhostUpdate(float deltaTime, SDL_Event e, int speed);
	void UpdateCollision(float deltaTime, SDL_Event e);
	bool GetHitWall() { return hitwall; }
	bool GetAlive() { return m_alive; }
	void HitWall(bool hitwall);
	void SetAlive(bool isAlive);
	float GetCollisionRadius();

	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_single_sprite_w, m_single_sprite_h); }
	Vector2D GetPosition();
	FACING m_facing_direction;
	TURN m_turn_direction;

private:
};


class EntityPacman : public Entity
{
public:
	EntityPacman(SDL_Renderer* renderer, string imagePath, Vector2D startposition, LevelMap* map);
	virtual void PacmanUpdate(float deltaTime, SDL_Event e);
};