#include "RenderSystem.h"

RenderSystem::RenderSystem(Engine * engine, SDL_Renderer * renderer)
{
	this->engine = engine;
	this->renderer = renderer;
}

void RenderSystem::init()
{
	em = static_cast<EntityManager*>(engine->getSystem(Hash("EntityManager")));
	SDL_Surface* loadedSurface = IMG_Load("gfx/tileSet.png");
	if (loadedSurface == NULL)
	{
		std::string error = "Unable to load image ! SDL_image Error: "; 
		throw error + IMG_GetError();
	}
	
	tileSet = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	if (tileSet == NULL)
	{
		std::string error = "Unable to create texture ! SDL Error: ";
		throw error + SDL_GetError();
	}
}

void RenderSystem::update(float dt)
{
	int wSize, hSize, xSize, ySize;
	SDL_GetRendererOutputSize(renderer, &wSize, &hSize);
	xSize = wSize / 32 + 1;
	ySize = hSize / 32 + 1;
	// Create a 3D array
	typedef boost::multi_array<int, 3> array_type;
	typedef array_type::index index;
	array_type spriteMap(boost::extents[xSize][ySize][10]);
	
	for (std::vector<ScreenPosition>::iterator it = em->screenPosition.begin(); it != em->screenPosition.end(); ++it)
	{
		if (it->entity!=0 && 0 <= it->x && it->x < xSize && 0 <= it->y && it->y < ySize)
		{
			Sprites sprites = em->sprites[em->entities[it->entity][spritesComponent]];
			for (int z = 0; z < 10; z++)
			{
				if (sprites.sprites[z] != 0)
				{
					spriteMap[it->x][it->y][z] = sprites.sprites[z];
				}
			}
		}
	}
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			SDL_Rect dest = { x * 32, y * 32, 32, 32 };
			for (int z = 0; z < 10; z++)
			{
				int sId = spriteMap[x][y][z];
				SDL_Rect base = { (sId % 64) * 32, (sId / 64) * 32, 32, 32 };
				SDL_RenderCopy(renderer, tileSet, &base, &dest);
			}
		}
	}
	SDL_RenderPresent(renderer);
}

