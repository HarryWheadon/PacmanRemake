#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer) : GameScreen(renderer)
{
	LoadScore();
	//loads in the background texture
	m_background_texture = new Texture(m_renderer);
	m_ScoreText = new TextLoad(m_renderer);
	m_HighScoreText = new TextLoad(m_renderer);

	m_ScoreText->LoadFont(35, to_string(m_score), { 255, 255, 255 });
	m_HighScoreText->LoadFont(35, to_string(m_HighScore), { 255, 255, 255 });

	if (!m_background_texture->LoadTexFromFile("Images/PacmanMenu.png"))
	{
		std::cout << " Failed to load background texture!" << std::endl;
	}
}

MainMenu::~MainMenu()
{
}

void MainMenu::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(0, 0), SDL_FLIP_NONE, 0.0);
	m_ScoreText->TextRender(60, 85);
	m_HighScoreText->TextRender(230, 85);
}

void MainMenu::Update(float deltaTime, SDL_Event e)
{

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_RETURN: {
			ofstream outfile;
			outfile.open("Score/Score.txt");
			outfile << 0;
			outfile.close();
			m_newScreen = SCREEN_LEVEL1;
			break; }
		}
	}
}

void MainMenu::LoadScore()
{
	ifstream infile;
	infile.open("Score/Score.txt");
	if (infile.is_open())
		infile >> m_score;
	infile.close();

	ifstream file;
	file.open("Score/HighScore.txt");
	if (file.is_open())
		file >> m_HighScore;
	file.close();
}
