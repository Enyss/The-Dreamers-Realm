#pragma once

#include <vector>

typedef struct Sprites Sprites;

struct Sprites
{
	Sprites() { sprites.assign(10,0); }
	std::vector<int> sprites;
};