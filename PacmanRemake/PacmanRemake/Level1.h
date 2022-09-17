#pragma once
#include "GameScreen.h"
#include "Characters.h"
#include "CharacterCoin.h"
#include "Commons.h"
#include "Texture.h"
#include "LevelMap.h"
#include <vector>
#include <iostream>

class Characters;
class CharacterCoin;
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
	CharacterCoin* Coin_Character;
	vector<CharacterCoin*> m_coins;


	float m_background_yPos;


	void CreateCoin(Vector2D position);
	void UpdateCoins(float deltaTime, SDL_Event e);
	void SetLevelMap();
	bool SetUpLevel();
};

