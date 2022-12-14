#pragma once
struct Vector2D
{
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float initial_x, float initial_y)
	{
		x = initial_x;
		y = initial_y;
	}
};

enum SCREENS
{
	SCREEN_NULL,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_LEVEL3,
	SCREEN_LEVEL4,
	SCREEN_GAMEOVER,
};

enum FACING
{
	FACING_LEFT,
	FACING_RIGHT,
	FACING_UP,
	FACING_DOWN
};

enum TURN
{
	TURN_LEFT,
	TURN_RIGHT,
	TURN_UP,
	TURN_DOWN
};

struct Rect2D
{
	float x;
	float y;
	float width;
	float height;

	Rect2D(float x_pos, float y_pos, float width, float height)
	{
		x = x_pos;
		y = y_pos;
		this->width = width;
		this->height = height;
	}
};
