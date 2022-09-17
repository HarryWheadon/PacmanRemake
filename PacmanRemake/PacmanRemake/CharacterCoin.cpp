#include "CharacterCoin.h"


CharacterCoin::CharacterCoin(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map) : Characters(render, imagepath, startposition, map)
{
	m_position = startposition;
}

CharacterCoin::~CharacterCoin() {}


void CharacterCoin::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE, 0.0);
}

void CharacterCoin::update(float deltaTime, SDL_Event e)
{
}
