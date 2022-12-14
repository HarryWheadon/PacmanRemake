#pragma once
#include "Commons.h"
#include "Entity.h"

class Entity;
class Collisions
{
public:
	~Collisions();

	static Collisions* Instance();
	bool Circle(Entity* Entity1, Entity* Entity2);
	bool Box(Rect2D rect1, Rect2D rect2);

private:
	Collisions();
	static Collisions* m_instance;
};


