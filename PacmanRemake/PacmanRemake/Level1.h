#pragma once
#include "GameScreen.h"
#include "Characters.h"
#include "CharacterPellet.h"
#include "Commons.h"
#include "Texture.h"
#include "LevelMap.h"
#include <vector>
#include <iostream>

class Characters;
class CharacterPellet;
class Texture;

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
	CharacterPacman* Pacman_Character;
	CharacterPellet* Pellet_Character;
	vector<CharacterPellet*> m_pellets;


	float m_background_yPos;


	void CreatePellet(Vector2D position);
	void UpdatePellet(float deltaTime, SDL_Event e);
	void SetLevelMap();
	bool SetUpLevel();
};

