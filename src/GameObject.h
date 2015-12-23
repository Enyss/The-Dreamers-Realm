#pragma once

#include <map>

#include "Hash.h"

class GameObject
{
public:
	int GetComponent(Hash id);
	void AddComponent(Hash id, int handle);
	bool HasComponent(Hash id);

private:
	std::map< Hash ,int > componentHandle;
};