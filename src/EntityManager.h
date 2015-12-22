#pragma once

class Engine;

#include <vector>

#include "FixedHash.h"

#include "CellPosition.h"
#include "ScreenPosition.h"
#include "Sprites.h"

#include "GameObject.h"
#include "System.h"

class EntityManager : public System
{
public:
	EntityManager();

	void update(float dt);
	void init(void);

	// the entities
	std::vector<GameObject> entities;

	// the components
	std::vector<CellPosition> cellPosition;
	std::vector<ScreenPosition> screenPosition;
	std::vector<Sprites> sprites;

};