#include "GameObject.h"

int GameObject::GetComponent(Hash id)
{
	if (HasComponent(id))
		return componentHandle[id];
	return -1;
}

void GameObject::AddComponent(Hash id, int handle)
{
	componentHandle[id] = handle;
}

bool GameObject::HasComponent(Hash id)
{
	return componentHandle.count(id)==1;
}
