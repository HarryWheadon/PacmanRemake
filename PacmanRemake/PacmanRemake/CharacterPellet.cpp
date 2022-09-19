#include "CharacterPellet.h"


CharacterPellet::CharacterPellet(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map) : Characters(render, imagepath, startposition, map)
{
	m_position = startposition;
}

CharacterPellet::~CharacterPellet() {}


void CharacterPellet::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE, 0.0);
}

void CharacterPellet::update(float deltaTime, SDL_Event e)
{
}
