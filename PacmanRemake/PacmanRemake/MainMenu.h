#pragma once
#include "GameScreen.h"
#include "Texture.h"
#include "ScreenManager.h"
#include <vector>
#include <iostream>
#include <fstream>

class Texture;
class ScreenManager;
class TextLoad;
class MainMenu : GameScreen
{
public:
	MainMenu(SDL_Renderer* renderer);
	~MainMenu();

	void Render() override;
	void Update(float deltaTime, SDL_Event e);
	void LoadScore();

	int m_score;
	int m_HighScore;
private:
	TextLoad* m_ScoreText;
	TextLoad* m_HighScoreText;
	Texture* m_background_texture;
};


