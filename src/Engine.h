#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <SDL.h>

#include "Hash.h"
#include "System.h"


#include "EntityManager.h"
//#include "EntityFactory.h"
#include "RenderSystem.h"
#include "InputSystem.h"


class Engine : public System
{
public:
	Engine(SDL_Window * window, SDL_Renderer * renderer);
	void init(void);
	void update(float dt);
	void mainLoop(void);

	void addSystem(System *sys, Hash id);
	System* getSystem(Hash id);

	Hash getState(void);
	void setState(Hash state);

	
private:
	std::map<Hash, System*> systems;
	Hash state;
	SDL_Renderer * renderer;
};