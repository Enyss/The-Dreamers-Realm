#pragma once

class Engine;

#include <boost/multi_array.hpp>
#include <vector>
#include <array>

#include "Hash.h"

#include "CellPosition.h"
#include "ScreenPosition.h"
#include "Sprites.h"

#include "GameObject.h"
#include "System.h"

enum Components {cellPositionComponent, screenPositionComponent, spritesComponent, _countComponents};

class EntityManager : public System
{
public:
	EntityManager();

	void update(float dt);
	void init(void);

	// the lookup table
	std::vector<std::array<int, _countComponents>> entities;

	// the components
	std::vector<CellPosition> cellPosition;
	std::vector<ScreenPosition> screenPosition;
	std::vector<Sprites> sprites;
};