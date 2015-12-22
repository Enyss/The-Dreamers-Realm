#pragma once
class Engine;
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <boost/multi_array.hpp>
#include "pugixml.hpp"

#include "GameObject.h"
#include "System.h"
#include "Engine.h"
#include "EntityManager.h"

class RenderSystem : public System
{
public:
	RenderSystem( Engine * engine, SDL_Renderer * renderer);

	void update(float dt);
	void init(void);
private:
	Engine * engine;
	EntityManager * em;
	SDL_Renderer * renderer;
	SDL_Texture* tileSet;
};