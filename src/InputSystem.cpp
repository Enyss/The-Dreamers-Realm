#include "InputSystem.h"

InputSystem::InputSystem(Engine * engine)
{
	this->engine = engine;
}

void InputSystem::update(float dt)
{
	int state = engine->getState();
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			engine->setState( FixedHash("quit") );
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		{
			engine->setState( FixedHash("quit") );
		}
	}
}

void InputSystem::init()
{
}
