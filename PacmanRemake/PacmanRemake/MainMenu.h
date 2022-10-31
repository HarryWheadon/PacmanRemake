#pragma once
#include "GameScreen.h"
#include "Texture.h"
#include "ScreenManager.h"
#include <vector>
#include <iostream>

class Texture;
class ScreenManager;

class MainMenu : GameScreen
{
public:
	MainMenu(SDL_Renderer* renderer);
	~MainMenu();

	void Render() override;
	void Update(float deltaTime, SDL_Event e);

private:
	bool changeScreen = false;

	ScreenManager* screen_manager;
	Texture* m_background_texture;
};


