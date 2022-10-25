#pragma once
#include "GameScreen.h"
#include "Entity.h"
#include "EntityPellet.h"
#include "EntityGhost.h"
#include "ScreenManager.h"
#include "MainMenu.h"
#include "TextLoad.h"
#include "SoundEffect.h"
#include <vector>
#include <iostream>

class LevelMap;
class Texture;
class SoundEffect;
class EntityPellet;
class EntityGhost;
class EntityPacman;
class Entity;
class Level1 : GameScreen
{
public:
	Level1(SDL_Renderer* renderer);
	~Level1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:
	Texture* m_background_texture;
	LevelMap* m_level_map;
	EntityPacman* Pacman_Entity;
	EntityGhost* Ghost_Entity;
	EntityPellet* Pellet_Entity;
	vector<EntityGhost*> m_ghost;
	vector<EntityPellet*> m_pellets;
	SoundEffect* m_pop;
	SoundEffect* m_background_sound;
	TextLoad* m_text;

	string message = "score";
	int score = 0, old_score;
	float m_background_yPos;

	void CreatePellet(Vector2D position);
	void CreateGhost(string file, Vector2D position);
	void UpdatePellet(float deltaTime, SDL_Event e);
	void UpdateGhost(float deltaTime, SDL_Event e);
	void SetLevelMap();
	bool SetUpLevel();
};

