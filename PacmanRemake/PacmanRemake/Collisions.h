#pragma once
#include "Commons.h"
#include "Characters.h"

class Characters;
class Collisions
{
public:
	~Collisions();

	static Collisions* Instance();
	bool Circle(Characters* character1, Characters* character2);
	bool Box(Rect2D rect1, Rect2D rect2);

private:
	Collisions();
	static Collisions* m_instance;
};


