#include "EntityManager.h"

EntityManager::EntityManager()
{
	int N = 1000;
	entities.reserve(N);
	cellPosition.reserve(N);
	screenPosition.reserve(N);
	sprites.reserve(N);
}

void EntityManager::update(float dt)
{
}

void EntityManager::init(void)
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			entities.push_back(GameObject());

			screenPosition.push_back(ScreenPosition(x, y));
			entities.back().AddComponent(FixedHash("ScreenPosition"), screenPosition.size() - 1);

			sprites.push_back(Sprites());
			entities.back().AddComponent(FixedHash("Sprites"), sprites.size() - 1);

			sprites[entities.back().GetComponent(FixedHash("Sprites"))].sprites[0] = 64 * 14 + 63;
		}
	}
}
