#include "Engine.h"


Engine::Engine(SDL_Window * window, SDL_Renderer * renderer) : state(Hash("menu"))
{
	addSystem(this, Hash("Engine"));
	//this->window = window;
	this->renderer = renderer;
}

void Engine::init()
{
	addSystem(new EntityManager(), Hash("EntityManager"));
	addSystem(new InputSystem(this), Hash("InputSystem"));
	addSystem(new RenderSystem(this, renderer), Hash("RenderSystem"));
	try 
	{
		static_cast<EntityManager*>(systems[Hash("EntityManager")])->init();
		static_cast<InputSystem*>(systems[Hash("InputSystem")])->init();
		static_cast<RenderSystem*>(systems[Hash("RenderSystem")])->init();
	}
	catch (std::string const& error)
	{
		std::cout << error << std::endl;
		state = Hash("quit");
	}
}


void Engine::update(float dt)
{
}

void Engine::mainLoop(void)
{
	while (!(state == Hash("quit")) )
	{
		static_cast<InputSystem*>(systems[Hash("InputSystem")])->update(0);
		static_cast<EntityManager*>(systems[Hash("EntityManager")])->update(0);
		static_cast<RenderSystem*>(systems[Hash("RenderSystem")])->update(0);
	}
}

void Engine::addSystem(System * sys, Hash id)
{
	systems[id] = sys;
}

System * Engine::getSystem(Hash id)
{
	if (systems.count(id) == 1)
		return systems[id];
	return nullptr;
}

Hash Engine::getState(void)
{
	return state;
}

void Engine::setState(Hash state)
{
	this->state = state;
}
