#pragma once

#include "component.h"

typedef struct : public Component
{
	int x;
	int y;
	int z;
} CellPosition;