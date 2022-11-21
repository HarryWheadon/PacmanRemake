#pragma once
#include "Level1.h"
#include "GameScreen.h"
#include <fstream>
#include <iostream>

class Texture;
class LevelMap;
class SoundEffect;
class GameScreen;
class EntityPellet;
class EntityPacman;
class EntityGhost;
class Entity;
class Level2 : GameScreen
{
public:
	Level2(SDL_Renderer* renderer);
	~Level2();

	void Render();
	void Update(float deltaTime, SDL_Event e);
private:
	Texture* m_background_texture;
	LevelMap* m_level_map;
	EntityPacman* Pacman_Entity;
	EntityGhost* Ghost_Entity;
	EntityPellet* Pellet_Entity;
	vector<EntityGhost*> m_ghost;
	vector<EntityPellet*> m_pellets;
	SoundEffect* m_munch;
	SoundEffect* m_background_sound;
	TextLoad* m_text;

	int score;
	int scoreOld;

	void CreatePellet(Vector2D position);
	void CreateGhost(string file, Vector2D position);
	void UpdatePellet(float deltaTime, SDL_Event e);
	void UpdateGhost(float deltaTime, SDL_Event e);

	void SetLevel2Map();
    void SetUpLevel2();
};
