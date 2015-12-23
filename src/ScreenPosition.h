#pragma once

#include "Component.h"

typedef struct ScreenPosition ScreenPosition;

struct ScreenPosition : public Component
{
	ScreenPosition() : entity(0), x(0), y(0) {};
	ScreenPosition(int id, int x, int y) : entity(id), x(x), y(y) {};
	int entity;
	int x;
	int y;
};