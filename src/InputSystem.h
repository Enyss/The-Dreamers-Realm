#pragma once
class Engine;
#include <SDL.h>

#include "System.h"
#include "Engine.h"

class InputSystem : public System
{
public:
	InputSystem(Engine * engine);

	void update(float dt);
	void init();
private:
	Engine * engine;
};

