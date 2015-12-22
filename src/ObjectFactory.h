#pragma once
class Engine;
#include <vector>

#include "GameObject.h"
#include "System.h"

class ObjectFactory : public System
{
public :
	void update(float dt);
	void init(void);
private :
	std::vector<GameObject> entities;
};