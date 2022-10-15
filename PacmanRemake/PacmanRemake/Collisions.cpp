#include "Collisions.h"

Collisions * Collisions::m_instance = nullptr;

Collisions::Collisions()
{}

Collisions::~Collisions()
{
	m_instance = nullptr;
}

Collisions* Collisions::Instance()
{
	if (!m_instance)
	{
		m_instance = new Collisions;
	}
	return m_instance;
}

bool Collisions::Circle(Entity* Entity1, Entity* Entity2)
{
	Vector2D vec = Vector2D((Entity1->GetPosition().x - Entity2->GetPosition().x), (Entity1->GetPosition().y) - Entity2->GetPosition().y);
	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	double combined_distance = (Entity1->GetCollisionRadius() + Entity2->GetCollisionRadius());
	return distance < combined_distance;
}

bool Collisions::Box(Rect2D rect1, Rect2D rect2)
{

	if (rect1.x + rect1.width > rect2.x &&
		rect1.x < rect2.x + rect2.width &&
		rect1.y + rect1.height > rect2.y &&
		rect1.y < rect2.y + rect2.height)
	{
		return true;
	}
	return false;
}
