#include "EntityFactory.h"

EntityFactory::EntityFactory(EntityManager * em)
{
	this->em = em;
}

void EntityFactory::update(float dt)
{
}

void EntityFactory::init(void)
{
	//entityDefinition["master"].load_file("xml/master.xml");
}

int EntityFactory::createEntity(std::string entityType)
{

	
	return 0;
}
