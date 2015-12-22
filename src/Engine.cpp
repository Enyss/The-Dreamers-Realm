#include "Engine.h"


Engine::Engine(SDL_Window * window, SDL_Renderer * renderer)
{
	state = FixedHash("menu");
	addSystem(this, FixedHash("Engine"));
	//this->window = window;
	this->renderer = renderer;
}

void Engine::init()
{
	addSystem(new EntityManager(), FixedHash("EntityManager"));
	addSystem(new InputSystem(this), FixedHash("InputSystem"));
	addSystem(new RenderSystem(this, renderer), FixedHash("RenderSystem"));
	try 
	{
		static_cast<EntityManager*>(systems[FixedHash("EntityManager")])->init();
		static_cast<InputSystem*>(systems[FixedHash("InputSystem")])->init();
		static_cast<RenderSystem*>(systems[FixedHash("RenderSystem")])->init();
	}
	catch (std::string const& error)
	{
		std::cout << error << std::endl;
		state = FixedHash("quit");
	}
}


void Engine::update(float dt)
{
}

void Engine::mainLoop(void)
{
	while (state != FixedHash("quit") )
	{
		static_cast<InputSystem*>(systems[FixedHash("InputSystem")])->update(0);
		static_cast<EntityManager*>(systems[FixedHash("EntityManager")])->update(0);
		static_cast<RenderSystem*>(systems[FixedHash("RenderSystem")])->update(0);
	}
}

void Engine::addSystem(System * sys, int id)
{
	systems[id] = sys;
}

System * Engine::getSystem(int id)
{
	if (systems.count(id) == 1)
		return systems[id];
	return nullptr;
}

int Engine::getState(void)
{
	return state;
}

void Engine::setState(int state)
{
	this->state = state;
}
