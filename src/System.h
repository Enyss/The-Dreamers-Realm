#pragma once

class System
{
public:
	// All systems must update each game loop
	void update(float dt) {};

	// It's good practice to separate the construction and initialization code.
	void init(void) {};

	///All systems need a virtual destructor to have their destructor called 
	~System() {};
};
