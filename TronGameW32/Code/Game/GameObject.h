#pragma once

#include"GameData.h"
//#include "Client.h"
#include "Collider.h"
#include"Animation.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	bool getAlive() { return Alive; }

	void setAlive(bool _alive);
	void setDT(float _dt);
	float getDT() { return DT; }
	float getSpeed() { return Speed; }

private:
	bool Alive;
	float Speed;
	float DT;
};
//#endif
