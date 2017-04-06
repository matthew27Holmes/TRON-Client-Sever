#pragma once
#include "GameData.h"
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();
	bool checkCollision(sf::Sprite objectA, sf::Sprite ObjectB);
	bool CheckGridCollisions(sf::RectangleShape _GridTile, sf::Sprite _Bike);
	sf::Vector2f GetPostion() { return body.getPosition(); }
	sf::Vector2f GetSizeHalf() { return body.getSize()/2.0f; }

private:
	sf::RectangleShape& body;

};

