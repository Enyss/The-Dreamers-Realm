#include "InputSystem.h"

InputSystem::InputSystem(Engine * engine)
{
	this->engine = engine;
}

void InputSystem::update(float dt)
{
	Hash state = engine->getState();
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			engine->setState(Hash("quit") );
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		{
			engine->setState(Hash("quit") );
		}
	}
}

void InputSystem::init()
{
}
