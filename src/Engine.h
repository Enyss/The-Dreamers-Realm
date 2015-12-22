#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <SDL.h>

#include "FixedHash.h"
#include "System.h"


#include "EntityManager.h"
#include "ObjectFactory.h"
#include "RenderSystem.h"
#include "InputSystem.h"


class Engine : public System
{
public:
	Engine(SDL_Window * window, SDL_Renderer * renderer);
	void init(void);
	void update(float dt);
	void mainLoop(void);

	void addSystem(System *sys, int id);
	System* getSystem(int id);

	int getState(void);
	void setState(int state);

	
private:
	std::map<int, System*> systems;
	int state;
	SDL_Renderer * renderer;
};