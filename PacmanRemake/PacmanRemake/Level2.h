#pragma once
#include "GameScreen.h"
#include "Characters.h"
#include "Commons.h"
#include "Texture.h"
#include "LevelMap.h"
#include <vector>
#include <iostream>

class Level2 : GameScreen
{
public:
	Level2(SDL_Renderer* renderer);
	~Level2();

	virtual void Render() override;
	virtual void Update(float deltaTime, SDL_Event e) override;
private:
	Texture* m_background_texture;

	bool SetUpLevel();
};
