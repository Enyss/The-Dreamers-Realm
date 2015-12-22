#include "GameObject.h"

int GameObject::GetComponent(int id)
{
	if (HasComponent(id))
		return componentHandle[id];
	return -1;
}

void GameObject::AddComponent(int id, int handle)
{
	componentHandle[id] = handle;
}

bool GameObject::HasComponent(int id)
{
	return componentHandle.count(id)==1;
}
