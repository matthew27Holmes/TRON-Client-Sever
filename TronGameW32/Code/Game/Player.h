#pragma once
#include "GameObject.h"

class Player:public GameObject
{
public:
	Player( sf::Vector2f size, sf::Vector2f Postion);
	~Player();

	void draw(sf::RenderWindow* window);

	sf::Sprite getBody() { return playerBody; }
	void movePlayer();

	void setHoldingPowerUp(bool _pickup);
	bool getHoldingPowerUp() { return HoldingpowerUp; }
	void activatePowerUp(sf::RenderWindow* window);

	void setPos(sf::Vector2f _pos);

private:
	bool HoldingpowerUp;
	sf::Vector2f speed;
	sf::Texture playerTexture;
	sf::Sprite playerBody;
};

