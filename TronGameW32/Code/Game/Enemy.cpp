#include"Enemy.h"

Enemy::Enemy( sf::Vector2f size, sf::Vector2f Postion)
{
	//set up enemy sprite 
	EnemyTexture.loadFromFile("PlayerBlue.png");
	EnemyBody.setScale(size);
	EnemyBody.setTexture(EnemyTexture);
	EnemyBody.setOrigin(0,0);
	EnemyBody.setColor(sf::Color::Green);
}
Enemy::~Enemy()
{

}

void Enemy::SetDirection(int _EDirection)
{
	int EDirection = _EDirection;
	switch (EDirection)
	{
	case 1:
		Enemy_action = EnemyAction::EUP;
		break;
	case 2:
		Enemy_action = EnemyAction::ELEFT;
		break;
	case 3:
		Enemy_action = EnemyAction::ERIGHT;
		break;
	case 4:
		Enemy_action = EnemyAction::EDOWN;
		break;
	}
	

}
void Enemy::setPos(sf::Vector2f _pos)
{
	EnemyBody.setPosition(_pos);
}
void Enemy::moveEnemy()
{
	switch (Enemy_action)
	{
	case EnemyAction::EUP:
		EnemyBody.setRotation(270);
		Espeedx = 0;
		Espeedy = -getSpeed() * getDT();
		break;
	case EnemyAction::ERIGHT:
		EnemyBody.setRotation(0);
		Espeedx = getSpeed() * getDT();
		Espeedy = 0;
		break;
	case EnemyAction::ELEFT:
		EnemyBody.setRotation(180);
		Espeedx = -getSpeed() * getDT();
		Espeedy = 0;
		break;
	case EnemyAction::EDOWN:
		EnemyBody.setRotation(90);
		Espeedx = 0;
		Espeedy = getSpeed() * getDT();
		break;
	}
	EnemyBody.move(Espeedx, Espeedy);
}
void Enemy::draw(sf::RenderWindow* window)
{
	window->draw(EnemyBody);
}