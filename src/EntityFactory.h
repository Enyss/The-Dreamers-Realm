#pragma once
class Engine;
#include <vector>
#include "pugixml.hpp"

#include "EntityManager.h"
#include "GameObject.h"
#include "System.h"

class EntityFactory : public System
{
public :
	EntityFactory(EntityManager * em);
	void update(float dt);
	void init(void);
	int createEntity(std::string entityType);
private :
	EntityManager * em;
	pugi::xml_document entityDefinition;
};