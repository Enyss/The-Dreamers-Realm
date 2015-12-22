#pragma once

typedef struct ScreenPosition ScreenPosition;

struct ScreenPosition
{
	ScreenPosition(int x, int y) : x(x), y(y) {};
	int x;
	int y;
};