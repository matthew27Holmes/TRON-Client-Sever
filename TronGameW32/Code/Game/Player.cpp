#include"Player.h"

Player::Player( sf::Vector2f size, sf::Vector2f Postion)
{
	// set up player sprite 
	playerTexture.loadFromFile("PlayerBlue.png");
	playerBody.setTexture(playerTexture);
	playerBody.setScale(size);
	playerBody.setOrigin(0,0);
	playerBody.setColor(sf::Color::Blue);

	
	setAlive(true);
}

Player::~Player()
{
}

void Player::movePlayer()
{
	
	switch (game_action)
	{
	case Action::UP:
		playerBody.setRotation(270);
		speed.x = 0;
		speed.y = -getSpeed() * getDT();
		break;
	case Action::RIGHT:
		playerBody.setRotation(0);
		speed.x = getSpeed() * getDT();
		speed.y = 0.0f;
		break;
	case Action::LEFT:
		playerBody.setRotation(180);
		speed.x = -getSpeed() * getDT();
		speed.y = 0.0f;
		break;
	case Action::DOWN:
		playerBody.setRotation(90);
		speed.x = 0;
		speed.y = getSpeed() * getDT();
		break;
	}
	playerBody.move(speed.x, speed.y);
}
void Player::setHoldingPowerUp(bool _pickup)
{
	HoldingpowerUp = _pickup;
}
void Player::activatePowerUp(sf::RenderWindow* window)
{
	if (HoldingpowerUp)
	{
		switch (powerUp_ation)
		{
		case PowerUp::BOOST:
			sf::Clock game_clock;

			sf::Time powerUpdelay = sf::seconds(0.10);
			sf::Time now = game_clock.getElapsedTime();
			sf::Clock;
			break;
		}
	}
}
void Player::setPos(sf::Vector2f _pos)
{
	playerBody.setPosition(_pos);
}
void Player::draw(sf::RenderWindow*window)
{
	window->draw(playerBody);
}

