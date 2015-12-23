#pragma once

#include <vector>
#include "Component.h"

typedef struct Sprites Sprites;

struct Sprites : public Component
{
	Sprites() { sprites.assign(10,0); }
	std::vector<int> sprites;
};