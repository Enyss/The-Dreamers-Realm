#include "EntityManager.h"

EntityManager::EntityManager()
{
	int N = 100000;

	std::array<int, 3> v = { 0,0,0 };
	// Create a 3D array
	entities.assign(N, v );
}

void EntityManager::update(float dt)
{
}

void EntityManager::init(void)
{
	int entityId = 1;
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 100; y++)
		{
			screenPosition.push_back(ScreenPosition(entityId, x, y));

			entities[entityId][screenPositionComponent] = screenPosition.size() - 1;

			Sprites s;
			s.sprites[0] = 64 * 14 + 63;
			s.entity = entityId;
			sprites.push_back( s );

			entities[entityId][spritesComponent] = sprites.size() - 1;

			entityId++;
		}
	}
}
