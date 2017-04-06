#include"GameObject.h"

class Enemy :public GameObject
{
public:
	Enemy( sf::Vector2f size, sf::Vector2f Postion);
	~Enemy();
	void draw(sf::RenderWindow* window);
	void SetDirection(int _EDirection);
	sf::Sprite getBody() { return EnemyBody; }
	void setPos(sf::Vector2f _pos);
	void moveEnemy();
	
private:

	float Espeedx;
	float Espeedy;
	sf::Sprite EnemyBody;
	sf::Texture EnemyTexture;
};