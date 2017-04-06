#include"GameObject.h"

GameObject::GameObject()
{
	Speed = 60;
}
GameObject::~GameObject()
{
}


void GameObject::setAlive(bool _alive)
{
	Alive = _alive;
	//should change texture to explosion maybe add animation
}

void GameObject::setDT(float _dt)
{
	DT = _dt;
}