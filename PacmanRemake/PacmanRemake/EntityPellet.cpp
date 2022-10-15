#include "EntityPellet.h"


EntityPellet::EntityPellet(SDL_Renderer* render, string imagepath, Vector2D startposition, LevelMap* map) : Entity(render, imagepath, startposition, map)
{
	m_position = startposition;
}

EntityPellet::~EntityPellet() {}


void EntityPellet::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE, 0.0);
}

void EntityPellet::update(float deltaTime, SDL_Event e)
{
}
