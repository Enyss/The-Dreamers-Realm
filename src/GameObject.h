#pragma once

#include <map>

class GameObject
{
public:
	int GetComponent(int id);
	void AddComponent(int id, int handle);
	bool HasComponent(int id);

private:
	std::map< int,int > componentHandle;
};